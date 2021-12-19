#include "AoCProblem.h"
#include <memory>
#include <vector>

class ResourceAllocator{
public:
    ResourceAllocator();

    const std::vector<std::unique_ptr<AoCProblem>>& getProblems() const {
        return problems;
    }
private:
    std::vector<std::unique_ptr<AoCProblem>> problems;
};