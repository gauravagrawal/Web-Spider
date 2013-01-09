#include <iostream>
#include <string>
#include <boost/regex.hpp>
#include <fstream>

using namespace std;
const int BUFSIZE = 10000;

int main(int argc, char** argv) {

    // Safety checks omitted...
    boost::regex re("<a\\s+href=\"([\\-:\\w\\d\\.\\/]+)\">");
    string file(argv[1]);
    char buf[BUFSIZE];
    boost::smatch matches;
    string sbuf;
    string::const_iterator begin, end;
    ifstream in(file.c_str());

    while (!in.eof())
    {
	in.getline(buf, BUFSIZE-1);
	sbuf = buf;
	begin = sbuf.begin();
	end   = sbuf.end() ;  

	while (boost::regex_search(begin, end, matches, re))
	{
	    string url(matches[0].first, matches[0].second);
	    cout << "URL: " << url << endl;
	    // Update the beginning of the range to the character
	    // following the match
	    begin = matches[0].second;
	}
    }
}

