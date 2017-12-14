#include "Table.h"

               /// CONSTRUCTORS ///

PKMN::Table::Table()
{

}

PKMN::Table::Table(std::string FilePath)
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

/// ///////////////////////////////////////// ///

                /// DESTRUCTOR ///

PKMN::Table::~Table()
{

}

/// ///////////////////////////////////////// ///

                /// GETTERS ///

std::vector<std::string> PKMN::Table::getLineNames() const
{
    return m_headerLine;
}

std::vector<std::string> PKMN::Table::getColumnNames() const
{
    return m_headerColumn;
}

std::vector<std::string> PKMN::Table::getLineValues(std::string nameLine) const
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

std::vector<std::string> PKMN::Table::getColumnValues(std::string nameColumn) const
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

std::vector<std::string> PKMN::Table::getLineValuesWithLineName(std::string nameLine) const
{
    return vector_insert(this->getLineValues(nameLine), nameLine, 0);
}

std::vector<std::string> PKMN::Table::getColumnValuesWithColumnName(std::string nameColumn) const
{
    return PKMN::vector_insert(this->getColumnValues(nameColumn), nameColumn, 0);
}

/// ///////////////////////////////////////// ///

                /// METHODS ///

std::vector<int> PKMN::Table::dimension() const
{
    std::vector<int> dim(2);
    dim[0] = m_headerLine.size();
    dim[1] = m_headerColumn.size();
    return dim;
}

std::string PKMN::Table::operator()(std::string nameLine, std::string nameColumn) const
{
    std::vector<int> dim =  this->dimension();
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

std::string PKMN::Table::text(const char& delim) const
{
    const unsigned int nbColumn = m_headerColumn.size();
    const unsigned int nbLine = m_headerLine.size();
    std::string str = "";
    str += delim;
    for(unsigned int j = 0; j < nbColumn; j++)
    {
        str += m_headerColumn[j];
        if(j < nbColumn - 1)
        {
            str += delim;
        }
    }
    str += '\n';
    for(unsigned int i = 0; i < nbLine; i++)
    {
        str += m_headerLine[i];
        str += delim;
        for(unsigned int j = 0; j < nbColumn; j++)
        {
            str += m_table[i][j];
            if(j < nbColumn - 1)
            {
                str += delim;
            }
        }
        if(i < nbLine - 1)
        {
            str += '\n';
        }
    }
    return str;
}

void PKMN::Table::print(const char& delim) const
{
    std::cout << this->text(delim);
}

/// ///////////////////////////////////////// ///

                /// FRIEND METHODS ///

namespace PKMN
{
std::ostream& operator<<(std::ostream &flux, Table const& t)
{
    const unsigned int nbColumn = t.m_headerColumn.size();
    const unsigned int nbLine = t.m_headerLine.size();
    flux << ';';
    for(unsigned int j = 0; j < nbColumn; j++)
    {
        flux << t.m_headerColumn[j];
        if(j < nbColumn - 1)
        {
            flux << ';';
        }
    }
    flux << '\n';
    for(unsigned int i = 0; i < nbLine; i++)
    {
        flux << t.m_headerLine[i];
        flux << ';';
        for(unsigned int j = 0; j < nbColumn; j++)
        {
            flux << t.m_table[i][j];
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
}

