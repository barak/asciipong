#include "Resource.h"

#include <map>
#include <fstream>
#include <string>
#include <sstream>
#include <iterator>
#include <pwd.h>

using namespace std;

#define RC_KEY_DEF(name,default_value)  \
const ResourceKey ResourceKey::name = ResourceKey(#name, default_value) \

ResourceKey::ResourceKey(string key, int defaultValue) {
    this->key=key;
    this->defaultVal = defaultValue;
};

string ResourceKey::getKey(){ return key; }
int ResourceKey::getDefault() { return defaultVal; }


RC_KEY_DEF(BALL_COLOR,108);
RC_KEY_DEF(WALL_COLOR,108);
RC_KEY_DEF(BG_COLOR,108);
RC_KEY_DEF(LATENCY,25000);
RC_KEY_DEF(SCREEN_WIDTH,30);
RC_KEY_DEF(SCREEN_HEIGHT,60);
RC_KEY_DEF(PADDLE_COLOR,108);
RC_KEY_DEF(PADDLE_1,108);
RC_KEY_DEF(PADDLE_2,108);
RC_KEY_DEF(PADDLE_3,108);
RC_KEY_DEF(PADDLE_4,108);
RC_KEY_DEF(BALL_COUNT,1);
RC_KEY_DEF(DEBUG,0);


Resource::Resource() {
    struct passwd *pw = getpwuid(getuid());
    const char *homedir = pw->pw_dir;
    this->ResourceRead( (string(homedir) + string("/.pongrc")).c_str() );
}

Resource Resource::r = Resource();

Resource *Resource::getResource() { 
    return &r; 
}

void Resource::ResourceRead (string filename) {

    ifstream file(filename.c_str());

    if( ! file ) {
        printf("No configuration file at %s\n", filename.c_str());
        return;
    }

    string line;
    while(!file.eof()) {
        std::getline(file,line);
        if( line.size() == 0 || line[0] == '#' ) {
            continue;
        }
        istringstream strStrm(line);
        string key(""), value("");
                
        if( std::getline(strStrm, key,'=') && key.size() > 0 ) {
            if( std::getline(strStrm,value) && value.size() > 0 ) {
                printf("overriding %s with value %d\n",key.c_str(),atoi(value.c_str()));
                this->resourceMap[key]=atoi(value.c_str());
            } 
        }
    }
}


int Resource::fetch (ResourceKey k) {

    stringIntMap::iterator it = this->resourceMap.find(k.getKey());
    if( it == this->resourceMap.end() ) {
        return k.getDefault();
    }
    return it->second;
}

/*
//just some quick testing
int main() {
   Resource *r= Resource::getResource();
   r->ResourceRead("/home/brian/.pongrc");
   int foo = r->fetch(ResourceKey::BALL_COLOR);
   printf("%d\n%d\n",foo,r->fetch(ResourceKey::WALL_COLOR));
}
*/


