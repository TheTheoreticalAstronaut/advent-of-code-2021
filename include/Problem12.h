#include "AoCProblem.h"

class Problem12 : public AoCProblem {
public:
	Problem12();

	virtual uint8_t getId() override { return 12; }

	virtual void loadData() override;

	virtual ret_t runPartOne() override;

	virtual ret_t runPartTwo() override;

private:
};
