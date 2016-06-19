#ifndef STICK_VTL_H
#define STICK_VTL_H


#include <QObject>
#include "../AbsClasses/GameItem.h"

class Stick_Vtl : public GameItem
{
    Q_OBJECT

    public:
        Stick_Vtl(b2World * inputWorld , int inputX , int inputY);

    public slots:
        void updatePos ();
};


#endif // STICK_VTL_H
