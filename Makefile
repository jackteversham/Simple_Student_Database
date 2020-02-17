CC=g++ # the compiler name
CCFLAGS= -std=c++11 #flags passed to compiler
LIBS= -l brain_dead_factorial # the libraries we will reference
#the normal build rules

driver: driver.o
	$(CC) -o driver driver.o --std=c++11

driver.o: driver.cpp
	$(CC) -c -o driver.o driver.cpp $(CCFLAGS)
	$(CC) -c -o database.o database.cpp $(CCFLAGS)
# other rules; no dependency; e.g.  ‘‘make clean’’


clean:
	rm -f *.o
	rm driver
run:
	./driver
