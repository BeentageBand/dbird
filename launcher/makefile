OBJ=$(wildcard *.cpp)

all : $(OBJ:.cpp=.o)

%.o : %.cpp
	-$(CXX) -E $(CXXFLAGS) $(SUBDIR:%=-I ../%) -o $@ -c $^
	$(CXX) $(CXXFLAGS) $(SUBDIR:%=-I ../%) -o $@ -c $^