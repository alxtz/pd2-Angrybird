#ifndef ENDMENUSCENE_H
#define ENDMENUSCENE_H


#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include "./EndScore.h"
#include "./BirdUsedAmount.h"
#include "./RestartButton.h"
#include "./LeaveButton.h"

class EndMenuScene : public QGraphicsScene
{
    public:
        EndMenuScene(int scoreGet , int birdUsed);
        //if you didn't kill all the pigs , it's just fail
        RestartButton * restartButton;
        LeaveButton * leaveButton;


    private:
        EndScore * endScore;
        BirdUsedAmount * birdUsedAmount;
        QGraphicsPixmapItem  * birdPic;
};


#endif // ENDMENUSCENE_H
