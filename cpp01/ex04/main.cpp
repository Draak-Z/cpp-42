#include <iostream>
#include <fstream>
#include <string>

int	error(const char *msg)
{
	std::cout << msg << std::endl;
	return(1);
}

int main(int argc, char *argv[])
{
	std::string newName;
	std::string buffer;
	std::string line;
	std::string s1;
	size_t		pos;

	if (argc != 4)
		return (error("Wrong number of params. First param is filename, second param is s1 and third param is s2."));
	s1 = argv[2];
	std::ifstream in_file(argv[1]);
	if (in_file.is_open())
	{
		while (std::getline(in_file, line))
			buffer = buffer + line + "\n";
		if ((pos = buffer.rfind("\n")) != std::string::npos)
			buffer.erase(pos, 1);
		in_file.close();
		newName = argv[1];
		newName.append(".replace");
		const char *nn = newName.c_str();
		std::ofstream out_file(nn);
		pos = 0;
		while ((pos = buffer.find(s1, pos)) != std::string::npos)
		{
			buffer.erase(pos, s1.length());
			buffer.insert(pos, argv[3]);
			pos++;
		}
		out_file << buffer;
	}
	else
		return (error("File does not exist or permission denied."));
	return (0);
}