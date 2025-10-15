CC = gcc
CFLAGS = -Wall -Wextra -O2 -Iinclude
GAME_NAME = fightsim 

SRC_DIR = src
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:.c=.o)

TARGET = $(GAME_NAME)
all: $(TARGET)

# ugh i hate writing makefiles

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

run: all
	./$(TARGET)
