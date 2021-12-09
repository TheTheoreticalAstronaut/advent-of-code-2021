#include "AoCProblem.h"
#include <vector>
#include <string>

class Problem2 : public AoCProblem {

public:
	Problem2();

	virtual void loadData() override;

	virtual uint32_t runPartOne() override;

	virtual uint32_t runPartTwo() override;

private:
	std::vector<std::pair<std::string, uint32_t>> data;
};
