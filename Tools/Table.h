#ifndef PKMN_TABLE_H_INCLUDED
#define PKMN_TABLE_H_INCLUDED

#include "VectorMethod.h" // Especially to cut string
#include "../FilePath.h" // Not necessary but in case someone
                              // forgot to include it when using this file

#include <iostream> // To use ostream for printing a table
#include <string> // For stocking values
#include <vector> // For stocking the matrix inside Table class
#include <fstream> // To access to file

namespace PKMN
{
    class Table;
}

class PKMN::Table
/** Table give an easier way to read table. Each element of a table can be
    accessed by the couple of it line name and it column name. It also provides
    other methods to get a whole line or a whole column but the most proper way
    to access the table remains operator() with line and column name. **/
{
public:

/// CONSTRUCTORS :

    Table();
        /** \brief Void constructor ,create a void table
         *
         */

    Table(std::string FilePath);
        /** \brief create a Table by splitting the text of a file
         *
         * \param FilePath std::string : path to the table to read,
         * path are defined as macro in FilePath.h
         *
         */

/// DESTRUCTOR :

    ~Table();
        /** \brief Destructor
         *
         */

/// GETTERS :

    std::vector<std::string> getLineValues(std::string nameLine) const;
        /** \brief give the value of a line without the line name
         *
         * \param nameLine std::string : name of the table's line to send back
         * \return std::vector<std::string> : the line will be stocked as a vector of string
         *
         */

    std::vector<std::string> getColumnValues(std::string nameColumn) const;
        /** \brief give the value of a column without the column name
         *
         * \param nameColumn std::string : name of the table's column to send back
         * \return std::vector<std::string> : the column will be stocked as a vector of string
         *
         */

    std::vector<std::string> getLineValuesWithLineName(std::string nameLine) const;
        /** \brief give the value of a line with the line name
         *
         * \param nameLine std::string : name of the table's line to send back
         * \return std::vector<std::string> : the line will be stocked as a vector of string,
         * the first value is the line name
         *
         */

    std::vector<std::string> getColumnValuesWithColumnName(std::string nameColumn) const;
        /** \brief give the value of a column with the column name
         *
         * \param nameColumn std::string : name of the table's column to send back
         * \return std::vector<std::string> : the column will be stocked as a vector of string,
         * the first value is the column name
         *
         */

    std::vector<std::string> getLineNames() const;
        /** \brief Give the list of all the table's line name
         *
         * \return std::vector<std::string> : line names are stocked in a vector
         *
         */

    std::vector<std::string> getColumnNames() const;
        /** \brief Give the list of all the table's column name
         *
         * \return std::vector<std::string> : column names are stocked in a vector
         *
         */

/// METHODS :

    std::vector<int> dimension() const;
        /** \brief Calculate the dimension of the table (useful for "for" structure)
         *
         * \return std::vector<int> : (line length, column length)
         *
         */

    std::string operator()(std::string nameLine, std::string nameColumn) const;
        /** \brief send the string element located at a specific line and a specific column
         *
         * \param nameLine, nameColumn std::string : position of the element (mask the number values)
         * \return std::string : string element stocked in this position
         *
         */

     std::string text(const char& delim = '\t') const;
         /** \brief get the text in the file
         *
         * \param delim const char& = '\t': separator of line
         *
         */

     void print(const char& delim = '\t') const;
         /** \brief print the table
         *
         * \param delim const char& = '\t': separator of line
         *
         */


private:

/// FRIEND METHODS :

    friend std::ostream& operator<<(std::ostream &flux, Table const& t);
        /** \brief For saving a table
         *
         * \param flux : for std::cout for example
         * \param Table Table const& : the table to write or to print
         * \return friend std::ostream& : flux
         *
         */

/// MEMBER VARIABLES :

    std::vector<std::string> m_headerColumn; /// Name of column, directly accessible
                                             /// without searching them in keys
    std::vector<std::string> m_headerLine; /// Give name of line, directly accessible
                                           /// without searching them
    std::vector< std::vector<std::string> > m_table; /// matrix of string that contain the splitted text

};


#endif // PKMN_TABLE_H_INCLUDED
