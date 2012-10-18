#ifndef _DEFLECTOR
#define _DEFLECTOR
#include "Bounceable.h"

typedef struct {
        int x;
        int y;
} DirectionVector;

class Deflector : public Drawable {
    public:
        virtual bool collisionTest( Point ) = 0;
        virtual DirectionVector getDeflectionDirection( Point ) = 0 ;

};
#endif

