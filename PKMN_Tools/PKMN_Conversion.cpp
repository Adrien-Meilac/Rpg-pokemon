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

double string_to_double(const std::string& str)
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
            std::cout << nb1;
            std::cout << nb2 << std::endl;
            return nb1 + nb2 / pow(10, length - i - 1);
        }
    }
    return 0;
}
