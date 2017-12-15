#include "Conversion.h"

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
    int number = 0;
    const unsigned int length = str.size();
    if(length > 0 && str[0] == '-')
    {
        for(unsigned int i = 1; i < length; i++)
        {
            number *= 10;
            number += static_cast<int>(str[i]) - static_cast<int>('0');
        }
        return - number;
    }
    else
    {
        for(unsigned int i = 0; i < length; i++)
        {
            number *= 10;
            number += static_cast<int>(str[i]) - static_cast<int>('0');
        }
        return number;
    }
}

double PKMN::string_to_double(const std::string& str)
{
    const unsigned int length = str.size();
    for(unsigned int i = 0; i < length; i++)
    {
        if(str[i] == '.')
        {
            std::string str1(""), str2("");
            for(unsigned int j = 0; j < i; j++)
            {
                str1 += str[j];
            }
            for(unsigned int j = i + 1; j < length; j++)
            {
                str2 += str[j];
            }
            int nb1 = string_to_int(str1);
            int nb2 = string_to_int(str2);
            return nb1 + nb2 / pow(10, length - i - 1);
        }
    }
    return 0;
}

std::string PKMN::int_to_string(int nb)
{
    std::string str = "";
    int a;
    char b;
    std::string sign = "";
    if(nb == 0)
    {
        return "0";
    }
    else if(nb < 0)
    {
        sign = "-";// not working
        nb = - nb;
    }
    for(int i = PKMN::nb_of_nb(nb) - 1; i >= 0; i-= 1)
    {
        a = static_cast<int>(floor(nb / pow(10,i)));
        b = static_cast<char>(a + static_cast<int>('0'));
        str += b;
        nb -= static_cast<int>(a * pow(10,i));
    }
    return sign + str;
}

unsigned int PKMN::nb_of_nb(int nb)
{
    return static_cast<int>(floor(static_cast<double>(log10(nb)))) + 1;
}
