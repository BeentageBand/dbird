OBJ=$(wildcard *.cc)

all : $(OBJ:%.cc=../$(OUTDIR)/%.o)

../$(OUTDIR)/%.o : %.cc
	$(CXX) $(CXXFLAGS) $(SUBDIRS:%=-I ../%) -o $@ -c $^