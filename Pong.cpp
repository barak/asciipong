#include "aalib.h"
#include "Point.h"
#include "Bounceable.h"
#include "Deflector.h"
#include "Ball.h"
#include "Paddle.h"
#include "Pong.h"
#include "Wall.h"
#include "Resource.h"

#include <unistd.h>
#include <cstdio>
#include <cstdlib>

using namespace std;

/*
 struct aa_renderparams {
 int bright, contrast;
 float gamma;
 int dither;
 int inversion;
 int randomval;
  };
 */

aa_context *Pong::getContext() {
    return this->context;
}

void clearScreen(aa_context *context) {
    int i,j;
    for( i = 4; i< aa_imgwidth(context)-5; i++ ) {
        for( j = 0 ; j < aa_imgheight(context); j++ ) {
            aa_putpixel(context, i, j, 0);
        }
    }
    aa_fastrender(context, 0, 0, aa_imgwidth(context), 
                  aa_imgheight(context) );
    aa_flush(context);
}


vector<Deflector *> Pong::getDeflectors() {
    return this->deflectors;
}

void Pong::initialize() {
    
  context = aa_autoinit(&aa_defparams);

  if(context == NULL) {
     fprintf(stderr,"Cannot initialize AA-lib. Sorry\n");
     return;
  }

   this->resource = Resource::getResource();
   //resource->ResourceRead("/home/brian/.pongrc");
}

int Pong::run() {
  int key_input;


  struct aa_renderparams params = { 1000, 1000, 0.0, AA_NONE, 1, 0 };
//  struct aa_renderparams params  = {10000, 10000, 0.0, 0, 1, 0}; 
   aa_autoinitkbd(context, 0);
    aa_hidecursor(context);
    
    Paddle paddle(context, Paddle::TOP);
     
    Paddle paddle2(context, Paddle::BOTTOM);


    Wall wall1(context,2,0,6,aa_imgheight(context));
    Wall wall2(context,
               aa_imgwidth(context) - 6,
               0,
               aa_imgwidth(context) - 2,
               aa_imgheight(context));
    
    deflectors.push_back(&paddle);
    deflectors.push_back(&paddle2);
    deflectors.push_back(&wall1);
    deflectors.push_back(&wall2);

    Point p(aa_imgwidth(context) / 2, aa_imgheight(context) / 2);
    Ball ball( context, this, &p, 0,3);
    
    for( int i = 0 ; i< deflectors.size() ; i ++ ) {
        drawables.push_back(deflectors[i]);
    }
    
    int ticked = 0;
    drawables.push_back(&ball);
    
    long sleepTime = this->resource->fetch(ResourceKey::LATENCY);
    
    while ( true ) {
        
        usleep(sleepTime);
        clearScreen(context);
        
        if( ticked > 3 ) {
            if ( ball.tick() != 0 ) {
                sleep(2);
                return 0;
            }
            ticked = 0;
        }
        
        ticked ++;
        
        for( int i = 0 ; i < drawables.size() ; i ++ ) {
            drawables[i]->draw();
    	}
        key_input = AA_NONE;
        int next;
	    while( (next = aa_getevent(context, 0)) != AA_NONE ) {
            key_input = next;
        }
    	switch (key_input) {
            case AA_RIGHT:
		    	paddle.moveRight();
			    break;
    		case AA_LEFT:
	    		paddle.moveLeft();
		    	break;
	        case 'z':
			    paddle2.moveLeft();
    			break;
	    	case 'x':
		    	paddle2.moveRight();
			    break;
    		case 'q':
	    		aa_close(context);
		    	return 0;
			    break;
    		default:
	    		break;
    	}
    }
    
    aa_close(context);

    return 0;
}


int main (int argc, char **argv)
{
    if(!aa_parseoptions(NULL, NULL, &argc, argv) || argc!=1) {
        printf("Usage: %s [options]\n"
               "Options:\n"
               "%s", argv[0], aa_help);
        exit(1);
    }
    Pong p;
    p.initialize();
    return p.run();
}



