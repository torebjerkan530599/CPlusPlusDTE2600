#include "header.h"
#include <iostream>
#include <ranges>
#include <algorithm>

// Include needed standard library functions

namespace sr = std::ranges;
namespace sv = std::views;
SortCriterion loadSortCriterion(std::istream& stream, int no_criterias,
    int criterion_nr)
{
    if (criterion_nr > no_criterias) return std::nullopt;

    using namespace std::literals;

   /* std::string str_crit;
    std::cin >> str_crit;*/

    std::string str_crit;
    stream >> str_crit;

    if (str_crit == "reciever"sv)
        return SortCriteria::ByReceiver;
    else if (str_crit == "sender"sv)
        return SortCriteria::BySender;
    else if (str_crit == "subject"sv)
        return SortCriteria::BySubject;

    return {};
}


/******
 * Main
 */

 // The main function is the entry point for any program written in C++
int main(int /*argc*/, char** /*argv*/)
{
    int no_messages;
    std::cin >> no_messages;

    // Load mail headers from standard in
    MailHeaders mail;
    mail.reserve(no_messages);
    sr::for_each(sv::iota(0, no_messages), [&](auto const&) {
        MessageHeader msg;
        std::cin >> msg.from >> msg.to >> msg.subject;
        mail.emplace_back(msg);
        });

    // Load sort criteria from standard in
    int no_criterias;
    std::cin >> no_criterias;
    SortCriterion lvl1 = loadSortCriterion(std::cin, no_criterias, 1);
    SortCriterion lvl2 = loadSortCriterion(std::cin, no_criterias, 2);
    SortCriterion lvl3 = loadSortCriterion(std::cin, no_criterias, 3);

    // Sort mail by lvl1, [lvl2], and [lvl3]
    sortMailBy(mail, lvl1, lvl2, lvl3);

    // Print mail header to standard out
    sr::copy(mail, std::ostream_iterator<MessageHeader>(std::cout, "\n"));

    // Return the value Zero to the operating system
    // Indicating that your program terminated successfully without sideeffects
    return 0;
}
