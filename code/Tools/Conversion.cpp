#include "Conversion.h"

template <typename T> std::string PKMN::NumberToString(T Number)
{
 std::ostringstream ss;
 ss << Number;
 return ss.str();
}

template <typename T> T PKMN::StringToNumber(const std::string &Text)
{
 std::istringstream ss(Text);
 T result;
 return ss >> result ? result : 0;
}


bool PKMN::string_to_bool(const std::string& str)
{
    if(str == "True")
    {
        return true;
    }
    return false;
}

int PKMN::string_to_int(const std::string& str)
{
    return StringToNumber<int>(str);
}

double PKMN::string_to_double(const std::string& str)
{
    return StringToNumber<double>(str);
}

std::string PKMN::int_to_string(int nb)
{
    return NumberToString(nb);
}

unsigned int PKMN::nb_of_nb(int nb)
{
    return static_cast<int>(floor(static_cast<double>(log10(nb)))) + 1;
}
