#ifndef BIRDUSEDAMOUNT_H
#define BIRDUSEDAMOUNT_H


#include <QGraphicsTextItem>
#include <QTimer>

class BirdUsedAmount : public QGraphicsTextItem
{
    Q_OBJECT

    public:
        BirdUsedAmount(int inputAmount);

        int usedAmount;
        int run;
        QTimer * addTimer;

    public slots:
        void addAmount();
};

#endif // BIRDUSEDAMOUNT_H
