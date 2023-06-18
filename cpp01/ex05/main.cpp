#include "Karen.hpp"

int main(void)
{
    Karen	karen;

    std::cout << "DEBUG" << std::endl;
	karen.complain("DEBUG");
    std::cout << "\n" << "INFO" << std::endl;
	karen.complain("INFO");
    std::cout << "\n" << "WARNING" << std::endl;
	karen.complain("WARNING");
    std::cout << "\n" << "ERROR" << std::endl;
	karen.complain("ERROR");
    std::cout << "\n" << "WRONG" << std::endl;
	karen.complain("WRONG");
	return (0);
}