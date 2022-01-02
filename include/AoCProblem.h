#ifndef AOCPROBLEM_H
#define AOCPROBLEM_H

#include <cstdint>
#include <vector>

using ret_t = uint64_t;

template<typename T>
using matrix_t = std::vector<std::vector<T>>;

class AoCProblem{

public:
	virtual ~AoCProblem(){}

	virtual uint8_t getId() = 0;

	virtual void loadData() = 0;

	virtual ret_t runPartOne() = 0;

	virtual ret_t runPartTwo() = 0;
};

#endif /* AOCPROBLEM_H */
