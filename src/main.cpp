#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "instructions.h"

int main(int argc, char **argv) {
	
	std::ifstream instructions;
  instructions.open ("build_instructions");
	
	std::string line;
	std::vector<std::string> lines;

	if (instructions.is_open())
  {
    while ( getline (instructions,line) )
    {
			//std::cout << line << '\n';
			lines.push_back(line);
    }
    instructions.close();
  }

	for ( std::string line : lines) {
		std::cout << line << "\n";
	}

	return 0;
}
