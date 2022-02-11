#include <iostream>
#include "ResourceAllocator.h"

int main(int argc, char** argv){
	ResourceAllocator resAlloc;
	if(argc < 2) resAlloc.addAllProblems();
	else for(int arg=1; arg<argc; arg++) resAlloc.addProblem(atoi(argv[arg]));

	const auto& problems = resAlloc.getProblems();
	for(const auto& problem : problems){
		std::cout << "Problem " << +problem->getId() << "\n";
		std::cout << "Part #1 = " << problem->runPartOne() << "\n";
		std::cout << "Part #2 = " << problem->runPartTwo() << "\n";
		std::cout << "\n";
	}
	return 0;
}
