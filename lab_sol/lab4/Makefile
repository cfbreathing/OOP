CC = g++
SRC = src
OBJS = $(SRC)/book.cpp $(SRC)/diary.cpp

all:
	g++ $(SRC)/pdadd.cpp $(OBJS) -o pdadd.exe
	g++ $(SRC)/pdlist.cpp $(OBJS) -o pdlist.exe
	g++ $(SRC)/pdshow.cpp $(OBJS) -o pdshow.exe
	g++ $(SRC)/pdremove.cpp $(OBJS) -o pdremove.exe
	
clean:
	rm pdadd
	rm pdlist
	rm pdshow
	rm pdremove