CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

TARGET = program.exe

SRCS = main.cpp check_datatype.cpp verify.cpp
OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp datatype.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
