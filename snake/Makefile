ifeq ($(origin CC),default)
CC  = gcc
endif
ifeq ($(origin CXX),default)
CXX = g++
endif
ifeq ($(PREFIX),)
    PREFIX := /usr/local
endif

all: snake

snake:
ifeq (,$(wildcard ./config.h))
	@echo "Unconfigured program detected! Did you run make configure?"
	@exit 1
endif
	$(CC) snake.c -o snake -Wall -Wextra -lcurses

clean:
	rm -f config.h snake

install:
	install -d $(DESTDIR)$(PREFIX)/bin/
	install -m 755 snake $(DESTDIR)$(PREFIX)/bin/

.PHONY: snake
