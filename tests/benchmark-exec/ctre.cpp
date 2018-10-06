#include <cstdio>
#include <iostream>
#include <fstream> 
#include <regex>
#include "ctre.hpp"

int main (int argc, char ** argv)
{
	using namespace ctre::literals;
	constexpr auto re = "ABCD|DEFGH|EFGHI|A{4,}"_ctre;

	auto grep = [&](auto && stream) {
		std::string line;
		while (std::getline(stream, line)) {
			if (bool(re.search(line))) {
				std::cout << line << '\n';
			}
		}
	}; 
	
	if (argc == 1) {
		grep(std::cin);
	} else for (int i = 1; i < argc; ++i) {
		std::string fname{std::string(argv[i])};
		grep(std::ifstream(fname, std::ifstream::in));
	}
}

