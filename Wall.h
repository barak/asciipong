#ifndef _WALL
#define _WALL
#include "Deflector.h"
#include "aalib.h"

class Wall : public Deflector {

    private:
        int x1,y1, x2,y2;
        aa_context *context;
    public:

    Wall(aa_context *, int,int,int,int);
    void draw();    
    bool collisionTest(Point) ;
    DirectionVector getDeflectionDirection(Point) ;
};
#endif

