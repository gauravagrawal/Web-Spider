#ifndef INCLUDES_H
#define INCLUDES_H

#include <iostream>
#include <utility>
#include <fstream>
#include <string>
#include <list> 
#include <map>

namespace WEB_SPIDER { 
    typedef std::list<std::string> 	       WEB_THREAD ; 
    typedef std::map<std::string, WEB_THREAD>  SPIDER_WEB ; 
} ; 

#endif
