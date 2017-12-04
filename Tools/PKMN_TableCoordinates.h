#ifndef PKMN_TABLECOORDINATES_H_INCLUDED
#define PKMN_TABLECOORDINATES_H_INCLUDED

#include <iostream>
#include <string>

class PKMN_TableCoordinates
/// PKMN_TableCoordinates objects are a couple of 2 string variables
{
public:

    // Constructor :
    PKMN_TableCoordinates();
    PKMN_TableCoordinates(std::string x,
                          std::string y);

    // Copy constructor and assignation operator :
    PKMN_TableCoordinates(PKMN_TableCoordinates const& tc);
    PKMN_TableCoordinates& operator=(PKMN_TableCoordinates const& tc);

    // Getters :
    std::string getLineName() const;
    std::string getColumnName() const;

    // Destructor :
    virtual ~PKMN_TableCoordinates();

private:

    friend std::ostream& operator<<(std::ostream& flux,
                                    PKMN_TableCoordinates const& tc);

    // Comparison operator
    friend bool operator==(PKMN_TableCoordinates const& tc1,
                           PKMN_TableCoordinates const& tc2);
    friend bool operator<(PKMN_TableCoordinates const& tc1,
                          PKMN_TableCoordinates const& tc2);
    friend bool operator>(PKMN_TableCoordinates const& tc1,
                          PKMN_TableCoordinates const& tc2);
    friend bool operator<=(PKMN_TableCoordinates const& tc1,
                           PKMN_TableCoordinates const& tc2);
    friend bool operator>=(PKMN_TableCoordinates const& tc1,
                           PKMN_TableCoordinates const& tc2);
    friend bool operator!=(PKMN_TableCoordinates const& tc1,
                           PKMN_TableCoordinates const& tc2);

    std::pair<std::string, std::string> m_pair;
};

#endif // PKMN_TABLECOORDINATES_H_INCLUDED
