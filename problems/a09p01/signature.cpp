#include "header.h"
#include <iomanip>
#include <iostream>
#include <typeinfo>
#include <type_traits>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <memory>
#include <chrono>
#include <variant>
#include <vector>

//std::ostream& operator<<(std::ostream& stream, ms::Message const& msg)
//{
//	return stream << msg.from << " " << msg.to << " "
//		<< " " << msg.date << " " << msg.message << "\n";
//}

	//not working!
	/*template<typename MessageBoxType, typename MessageBoxes>
	std::ostream& operator<<(std::ostream& os,
		std::unordered_map<MessageBoxType, MessageBoxes>& m)
	{
		for (std::pair<MessageBoxType, MessageBoxes>& p : m) {
			os << "{" << p.first << ": " << p.second << "}\n";
		}
		return os;
	}*/

	//std::cout << m_messageboxes;

namespace sr = std::ranges;

namespace ms
{
	namespace messageclient
	{
		bool criteriaMatcher(match::Criteria filter, Message const& message)
		{
			for (auto itr = std::cbegin(filter); itr != std::cend(filter); ++itr)
			{
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
					std::string s = std::get<match::InMessage>(*itr); //extract criteria

					/*size_t pos = message.message.find_first_of(s);

					if (pos == std::string::npos)
						return false;*/

					auto found = sr::search(message.message, s);

					if (!found)
						return false;
				}
			}
			return true; //for-loop completes, meaing every criteria matches
		}
	}

	MessageClient::MessageClient(std::string owner)
	{
		m_owner = owner;

		std::vector<Message> vec_inbox;
		std::vector<Message> vec_outbox;
		std::vector<Message> vec_sent;
		std::vector<Message> vec_spam;
		std::vector<Message> vec_trash;

		m_messageboxes =
		{
			{MessageBoxType::Inbox,vec_inbox},
			{MessageBoxType::Outbox, vec_outbox},
			{MessageBoxType::Sent, vec_sent},
			{MessageBoxType::Spam, vec_spam},
			{MessageBoxType::Trash, vec_trash},
		};
	}

	std::string const&
		MessageClient::owner() const
	{
		return m_owner;
	}

	MessageBox& MessageClient::messageBox(MessageBoxType which)
	{
		return m_messageboxes.at(which);
	}

	MessageBox const& MessageClient::messageBox(MessageBoxType which) const
	{
		return m_messageboxes.at(which);
	}

	void MessageClient::sendMessage(std::string to, MessageDate date, std::string message)
	{
		Message msg{ m_owner, to, date, message };
		MessageBox& msgBox = messageBox(MessageBoxType::Outbox);
		msgBox.push_back(msg);
	}

	Messages MessageClient::findMessages(MessageBoxType  where, match::Criteria filter) const
	{
		Messages messages;
		auto result = search(where, filter);

		for (auto& itr : result) //her er det altså MBoxIterator = MessageBox::const_iterator; som pakkes ut
			messages.push_back(*itr); //blir dette riktig da?

		return messages;
	}

	void MessageClient::deleteMessages(MessageBoxType where, match::Criteria filter)
	{
		MessageBox& msgBox = messageBox(where);

		std::for_each(std::cbegin(msgBox), std::cend(msgBox), [](Message const& msg) {
			std::cout << msg.message;
		});

		for (auto itr = msgBox.cbegin(); itr != msgBox.cend(); ++itr)
			if (ms::messageclient::criteriaMatcher(filter, *itr))
				msgBox.erase(itr);
	}

	void MessageClient::setSpamFilter(match::Criteria filter)
	{
		m_spam_filter = filter;
	}


	MessageClient::MBoxConstIterators MessageClient::search(MessageBoxType where, match::Criteria filter) const
	{
		auto const& mbox = messageBox(where);

		auto const& pred = [&filter](const Message& msg)
		{
			return ms::messageclient::criteriaMatcher(filter, msg);
		};
	
		MBoxConstIterators mboxItrs;

		for (auto itr = mbox.cbegin(); itr != mbox.cend(); ++itr) 
		{
			if (sr::any_of(mbox, pred))
				mboxItrs.push_back(itr);
		}

		return mboxItrs;
	}

	void MessageClient::sync()
	{
		// Instantiate an instance of the backend

		//auto backend_wp = backend::MessageBackendSimulator::instance();
		//auto backend = backend_wp.lock();
		// ...

		//hva er riktig her da?
		// Retrieve all messages currently in the backend
		//auto msgs = backend.get()->retrieveMessages();


		// Send one or several messages
		/*backend.sendMessage("");
		backend.sendMessages("");*/
	}

} // END namespace ms