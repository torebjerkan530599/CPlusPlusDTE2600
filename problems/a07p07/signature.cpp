#include "header.h"
#include <algorithm>
#include <iostream>

std::size_t NameHasher::operator()(Name const& name) const noexcept
{
    //std::hash<std::string> hash_obj;
    //size_t myhash = hash_obj(name.m_name);
    //std::cout << "String hash values: "
    //    << myhash
    //    << std::endl;
    
    return std::hash<std::string>{}(name.m_name);
}

OrderedNameMap countNames01(std::forward_list<Name> const& names)
{
    OrderedNameMap myMap;

    for (auto& name : names)
    { 
        if(myMap.contains(name.toString()))
            myMap[name]++;
        else
            myMap.insert(std::pair<Name, int>(name.toString(), 1));
    }

    return myMap;
}

UnorderedNameMap countNames02(std::forward_list<Name> const& names)
{
    UnorderedNameMap name_map;

    for (auto& name : names)
    {
        if (name_map.contains(name.toString()))
            name_map[name]++;
        else
            name_map.insert(std::pair<Name, int>(name.toString(), 1));
    }

    return name_map;
}

//using NameInfoMap = std::unordered_map<std::string, Info>;
//
//std::string      idToString(size_t id, std::vector<Name> const& names,
//    NameInfoMap const& info);
//
//struct Info {
//    int age;
//};
//
//class Name {
//    std::string m_name;
//
//    friend class NameHasher;
//}

//for (auto itr = std::begin(names); itr != std::end(names); itr++)
     //size_t dist = std::distance(std::begin(names), itr);

        //bool id_out_of_bounds = id < ???? && id > ????; //if the id is out of bounds , return "n/a"...

        //...OR...if the id's associated name has no associated age, return the string: "n/a") 

std::string idToString(size_t id, std::vector<Name> const& names,
    NameInfoMap const& info)
{
    std::string id_name_age = "";

    if (id >= 0 && id < names.size())
    {
        auto& name = names.at(id);

        if (info.contains(name.toString()))
        { 
          Info info_obj = info.at(name.toString());
          id_name_age = std::to_string(id) + " " + name.toString() + " " + std::to_string(info_obj.age);
        }
        else
            id_name_age = "n/a";
    }
    else
        id_name_age = "n/a";

    return id_name_age;
}
