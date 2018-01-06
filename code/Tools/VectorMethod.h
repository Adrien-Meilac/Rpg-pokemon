#ifndef PKMN_VECTORMETHOD_H_INCLUDED
#define PKMN_VECTORMETHOD_H_INCLUDED

#include <vector> // To stock split string
#include <string> // to manipulate strings
#include <sstream> // for split method
#include <iostream> // for print method

#include "Conversion.h"

namespace PKMN
{

std::vector<std::string> string_split(const std::string& line,
                                      const char& delim = ';',
                                      int reserv = -1);
    /** \brief Split a line into a vector
     *
     * \param line const std::string& : phrase to cut
     * \param const char& delim = ';' : separator character for cutting
     * \param reserv int : nb of space to set (improve by 78% performance)
     * \return std::vector<std::string> : vector containing each block separated by the separator
     *
     */

bool vector_in(const std::vector<std::string>& L,
               const std::string& word);
    /** \brief Boolean test : Is the word in L ?
     *
     * \param L const std::vector<std::string>&
     * \param word const std::string& : word to search in the list
     * \return bool : True if word is in L.
     *
     */

std::vector<std::string> vector_insert(std::vector<std::string> L,
                                       const std::string& str,
                                       const unsigned int& pos);
    /** \brief Insert a string in a list of string
     *
     * \param L std::vector<std::string> : not modified by the function
     * \param str const std::string& : word to add
     * \param pos const unsignedint& : position of the insertion
     * \return new list with the insertion
     *
     */

void vector_print(const std::vector<std::string>& L);
    /** \brief print a vector (Ex (1; 2; 3)
     *
     * \param v const std::vector<std::string>& : vector to print
     *
     */

std::string vector_join(const std::vector<std::string>& L,
                        const char& delim = ';');
    /** \brief join a list on a separator character
     *
     * \param L const std::vector<std::string>& : list to join
     * \param const char& delim = ';' : character to add at the end of each cell
     * \return std::string : text contained in the vector L
     *
     */

std::vector<bool> split_string_to_bool(std::string str);
     /** \brief Split a string into a vector of bool
      *
      * \param str std::string : string to cut
      * \return std::vector<bool> : vector of boolean values
      *
      */

}

#endif // PKMN_VECTORMETHOD_H_INCLUDED
