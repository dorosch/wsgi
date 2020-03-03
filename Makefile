CC=gcc
INCLUDE=-I src/include -I /usr/include/python3.8 -lpython3.8 -lm -export-dynamic
CFLAGS=-std=c99 -g -Wall -pedantic $(INCLUDE)
OBJECTS=src/app.o src/args.o src/main.o
TARGET=main


$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) $(CFLAGS) -o $(TARGET)
clean:
	@rm -f $(TARGET) src/*.o
