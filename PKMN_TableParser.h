#ifndef PKMN_TABLEPARSER_H_INCLUDED
#define PKMN_TABLEPARSER_H_INCLUDED

#include <vector>
#include <map>
#include "PKMN_Tuple.h"


/** \brief Returns a map with the first word of the line as a key and the rest of the line in a vector as a value, words being separated by char sep.
 *
 * \param line std::string
 * \param const char sep = ';'
 * \return std::map<std::string, std::vector<std::string>>
 *
 */
std::map<std::string, std::vector<std::string> > splitLine(std::string line, const char sep = ';')

class Table
{
public:

    Table();
    Table(std::string FilePath);
    std::vector<std::vector<std::string> > getTable();
    std::vector<unsigned int> getDimension();
    void transpose();
    std::vector<std::string> getLine(std::string nameLine);
    std::vector<std::string> getColumn(std::string nomColumn);
    std::string getValue(std::string nameColumn, std::string nameLine);
    virtual ~Table();

private:

    std::vector<std::string> m_headerColumn;
    std::vector<std::string> m_headerLine;
    std::map<PKMN_Tuple, std::string>  m_table;
};


#endif // PKMN_TABLEPARSER_H_INCLUDED
