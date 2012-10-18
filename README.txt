

Circa 2003 or 2004, a couple of friends and I were in San Francisco sitting 
around a linux computer that only had a text console.  We had a bunch of 
beer, and plenty of time to kill.  We installed lynx to read online 
documentation.  We installed aalib (ascii art lib), a graphics library that 
uses ascii characters and ncurses to display the likeness of whatever pixels 
are "plotted."  We passed the keyboard around, and wrote a game of pong.

It's pretty buggy, and none of us were that great with C++.

Today I found the old pong code sitting on my laptop.  I figured I should make
it compile on a modern C++ compiler (needed to add some #include's that
apparently used to be assumed, and an interface in aalib had changed).  This 
is the result.

Requires aalib.  For me that was `sudo apt-get install libaa1 libaa1-dev`.

To play, make and then run the executable 'pong'.  The arrow keys control one
of the paddles, the x and z keys control the other.  'q' to quit.  Once one
player scores, the game exits.  Sometimes the 'ball' fails to bounce off the
walls, because this is buggy.  This was more fun to write than to play.

Some of the constants in Resource.h can be overriden in a .pongrc in the users 
home directory.  Most of the constants seem to be ignored.





