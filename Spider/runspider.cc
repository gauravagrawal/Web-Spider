#include "includes.h"
#include "spider.hh"

int main(int argc, char **argv) { 

    WEB_SPIDER::Spider spider; 
    
    WEB_SPIDER::SPIDER_WEB web = spider.WeaveWeb("http://www.cs.fsu.edu/"); 

    WEB_SPIDER::SPIDER_WEB :: iterator webIter = web.begin() ; 

    while (webIter != web.end()) { 
	std::cout<<"Links: "<<webIter->first<<std::endl;
	webIter++ ; 
    }

    return 0 ; 
}
