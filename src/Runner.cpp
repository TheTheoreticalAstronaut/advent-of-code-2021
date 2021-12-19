#include <iostream>
#include "ResourceAllocator.h"

int main(){
	ResourceAllocator resAlloc;
	const auto& problems = resAlloc.getProblems();
	for(const auto& problem : problems){
		std::cout << "Problem " << +problem->getId() << "\n";
		std::cout << "Part #1 = " << problem->runPartOne() << "\n";
		std::cout << "Part #2 = " << problem->runPartTwo() << "\n";
		std::cout << "\n";
	}
	return 0;
}
