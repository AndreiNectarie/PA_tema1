# Exemplu de Makefile pentru soluții scrise în C++.

CC = g++
CCFLAGS = -Wall -Wextra -std=c++17 -O0 -lm

.PHONY: build clean

build: p1

# Nu compilați aici, nici măcar ca dependențe de reguli.
run-p1:
	./p1

# Schimbați numele surselor (și, eventual, ale executabilelor - peste tot).
p1: servere.cpp input.cpp helper.cpp
	$(CC) -o $@ $^ $(CCFLAGS)

# Vom șterge executabilele.
clean:
	rm -f p1
