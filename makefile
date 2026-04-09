CXX = g++
CXXFLAGS = -std=c++20 -Wall -I./lib/SFML/include
LDFLAGS = -L./lib/SFML/lib -Wl,-rpath,'$$ORIGIN/lib/SFML/lib'

LIBS = -lsfml-graphics -lsfml-window -lsfml-system
TARGET = wolfram

SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS) $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean run