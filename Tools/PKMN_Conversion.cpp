#include "PKMN_Conversion.h"

bool string_to_bool(const std::string& str)
{
    if(str == "True")
    {
        return true;
    }
    return false;
}

int string_to_int(const std::string& str)
{
    int number = 0;
    const unsigned int length = str.size();
    for(unsigned int i = 0; i < length; i++)
    {
        number *= 10;
        number += static_cast<int>(str[i]) - static_cast<int>('0');
    }
    return number;
}
