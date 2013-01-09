#ifndef FETCHER_HPP
#define FETCHER_HPP 

#include <curlpp/curlpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <fstream>
#include <iostream>

namespace WEB_SPIDER { 
    class Fetcher { 

	public:
	    void FetchHtml(std::string url, std::string filename) ; 
    } ; 

    void Fetcher :: FetchHtml(std::string url, std::string filename) { 
	try { 
	    curlpp::Cleanup myCleanup; 

	    std::ofstream outfile (filename.c_str())   ;

	    outfile<<curlpp::options::Url(url) ; 

	    outfile.close();
	}
	catch(curlpp::RuntimeError &e) {
	    std::cerr << e.what() << std::endl;  
	}

	catch(curlpp::LogicError &e) { 
	    std::cerr << e.what() << std::endl; 
	} 
    }
} ; 

#endif
