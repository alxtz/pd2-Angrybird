#include <QDebug>
#include <QWidget>
#include "GameView.h"

GameView::GameView(QWidget * parent)
 : QGraphicsView(parent)
{
    setFixedSize(1202 , 602);

    //設定scene
    gameScene = new GameScene();
    connect(gameScene , SIGNAL(setEndScene(int , int )) , this , SLOT(setEndGameScene(int,int)) );
    setScene (gameScene);

}

void GameView::setEndGameScene(int scoreGet, int birdUsed)
{
    qDebug()<<"setEndGameScene";

    endMenuScene = new EndMenuScene(scoreGet , birdUsed);
    connect(endMenuScene->restartButton , SIGNAL(clicked()) , this , SLOT(setPlayAgain()) );
    connect(endMenuScene->leaveButton , SIGNAL(clicked()) , this , SLOT(exitGame()) );

    setScene(endMenuScene);

    delete gameScene;
}

void GameView::setPlayAgain()
{
    qDebug()<<"setPlayAgain";

    gameScene = new GameScene();
    connect(gameScene , SIGNAL(setEndScene(int , int )) , this , SLOT(setEndGameScene(int,int)) );
    setScene (gameScene);

    delete endMenuScene;
}

void GameView::exitGame()
{
    emit quitGame ();
    qDebug()<<"emitted quit game";
    exit(0);
}
