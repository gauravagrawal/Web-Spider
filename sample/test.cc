#include<iostream>
#include<string> 
#include "extractor.hh"
#include "fetcher.hh"

using namespace WEB_SPIDER;

int main(int argc, char **argv) { 

//    Fetcher fetcher; 
//    fetcher.FetchHtml("http://ww2.cs.fsu.edu/~sahu/","test.txt"); 
    

    WEB_SPIDER::Extractor *extractor = new Extractor() 	 	     ;  
    std::list<std::string> urls   = extractor->extractUrls("test.txt") ;

    std::list<std::string>::iterator iter = urls.begin(); 

    while (iter != urls.end()) { 
	std::cout<<*iter<<std::endl; 
	iter++ ; 
    }	

    return 0 ; 
}
