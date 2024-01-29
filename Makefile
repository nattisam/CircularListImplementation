CWFLAGS=-Wall -Wextra

all: cList

cList.o: cList.cpp cList.h
	g++ $(CWFLAGS) -O2 -c cList.cpp

cListMain.o: cListMain.cpp cList.h
	g++ $(CWFLAGS) -O2 -c cListMain.cpp
	
cList: cListMain.o cList.o
	g++ $(CWFLAGS) -O2 cListMain.o cList.o -o cList

clean:
	rm -f *.o cList
