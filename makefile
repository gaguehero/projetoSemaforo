#Makefile for building demo applications.
#by Gabriel Guerrero

TARGETS = threads

CC_C = $(CROSS_TOOL)gcc
CFLAGS = -Wall -g -std=c99 -Werror -pthread

all:clean $(TARGETS)
$(TARGETS):
	$(CC_C) $(CFLAGS) $@.c -o $@

clean:
	rm -f $(TARGETS)