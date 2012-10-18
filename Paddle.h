#ifndef _PADDLE
#define _PADDLE
#include "Deflector.h"
#include "Point.h"
#include "aalib.h"

class Paddle : public Deflector {
    
    private:
    int align;    
        
    public:
	    
    const static int TOP ;
    const static int BOTTOM ;
    
    aa_context *context;
    
    int x1,y1,x2,y2;
    
    Paddle(aa_context *c, int align);
    
    void moveRight() ;

    void moveLeft();
   
    void draw(); 
 
    bool collisionTest( Point p);
   
   
    DirectionVector getDeflectionDirection(Point);
    
};

#endif

