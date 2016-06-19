#include "LeaveButton.h"

LeaveButton::LeaveButton()
{
    setPixmap (QPixmap("./GameData/DefaultResources/Images/leave1.png"));
    setPos(950 , 400);

    setAcceptHoverEvents(true);
}

void LeaveButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
}

void LeaveButton::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    setPixmap (QPixmap("./GameData/DefaultResources/Images/leave2.png"));
}

void LeaveButton::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    setPixmap (QPixmap("./GameData/DefaultResources/Images/leave1.png"));
}
