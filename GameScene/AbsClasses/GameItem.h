#ifndef GAMEITEM_H
#define GAMEITEM_H


#include <string>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <Box2D/Box2D.h>
#include "ItemData.h"

using namespace std;

class GameItem : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT

    public:
        GameItem();

        string objectType;
        ItemData * itemData;
        b2Body * physicBody;
        b2World * inWorld;
        b2BodyDef * bodyStruct;
        b2FixtureDef * bodyFixture;

        static float PixToMeter_x(float Pix);
        static float MeterToPix_x(float Meter);

        static float PixToMeter_y(float Pix);
        static float MeterToPix_y(float Meter);

        static float RadToDeg(float Rad);
        static float DegToRad(float Deg);

        int health;

    public slots:
        virtual void updatePos();

    protected:


        
        void addPhysics();
};

#endif // GAMEITEM_H
