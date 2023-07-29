#include <iostream>
#include <fstream>

int main(int ac, char** av)
{
    if (ac == 4 || !*av[2])
    {
        std::string file = av[1];
        std::string find = av[2];
        std::string replace = av[3];
        std::string filecontent = "";
        std::string buffer;
		std::ifstream infile(file, std::ios::in);
        if (infile.is_open())
        {
			std::ofstream outfile(file + ".replace");
			while (getline(infile, buffer))
				filecontent = filecontent + buffer + "\n";
			size_t pos = filecontent.std::string::find(find);
			while (pos != std::string::npos)
			{
				filecontent.std::string::erase(pos, find.length());
				filecontent.std::string::insert(pos, replace);
				pos = filecontent.std::string::find(find);
			}
			outfile << filecontent;
			infile.close();
			outfile.close();
			return 0;
		}
        std::cerr << "cann`t open file for read\n";
		return 1;
    }
    std::cerr << "argument quontity error\n";
	return 1;
}
