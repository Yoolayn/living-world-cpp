CXX = g++
CXXFLAGS = -std=c++23 -Wall -Wextra -Werror -pedantic -O2
SRCS = $(wildcard *.cpp)
OBJDIR = build
OBJS = $(SRCS:.cpp=.o)
OBJS := $(addprefix $(OBJDIR)/, $(OBJS))
TARGETDIR = bin
BOOSTDIR = boost
TARGET = $(TARGETDIR)/main

$(TARGET): $(OBJS) | boost
	@mkdir -p $(TARGETDIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

world: $(TARGET)

boost_1_85_0.tar.gz:
	wget https://archives.boost.io/release/1.85.0/source/boost_1_85_0.tar.gz

$(BOOSTDIR)/: boost_1_85_0.tar.gz
	tar xzf ./boost_1_85_0.tar.gz
	@mv boost_1_85_0 $(BOOSTDIR)

boost: boost/

clean:
	rm -f $(OBJS)/*.o $(TARGET)

.PHONY: world clean boost
