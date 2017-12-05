#ifndef PKMN_TableMapPARSER_H_INCLUDED
#define PKMN_TableMapPARSER_H_INCLUDED

#include "PKMN_TableCoordinates.h"
#include "PKMN_VectorMethod.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>

class PKMN_TableMap
{
public:

    PKMN_TableMap();
    PKMN_TableMap(std::string FilePath);
    std::vector<int> dimension() const;
    std::vector<std::string> getLineValues(std::string nameLine) const;
    std::vector<std::string> getColumnValues(std::string nomColumn) const;
    std::vector<std::string> getLineValuesWithLineName(std::string nameLine) const;
    std::vector<std::string> getColumnValuesWithColumnName(std::string nomColumn) const;
    std::vector<std::string> getLineNames(std::string nameLine) const;
    std::vector<std::string> getColumnNames(std::string nomColumn) const;
    std::string operator()(std::string lineName, std::string columnName) const;
    virtual ~PKMN_TableMap();

private:

    friend std::ostream& operator<<(std::ostream &flux, PKMN_TableMap const& Table);

    std::vector<std::string> m_headerColumn; /* Name of column, directly accessible without searching them in keys */
    std::vector<std::string> m_headerLine; /* Give name of line, directly accessible without searching them */
    std::map<PKMN_TableCoordinates, std::string> m_table; /* dictionnary[key] = value with key = (x, y) */
};


#endif // PKMN_TableMapPARSER_H_INCLUDED