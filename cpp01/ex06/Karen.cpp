#include "Karen.hpp"

Karen::Karen(void)
{
    return ;
}

Karen::~Karen(void)
{
    return ;
}

void    Karen::complain(std::string level)
{
    int i = 0;
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	while (i < 4 && level.compare(levels[i]))
		i++;
    switch (i)
    {
        case 0:
            _debug();
            _info();
            _warning();
            _error();
            break ;
        case 1:
            _info();
            _warning();
            _error();
            break ;
        case 2:
            _warning();
            _error();
            break ;
        case 3:
            _error();
            break ;
        default:
            _other();
    }
}

void    Karen::_debug(void)
{
    std::cout << "[DEBUG]" << std::endl;
    std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
    std::cout << std::endl;
}

void    Karen::_info(void)
{
    std::cout << "[INFO]" << std::endl;
    std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
    std::cout << std::endl;
}

void    Karen::_warning(void)
{
    std::cout << "[WARNING]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
    std::cout << std::endl;
}

void    Karen::_error(void)
{
    std::cout << "[ERROR]" << std::endl;
    std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
    std::cout << std::endl;
}

void Karen::_other( void )
{
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    std::cout << std::endl;
}