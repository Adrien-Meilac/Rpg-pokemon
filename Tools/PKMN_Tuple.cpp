#include "PKMN_Tuple.h"

template<class T>
PKMN_Tuple<T>::PKMN_Tuple():
    m_x(),
    m_y()
{

}

template<class T>
PKMN_Tuple<T>::PKMN_Tuple(T x, T y):
    m_x(x),
    m_y(y)
{

}

template<class T>
PKMN_Tuple<T>::PKMN_Tuple(PKMN_Tuple const& Tuple)
{
    m_x = Tuple.m_x;
    m_y = Tuple.m_y;
}

template<class T>
PKMN_Tuple<T>& PKMN_Tuple<T>::operator=(PKMN_Tuple<T> const& Tuple)
{
    m_x = Tuple.m_x;
    m_y = Tuple.m_y;
    return *this;
}

template<class T>
PKMN_Tuple<T>::~PKMN_Tuple()
{
    delete &m_x;
    delete &m_y;
}

template<class T>
T PKMN_Tuple<T>::getx() const
{
    return m_x;
}

template<class T>
T PKMN_Tuple<T>::gety() const
{
    return m_y;
}

template<class T>
bool operator==(PKMN_Tuple<T> const& Tuple1, PKMN_Tuple<T> const& Tuple2)
{
    return (Tuple1.getx() == Tuple2.getx()) && (Tuple1.gety() == Tuple2.gety());
}

template<class T>
bool operator<(PKMN_Tuple<T> const& Tuple1, PKMN_Tuple<T> const& Tuple2)
{
    return ((Tuple1.getx() < Tuple2.getx()) || ((Tuple1.getx() == Tuple2.getx()) && (Tuple1.gety() < Tuple2.gety())));
}

template<class T>
bool operator>(PKMN_Tuple<T> const& Tuple1, PKMN_Tuple<T> const& Tuple2)
{
    return ((Tuple1.getx() > Tuple2.getx()) || ((Tuple1.getx() == Tuple2.getx()) && (Tuple1.gety() > Tuple2.gety())));
}

template<class T>
bool operator<=(PKMN_Tuple<T> const& Tuple1, PKMN_Tuple<T> const& Tuple2)
{
    return !(Tuple1 > Tuple2);
}

template<class T>
bool operator>=(PKMN_Tuple<T> const& Tuple1, PKMN_Tuple<T> const& Tuple2)
{
    return !(Tuple1 < Tuple2);
}

template<class T>
bool operator!=(PKMN_Tuple<T> const& Tuple1, PKMN_Tuple<T> const& Tuple2)
{
    return !(Tuple1 == Tuple2);
}

