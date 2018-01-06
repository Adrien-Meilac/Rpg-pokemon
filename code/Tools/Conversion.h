#ifndef PKMN_CONVERSION_H_INCLUDED
#define PKMN_CONVERSION_H_INCLUDED

#include <string> // To manipulate string
#include <cmath> // To use pow function
#include <sstream>
#include <iostream>

namespace PKMN
{

template <typename T> std::string NumberToString(T Number);
    /** \brief Convert T type to string, where T is a number type using sstream
     *
     * \param number T
     * \return std::string
     *
     */

template <typename T> T StringToNumber (const std::string &Text);
    /** \brief Convert a string object into a number #deduction
     *
     * \param Text const std::string& : text to convert
     * \return T : number type of the output
     *
     */

bool string_to_bool(const std::string& str);
    /** \brief Convert a string into a boolean variable (Supposing that true = "True" and false = "False")
     *
     * \param str const std::string& : the string variable
     * \return bool
     *
     */

int string_to_int(const std::string& str);
    /** \brief Convert a string into a double variable (Ex : "1234" -> 1234)
     *
     * \param str const std::string& : the string variable
     * \return int (can be negative)
     *
     */

double string_to_double(const std::string& str);
    /** \brief Convert a string into a double variable (Ex : "123.21" -> 123.21)
     *
     * \param str const std::string& : the string variable
     * \return bool
     *
     */

std::string int_to_string(int nb);
    /** \brief Convert an integer to a string
     *
     * \param nb int : number to convert
     * \return std::string : number as a string
     *
     */

unsigned int nb_of_nb(int nb);
    /** \brief Give the number of number of an integer
     *
     * \param nb int : number to count number of number
     * \return unsigned int : number of number
     *
     */

}



#endif // PKMN_CONVERSION_H_INCLUDED
