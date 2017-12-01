#include "PKMN_Table.h"

template<class T, class T2>
std::vector<T> map_keys(std::map<T,T2> dictionary)
{
    std::vector<T> keys;
    for (typename std::map<T,T2>::iterator i(dictionary.begin()); i != dictionary.end(); i++)
    {
        keys.push_back(i->first);
    }
    return keys;
}

std::map<std::string, std::vector<std::string> > splitLine(std::string line, const char sep)
{

    std::map<std::string, std::vector<std::string> > dic;
    std::string key;
    const unsigned int length = line.size();
    bool firstWord(true);
    for(unsigned int i = 0, newWordIndice = 0; i < length; i++)
    {
        if(line[i] == sep)
        {
            std::string word("");
            for(unsigned int j = newWordIndice; j < i; j++)
            {
                word += line[j];
            }
            if(firstWord)
            {
                key = word;
                std::vector<std::string> value;
                dic[word] = value;
                firstWord = false;
            }
            else
            {
                dic[key].push_back(word);
            }
            newWordIndice = i + 1;
        }
    }
    return dic;
}

PKMN_Table::PKMN_Table()
{

}

PKMN_Table::PKMN_Table(std::string FilePath)
{
    std::ifstream flux(FilePath.c_str());
    if(flux)
    {
        std::string line;
        std::map<std::string, std::vector<std::string> > dic;
        bool firstLine(true);
        while(getline(flux, line))
        {
            dic = splitLine(line);
            std::vector<std::string> keys(map_keys(dic));
            std::string key(keys[0]);
            if(firstLine)
            {
                m_headerColumn = dic[key];
                firstLine = false;
            }
            else
            {
                m_headerLine.push_back(key);
                std::vector<std::string> values = dic[key];
                std::vector<PKMN_Tuple> tupleKeys;
                const unsigned int length = values.size();
                for(unsigned int i = 0; i < length; i++)
                {
                    m_table.insert(std::pair<PKMN_Tuple, std::string>(PKMN_Tuple(key, m_headerColumn[i]), values[i]));
                }
            }
        }
    }
}

PKMN_Table::~PKMN_Table()
{

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

std::ofstream& operator<<(std::ofstream &flux, PKMN_Table const& Table)
{
    std::vector<int>  dim = Table.dimension();
    for(int i = 0; i <= dim[0]; i++)
    {
        for(int j = 0; j <= dim[1]; j++)
        {
            flux << Table(Table.m_headerLine[i], Table.m_headerColumn[j]);
            if(j == dim[1] - 1)
            {
                if(i != dim[0] - 1)
                {
                    flux << "\n";
                }
            }
            else
            {
                flux << "\t";
            }
        }
    }
    return flux;
}

std::string PKMN_Table::operator()(std::string lineName, std::string columnName) const
{
    return m_table.at(PKMN_Tuple(lineName, columnName));
}

std::vector<std::string> PKMN_Table::getLineValues(std::string nameLine) const
{
    std::vector<std::string> line;
    const int length = m_headerColumn.size();
    for(int i = 0; i <= length; i++)
    {
        line.push_back(m_table.at(PKMN_Tuple(nameLine,m_headerColumn[i])));
    }
    return line;
}

std::vector<std::string> PKMN_Table::getColumnValues(std::string nameColumn) const
{
    std::vector<std::string> column;
    const int length = m_headerLine.size();
    for(int j = 0; j <= length; j++)
    {
        column.push_back(m_table.at(PKMN_Tuple(m_headerLine[j],nameColumn)));
    }
    return column;
}
