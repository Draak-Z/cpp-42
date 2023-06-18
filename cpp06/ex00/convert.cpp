#include <string>
#include <iostream>
#include <climits>
#include <limits>
#include <cmath>
#include <iomanip>
#include <cerrno>

bool	is_char(std::string const & str);
bool	is_int(std::string const & str);
bool	is_float(std::string const & str);
bool	is_double(std::string const & str);

bool    convert_char(std::string const &str)
{
    std::cout << "char: " << str[0] << std::endl;
    std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
    std::cout << "float: " << static_cast<float>(str[0]) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(str[0]) << ".0" << std::endl;
    return (true);
}

bool    convert_int(std::string const &str)
{
	long long	l = strtol(str.data(), NULL, 10);
    bool        b = false;

    if (l > CHAR_MAX || l < CHAR_MIN)
        std::cout << "char: Non displayable" << std::endl;
    else if (!isprint(static_cast<char>(l)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: " << static_cast<char>(l) << std::endl;
    if (l > INT_MAX || l < INT_MIN)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << l << std::endl;
    double  d = strtod(str.data(), NULL);
    if (errno == ERANGE)
        b = true;
    if (d < -999999 || d > 999999  || d > std::numeric_limits<float>::max() || d <= -std::numeric_limits<float>::max())
        std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
    else
        std::cout << "float: " << static_cast<float>(d) << ".0f" << std::endl;
    if (b)
        std::cout << "double: " << d << std::endl;
    else if (d < -999999 || d > 999999)
        std::cout << "double: " << d << std::endl;
    else
        std::cout << "double: " << d << ".0" << std::endl;
    return (true);
}

bool	convert_float(std::string const & str)
{
    const std::string nan = "nanf", inf = "inff", pinf = "+inff", minf = "-inff";

    if (str == nan || str == inf || str == pinf || str == minf)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << str << std::endl;
        std::cout << "double: " << str.substr(0, str.length() - 1) << std::endl;
        return (true);
    }
    double	d = strtod(str.data(), NULL);
    if (static_cast<int>(d) > CHAR_MAX || static_cast<int>(d) < CHAR_MIN)
        std::cout << "char: Non displayable" << std::endl;
    else if (!isprint(static_cast<char>(d)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: " << static_cast<char>(d) << std::endl;
    if (static_cast<long>(d) > INT_MAX || static_cast<long>(d) < INT_MIN)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;
    if (fmod(d, 1) || d < -999999 || d > 999999)
    {
        std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
    }
    else
    {
        std::cout << "float: " << static_cast<float>(d) << ".0f" << std::endl;
	    std::cout << "double: " << d << ".0" << std::endl;
    }
	return (true);
}

bool	convert_double(std::string const & str)
{
    const std::string nan = "nan", inf = "inf", pinf = "+inf", minf = "-inf";

    if (str == nan || str == inf || str == pinf || str == minf)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << str << "f" << std::endl;
        std::cout << "double: " << str << std::endl;
        return (true);
    }
    double	d = strtod(str.data(), NULL);
    if (static_cast<int>(d) > CHAR_MAX || static_cast<int>(d) < CHAR_MIN)
        std::cout << "char: Non displayable" << std::endl;
    else if (!isprint(static_cast<char>(d)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: " << static_cast<char>(d) << std::endl;
    if (static_cast<long>(d) > INT_MAX || static_cast<long>(d) < INT_MIN)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;
    if (fmod(d, 1) || d < -999999 || d > 999999 || d > std::numeric_limits<float>::max() || d <= -std::numeric_limits<float>::max())
    {
        std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
    }
    else
    {
        std::cout << "float: " << static_cast<float>(d) << ".0f" << std::endl;
	    std::cout << "double: " << d << ".0" << std::endl;
    }
	return (true);
}

bool    convert(std::string const &str)
{
    if (is_char(str))
        return (convert_char(str));
    else if (is_int(str))
        return (convert_int(str));
    else if (is_float(str))
        return (convert_float(str));
    else if (is_double(str))
        return (convert_double(str));
    else
        std::cout << "Error: Bad argument" << std::endl;
    return (false);
}