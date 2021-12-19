#include "ResourceAllocator.h"
#include "Problem1.h"
#include "Problem2.h"
#include "Problem3.h"
#include "Problem4.h"
#include "Problem5.h"
#include "Problem6.h"
#include "Problem7.h"

ResourceAllocator::ResourceAllocator(){
    problems.push_back(std::make_unique<Problem1>());
    problems.push_back(std::make_unique<Problem2>());
    problems.push_back(std::make_unique<Problem3>());
    problems.push_back(std::make_unique<Problem4>());
    problems.push_back(std::make_unique<Problem5>());
    problems.push_back(std::make_unique<Problem6>());
    problems.push_back(std::make_unique<Problem7>());
}