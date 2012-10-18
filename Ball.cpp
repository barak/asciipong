#include "Ball.h"
#include "aalib.h"
#include "Deflector.h"
#include "Pong.h"
#include "Resource.h"

#include <vector>
using namespace std;

Ball::Ball(aa_context *c, Pong *pong, Point *point, int x_vel, int y_vel) {
    this->context = c;
    this->p = point;
    this->x_vel = x_vel;
    this->y_vel = y_vel;
    this->pong = pong;
}


    void Ball::draw() {
        Resource *resource=Resource::getResource();
        aa_putpixel(context, 
                    this->p->getX(),
                    this->p->getY(), 
                    resource->fetch(ResourceKey::BALL_COLOR));
        
        aa_fastrender(context, 0, 0, aa_scrwidth(context),
                      aa_scrheight(context) );
        aa_flush(context);
   }

   int Ball::tick() {
//        vector<Deflector *>::iterator i;
        int newY, newX;
        newX = this->p->getX() + this->x_vel;
        newY = this->p->getY() + this->y_vel;
        if ( newY <= 0 || newY >= aa_imgheight(context) ) {
            return 1;
        }
        p->setX( newX );
        p->setY( newY );

        vector<Deflector *> vec = pong->getDeflectors();
        
        for( int i = 0 ; i < vec.size(); i++ ) {
                if( vec[i]->collisionTest( *(this->p) ) ) {
                    DirectionVector dv = vec[i]->getDeflectionDirection(*(this->p));
                    
                    this->x_vel = this->x_vel + (2 * dv.x);
                    this->y_vel = this->y_vel + (2 * dv.y);
                    return 0;
                }
        }
      
    return 0; 
   }
