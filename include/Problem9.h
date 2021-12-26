#include "AoCProblem.h"
#include <vector>

using matrix_t = std::vector<std::vector<uint8_t>>;
using pair_t = std::pair<uint32_t, uint32_t>;

class Problem9 : public AoCProblem {
public:
	Problem9();

	virtual uint8_t getId() override { return 9; }

	virtual void loadData() override;

	virtual ret_t runPartOne() override;

	virtual ret_t runPartTwo() override;

private:
	matrix_t heightMap;

	std::vector<pair_t> findMinima() const;
};
