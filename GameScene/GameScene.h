#ifndef GAMESCENE_H
#define GAMESCENE_H


#include <Box2D/Box2D.h>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
#include <QTimer>
#include <cstring>
#include "./AbsClasses/AbsBird.h"
#include "Singleshot.h"
#include "GameEngine.h"
#include "CollisionListener.h"
#include "PlayScore.h"

using namespace std;

class GameScene : public QGraphicsScene
{
    Q_OBJECT

    public:
        GameScene();

        void setupStage();

        QTimer * timer60;

    public slots:
        void updateWorld();
        void releaseBird();
        void setNewBird();
        void useSpecialAbility();
        void spawnBlueChild(int x , int y);

        void deletePig();

        void testEndGame();

    signals:
        void setEndScene(int  , int );

    private:
        Singleshot * singleshot;
        GameEngine * gameEngine;

        b2World * physicWorld;
        b2Vec2 * gravity;

        AbsBird * focusedBird;
        AbsBird * flyingBird;

        CollisionListener * collisionListener;

        string stage;

        PlayScore * playScore;

        int pigAmount;
        int usedBird;



        //設定一個vector，貯存在physicWorld裡面的所有物體
};


#endif // GAMESCENE_H
