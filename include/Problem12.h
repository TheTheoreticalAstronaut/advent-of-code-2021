#include "AoCProblem.h"
#include <map>
#include <string>

class Problem12 : public AoCProblem {
public:
	Problem12();

	virtual uint8_t getId() override { return 12; }

	virtual void loadData() override;

	virtual ret_t runPartOne() override;

	virtual ret_t runPartTwo() override;

private:
	struct Node {
		std::vector<std::string> neighbours;
		bool repeatable{false};
	};

	std::map<std::string, Node> nodes;

	void findPaths(ret_t& numPaths, std::vector<std::string>& path, const std::string& currentNode, const bool smallCaveVisited);
};
