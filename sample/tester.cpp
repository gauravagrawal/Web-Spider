#include<iostream>
#include "spider.hh"
#include <string>

using namespace WEB_SPIDER;

int main(){ 

    Fetcher obj; 
    obj.FetchHtml("http://ww2.cs.fsu.edu/~sahu/", "hello.txt");

    Extractor extract;
    std::list<std::string> urls = extract.extractUrls("hello.txt"); 

    std::cout<<"  A C " <<urls.size()<<std::endl;

    std::list<std::string> :: iterator iter = urls.begin() ; 

    while (iter != urls.end()) { 
	std::cout<<*iter<<std::endl; 
	iter++ ; 
    }	

    return 0;
}
