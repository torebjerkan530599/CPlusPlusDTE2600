#include "header.h"

namespace ms
{
    namespace messageclient
    {
        bool criteriaMatcher(match::Criteria filter, Message const& message)
        {
            
            //The criteriaMatcher function is used to match a single message with a set of criteria.
        }
    }

    MessageClient::MessageClient(std::string owner)
    {
        static_assert(false, "Complete the code");
    }

    std::string const&
        MessageClient::owner() const
    {
        static_assert(false, "Complete the code");
    }

    void
        MessageClient::sendMessage(std::string to, MessageDate date, std::string message)
    {
        static_assert(false, "Complete the code");
    }

    Messages
        MessageClient::findMessages(MessageBoxType  where, match::Criteria filter) const
    {
        static_assert(false, "Complete the code");
    }

    void
        MessageClient::deleteMessages(MessageBoxType where, match::Criteria filter)
    {
        static_assert(false, "Complete the code");
    }

    void
        MessageClient::setSpamFilter(match::Criteria filter)
    {
        static_assert(false, "Complete the code");
    }

    void
        MessageClient::sync()
    {
        static_assert(false, "Complete the code");
    }

    MessageClient::MBoxConstIterators
        MessageClient::search(MessageBoxType where, match::Criteria filter) const
    {
        static_assert(false, "Complete the code");
    }

    MessageBox&
        MessageClient::messageBox(MessageBoxType which)
    {
        static_assert(false, "Complete the code");
    }

    MessageBox const&
        MessageClient::messageBox(MessageBoxType which) const
    {
        static_assert(false, "Complete the code");
    }

} // END namespace ms
