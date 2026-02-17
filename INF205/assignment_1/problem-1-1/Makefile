TARGET = program.exe

SRCS = main.cpp check_datatype.cpp verify.cpp
OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	g++ $(OBJS) -o $(TARGET)

%.o: %.cpp task1.h
	g++ $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
