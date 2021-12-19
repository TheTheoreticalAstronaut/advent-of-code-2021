#include "AoCProblem.h"

class Problem7 : public AoCProblem {
public:
	Problem7();

	virtual uint8_t getId() override { return 7; }

	virtual void loadData() override;

	virtual ret_t runPartOne() override;

	virtual ret_t runPartTwo() override;

private:
};
