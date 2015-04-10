OBJS = Ball.o Paddle.o Point.o Pong.o Resource.o Wall.o

LOADLIBES += -laa
LDFLAGS += -g
CXXFLAGS += -g
CXXFLAGS += -Wall
CXXFLAGS += -Wextra

Pong: CC=${CXX}
Pong: $(OBJS)

clean:
	rm -f $(OBJS) pong
