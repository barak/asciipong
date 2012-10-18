#include <stdio.h>
#include "Deflector.h"
#include "Wall.h"
#include "aalib.h"

    Wall::Wall(aa_context *c, int x,int y, int xx, int yy) {
        this->context = c;
        this->x1=x;
        this->y1=y;
        this->x2=xx;
        this->y2=yy;
    }

    bool Wall::collisionTest(Point p) {
        return ( x1 <= p.getX() && p.getX() <= x2 &&
            y1 <= p.getY() && p.getY() <= y2);
            
    }


    DirectionVector Wall::getDeflectionDirection(Point p) {
        DirectionVector vec;
        
        
        if( x1 < 20 ) {
            vec.x=2;
            vec.y=0;
        } else {
            vec.x=-2;
            vec.y=0;
        }
        return vec;
            
    }

    void Wall::draw() {
        int i, j;
        for( i = x1; i< x2; i++ ) {
            for( j = y1; j< y2 ; j++ ) {
                aa_putpixel(context, i, j, 108);
            }
        }
        aa_fastrender(context, 0, 0, aa_scrwidth(context),
        aa_scrheight(context) );
        aa_flush(context);
    }



