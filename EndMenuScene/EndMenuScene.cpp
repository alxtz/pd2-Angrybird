#include <QBrush>
#include <QImage>
#include <QDebug>
#include <QPixmap>
#include "EndMenuScene.h"


EndMenuScene::EndMenuScene(int scoreGet , int birdUsed)
{
    setBackgroundBrush (QBrush(QImage("./GameData/DefaultResources/Images/background2.png")));

    setSceneRect( 0 , 0 ,1200 , 600 );

    qDebug()<<"score is "<<scoreGet<<" birdUsed is "<<birdUsed;

    endScore = new EndScore(scoreGet);
    addItem(endScore);

    birdUsedAmount = new BirdUsedAmount(birdUsed);
    addItem(birdUsedAmount);

    birdPic = new QGraphicsPixmapItem();
    birdPic->setPixmap (QPixmap("./GameData/DefaultResources/Images/BirdImages/redBird.png"));
    birdPic->setPos (40 , 250);
    addItem(birdPic);

    restartButton = new RestartButton();
    addItem(restartButton);

    leaveButton = new LeaveButton();
    addItem(leaveButton);
}
