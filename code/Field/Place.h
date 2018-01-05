#ifndef PKMN_PLACE_H_INCLUDED
#define PKMN_PLACE_H_INCLUDED

#include "../Tools/Table.h"
#include "Weather.h"
#include "../FilePath.h"

#include <string>
#include <iostream>
#include <fstream>

namespace PKMN
{
    class Place;
}

class PKMN::Place
{
public:

    Place();
    Place(std::string InternalName);

    Place(Place const& other);

    Place& operator=(Place const& other);

    ~Place();

    Weather getWeather() const;
    std::string getName() const;
    std::string getInternalName() const;

private:

    std::string m_InternalName;
    std::string m_Name;
    Weather m_Weather;
};


#endif // PKMN_PLACE_H_INCLUDED
