export CXX=gcc
export CPP=g++
export TEST_DEPS=gmock_main gtest gmock
export DEPS=jsoncpp
export LDFLAGS=$(shell pkg-config --libs --static $(DEPS))
export TEST_LDFLAGS=$(shell pkg-config --libs --static $(TEST_DEPS))
export CXXFLAGS=-std=gnu++11 $(shell pkg-config --cflags $(DEPS) $(TEST_DEPS)) 
export OUT=out
export BINARY=standalone slave master
export TEST=\
connection-http \
connection-manager-app \
connection-sip \
data-access-persistency \
push-data-app \
read-data-app \
data-reader-sip \

export SUBDIRS=. \
applications \
bird-types \
launcher \
persistency \
protocols \
services  \
system  \
utilities \

ifndef test
test=dummy-test
endif

.PHONY: all clean binary test single-test 

all : binary test  

binary : $(OUT) $(BINARY:%=$(OUT)/%) 

test : $(OUT) $(OUT)/unit-test 
	./$(OUT)/unit-test

single-test : $(OUT) $(OUT)/$(test)
	./$(OUT)/$(test)

clean :
	rm -rf out

$(OUT) :
	mkdir -p $@

$(TEST:%=$(OUT)/%.o) : tst 
	make -C $<

$(BINARY:%=$(OUT)/%) : $(BINARY:%=$(OUT)/%.o) 
	$(CXX) $(CXXFLAGS) $(SUBDIRS:%=-I %) -o $@ -c $< $(LDFLAFS) 

$(BINARY:%=$(OUT)/%.o) : launcher
	make -C $<

$(OUT)/$(test).o : tst/$(test).cc
	$(CXX) $(CXXFLAGS) $(SUBDIRS:%=-I %) -o $@ -c $<

$(OUT)/unit-test : $(TEST:%=$(OUT)/%.o)
	$(CPP) $(CXXFLAGS) $(SUBDIRS:%=-I %) -o $@ $^ $(LDFLAGS) $(TEST_LDFLAGS) 
$(OUT)/$(test) : $(OUT)/$(test).o
	$(CPP) $(CXXFLAGS) $(SUBDIRS:%=-I %) -o $@ $^ $(LDFLAGS) $(TEST_LDFLAGS) 
	
