#include "AoCProblem.h"

class Problem9 : public AoCProblem {
public:
	Problem9();

	virtual uint8_t getId() override { return 9; }

	virtual void loadData() override;

	virtual ret_t runPartOne() override;

	virtual ret_t runPartTwo() override;

private:
};
