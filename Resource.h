#ifndef _RESOURCE
#define _RESOURCE

#include <map>
#include <fstream>
#include <cstring>
#include <cstdlib>


using namespace std;



class ResourceKey {
    string key;
    int defaultVal;
    public:
    ResourceKey(string key, int defaultValue);
    string getKey();
    
    int getDefault();

    static const ResourceKey BALL_COLOR;
    static const ResourceKey WALL_COLOR;
    static const ResourceKey BG_COLOR;
    static const ResourceKey LATENCY;
    static const ResourceKey SCREEN_WIDTH;
    static const ResourceKey SCREEN_HEIGHT;
    static const ResourceKey PADDLE_COLOR;
    static const ResourceKey PADDLE_1;
    static const ResourceKey PADDLE_2;
    static const ResourceKey PADDLE_3;
    static const ResourceKey PADDLE_4;
    static const ResourceKey BALL_COUNT;
    static const ResourceKey DEBUG;
   
};

struct resComp {
    bool operator()(const char * key1,
                    const char * key2) const {
        return strcmp(key1, key2) < 0;
    }  
};

typedef map<string, int /*, resComp*/> stringIntMap;

class Resource {
    private:
        stringIntMap resourceMap;
        Resource ();
        static Resource r;

    public:
        
        static Resource *getResource();
        
        void ResourceRead (string filename);
        
        int fetch (ResourceKey k);
       
}; 
#endif


