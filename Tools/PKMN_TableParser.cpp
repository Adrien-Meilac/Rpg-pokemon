#include "PKMN_TableParser.h"

template<class T, class T2>
std::vector<T> map_keys(std::map<T,T2> dictionnary)
{
    std::vector<T> keys;
    for (typename std::map<T,T2>::iterator i(dictionnary.begin()); i != dictionnary.end(); i++)
    {
        keys.push_back(i->first);
    }
    return keys;
}

std::map<std::string, std::vector<std::string> > splitLine(std::string line, const char sep = ';')
{

    std::map<std::string, std::vector<std::string> > L;
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
                std::string key(word);
                std::vector<std::string> value;
                L[word] = value;
                firstWord = false;
            }
            else
            {
                L[key].push_back(word);
            }
            newWordIndice = i + 1;
        }
    }
    return L;
}

Table::Table()
{

}

Table::Table(std::string FilePath)
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
            std::string key(keys[0])
            if(firstLine)
            {
                m_headerColumn = dic[key];
                firstLine=false;
            }
            else
            {
                m_headerLine.push_back(key);
                const unsigned int length = dic[key].size();
                for (unsigned int i=0; i < length; i++)
                {
                    PKMN_Tuple Tuple(key, m_headerColumn[i]);
                    m_table[Tuple] = dic[key][i];
                }
            }
        }
    }
}

std::vector<std::vector<std::string> > Table::getTable()
{
    return m_table;
}

std::vector<unsigned int> Table::getDimension()
{
    std::vector<unsigned int> dimension;
    dimension.push_back(m_headerColumn.size());
    dimension.push_back(m_headerLine.size());
    return dimension;
}

void Table::transpose() //inverser les éléments à chaque fois qu'on voit un tuple avec une copie
{
    const unsigned int dimensionColumn(this->getDimension()[0]);
    const unsigned int dimensionLine(this->getDimension()[1]);
    std::vector<std::vector<std::string> > tableTranspose;
    for(unsigned int i(0); i < dimensionColumn; i++)
    {
        std::vector<std::string> L;
        for(unsigned int j(0); j < dimensionLine; j++)
        {
            L.push_back(m_table[j][i]);
        }
        tableTranspose.push_back(L);
        while (!L.empty())
        {
            L.pop_back();
        }
    }
    std::vector<std::string> tempC;
    for(unsigned int i(0); i < dimensionColumn; i++)
    {
        temp.push_back(m_headerColumn[i]);
    }
    std::vector<std::string> tempL;
    for(unsigned int i(0); i < dimensionColumn; i++)
    {
        temp.push_back(m_headerColumn[i]);
    }
}

std::vector<std::string> Table::getLine(std::string nomLigne)//a modifier avec return[keys]
{
    const unsigned int dimensionLine(this->getDimension()[1]);
    for(unsigned int i(0); i < dimensionLine; i++)
    {
        if(nomLigne == m_headerLine[i])
        {
            return m_table[i];
        }
    }
}

std::vector<std::string> Table::getColumn(std::string nomColumn)  //a modifier
{
    const unsigned int dimensionColumn(this->getDimension()[0]);
    const unsigned int dimensionLine(this->getDimension()[1]);
    for(unsigned int j(0); j < dimensionColumn; j++)
    {
        if(nomLigne == m_headerLine[j])
        {
            std::vector<std::string> column;
            for(unsigned int i(0); i < dimensionLine; i++)
            {
                column.push_back(m_table[i][j]);
            }
            return column;
        }
    }
}

std::string getValue(std::string nomColumn, std::string nomLigne);

