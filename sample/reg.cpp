#include <iostream>
#include <string>
#include <boost/regex.hpp>

int main(int argc, char **argv) { 

    std::string s, sre; 
    boost::regex re   ; 

    while(true) { 
    sre = "<a\\s+href=\"([\\-:\\w\\d\\.\\/]+)\">";

	if (sre == "quit") { 
	    break ; 
	}

	std::cout<<"String : " ; 
	std::cin>>s ; 

	try { 
	    re.assign(sre, boost::regex_constants::icase) ; 
	} catch(boost::regex_error& err) { 
	    std::cerr<<sre<<" is not a valid regex " <<err.what()<<std::endl; 
	    continue; 
	}

	std::cout<<" RE " <<re<<std::endl;

	if (boost::regex_match(s, re)) { 
	    std::cout<<re<<" matches " <<s<<std::endl; 
	}
	else { 
	    std::cout<<" false  " <<std::endl; 
	}
    }

    return 0; 
}

