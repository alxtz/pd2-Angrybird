#include <QDebug>
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

    setScene(endMenuScene);

    delete gameScene;
}
