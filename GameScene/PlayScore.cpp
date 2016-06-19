#include <QFont>
#include "PlayScore.h"

PlayScore::PlayScore()
{
    score = 0;
    setPlainText (QString::number (score));

    setDefaultTextColor(Qt::white);
    setFont(QFont("SansSerif" , 60));
    setPos(900 , 5 );
}

void PlayScore::addScore(int amount)
{
    score+=amount;
    setPlainText(QString::number(score));
}
