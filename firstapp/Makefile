OBJS	= main.o task.o
SOURCE	= main.cpp task.cpp
HEADER	= task.hpp
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


clean:
	rm -f $(OBJS) $(OUT)
