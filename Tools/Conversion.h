#ifndef PKMN_CONVERSION_H_INCLUDED
#define PKMN_CONVERSION_H_INCLUDED

#include <string> // To manipulate string
#include <cmath> // To use pow function

namespace PKMN
{

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

}



#endif // PKMN_CONVERSION_H_INCLUDED
