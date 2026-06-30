CC = gcc
FLAG = -Wall -Werror

VERSION = 0_6
TARGET = crs_$(VERSION)

all: $(TARGET)

$(TARGET): ./Build/main.o ./Build/structure.o ./Build/bufferz.o ./Build/wca.o
	$(CC) ./Build/main.o ./Build/structure.o ./Build/bufferz.o ./Build/wca.o -o $(TARGET)

./Build/main.o: ./Source/main.c
	$(CC) $(FLAG) -c ./Source/main.c -o ./Build/main.o

./Build/structure.o: ./Source/structure.c
	$(CC) $(FLAG) -c ./Source/structure.c -o ./Build/structure.o

./Build/bufferz.o: ./Source/bufferz.c
	$(CC) $(FLAG) -c ./Source/bufferz.c -o ./Build/bufferz.o

./Build/wca.o: ./Source/wca.c
	$(CC) $(FLAG) -c ./Source/wca.c -o ./Build/wca.o

clean:
	rm ./Build/*.o
