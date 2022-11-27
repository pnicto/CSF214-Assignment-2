CPPFILES  := $(wildcard src/**/*.cpp) $(wildcard src/*.cpp)
CC        = g++
GDB       = gdb
LD        = g++
OBJ      := $(patsubst src/%.cpp,build/%.o,$(CPPFILES))

MAKE_DIR = @mkdir -p $(@D)

CFLAGS = -std=c++20         \
		 -g                 \
		 -Wall              \
		 -Wextra            \
		 -Werror            \
		 -Wconversion       \
		 -pedantic-errors

EXECUTABLE = build/main

.PHONY: clean docs

.DEFAULT_GOAL = $(EXECUTABLE)

all: $(EXECUTABLE) $(CPPFILES)

run: $(EXECUTABLE) $(CPPFILES)
	./$(EXECUTABLE)

debug: $(EXECUTABLE) $(CPPFILES)
	${GDB} $(EXECUTABLE)

build/%.o: src/%.cpp include/%.h
	$(MAKE_DIR)
	$(CC) $(CFLAGS) -c $< -o $@


$(EXECUTABLE): $(OBJ)
	$(LD) $(OBJ) -g -o $@

clean:
	rm -rf $(EXECUTABLE_WIN) $(EXECUTABLE) logs/*

cleaner:
	rm -rf $(EXECUTABLE_WIN) $(EXECUTABLE) $(OBJ) logs/*

valgrind:
	@mkdir -p logs
	valgrind --leak-check=full \
						--show-leak-kinds=all \
						--track-origins=yes \
						--verbose \
						--log-file=logs/valgrind-out.txt \
						$(EXECUTABLE)

docs:
	rm -rf docs
	doxygen Doxyfile