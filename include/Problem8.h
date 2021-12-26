#include "AoCProblem.h"
#include <vector>
#include <string>

class Problem8 : public AoCProblem {
public:
	Problem8();

	virtual uint8_t getId() override { return 8; }

	virtual void loadData() override;

	virtual ret_t runPartOne() override;

	virtual ret_t runPartTwo() override;

private:
	struct Entry{
		std::vector<std::string> segments;
		std::vector<std::string> digits;
	};
	std::vector<Entry> entries;

	uint32_t processSizeFive(const std::string& code, const std::string& codeOfOne, const std::string& codeOfFour) const;
	uint32_t processSizeSix(const std::string& code, const std::string& codeOfOne, const std::string& codeOfFour) const;
	uint32_t numberOfMatchingChars(const std::string& str0, const std::string& str1) const;
};
