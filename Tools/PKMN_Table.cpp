#include "PKMN_Table.h"

std::vector<PKMN_TableCoordinates> map_keys(std::map<PKMN_TableCoordinates, std::string> dictionary)
{
    std::vector<PKMN_TableCoordinates> keys;
    for(std::map<PKMN_TableCoordinates, std::string>::iterator i(dictionary.begin()); i != dictionary.end(); i++)
    {
        keys.push_back(i->first);
    }
    return keys;
}

void map_print(std::map<PKMN_TableCoordinates, std::string> dictionnary)
{
  for(std::map<PKMN_TableCoordinates, std::string>::iterator i(dictionnary.begin()); i != dictionnary.end(); i++)
  {
        std::cout << i->first << " : " << i->second << std::endl;
  }
}

std::vector<std::string> string_split(const std::string& line, const char delim)
{
    std::stringstream ss(line);
    std::string item;
    std::vector<std::string> L;
    while (getline(ss, item, delim))
    {
        L.push_back(item);
    }
    return L;
}

//PKMN_Table::PKMN_Table()
//{
//
//}
//
//PKMN_Table::PKMN_Table(std::string FilePath)
//{
//    std::ifstream flux(FilePath.c_str());
//    if(flux)
//    {
//        std::string line;
//        std::vector<std::string> L;
//        bool firstLine(true);
//        unsigned int length;
//        while(getline(flux, line))
//        {
//            L = split(line);
//            length = L.size();
//            if(firstLine)
//            {
//                for(unsigned int i = 1; i < length; i++)
//                {
//                     m_headerColumn.push_back(L[i]);
//                }
//                firstLine = false;
//            }
//            else
//            {
//                std::string key(L[0]);
//                m_headerLine.push_back(key);
//                for(unsigned int i = 1; i < length; i++)
//                {
//                     m_headerLine.push_back(L[i]);
//                     m_table.insert(std::pair<PKMN_Tuple, std::string>(PKMN_Tuple(key, m_headerColumn[i]), L[i]));
//                }
//            }
//        }
//    }
//}
//
//PKMN_Table::~PKMN_Table()
//{
//
//}

//std::vector<int> PKMN_Table::dimension() const
//{
//    std::vector<int> dim(2);
//    dim[0] = m_headerLine.size();
//    dim[1] = m_headerColumn.size();
//    return dim;
//}
//
//std::vector<std::string> PKMN_Table::getLineNames(std::string nameLine) const
//{
//    return m_headerLine;
//}
//
//std::vector<std::string> PKMN_Table::getColumnNames(std::string nomColumn) const
//{
//    return m_headerColumn;
//}
//
//std::ostream& operator<<(std::ostream &flux, PKMN_Table const& Table)
//{
//    std::vector<int>  dim = Table.dimension();
//    for(int i = 0; i <= dim[0]; i++)
//    {
//        for(int j = 0; j <= dim[1]; j++)
//        {
//            flux << Table(Table.m_headerLine[i], Table.m_headerColumn[j]);
//            if(j == dim[1] - 1)
//            {
//                if(i != dim[0] - 1)
//                {
//                    flux << "\n";
//                }
//            }
//            else
//            {
//                flux << "\t";
//            }
//        }
//    }
//    return flux;
//}
//
//std::string PKMN_Table::operator()(std::string lineName, std::string columnName) const
//{
//    return m_table.at(PKMN_Tuple(lineName, columnName));
//}
//
//std::vector<std::string> PKMN_Table::getLineValues(std::string nameLine) const
//{
//    std::vector<std::string> line;
//    const int length = m_headerColumn.size();
//    for(int i = 0; i <= length; i++)
//    {
//        line.push_back(m_table.at(PKMN_Tuple(nameLine,m_headerColumn[i])));
//    }
//    return line;
//}
//
//std::vector<std::string> PKMN_Table::getColumnValues(std::string nameColumn) const
//{
//    std::vector<std::string> column;
//    const int length = m_headerLine.size();
//    for(int j = 0; j <= length; j++)
//    {
//        column.push_back(m_table.at(PKMN_Tuple(m_headerLine[j],nameColumn)));
//    }
//    return column;
//}
