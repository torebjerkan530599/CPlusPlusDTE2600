#include "header.h"
#include <iomanip>
#include <iostream>
#include <variant>
#include <vector>
#include <typeinfo>
#include <type_traits>
#include <string>
#include <algorithm>

namespace sr = std::ranges;

namespace ms
{
    //backend::MessageBackendSimulator sim; //I included this
    namespace messageclient
    {
        bool criteriaMatcher(match::Criteria filter, Message const& message)
        {
            for (auto itr = std::cbegin(filter); itr != std::cend(filter); ++itr)
            {
                /* if constexpr(std::is_same<match::Criteria, Message>::value) //alternative*/
                if (std::holds_alternative<match::From>(*itr))
                { 
                    if (std::get<match::From>(*itr) != message.from)
                        return false;
                }
                
                else if (std::holds_alternative<match::To>(*itr))
                { 
                    if (std::get<match::To>(*itr) != message.to)
                        return false;
                }
                
                else if (std::holds_alternative<match::DateInterval>(*itr))
                { 
                    const auto& crit_date = std::get<match::DateInterval>(*itr);
                    const auto crit_from = std::chrono::year_month_day(crit_date.from);
                    const auto crit_to = std::chrono::year_month_day(crit_date.to);
                    const auto msg_date = std::chrono::year_month_day(message.date);

                    if (msg_date < crit_from || msg_date > crit_to)
                        return false;
                }
                
                else if (std::holds_alternative<match::InMessage>(*itr))
                { 
                    if (std::get<match::InMessage>(*itr) != message.message)
                        return false;
                }
            }
            return true; //for-loop completes, meaing every criteria matches
        }
    }

    MessageClient::MessageClient(std::string owner)
    {
        m_owner = owner;
    }

    std::string const&
        MessageClient::owner() const
    {
        return m_owner;
    }

    void MessageClient::sendMessage(std::string to, MessageDate date, std::string message)
    {
        Message msg {m_owner, to, date, message};
        MessageBox& msgBox = messageBox(MessageBoxType::Outbox);
        msgBox.push_back(msg);
    }

    MessageBox& MessageClient::messageBox(MessageBoxType which)
    {
        return m_messageboxes.at(which);
    }

    MessageBox const& MessageClient::messageBox(MessageBoxType which) const
    {
        return m_messageboxes.at(which);
    }



    //Messages MessageClient::findMessages(MessageBoxType  where, match::Criteria filter) const
    //{
    //    // ...
    //    auto result = search(where, filter);
    //   
    //    // ...
    //}
    /**/
    void MessageClient::deleteMessages(MessageBoxType where, match::Criteria filter)
    {
        //static_assert(false, "Complete the code");
    }

    void MessageClient::setSpamFilter(match::Criteria filter)
    {
        //static_assert(false, "Complete the code");
    }

    //void MessageClient::sync()
    //{
    //    // Instantiate an instance of the backend

    //    auto backend_wp = backend::MessageBackendSimulator::instance();
    //    auto backend = backend_wp.lock();
    //    // ...

    //    //hva er riktig her da?
    //    // Retrieve all messages currently in the backend
    //    auto msgs1 = backend.get()->retrieveMessages();
    //    //auto msgs2 = backend_wp.get()->retrieveMessages(); //get() is not working

    //    // ms::backend::MessageBackendSimulator sim; //I included this at the top
    //    Messages msgs = sim.retrieveMessages();

    //    
    //    // Send one or several messages
    //    //backend.sendMessage(...);
    //    //backend.sendMessages(...);
    //}

    MessageClient::MBoxConstIterators MessageClient::search(MessageBoxType where, match::Criteria filter) const
    {
        auto const& mbox = messageBox(where);
    }



    //MessageBox const& MessageClient::messageBox(MessageBoxType which) const
    //{
    //    static_assert(false, "Complete the code");
    //}

} // END namespace ms
