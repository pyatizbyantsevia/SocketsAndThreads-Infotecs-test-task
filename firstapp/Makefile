OBJS	= main.o task.o utils.o
SOURCE	= main.cpp task.cpp utils.cpp
HEADER	= task.hpp utils.hpp
OUT	= app
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp

task.o: task.cpp
	$(CC) $(FLAGS) task.cpp

utils.o: utils.cpp
	$(CC) $(FLAGS) utils.cpp


clean:
	rm -f $(OBJS) $(OUT)
