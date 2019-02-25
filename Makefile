export SUBDIR=\
applications \
bird-types \
launcher \
protocols \
services  \
system  \
utilities \

export CXXFLAGS+=-std=c++11 
export BINARY=standalone
export LDFLAGS+=

.PHONY : all clean
all : $(BINARY) 

clean : 
	rm $(BINARY) $(BINARY:%=launcher/%.o)

$(BINARY) : $(BINARY:%=launcher/%.o)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^

$(BINARY:%=launcher/%.o) :
	$(MAKE) -C launcher 


	