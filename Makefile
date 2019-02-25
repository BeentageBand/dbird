export OUTDIR=out
export SUBDIR=\
applications \
bird-types \
launcher \
persistency \
protocols \
services  \
system  \
utilities \

export CXXFLAGS+=-std=c++11 
export BINARY=standalone slave master
export LDFLAGS+=

.PHONY : all clean $(BINARY) 
all : $(BINARY) 

$(BINARY) : $(BINARY:%=$(OUTDIR)/%)

clean : 
	rm $(BINARY:%=$(OUTDIR)/%.o) $(BINARY:%=$(OUTDIR)/%)

$(OUTDIR)/% : $(OUTDIR)/%.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $<

$(BINARY:%=$(OUTDIR)/%.o) :
	$(MAKE) -C launcher 


	