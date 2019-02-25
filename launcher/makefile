OBJ=$(wildcard *.cpp)

all : $(OBJ:%.cpp=../$(OUTDIR)/%.o)

../$(OUTDIR)/%.o : %.cpp
	-$(CXX) -E $(CXXFLAGS) $(SUBDIR:%=-I ../%) -o $@ -c $^
	$(CXX) $(CXXFLAGS) $(SUBDIR:%=-I ../%) -o $@ -c $^