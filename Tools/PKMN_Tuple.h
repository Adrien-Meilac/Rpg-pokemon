#ifndef TUPLE_H_INCLUDED
#define TUPLE_H_INCLUDED

#include <string>

class PKMN_Tuple
{
public:
    PKMN_Tuple();
    PKMN_Tuple(PKMN_Tuple const& Tuple);
    PKMN_Tuple(std::string x, std::string y);
    PKMN_Tuple& operator=(PKMN_Tuple const&);
    virtual ~PKMN_Tuple();

    std::string getx() const;
    std::string gety() const;

private:
    std::string m_x;
    std::string m_y;
};

bool operator==(PKMN_Tuple const& Tuple1, PKMN_Tuple const& Tuple2);

#endif // TUPLE_H_INCLUDED
