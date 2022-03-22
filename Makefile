
CC = g++
CFLAGS = -Wall -std=c++11 

HEADERS = -I/usr/include/boost

SRCDIR = src
BINDIR = bin

OBJS = $(BINDIR)/main.o

EXEC = bin/main

$(BINDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

main: $(OBJS)
	$(CC) $(HEADERS) $(CFLAGS) $(OBJS) -o $(EXEC)

.PHONY: clean clean-objs

clean:
	rm $(EXEC)
clean-objs:
	rm $(BINDIR)/*.o
