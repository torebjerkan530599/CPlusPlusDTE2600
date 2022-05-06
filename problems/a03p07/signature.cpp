#include "header.h"
#include <limits>

// The <signature> function definition(s)
std::string toString(Record const& rec) {

    // Using structured binding to bind local aliases to the every member of the Record object rec.
    // Bound as constant references
    auto const& [name, age] = rec;

    // Return a string on the format: "Name: [name] - Age: [age]", withouth the brackets


    return "Name: " + name + "  - Age: " + std::to_string(age);
}

void resetAge(std::vector<Record>& records) {

    // Using structured binding to bind local aliases to the every member of the Record object rec.
    // Bound as references
    for (auto& [name, age] : records) {

        age = 0;// <-- Reset each age to 0.
    }
}

Record getOldestAndAnonymizeInput(std::vector<std::tuple<std::string, int>>& records, std::string const& p_anon_name) {

    // Initial 'oldest' record
    Record oldest{ "hmm", std::numeric_limits<int>::min() }; //Får error beskjed om at denne ikke har blitt initializert enda. 
    // TEST: Record oldest{ "hmm", 5}; <--- ingen error her...

    std::string name;
    int age;
    for (auto itr = records.begin(); itr != records.end(); ++itr)
    {
        std::tie(name, age) = *itr;

        if(age > oldest.age)
        { 
            oldest.name = name;// <-- If older: save original name and age to oldest record
            oldest.age = age;
        }

        int index = std::distance(records.begin(), itr);
        records[index] = { p_anon_name, age };

        std::get<0>(*itr) = p_anon_name;
        
    }

    return oldest;
}
