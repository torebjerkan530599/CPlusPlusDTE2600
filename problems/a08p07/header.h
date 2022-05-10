#include <vector>
#include <optional>

#ifndef HEADER_H
#define HEADER_H

// Include needed standard library functions (STL)

struct MessageHeader {
    std::string from;
    std::string to;
    std::string subject;

    friend std::ostream& operator<<(std::ostream& stream,
        MessageHeader const& header)
    {
        stream << "from: " << header.from << ", to: " << header.to
            << ", subject: " << header.subject;
        return stream;
    }
};


using MailHeaders = std::vector<MessageHeader>;

enum class SortCriteria { ByReceiver, BySender, BySubject };
using SortCriterion = std::optional<SortCriteria>;

void sortMailBy(MailHeaders& mail, SortCriterion lvl1, SortCriterion lvl2,
    SortCriterion lvl3) noexcept;

#endif // HEADER_H
