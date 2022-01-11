#include "AoCProblem.h"
#include <set>

class Problem13 : public AoCProblem {
public:
	Problem13();

	virtual uint8_t getId() override { return 13; }

	virtual void loadData() override;

	virtual ret_t runPartOne() override;

	virtual ret_t runPartTwo() override;

private:
	struct Fold {
		Fold(bool _horizontal, uint32_t _value) : horizontal{_horizontal}, value{_value} {}
		bool horizontal;
		uint32_t value;
	};
	using coords_t = std::pair<uint32_t, uint32_t>;

	std::set<coords_t> originalPoints;
	std::vector<Fold> folds;

	std::set<coords_t> foldPoints(const Fold& fold, const std::set<coords_t>& points) const;
	ret_t printCode(const std::set<coords_t>& points) const;
};
