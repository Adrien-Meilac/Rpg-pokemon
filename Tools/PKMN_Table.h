#ifndef PKMN_TABLEPARSER_H_INCLUDED
#define PKMN_TABLEPARSER_H_INCLUDED

#include "PKMN_TableCoordinates.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <sstream>

std::vector<PKMN_TableCoordinates> map_keys(std::map<PKMN_TableCoordinates, std::string> dictionary);
void map_print(std::map<PKMN_TableCoordinates, std::string> dictionary);
std::vector<std::string> string_split(const std::string& line, const char delim = ';');
bool str_to_bool(const std::string& str_bool);
bool vector_in(std::vector<std::string> L, std::string mot);

class PKMN_Table
{
public:

    PKMN_Table();
    PKMN_Table(std::string FilePath);
    std::vector<int> dimension() const;
    std::vector<std::string> getLineValues(std::string nameLine) const;
    std::vector<std::string> getColumnValues(std::string nomColumn) const;
    std::vector<std::string> getLineNames(std::string nameLine) const;
    std::vector<std::string> getColumnNames(std::string nomColumn) const;
    std::string operator()(std::string lineName, std::string columnName) const;
    virtual ~PKMN_Table();

private:

    friend std::ostream& operator<<(std::ostream &flux, PKMN_Table const& Table);

    std::vector<std::string> m_headerColumn; /* Name of column, directly accessible without searching them in keys */
    std::vector<std::string> m_headerLine; /* Give name of line, directly accessible without searching them */
    std::map<PKMN_TableCoordinates, std::string> m_table; /* dictionnary[key] = value with key = (x, y) */
};


#endif // PKMN_TABLEPARSER_H_INCLUDED
