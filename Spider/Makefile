CXX = g++
CXXFLAGS = -gstabs -g
BLIB = -lboost_regex
LIBS = -lcurlpp -lcurl 
LINK = /usr/local/lib

all: runner

runner: runspider.cc spider.hh extractor.hh fetcher.hh includes.h 
	$(CXX) $(CXXFLAGS) -I$(BOOST) -o runner runspider.cc -L$(BOOST_LIB) -L$(LINK) $(LIBS) $(BLIB) 

clean: 
	rm -rf runner.dSYM 
	rm runner
