ifeq ($(origin CC),default)
CC  = gcc
endif
ifeq ($(origin CXX),default)
CXX = g++
endif

all: configure mines snake

configure:
	$(CXX) configure.cpp -o configure -Wall -Wextra
	./configure

mines:
	@$(MAKE) -C mines

snake:
	@$(MAKE) -C snake

clean:
	rm -f configure
	@$(MAKE) -C mines clean
	@$(MAKE) -C snake clean

install:
	@$(MAKE) -C mines install
	@$(MAKE) -C snake install

.PHONY: configure mines snake clean install
