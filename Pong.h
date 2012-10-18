#ifndef _PONG
#define _PONG

#include "aalib.h"
#include "Deflector.h"
#include "Drawable.h"
#include "Resource.h"

#include <vector>
using namespace std;

class Pong {

        vector<Deflector *> deflectors;
        vector<Drawable *> drawables;
        aa_context *context;
        Resource *resource;
    public:
        aa_context *getContext(); 
        void initialize();
        vector<Deflector *> getDeflectors();

        int run();

};

#endif


