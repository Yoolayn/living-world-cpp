CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -Werror -pedantic -O2
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
