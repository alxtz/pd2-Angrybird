#ifndef LEAVEBUTTON_H
#define LEAVEBUTTON_H


#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class LeaveButton : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT

    public:
        LeaveButton();
        void mousePressEvent( QGraphicsSceneMouseEvent * event );
        void hoverEnterEvent( QGraphicsSceneHoverEvent * event);
        void hoverLeaveEvent( QGraphicsSceneHoverEvent * event);

    signals:
        void clicked();
};

#endif // LEAVEBUTTON_H
