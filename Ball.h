#ifndef _BALL
#define _BALL

#include "Bounceable.h"
#include "Point.h"
#include "Pong.h"

#include "aalib.h"

class Ball : public Bounceable {
    private:
    aa_context *context;
    Point *p ;
    int x_vel, y_vel;
    Pong *pong;

    public:
    Ball(aa_context *, Pong *, Point *, int , int );
    
    void draw();
    
    int tick();
};

#endif
