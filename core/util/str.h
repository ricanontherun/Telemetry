#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> &split(const string &s, char delim, vector<string> &elems) {
   stringstream ss(s);
   string item;

   while ( getline(ss, item, delim) ) {
       elems.push_back(item);
   }

   return elems;
}


/**
 *  Split a string into a vector of elements, off a delimeter.
 *  @s: String to be split.
 *  @delim: Delimeter to split off of.
 */
vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, elems);

    return elems;
}
