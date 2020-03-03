CC=gcc
INCLUDE=-I src/include
CFLAGS=-std=c89 -g -Wall -pedantic $(INCLUDE)
OBJECTS=src/args.o src/main.o
TARGET=main


$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) $(CFLAGS) -o $(TARGET)
clean:
	@rm -f $(TARGET) src/*.o
