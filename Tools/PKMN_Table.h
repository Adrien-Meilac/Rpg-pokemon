#ifndef PKMN_TABLEPARSER_H_INCLUDED
#define PKMN_TABLEPARSER_H_INCLUDED

#include <string>
#include "PKMN_Tuple.h"
#include <vector>
#include <map>
#include <fstream>

/** \brief Get the keys of a map dictionary a tu vois quelquechose ? 
 *
 * \param T = type of keys
 * \param  T2 = type of values
 * \return  std::vector<T> = returns list of keys
 *
 */
template<class T, class T2> std::vector<T> map_keys(std::map<T,T2> dictionary);


/** \brief Returns a map with the first word of the line as a key and the rest of the line in a vector as a value, words being separated by char sep.
 *
 * \param line std::string = sentence to cut
 * \param const char sep = ';' = split character
 * \return std::map<std::string, std::vector<std::string>> dictionary [ first value ] = list of the remaining line splitted
 *
 */
std::map<std::string, std::vector<std::string> > splitLine(std::string line, const char sep = ';');

/** \brief Extract a table from a file path, allow data to be accessed by column name and row name
 */

class PKMN_Table
{
public:

    PKMN_Table();
    PKMN_Table(std::string FilePath);

    //std::vector<unsigned int> getDimension();
    //void transpose();
//    std::vector<std::string> getLineValues(std::string nameLine);
//    std::vector<std::string> getColumnValues(std::string nomColumn);
//    std::vector<std::string> getLineNames(std::string nameLine);
//    std::vector<std::string> getColumnNames(std::string nomColumn);
    std::string getValue(std::string nameLine, std::string nameColumn);
    virtual ~PKMN_Table();

private:

    std::vector<std::string> m_headerColumn; /* Name of column, directly accessible without searching them in keys */
    std::vector<std::string> m_headerLine; /* Give name of line, directly accessible without searching them */
    std::map<PKMN_Tuple<std::string>, std::string>  m_table; /* dictionnary[key] = value with key = (x, y) */
};


#endif // PKMN_TABLEPARSER_H_INCLUDED
