/**
 *--------------------------------------------------
 * A keyed regular expression abstraction
 *--------------------------------------------------
 *
 * RegexMap<Type> map;
 *
 * map.Set(KEY_OF_TYPE, REGULAR_EXPRESSION);
 *
 * bool result = map.Test(KEY_OF_TYPE, ONE_CONTEXT);
 *
 * result = map.Test(KEY_OF_TYPE, ANOTHER_CONTEXT);
 */

#ifndef REGEX_MAP_H
#define REGEX_MAP_H

#include <regex>
#include <stdexcept>

template <class T>
class RegexMap
{
    public:
        /**
         * Set a key/expression pair.
         *
         * @param key
         * @param regex
         *
         * @return
         */
        RegexMap<T> &Set(T key, std::string regex);

        /**
         * Test an expression stored at key.
         *
         * @param key
         * @param context
         *
         * @throws std::runtime_error
         * @return
         */
        bool Test(T key, std::string context) const;

        /**
         * Check if a key exists.
         *
         * @param key
         *
         * @return
         */
        bool KeyExists(T key) const;

    protected:
        std::map<T, std::regex> map;
};

template <class T>
RegexMap<T> &RegexMap<T>::Set(T key, std::string regex)
{
    this->map[key] = std::regex(regex);

    return *this;
}

template <class T>
bool RegexMap<T>::Test(T key, std::string context) const
{
    if ( !this->KeyExists(key) )
    {
        throw std::runtime_error("RegexMap: The provided key not exist.");
    }

    std::regex expression = this->map.find(key)->second;

    return std::regex_match(
        context,
        expression
    );
}

template <class T>
bool RegexMap<T>::KeyExists(T key) const
{
    return this->map.find(key) != this->map.end();
}

#endif
