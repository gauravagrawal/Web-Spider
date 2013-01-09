#ifndef EXTRACTOR_HPP
#define EXTRACTOR_HPP

#include "includes.h"
#include<boost/regex.hpp>

namespace WEB_SPIDER { 

    // Extract URLs from the file 
    class Extractor { 

	private: 
	    std::string  	   expression ; // regular expression used to match urls 
	    boost::regex 	   matcher    ; // boost regex wrapper
	    boost::smatch 	   matches    ; // boost matcher from string
	    WEB_THREAD             urls       ; // list of all the urls from a file 

	    enum { 
		URL = 1
	    } ; 

	public:
	    Extractor() : 
	       expression("<a\\s+href=\"([\\-:\\w\\d\\.\\/]+)")
	       {
		   this->matcher.assign(this->expression, boost::regex_constants::icase) ; 
	       }

	    ~Extractor() { 
		urls.clear() ; 
	    }

	    const WEB_THREAD& extractUrls(std::string filename) ; 	    
    } ; 


    // Get the list of all URLs from the file 
    // TODO: Construct the urls. For ex . index.html from a page should have proper
    // http url prefixed to it 
    const WEB_THREAD& Extractor :: extractUrls(std::string filename) { 

	if (!filename.empty()) { 

	    std::ifstream htmlFile(filename.c_str()); 

	    if (!htmlFile.is_open()) { 
		throw std::runtime_error(std::string("Error: Could not read " + filename)) ; 
	    }

	    std::string::const_iterator begin, end ; 

	    while (!htmlFile.eof()) { 

		std::string line        ;
		getline(htmlFile, line) ; 

		begin = line.begin()    ; 
		end   = line.end()      ;  

		while(boost::regex_search(begin, end, this->matches, this->matcher)) { 

		    std::string url(this->matches[URL].first, this->matches[URL].second) ; 
		    this->urls.push_back(url) 	  	; 
		    begin = this->matches[URL].second ; 
		}
	    }
	}

	else { 
	    throw std::invalid_argument(std::string("Error: Invalid file name")) ; 
	}
	return this->urls; 
    }
} ; 

#endif
