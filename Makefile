CC = gcc
CFLAGS_RELEASE = -Wall -Wextra -O2 -Iinclude
CFLAGS_DEBUG   = -Wall -Wextra -O1 -g -fsanitize=address -Iinclude

GAME_NAME = fightsim

SRC_DIRS = src data
SRCS = $(wildcard $(addsuffix /*.c, $(SRC_DIRS)))
OBJS = $(SRCS:.c=.o)

TARGET = $(GAME_NAME)

all: release

release: CFLAGS = $(CFLAGS_RELEASE)
release: $(TARGET)

debug: CFLAGS = $(CFLAGS_DEBUG)
debug: clean $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET) -lraylib -lm

clean:
	rm -f $(OBJS) $(TARGET)

run: all
	./$(TARGET)
