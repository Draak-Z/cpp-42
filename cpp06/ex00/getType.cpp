#include <string>
#include <iostream>
#include <cerrno>
#include <cstdlib>
#include <limits>

bool    is_char(std::string const &str)
{
    if (str.length() == 1 && isprint(str[0]) && !isdigit(str[0]))
        return (true);
    return (false);
}

bool    is_int(std::string const &str)
{
    if (!isdigit(str[0]) && str[0] != '-' && str[0] != '+')
        return (false);
    for (unsigned long i = 0; i < str.length(); i++)
    {
        if (!isprint(str[i]))
            return (false);
        if (!isdigit(str[i]) && i != 0)
            return (false);
    }
    return (true);
}

bool    is_float(std::string const &str)
{
    size_t i = 0;
    size_t len = str.length() - 1;

    if (!(str.compare("-inff")) || !(str.compare("+inff")) || !(str.compare("inff")) || !(str.compare("nanf")))
        return (true);
    if (!(str.compare(".f")) || !(str.compare("-.f")))
        return (false);
    if (str.find('.') == std::string::npos || (str.find('.') != str.rfind('.')) || str.find('.') == len)
        return (false);
    if (str.find('f') == std::string::npos || (str.find('f') != str.rfind('f')) || str.find('f') != len)
        return (false);
    if (!isprint(str[0]) || (!isdigit(str[0]) && str[0] != '-' && str[0] != '+' && str[0] != '.'))
        return (false);
    while (++i < len)
        if (!isprint(str[i]) || (!isdigit(str[i]) && str[i] != '.'))
            return (false);
    double	d = strtod(str.data(), NULL);
    if (d != 0 && (errno == ERANGE || d <= -std::numeric_limits<float>::max() || d > std::numeric_limits<float>::max()))
    	return (false);
    return (true);
}

bool    is_double(std::string const &str)
{
    size_t i = 0;
    size_t len = str.length() - 1;

    if (!(str.compare("-inf")) || !(str.compare("+inf")) || !(str.compare("inf")) || !(str.compare("nan")))
        return (true);
    if (!(str.compare(".f")) || !(str.compare("-.f")))
        return (false);
    if (str.find('.') == std::string::npos || (str.find('.') != str.rfind('.')))
        return (false);
    if (!isprint(str[0]) || (!isdigit(str[0]) && str[0] != '-' && str[0] != '+' && str[0] != '.'))
        return (false);
    while (++i < len)
        if (!isprint(str[i]) || (!isdigit(str[i]) && str[i] != '.'))
            return (false);
    return (true);
}