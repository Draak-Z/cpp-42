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
    void (Karen::*f[5])(void) = {&Karen::_debug, &Karen::_info, &Karen::_warning, &Karen::_error, &Karen::_wrong_param};
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	while (i < 4 && level.compare(levels[i]))
		i++;
	(this->*f[i])();

}

void    Karen::_debug(void)
{
    std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
}

void    Karen::_info(void)
{
    std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void    Karen::_warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
}

void    Karen::_error(void)
{
    std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void Karen::_wrong_param( void )
{

}