#include <QPixmap>
#include "RestartButton.h"

RestartButton::RestartButton()
{
    setPixmap (QPixmap("./GameData/DefaultResources/Images/restart1.png"));
    setPos(800 , 400);

    setAcceptHoverEvents(true);
}

void RestartButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
}

void RestartButton::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    setPixmap (QPixmap("./GameData/DefaultResources/Images/restart2.png"));

}

void RestartButton::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    setPixmap (QPixmap("./GameData/DefaultResources/Images/restart1.png"));
}
