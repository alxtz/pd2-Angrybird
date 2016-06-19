#ifndef COLLISIONLISTENER_H
#define COLLISIONLISTENER_H


#include <QObject>
#include <Box2D/Box2D.h>

class CollisionListener : public QObject , public b2ContactListener
{
    Q_OBJECT

    public:
        CollisionListener();

        void BeginContact (b2Contact * contact);

        void EndContact (b2Contact * contact);

        void PreSolve (b2Contact * contact , const b2Manifold * oldManifold);

        void PostSolve (b2Contact * contact , const b2ContactImpulse * impulse);

    signals:
        void spawnScore(int);
         void killPig();
};

#endif // COLLISIONLISTENER_H
