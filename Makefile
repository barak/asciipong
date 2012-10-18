OBJS := Ball.o Paddle.o Point.o Pong.o Resource.o Wall.o

LD_FLAGS += -laa 
ADDED_CFLAGS += -g

%.o: %.cpp
	$(CXX) -c $? -o $@ $(ADDED_CFLAGS)

pong: $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LD_FLAGS)


clean:
	rm -f *.o pong
