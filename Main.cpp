#include "LCG.hpp"

#include <iostream>

int main() {
	LCG lcg;

	for(size_t i = 0; i < 1234; i++) {
		std::cout << lcg.Next(lcg.Next(), lcg.Next(), false) << std::endl;
	}

	return 0;
}