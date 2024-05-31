CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -Werror -pedantic -O2
SRCS = $(wildcard *.cpp)
OBJDIR = build
OBJS = $(SRCS:.cpp=.o)
OBJS := $(addprefix $(OBJDIR)/, $(OBJS))
TARGETDIR = bin
BOOSTDIR = boost
TARGET = $(TARGETDIR)/main
TEST = $(TARGETDIR)/test

$(TARGET): $(OBJS) | boost
	@mkdir -p $(TARGETDIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

world: $(TARGET)

polygon: $(TEST)

$(TEST):
	$(CXX) $(CXXFLAGS) -o $@ test.cpp

boost_1_85_0.tar.gz:
	wget https://archives.boost.io/release/1.85.0/source/boost_1_85_0.tar.gz

boost/: boost_1_85_0.tar.gz
	tar xzf ./boost_1_85_0.tar.gz
	@mv boost_1_85_0 $(BOOSTDIR)

boost: boost/

clean:
	rm -f $(OBJS)/*.o $(TARGET)

.PHONY: world clean boost
