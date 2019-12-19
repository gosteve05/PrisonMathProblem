CC = g++
CFLAGS = -Wall --std=c++11
OBJECTS = prison.o

PRISON: $(OBJECTS) #OBJECTS refers to this
	$(CC) $(CFLAGS) -o PRISON $(OBJECTS)

prison.o: prison.cpp #needs space after colon
	$(CC) $(CFLAGS) -c prison.cpp -o prison.o

clean:
	rm PRISON $(OBJECTS)