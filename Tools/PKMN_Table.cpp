#include "PKMN_Table.h"

PKMN_Table::PKMN_Table()
{

}

PKMN_Table::PKMN_Table(std::string FilePath)
{
    std::ifstream flux(FilePath.c_str());
    if(flux)
    {
        std::string line;
        std::vector<std::string> L;
        bool firstLine(true);
        unsigned int length;
        while(getline(flux, line))
        {
            L = string_split(line);
            length = L.size();
            if(firstLine)
            {
                for(unsigned int i = 1; i < length; i++)
                {
                    m_headerColumn.push_back(L[i]);
                }
                firstLine = false;
            }
            else
            {
                std::string key(L[0]);
                m_headerLine.push_back(key);
                for(unsigned int i = 1; i < length; i++)
                {
                    m_table[PKMN_TableCoordinates(key, m_headerColumn[i - 1])] = L[i];
                }
            }
        }
    }
}

PKMN_Table::~PKMN_Table()
{

}

std::ostream& operator<<(std::ostream &flux, PKMN_Table const& Table)
{
    const unsigned int nbColumn = Table.m_headerColumn.size();
    const unsigned int nbLine = Table.m_headerLine.size();
    flux << '\t';
    for(unsigned int j = 0; j < nbColumn; j++)
    {
        flux << Table.m_headerColumn[j];
        if(j < nbColumn - 1)
        {
            flux << '\t';
        }
    }
    flux << '\n';
    for(unsigned int i = 0; i < nbLine; i++)
    {
        flux << Table.m_headerLine[i];
        flux << '\t';
        for(unsigned int j = 0; j < nbColumn; j++)
        {
            flux << Table(Table.m_headerLine[i], Table.m_headerColumn[j]);
            if(j < nbColumn - 1)
            {
                flux << '\t';
            }
        }
        if(i < nbLine - 1)
        {
            flux << '\n';
        }
    }
    return flux;
}

std::vector<int> PKMN_Table::dimension() const
{
    std::vector<int> dim(2);
    dim[0] = m_headerLine.size();
    dim[1] = m_headerColumn.size();
    return dim;
}

std::vector<std::string> PKMN_Table::getLineNames(std::string nameLine) const
{
    return m_headerLine;
}

std::vector<std::string> PKMN_Table::getColumnNames(std::string nomColumn) const
{
    return m_headerColumn;
}


std::string PKMN_Table::operator()(std::string lineName, std::string columnName) const
{
    PKMN_TableCoordinates t(lineName, columnName);
    std::map<PKMN_TableCoordinates, std::string> dictionnary = m_table;
    for(std::map<PKMN_TableCoordinates, std::string>::iterator i(dictionnary.begin()); i != dictionnary.end(); i++)
    {
        if(i->first == t)
        {
            return i->second;
        }
    }
    return "";
}

std::vector<std::string> PKMN_Table::getLineValues(std::string nameLine) const
{
    std::vector<std::string> line;
    const unsigned int length = m_headerColumn.size();
    for(unsigned int i = 0; i < length; i++)
    {
        line.push_back(this->operator()(nameLine,m_headerColumn[i]));
    }
    return line;
}

std::vector<std::string> PKMN_Table::getColumnValues(std::string nameColumn) const
{
    std::vector<std::string> column;
    const unsigned int length = m_headerLine.size();
    for(unsigned int j = 0; j < length; j++)
    {
        column.push_back(this->operator()(m_headerLine[j],nameColumn));
    }
    return column;
}

std::vector<std::string> PKMN_Table::getLineValuesWithLineName(std::string nameLine) const
{
    std::vector<std::string> line;
    line.push_back(nameLine);
    const unsigned int length = m_headerColumn.size();
    for(unsigned int i = 0; i < length; i++)
    {
        line.push_back(this->operator()(nameLine,m_headerColumn[i]));
    }
    return line;
}

std::vector<std::string> PKMN_Table::getColumnValuesWithColumnName(std::string nameColumn) const
{
    std::vector<std::string> column;
    column.push_back(nameColumn);
    const unsigned int length = m_headerLine.size();
    for(unsigned int j = 0; j < length; j++)
    {
        column.push_back(this->operator()(m_headerLine[j],nameColumn));
    }
    return column;
}
