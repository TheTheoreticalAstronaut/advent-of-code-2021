#ifndef AOCPROBLEM_H
#define AOCPROBLEM_H

#include <cstdint>

using ret_t = uint64_t;

class AoCProblem{

public:
	virtual ~AoCProblem(){}

	virtual uint8_t getId() = 0;

	virtual void loadData() = 0;

	virtual ret_t runPartOne() = 0;

	virtual ret_t runPartTwo() = 0;
};

#endif /* AOCPROBLEM_H */
