#ifndef CORE_UTIL_STR_H
#define CORE_UTIL_STR_H

#include <string>
#include <vector>
#include <sstream>

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
   std::stringstream ss(s);
   std::string item;

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
std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);

    return elems;
}

#endif
