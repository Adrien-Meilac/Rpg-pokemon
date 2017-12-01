#ifndef TUPLE_H_INCLUDED
#define TUPLE_H_INCLUDED

#include <string>

class PKMN_Tuple /// PKMN_Tuple objects are a couple of 2 string variables
{
public:

    // Constructor :
    PKMN_Tuple();
    PKMN_Tuple(std::string x, std::string y);

    // Copy constructor and assignation operator :
    PKMN_Tuple(PKMN_Tuple const& Tuple);
    PKMN_Tuple& operator=(PKMN_Tuple const&);

    // Getters :
    std::string getx() const;
    std::string gety() const;

    // Destructor :
    virtual ~PKMN_Tuple();

private:

    std::string m_x;
    std::string m_y;

};

// Comparison operator for PKMN_Tuple and PKMN_Tuple:
bool operator==(PKMN_Tuple const& Tuple1, PKMN_Tuple const& Tuple2);
bool operator<(PKMN_Tuple const& Tuple1, PKMN_Tuple const& Tuple2);
bool operator>(PKMN_Tuple const& Tuple1, PKMN_Tuple const& Tuple2);
bool operator<=(PKMN_Tuple const& Tuple1, PKMN_Tuple const& Tuple2);
bool operator>=(PKMN_Tuple const& Tuple1, PKMN_Tuple const& Tuple2);
bool operator!=(PKMN_Tuple const& Tuple1, PKMN_Tuple const& Tuple2);

#endif // TUPLE_H_INCLUDED
