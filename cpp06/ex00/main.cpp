#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <limits>

#include <string>
#include <cctype>
#include <cstdlib>

bool  convert(std::string const &str);

int main(int argc, char **argv)
{
  std::string arg;

  if (argc != 2)
  {
    std::cerr << "Error: wrong numbers of arguments" << std::endl;
    return (1);
  }
  arg = argv[1];
  if (arg.empty())
  {
    std::cerr << "Error: the argument is empty." << std::endl;
    return (1);
  }
  convert(arg);
  return (0);
}