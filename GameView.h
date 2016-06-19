#ifndef GAMEVIEW_H
#define GAMEVIEW_H


#include <QObject>
#include <QGraphicsView>
#include "./GameScene/GameScene.h"
#include "./EndMenuScene/EndMenuScene.h"

class GameView : public QGraphicsView
{
    Q_OBJECT

    public:
        GameView(QWidget * parent = 0);

        GameScene * gameScene;

        EndMenuScene * endMenuScene;

    public slots:
        void setEndGameScene(int scoreGet , int birdUsed);

};


#endif // GAMEVIEW_H
