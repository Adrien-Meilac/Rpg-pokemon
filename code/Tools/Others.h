#ifndef OTHERS_H_INCLUDED
#define OTHERS_H_INCLUDED

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>

namespace std
{
template <typename _CharT, typename _Traits>
inline basic_ostream<_CharT, _Traits>&  tab(basic_ostream<_CharT, _Traits> &__os)
    /** \brief Allow to use std::tab for tabulation
     *
     * \param basic_ostream<_CharT, __os _Traits>&
     * \return basic_ostream<_CharT, _Traits>&
     *
     */
{
    return __os.put(__os.widen('\t'));
}
}


namespace PKMN
{
inline bool does_file_exist(std::string fileName)
    /** \brief Test to see if a file exists
     *
     * \param fileName std::string
     * \return bool
     *
     */
{
    std::ifstream infile(fileName.c_str());
    return infile.good();
}

}

#endif // OTHERS_H_INCLUDED
