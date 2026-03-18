# For the start of this project I will be using this make file that was made using gpt 5.4. I am not good at make files and will revisit it, but for now in order to get to programming I will use this.

CC := gcc
CXX := g++

CFLAGS := -Wall -Wextra -g -Iinclude \
	$(shell pkg-config --cflags glfw3)
CXXFLAGS := -std=c++20 -Wall -Wextra -g -Iinclude \
	$(shell pkg-config --cflags glfw3)

LDLIBS := -lvulkan $(shell pkg-config --libs glfw3)

C_SRC := $(shell find src -type f -name '*.c')
CPP_SRC := $(shell find src -type f -name '*.cpp')

C_OBJ := $(patsubst src/%.c,build/%.o,$(C_SRC))
CPP_OBJ := $(patsubst src/%.cpp,build/%.o,$(CPP_SRC))

OBJ := $(C_OBJ) $(CPP_OBJ)
TARGET := build/app

all: $(TARGET)

$(TARGET): $(OBJ)
	@mkdir -p $(dir $@)
	$(CXX) $(OBJ) -o $@ $(LDLIBS)

build/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

build/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf build

run: all
	GLFW_PLATFORM=wayland ./$(TARGET)

.PHONY: all clean run
