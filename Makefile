CC=g++
COMMON= -Wall -Wextra -Wfloat-equal -Wpedantic -Wvla -Werror
DEBUG= -g3
SANITIZE= $(COMMON) -fsanitize=undefined -fsanitize=address $(DEBUG)
VALGRIND= $(COMMON) $(DEBUG)
PRODUCTION= $(COMMON) -O3

all: driver

driver: driver.cpp solution23.h solution23.cpp
	rm -f driver
	$(CC) driver.cpp solution23.cpp -o driver $(SANITIZE) -lm

run: all
	./driver 

clean:
	rm -f driver
