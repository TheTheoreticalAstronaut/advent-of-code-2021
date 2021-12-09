#ifndef AOCPROBLEM_H
#define AOCPROBLEM_H

#include <cstdint>

class AoCProblem{

public:
	virtual ~AoCProblem(){}

	virtual void loadData() = 0;

	virtual uint32_t runPartOne() = 0;

	virtual uint32_t runPartTwo() = 0;
};

#endif /* AOCPROBLEM_H */
