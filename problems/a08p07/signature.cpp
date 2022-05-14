#include "header.h"
#include <string>
#include <algorithm>
//#include <optional>

void sortMailBy(MailHeaders& mail, SortCriterion lvl1, SortCriterion lvl2,
    SortCriterion lvl3) noexcept
{

    // Lvl Projections
    auto const proj_hlpr = [](MessageHeader const& header, SortCriterion crit) -> std::string
    {
        switch (crit.value()) {
            case SortCriteria::BySender:
                return header.from;
            case SortCriteria::ByReceiver:
                return header.to;
            default:
                return header.subject;
        }
    };
    auto const lvl1_proj = [proj_hlpr, lvl1](MessageHeader const& header) {
        return proj_hlpr(header, lvl1);
    };
    auto const lvl2_proj = [proj_hlpr, lvl2](MessageHeader const& header) {
        return proj_hlpr(header, lvl2);
    };
    auto const lvl3_proj = [proj_hlpr, lvl3](MessageHeader const& header) {
        return proj_hlpr(header, lvl3);
    };

    // Lvl sort comparators
    auto const lvl1_comp = [](auto const& lhs, auto const& rhs) 
    { 
        //bool test = lhs < rhs;
        return lhs < rhs; 
    };
    auto const lvl2_comp = [](auto const& lhs, auto const& rhs) 
    { 
        return lhs < rhs; 
    };
    auto const lvl3_comp = [](auto const& lhs, auto const& rhs) 
    { 
        return lhs < rhs; 
    };

    // Sort mail by lvl1, then lvl2, and then finally lvl3
    namespace sr = std::ranges;
    
    if (lvl3.has_value())
        sr::sort(mail, lvl3_comp, lvl3_proj);

    if (lvl2.has_value())
        sr::sort(mail, lvl2_comp, lvl2_proj);

    if (lvl1.has_value())
        sr::sort(mail, lvl1_comp, lvl1_proj);
    //else
    //    lvl1 = nullopt;
}
