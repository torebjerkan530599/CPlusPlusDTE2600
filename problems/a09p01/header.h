// STL headers
#include <string>
#include <unordered_map>
#include <memory>
#include <chrono>
#include <variant>
#include <vector>

//namespace ms::backend
//{
//    class MessageBackendSimulator
//    {
//    public:
//
//        // Types
//        using SPtr = std::shared_ptr<MessageBackendSimulator>;
//        using WPtr = std::weak_ptr<MessageBackendSimulator>;
//
//        // Insantiation
//        static WPtr instance();
//
//        // Communication API
//        Messages retrieveMessages();
//
//        void sendMessage(Message const& message);
//        void sendMessages(Messages const& messages);
//
//        static WPtr instance()
//        {
//            if (not s_instance) s_instance = std::make_shared<MessageBackendSimulator>();
//            return s_instance;
//        }
//
//        Messages retrieveMessages()
//        {
//			ms::MessageBox& mbox =
//			
//			std::ranges::find(
//				
//				
//				MessageClient::MessageBoxType::Inbox;
//        }
//
//		void sendMessage(Message const& message)
//        {
//			MessageClient::MessageBoxType::Outbox;
//        }
//
//        void sendMessages(Messages const& messages)
//        {
//			MessageClient::MessageBoxType::Outbox;
//        }
//
//    private:
//        static inline SPtr s_instance{ nullptr };
//    };
//}


namespace ms
{

	///////////
	// Messages

	using MessageDate = std::chrono::year_month_day;

	struct Message {
		std::string from;
		std::string to;
		MessageDate date;
		std::string message;
	};
	using Messages = std::vector<Message>;
	using MessageBox = std::vector<Message>;

	std::ostream& operator<<(std::ostream& stream, ms::Message const& msg);


	 ///////////////////
	 // Message Matching

	namespace match
	{
		namespace criterion
		{
			struct From : std::string
			{
				using std::string::string;
			};

			struct To : std::string
			{
				using std::string::string;
			};

			struct DateInterval
			{
				MessageDate from;
				MessageDate to;

			};
			struct InMessage : std::string
			{
				using std::string::string;
			};

		}   // namespace criterion

		using namespace match::criterion;

		using Criterion = std::variant<criterion::From, criterion::To,
			criterion::DateInterval, criterion::InMessage>;
		using Criteria = std::vector<Criterion>;

	}   // namespace match



	/////////////
	// The Client

	namespace messageclient
	{
		bool criteriaMatcher(match::Criteria filter, Message const& message);
	}

	class MessageClient
	{
	public:

		// Message box types
		enum class MessageBoxType { Inbox, Outbox, Sent, Spam, Trash};
	

		// Constructor
		MessageClient(std::string owner);

		// Public API
		std::string const& owner() const;
		void               sendMessage(std::string to, MessageDate date, std::string message);
		Messages           findMessages(MessageBoxType  where, match::Criteria filter = {}) const;
		void               deleteMessages(MessageBoxType where, match::Criteria filter = {});
		void               setSpamFilter(match::Criteria filter = {});
		void               sync();

		
		

	private:

		// Private types
		using MessageBoxes = std::unordered_map<MessageBoxType, MessageBox>;
		using MBoxIterator = MessageBox::const_iterator;
		using MBoxConstIterators = std::vector<MBoxIterator>;

		// Private members
		std::string     m_owner;
		MessageBoxes    m_messageboxes;
		match::Criteria m_spam_filter;

		// Private helper functions
		MBoxConstIterators search(MessageBoxType where, match::Criteria filter) const;
		MessageBox& messageBox(MessageBoxType which);
		MessageBox const& messageBox(MessageBoxType which) const;
	};
	
	//template<typename MessageBoxType, typename MessageBoxes>
	//std::ostream& operator<<(std::ostream& os,
	//	std::unordered_map<MessageBoxType, MessageBoxes>& m);
	

} // END namespace ms
