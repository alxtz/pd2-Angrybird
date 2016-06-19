#include <QFont>
#include "EndScore.h"

EndScore::EndScore(int inputScore)
{
    run = 0;
    score = inputScore;
    setPlainText (QString("Points Got : ") + QString::number (run));

    setDefaultTextColor(Qt::white);
    setFont(QFont("SansSerif" , 60));
    setPos( 100 , 100 );

    addTimer = new QTimer();
    addTimer->start(5);
    connect(addTimer , SIGNAL(timeout()) , this , SLOT(addAmount()) );
}

void EndScore::addAmount()
{
    run+=10;
    if(run<=score)
    {
        setPlainText (QString("Points Got : ") + QString::number (run));
    }
    else
    {
        addTimer->stop();
        return;
    }
}
