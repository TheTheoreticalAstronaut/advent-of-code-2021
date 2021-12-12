#include <iostream>
#include "Problem1.h"
#include "Problem2.h"
#include "Problem3.h"
#include "Problem4.h"

int main(){
	Problem1 problem1;
	std::cout << "Problem 1\n";
	std::cout << "Part #1 = " << problem1.runPartOne() << "\n";
	std::cout << "Part #2 = " << problem1.runPartTwo() << "\n\n";

	Problem2 problem2;
	std::cout << "Problem 2\n";
	std::cout << "Part #1 = " << problem2.runPartOne() << "\n";
	std::cout << "Part #2 = " << problem2.runPartTwo() << "\n\n";

	Problem3 problem3;
	std::cout << "Problem 3\n";
	std::cout << "Part #1 = " << problem3.runPartOne() << "\n";
	std::cout << "Part #2 = " << problem3.runPartTwo() << "\n\n";

	Problem4 problem4;
	std::cout << "Problem 4\n";
	std::cout << "Part #1 = " << problem4.runPartOne() << "\n";
	std::cout << "Part #2 = " << problem4.runPartTwo() << "\n\n";

	return 0;
}
