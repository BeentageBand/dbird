OBJ=$(wildcard *.cc)

all : $(OBJ:%.cc=../$(OUTDIR)/%.o)

../$(OUTDIR)/%.o : %.cc
	-$(CXX) -E $(CXXFLAGS) $(SR:%=-I ../%) -o $@ -c $^
	$(CXX) $(CXXFLAGS) $(SUBDIRS:%=-I ../%) -o $@ -c $^