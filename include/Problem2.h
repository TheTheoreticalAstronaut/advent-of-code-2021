#include "AoCProblem.h"
#include <string>

class Problem2 : public AoCProblem {

public:
	Problem2();

	virtual uint8_t getId() override { return 2; }

	virtual void loadData() override;

	virtual ret_t runPartOne() override;

	virtual ret_t runPartTwo() override;

private:
	std::vector<std::pair<std::string, uint32_t>> data;
};
