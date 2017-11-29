#ifndef TUPLE_H_INCLUDED
#define TUPLE_H_INCLUDED

#include <string>

template<class T> class PKMN_Tuple /// PKMN_Tuple objects are a couple of 2 variables
{
public:

    // Constructor :
    PKMN_Tuple();
    PKMN_Tuple(T x, T y);

    // Copy constructor and assignation operator :
    PKMN_Tuple(PKMN_Tuple const& Tuple);
    PKMN_Tuple& operator=(PKMN_Tuple const&);

    // Getters :
    T getx() const;
    T gety() const;

    // Destructor :
    virtual ~PKMN_Tuple();

private:

    T m_x;
    T m_y;

};

// Comparison operator for PKMN_Tuple and PKMN_Tuple:
template<class T>
bool operator==(PKMN_Tuple<T> const& Tuple1, PKMN_Tuple<T> const& Tuple2);
template<class T>
bool operator<(PKMN_Tuple<T> const& Tuple1, PKMN_Tuple<T> const& Tuple2);
template<class T>
bool operator>(PKMN_Tuple<T> const& Tuple1, PKMN_Tuple<T> const& Tuple2);
template<class T>
bool operator<=(PKMN_Tuple<T> const& Tuple1, PKMN_Tuple<T> const& Tuple2);
template<class T>
bool operator>=(PKMN_Tuple<T> const& Tuple1, PKMN_Tuple<T> const& Tuple2);
template<class T>
bool operator!=(PKMN_Tuple<T> const& Tuple1, PKMN_Tuple<T> const& Tuple2);

template class PKMN_Tuple<std::string>;
template class PKMN_Tuple<int>;

#endif // TUPLE_H_INCLUDED
