ifeq ($(origin CC),default)
CC  = gcc
endif
ifeq ($(origin CXX),default)
CXX = g++
endif
ifeq ($(PREFIX),)
    PREFIX := /usr/local
endif


all: mines

mines:
ifeq (,$(wildcard ./config.h))
	@echo "Unconfigured program detected! Did you run make configure?"
	@exit 1
endif
	$(CC) mines.c -o mines -Wall -Wextra -lcurses

clean:
	rm -f config.h mines

install:
	install -d $(DESTDIR)$(PREFIX)/bin/
	install -m 755 mines $(DESTDIR)$(PREFIX)/bin/

.PHONY: mines
