CC = g++
CFLAGS = -g -Wall -std=c++20
# OBJS = main.o buildTree.o traversals.o
TARGET = P0

# Rule to build the target
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)