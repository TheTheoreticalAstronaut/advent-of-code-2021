#include "AoCProblem.h"
#include <vector>

class Problem1 : public AoCProblem {

public:
	Problem1();

	virtual void loadData() override;

	virtual uint32_t runPartOne() override;

	virtual uint32_t runPartTwo() override;

private:
	std::vector<uint32_t> data;
};
