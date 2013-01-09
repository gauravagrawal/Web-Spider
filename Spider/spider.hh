#ifndef SPIDER_HPP
#define SPIDER_HPP 

#include "extractor.hh"
#include "fetcher.hh" 
#include "includes.h"

namespace WEB_SPIDER { 

    class Spider { 

	private:
	    SPIDER_WEB web; 

	public:
	    Spider() ; 
	   ~Spider() ;  
	    const SPIDER_WEB&  WeaveWeb(std::string url) ;  
    } ; 

    Spider :: Spider()  { 
    }

    Spider :: ~Spider() { 
	web.clear()     ; 
    }

    const SPIDER_WEB& Spider :: WeaveWeb(std::string url) { 

	SPIDER_WEB :: iterator webIter = web.find(url) ; 
	const std::string filename = "links.txt"       ; 

	if (webIter == web.end()) { 

	    WEB_THREAD tt; 
	    web.insert(std::make_pair(url, tt)) ; 

	    webIter = web.begin() ; 

	    while (webIter != web.end()) { 

		std::cout<<" L : " <<webIter->first<<std::endl;

		Fetcher   *fetcher   = new Fetcher()   ; 
		fetcher->FetchHtml(webIter->first, filename) ;  

		Extractor *extractor = new Extractor() ;  
		webIter->second      = extractor->extractUrls(filename) ; 

		WEB_THREAD :: iterator threadIter = webIter->second.begin() ; 

		while (threadIter != webIter->second.end()) { 

		    std::cout<<"Hello "<<std::endl;
		    SPIDER_WEB :: iterator checkIter = web.find(*threadIter) ; 

		    if (checkIter == web.end()) { 
			WEB_THREAD t ; 
			web.insert(std::make_pair(*threadIter, t)) ; 
		    }

		    threadIter++; 
		}

		delete fetcher   ; 
		delete extractor ;

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
