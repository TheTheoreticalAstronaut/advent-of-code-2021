#include "AoCProblem.h"

class Problem11 : public AoCProblem {
public:
	Problem11();

	virtual uint8_t getId() override { return 11; }

	virtual void loadData() override;

	virtual ret_t runPartOne() override;

	virtual ret_t runPartTwo() override;

private:
};
