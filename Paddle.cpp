#include <stdio.h>

#include "Paddle.h"
#include "aalib.h"
#include "Ball.h"
#include "Resource.h"

    const int Paddle::TOP = 1;
    const int Paddle::BOTTOM = 2;

	    
    Paddle::Paddle(aa_context *c, int align) {
        context = c;
        this->align=align;
        x1 = aa_imgwidth(context) / 2 - 6;
        x2 = x1 + 12;
        if( align == TOP ) {
            y1 = 2;
        } else {
            y1 = aa_imgheight(context) - 5;
        }
        y2 = y1 + 3;
    }
    void Paddle::moveRight() {
        if( x2 == aa_imgwidth(context) ) {
            return;
        }
        x1+=3;
        x2+=3;
    }

    void Paddle::moveLeft() {
        if( x1 == 0 ) {
            return;
        }
        x1-=3;
        x2-=3;
    }

    void Paddle::draw() {
        Resource *resource=Resource::getResource();
        for(int i = x1; i< x2; i++ ) {
            for(int j = y1; j< y2 ; j++ ) {
                aa_putpixel(context, 
                            i, j,
                            resource->fetch(ResourceKey::PADDLE_COLOR));
            }
        }
        aa_fastrender(context, 0, 0, aa_scrwidth(context),
                      aa_scrheight(context) );
        aa_flush(context);            
    }
    
    bool Paddle::collisionTest( Point p ) {
        return (x1 <= p.getX() && p.getX() <= x2) &&
               (y1 <= p.getY() && p.getY() <= y2);
    }
    
    DirectionVector Paddle::getDeflectionDirection( Point p ) {
        DirectionVector v;
        if( this->align==TOP ) {
            v.x= (-(x2 - p.getX() - 6)) / 3 ;
            v.y= 3; 
        } else {
            v.x = (-(x2 - p.getX() - 6 )) / 3 ;
            v.y = -3; 
        }
        return v;
    }
    


