#ifndef SPIDER_HPP
#define SPIDER_HPP 

#include "extractor.hh"
#include "fetcher.hh" 
#include "includes.h"

namespace WEB_SPIDER { 

    // the real Spider that will make the real web ;-) 
    class Spider { 

	private:
	    SPIDER_WEB web;  // map of each url along with list of all the urls on that page 

	public:
	    Spider() ; 
	   ~Spider() ;  
	    const SPIDER_WEB&  WeaveWeb(std::string url) ;  
    } ; 

    Spider :: Spider()  { }

    Spider :: ~Spider() { 
	web.clear()     ; 
    }

    // Takes the starting url and start weaving the web from 
    // that starting url. 
    // TODO: Do we need a domain specific? if we don't it will crawl forever 
    const SPIDER_WEB& Spider :: WeaveWeb(std::string url) { 

	SPIDER_WEB :: iterator webIter = web.find(url) ;  
	const std::string filename = "links.txt"       ; 

	if (webIter == web.end()) { 

	    WEB_THREAD tt; 
	    web.insert(std::make_pair(url, tt)) ; 

	    webIter = web.begin() ; 

	    int counter = 0 ;

	    while (webIter != web.end()) { 

		std::string findUrl = webIter->first; 
		size_t found = findUrl.find("cs.fsu.edu")     ;
	    	if (found != std::string::npos) { 

		    std::cout<<" L : "<<counter++<<"  "<<webIter->first<<std::endl;

		    Fetcher   *fetcher   = new Fetcher()   ; 
		    fetcher->FetchHtml(webIter->first, filename) ;  

		    Extractor *extractor = new Extractor() ;  
		    webIter->second      = extractor->extractUrls(filename) ; 

		    WEB_THREAD :: iterator threadIter = webIter->second.begin() ; 

		    while (threadIter != webIter->second.end()) { 

			SPIDER_WEB :: iterator checkIter = web.find(*threadIter) ; 

			if (checkIter == web.end()) { 
			    WEB_THREAD t ; 
			    web.insert(std::make_pair(*threadIter, t)) ; 
			}

			threadIter++; 
		    }

		    delete fetcher   ; 
		    delete extractor ;
		}

		webIter++; 
	    }	
	}

	else { 
	    throw ; 
	}
	return web ;
    }
} ; 

#endif
