CC=gcc
CFLAGS=-std=c89 -g -Wall -pedantic
OBJECTS=src/main.o
TARGET=main


$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) $(CFLAGS) -o $(TARGET)

clean:
	@rm -f $(TARGET) src/*.o
