// Include needed standard library functions (STL)
#include <iostream>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <utility>
#include "header.h"

// The <signature> function definition
// Sort with respect to |a| < |b|
void sortIntsOne(std::vector<int>& data) {

    auto pred = [](auto a, auto b)
    {
        return a < b;
    };
    
    std::sort(data.begin(), data.end(), pred);
}

// Sort with respect to |-a| < |-b|
void sortIntsTwo(std::vector<int>& data) {

    auto pred = [](auto a, auto b)
    {

        return std::abs(a) < std::abs(b);
            
    };
    
    std::sort(data.begin(), data.end(), pred);
}

// sort with respect to a^exp > b^exp
void sortIntsThree(std::vector<int>& data, int exp)
{
    auto pred = [exp](auto a, auto b)
    {
        return std::pow(a, exp) > std::pow(b, exp);
    };
    
    std::sort(data.begin(), data.end(), pred);
}

// sort with respect to a^2 > b^2
// return the overall minimum and maximum value of (a^2)
void sortIntsFour(std::vector<int>& data, int& min, int& max)
{
    min = std::numeric_limits<int>::max();
    max = std::numeric_limits<int>::min();

    auto pred = [&min, &max](int a, int b)
    {
        int a2 = pow(a, 2);
        int b2 = pow(b, 2);

        //update min and max
        min = std::min(a2, min);
        max = std::max(a2, max);

        return a2 > b2;
     
    };
    
    std::sort(data.begin(), data.end(), pred);

    //for debugging purposes
    //for (auto& t : data)
    //{
    //    std::cout << t << std::endl;
    //}
}

// Sort with respect to a < b. Return a pair containing the mean and
// median of the sorted range.
std::pair<int, int> sortIntsMeanAndMedian(std::vector<int>& data) {

    auto pred = [](int a, int b)
    {
        return a < b;
    };
    std::sort(data.begin(), data.end(), pred);

    // mean;
    int mean = 0;/* complete the code */
    
    for (auto it = begin(data); it != end(data); ++it)
    {
        mean += *it;
    }

    mean = mean / int(data.size());
    
    // median;
    int median = data[(data.size() + 1) / 2];; /* complete the code */

    return { mean, median };
}

// Sort the people by name or year of birth in ascending or descending order
void sortPeople(std::vector<Person>& people, SortOrder order, SortBy sort_by) {

    auto pred = [order, sort_by](auto const& p1_in, auto const& p2_in)
    {
       
        if (order == SortOrder::Asc)
        { 
            if (sort_by == SortBy::Name)
            {
                return p1_in.name < p2_in.name;
            }
            if (sort_by == SortBy::YearOfBirth)
            {
                return p1_in.year_of_birth < p2_in.year_of_birth;
            }
        } 
        else if (order == SortOrder::Dsc)
        {
            if (sort_by == SortBy::Name)
            {
                return p1_in.name > p2_in.name;
            }
            if (sort_by == SortBy::YearOfBirth)
            {
                return p1_in.year_of_birth > p2_in.year_of_birth;
            }
        } 
        else
        { 
        
            return p1_in.name == p2_in.name || p1_in.year_of_birth == p2_in.year_of_birth;
        }
    };
    
    std::sort(people.begin(), people.end(), pred);

    //for debugging purposes
    for (auto& p : people)
    {
        if (sort_by == SortBy::Name)
        { 
            std::cout << p.name << std::endl;
        }
        else
        {
            std::cout << p.year_of_birth << std::endl;
        }
    }
}
