#include <QFont>
#include "BirdUsedAmount.h"

BirdUsedAmount::BirdUsedAmount(int inputAmount)
{
    run = 0;
    usedAmount = inputAmount;
    setPlainText (QString("Birds Used : ") + QString::number (run));

    setDefaultTextColor(Qt::white);
    setFont(QFont("SansSerif" , 60));
    setPos( 100 , 200 );

    addTimer = new QTimer();
    addTimer->start(250);
    connect(addTimer , SIGNAL(timeout()) , this , SLOT(addAmount()) );
}

void BirdUsedAmount::addAmount()
{
    ++run;
    if(run<=usedAmount)
    {
        setPlainText (QString("Birds Used : ") + QString::number (run));
    }
    else
    {
        addTimer->stop();
        return;
    }
}
