#include <iostream>
#include "Problem1.h"
#include "Problem2.h"

int main(){
	Problem1 problem1;
	std::cout << "Problem 1\n";
	std::cout << "Part #1 = " << problem1.runPartOne() << "\n";
	std::cout << "Part #2 = " << problem1.runPartTwo() << "\n\n";

	Problem2 problem2;
	std::cout << "Problem 2\n";
	std::cout << "Part #1 = " << problem2.runPartOne() << "\n";
	std::cout << "Part #2 = " << problem2.runPartTwo() << "\n\n";

	return 0;
}
