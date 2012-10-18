#ifndef _POINT
#define _POINT

class Point {
    
    private:
            
    int x, y;
        
    public:
	
    Point(int,int);
    
    int getX() { return x; }
    int getY() { return y; }
    void setX(int x) { this->x=x; }
    void setY(int y) { this->y=y; }
};


#endif

