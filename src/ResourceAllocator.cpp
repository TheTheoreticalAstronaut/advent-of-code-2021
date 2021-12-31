#include "ResourceAllocator.h"
#include "Problem1.h"
#include "Problem2.h"
#include "Problem3.h"
#include "Problem4.h"
#include "Problem5.h"
#include "Problem6.h"
#include "Problem7.h"
#include "Problem8.h"
#include "Problem9.h"
#include "Problem10.h"
#include "Problem11.h"
#include "Problem12.h"
#include "Problem13.h"
#include "Problem14.h"
#include "Problem15.h"

ResourceAllocator::ResourceAllocator(){
    problems.push_back(std::make_unique<Problem1>());
    problems.push_back(std::make_unique<Problem2>());
    problems.push_back(std::make_unique<Problem3>());
    problems.push_back(std::make_unique<Problem4>());
    problems.push_back(std::make_unique<Problem5>());
    problems.push_back(std::make_unique<Problem6>());
    problems.push_back(std::make_unique<Problem7>());
    problems.push_back(std::make_unique<Problem8>());
    problems.push_back(std::make_unique<Problem9>());
    problems.push_back(std::make_unique<Problem10>());
    problems.push_back(std::make_unique<Problem11>());
    problems.push_back(std::make_unique<Problem12>());
    problems.push_back(std::make_unique<Problem13>());
    problems.push_back(std::make_unique<Problem14>());
    problems.push_back(std::make_unique<Problem15>());
}