#ifndef RESTARTBUTTON_H
#define RESTARTBUTTON_H


#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class RestartButton : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT

    public:
        RestartButton();
        void mousePressEvent( QGraphicsSceneMouseEvent * event );
        void hoverEnterEvent( QGraphicsSceneHoverEvent * event);
        void hoverLeaveEvent( QGraphicsSceneHoverEvent * event);

    signals:
        void clicked();
};


#endif // RESTARTBUTTON_H
