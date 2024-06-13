CXX = clang++
CXXFLAGS = -std=c++23 -Wall -Wextra -Werror -pedantic -Wno-writable-strings
BUILD ?= debug
MAKEFLAGS := --jobs=$(shell nproc)

ifeq ($(BUILD), debug)
	CXXFLAGS += -g -O0 -DDEBUG
else
	CXXFLAGS += -O2
endif

SRCS = $(wildcard *.cpp)
OBJDIR = build
OBJS = $(SRCS:.cpp=.o)
OBJS := $(addprefix $(OBJDIR)/, $(OBJS))
TARGETDIR = bin
TARGET = $(TARGETDIR)/main

$(TARGET): $(OBJS)
	@mkdir -p $(TARGETDIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

all: $(TARGET)

clean:
	rm -f $(OBJS)/*.o $(TARGET)

.PHONY: all clean
