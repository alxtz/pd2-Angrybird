#include <fstream>
#include <iostream>
#include <QBrush>
#include <QImage>
#include <QDebug>
#include <QObject>
#include <QWidget>
#include "./AbsClasses/GameItem.h"
#include "./Birds/RedBird.h"
#include "./Birds/YellowBird.h"
#include "./Birds/BigBird.h"
#include "./Birds/BlueBird.h"
#include "./RandomItems/Ground.h"
#include "./RandomItems/Stick_Vtl.h"
#include "./RandomItems/Stick_Hrz.h"
#include "./RandomItems/Stick2_Hrz.h"
#include "./RandomItems/Stick2_Vtl.h"
#include "./RandomItems/Block_Vtl.h"
#include "./Pigs/Pig1.h"
#include "./AbsClasses/GameItem.h"
#include "GameScene.h"

using namespace std;

GameScene::GameScene()
{
    //基本設定
    setBackgroundBrush(QBrush(QImage("./GameData/DefaultResources/Images/background.png")));
    setSceneRect ( 0 , 0 , 1200 , 600 );

    //設定哪一關
    stage = "Stage1";

    //設定timer60
    timer60 = new QTimer();
    timer60->setTimerType(Qt::PreciseTimer);
    timer60->start(1); //1/60秒

    //設定物理世界的更新頻率
    connect(timer60 , SIGNAL(timeout()) , this , SLOT(updateWorld()));

    //設定彈弓
    singleshot = new Singleshot();
    addItem(singleshot);

    connect (singleshot , SIGNAL(setNewBird()) , this , SLOT(setNewBird()));

    //設定gameEngine
    gameEngine = new GameEngine();
    addItem(gameEngine);
    gameEngine->setFlag(QGraphicsItem::ItemIsFocusable);
    gameEngine->setFocus ();
    gameEngine->grabKeyboard ();
    gameEngine->grabMouse ();


    connect (gameEngine , SIGNAL(release())  , singleshot , SLOT(release()) );
    connect (gameEngine , SIGNAL(release())  , this , SLOT(releaseBird()) );
    connect (gameEngine , SIGNAL(useSpecialAbility()) , this , SLOT(useSpecialAbility()));
    connect(gameEngine , SIGNAL(testEndGame()) , this , SLOT(testEndGame()) );

    //新增一個碰撞感測器
    collisionListener = new CollisionListener();
    connect(collisionListener , SIGNAL(killPig()) , this , SLOT(deletePig()) );

    //設定一個向量，在物理世界裡會使用的重力
    int gravityFactor = 100;
    gravity = new b2Vec2( 0.0f , -9.8f * gravityFactor );

    //設定物理世界，使用自定義的重力，與碰撞感測器
    physicWorld = new b2World( * gravity );
    physicWorld->SetContactListener (collisionListener);

    //新增一隻鳥
    AbsBird * redBird = new RedBird(physicWorld);
    focusedBird = redBird;
    addItem(redBird);
    connect(gameEngine , SIGNAL(getPullPos(int , int)) , redBird , SLOT(setPullPos(int , int)) );
    flyingBird = redBird;


    //新增一個地板
    GameItem * ground = new Ground(physicWorld);
    addItem(ground);

    //add PlayScore
    playScore = new PlayScore();
    addItem(playScore);
    connect(collisionListener , SIGNAL(spawnScore(int)) , playScore , SLOT(addScore(int)) );

    //set used bird amount
    usedBird = 0;

    setupStage ();

    connect(gameEngine , SIGNAL(getPullPos(int , int)) , singleshot , SLOT(pull(int , int)) );
}

GameScene::~GameScene()
{

}

void GameScene::setupStage()
{
    pigAmount = 0;

    ifstream inFile;
    string stagePath;
    stagePath = "./GameData/Stages/" + stage + "/setup.txt";
    inFile.open (stagePath);

    for(int i=0; i<=999; i++)
    {
        int objectType;
        int x , y;
        if(inFile>>objectType)
        {
            cout<<"第"<<i+1<<"個物體的type為"<<objectType<<endl;
            inFile>>x;
            inFile>>y;

            switch(objectType)
            {
                case 0:
                {
                    //0代表產生一個垂直的stick
                    GameItem * stick_vtl = new Stick_Vtl(physicWorld, x , y);
                    addItem(stick_vtl);
                    connect(timer60 , SIGNAL(timeout()) , stick_vtl , SLOT(updatePos()));
                    break;
                }
                case 1:
                {
                    //1代表產生一個水平的stick
                    GameItem * stick_hrz = new Stick_Hrz(physicWorld, x , y);
                    addItem(stick_hrz);
                    connect(timer60 , SIGNAL(timeout()) , stick_hrz , SLOT(updatePos()));
                    break;
                }
                case 3:
                {
                    //3代表產生一個水平的長stick
                    GameItem * stick2_hrz = new Stick2_Hrz(physicWorld, x , y);
                    addItem(stick2_hrz);
                    connect(timer60 , SIGNAL(timeout()) , stick2_hrz , SLOT(updatePos()));
                    break;
                }
                case 4:
                {
                    //4代表產生一隻垂直的長stick
                    GameItem * stick2_vtl = new Stick2_Vtl(physicWorld, x , y);
                    addItem(stick2_vtl);
                    connect(timer60 , SIGNAL(timeout()) , stick2_vtl , SLOT(updatePos()));
                    break;
                }
                case 10:
                {
                    //10代表產生一隻pig1
                    GameItem * pig1 = new Pig1(physicWorld, x , y);
                    addItem(pig1);
                    connect(timer60 , SIGNAL(timeout()) , pig1 , SLOT(updatePos()));
                    pigAmount++;
                    break;
                }
            }
        }
        else
        {
            cout<<"讀檔結束"<<endl;
            return;
        }
    }

}

void GameScene::updateWorld()
{
    physicWorld->Step(0.001f , 10 , 10);
    //qDebug()<<"there are "<<pigAmount<<" pigs";
}

void GameScene::releaseBird()
{
    connect(timer60 , SIGNAL(timeout()) , focusedBird , SLOT(updatePos()));
    focusedBird->releaseBird(singleshot->forceX , singleshot->forceY);
    usedBird++;
}

void GameScene::setNewBird()
{
    disconnect(gameEngine , SIGNAL(getPullPos(int , int)) , focusedBird , SLOT(setPullPos(int , int)) );
    flyingBird = focusedBird;
    //把正在飛的鳥設為上一隻射出的鳥

    if(usedBird%4==0)
    {
        AbsBird * redBird = new RedBird(physicWorld);
        focusedBird = redBird;
        addItem(redBird);
        connect(gameEngine , SIGNAL(getPullPos(int , int)) , redBird , SLOT(setPullPos(int , int)) );
    }
    else if(usedBird%4==1)
    {
        AbsBird * yellowBird = new YellowBird(physicWorld);
        focusedBird = yellowBird;
        addItem(yellowBird);
        connect(gameEngine , SIGNAL(getPullPos(int , int)) , yellowBird , SLOT(setPullPos(int , int)) );
    }
    else if(usedBird%4==2)
    {
        AbsBird * bigBird = new BigBird(physicWorld);
        focusedBird = bigBird;
        addItem(bigBird);
        connect(gameEngine , SIGNAL(getPullPos(int , int)) , bigBird , SLOT(setPullPos(int , int)) );
    }
    else if(usedBird%4==3)
    {
        AbsBird * blueBird = new BlueBird(physicWorld);
        focusedBird = blueBird;
        addItem(blueBird);
        connect(gameEngine , SIGNAL(getPullPos(int , int)) , blueBird , SLOT(setPullPos(int , int)) );
        connect(blueBird , SIGNAL(spawnBlueChild(int , int)) , this , SLOT(spawnBlueChild(int,int)) );
    }
}

void GameScene::useSpecialAbility()
{
    flyingBird->specialAbility ();
}

void GameScene::spawnBlueChild(int x, int y)
{
    //cout<<"產生child於"
    AbsBird * child1 = new BlueBird(physicWorld );
    child1->bodyStruct->position.Set(GameItem::PixToMeter_x(x) , GameItem::PixToMeter_y(y));
    child1->physicBody = child1->inWorld->CreateBody(child1->bodyStruct);
    child1->physicBody->SetUserData (child1->itemData);
    child1->physicBody->CreateFixture(child1->bodyFixture);
    child1->physicBody->SetAngularDamping(0.3);
    child1->physicBody->SetLinearDamping(0.07);
    addItem(child1);
    connect(timer60 , SIGNAL(timeout()) , child1 , SLOT(updatePos()));

    /*
    AbsBird * child2 = new BlueBird(physicWorld);
    child2->physicBody->SetTransform (b2Vec2(x , y) , 0);
    addItem(child2);
    connect(timer60 , SIGNAL(timeout()) , child2 , SLOT(updatePos()));
    */
}

void GameScene::deletePig()
{
    qDebug()<<"delete!";
    pigAmount--;
    if(pigAmount<=0)
    {
        qDebug()<<"GameEnd";
        emit setEndScene (playScore->score , usedBird);
    }
}

void GameScene::testEndGame()
{
    emit setEndScene (playScore->score , usedBird);
}
