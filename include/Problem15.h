#include "AoCProblem.h"

class Problem15 : public AoCProblem {
public:
	Problem15();

	virtual uint8_t getId() override { return 15; }

	virtual void loadData() override;

	virtual ret_t runPartOne() override;

	virtual ret_t runPartTwo() override;

private:
};
