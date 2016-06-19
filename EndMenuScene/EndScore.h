#ifndef ENDSCORE_H
#define ENDSCORE_H


#include <QGraphicsTextItem>
#include <QTimer>

class EndScore : public QGraphicsTextItem
{
    Q_OBJECT

    public:
        EndScore(int inputScore);

        int score;
        int run;
        QTimer * addTimer;

    public slots:
        void addAmount();
};

#endif // ENDSCORE_H
