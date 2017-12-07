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
                std::vector<std::string> line(length - 1);
                for(unsigned int i = 1; i < length; i++)
                {
                    line[i - 1] = L[i];
                }
                m_table.push_back(line);
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
    flux << ';';
    for(unsigned int j = 0; j < nbColumn; j++)
    {
        flux << Table.m_headerColumn[j];
        if(j < nbColumn - 1)
        {
            flux << ';';
        }
    }
    flux << '\n';
    for(unsigned int i = 0; i < nbLine; i++)
    {
        flux << Table.m_headerLine[i];
        flux << ';';
        for(unsigned int j = 0; j < nbColumn; j++)
        {
            flux << Table.m_table[i][j];
            if(j < nbColumn - 1)
            {
                flux << ';';
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

std::vector<std::string> PKMN_Table::getLineNames() const
{
    return m_headerLine;
}

std::vector<std::string> PKMN_Table::getColumnNames() const
{
    return m_headerColumn;
}


std::string PKMN_Table::operator()(std::string nameLine, std::string nameColumn) const
{
    std::vector<int> dim = this->dimension();
    std::vector<int> i_value(2);
    for(int i = 0; i < dim[0]; i++)
    {
        if(m_headerLine[i] == nameLine)
        {
            i_value[0] = i;
        }
    }
    for(int j = 0; j < dim[1]; j++)
    {
        if(m_headerColumn[j] == nameColumn)
        {
            i_value[1] = j;
        }
    }
    return m_table[i_value[0]][i_value[1]];
}

std::vector<std::string> PKMN_Table::getLineValues(std::string nameLine) const
{
    std::vector<int> dim = this->dimension();
    for(int i = 0; i < dim[0]; i++)
    {
        if(m_headerLine[i] == nameLine)
        {
            return m_table[i];
        }
    }
    return m_table[0];
}

std::vector<std::string> PKMN_Table::getColumnValues(std::string nameColumn) const
{
    std::vector<int> dim = this->dimension();
    std::vector<std::string> column(dim[0]);
    int j_col = 0;
    for(int j = 0; j < dim[1]; j++)
    {
        if(m_headerColumn[j] == nameColumn)
        {
            j_col = j;
        }
    }
    for(int i = 0; i < dim[0]; i++)
    {
        column[i] = m_table[i][j_col];
    }
    return column;
}

std::vector<std::string> PKMN_Table::getLineValuesWithLineName(std::string nameLine) const
{
    return vector_insert(this->getLineValues(nameLine), nameLine, 0);
}

std::vector<std::string> PKMN_Table::getColumnValuesWithColumnName(std::string nameColumn) const
{
    return vector_insert(this->getColumnValues(nameColumn), nameColumn, 0);
}

std::map<std::string, std::string> PKMN_Table::getDicLineValues(std::string nameLine) const
{
    std::vector<std::string> Line = this->getLineValues(nameLine);
    std::map<std::string, std::string> mapy;
    const unsigned int length = Line.size();
    for(unsigned int i = 0; i < length; i++)
    {
        mapy[m_headerColumn[i]] = Line[i];
    }
    return mapy;
}

std::map<std::string, std::string> PKMN_Table::getDicColumnValues(std::string nameColumn) const
{
    std::vector<std::string> Column = this->getColumnValues(nameColumn);
    std::map<std::string, std::string> mapy;
    const unsigned int length = Column.size();
    for(unsigned int i = 0; i < length; i++)
    {
        mapy[m_headerLine[i]] = Column[i];
    }
    return mapy;
}

std::map<std::string, std::string> PKMN_Table::getDicLineValuesWithLineName(std::string nameLine) const
{
    std::map<std::string, std::string> mapy = this->getDicLineValues(nameLine);
    mapy["nameLine"] = nameLine;
    return mapy;
}

std::map<std::string, std::string> PKMN_Table::getDicColumnValuesWithColumnName(std::string nameColumn) const
{
    std::map<std::string, std::string> mapy = this->getDicColumnValues(nameColumn);
    mapy["nameColumn"] = nameColumn;
    return mapy;
}
