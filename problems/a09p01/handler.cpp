#include "header.h"
#include <iostream>


//using namespace std;
using namespace ms::messageclient;
using namespace ms::match::criterion;
using namespace ms;
using namespace std::chrono;

// The main function is the entry point for any program written in C++
int main(int /*argc*/, char** /*argv*/)
{
	//The message
	Message msg = { 
		From{"Scrooge"}, 
		To{"Donald"}, 
		February / 27 / 2022,
		InMessage{"you owe me"}
	};
	
	//The criteria
	From from = "Scrooge";
	To to = "Donald";
	InMessage hint = "you owe me";
	DateInterval date_interval = { January / 1 / 2022, March / 5 / 2022 };
	
	//compare message and criteria
	auto is_match = criteriaMatcher({from, to, date_interval, hint }, msg);

	if(is_match)
		std::cout << "A perfect Match!" << std::endl;

	////set up a client
	//MessageClient client("Donald \"the dev\" Duck");

	////Send a message
	//client.sendMessage("Dolly", January / 1 / 2022, "Quack Quack !!");

	////Find messages
	//auto result = client.findMessages(MessageClient::MessageBoxType::Inbox, { from = "Dolly"});

	////Delete messages
	//client.deleteMessages(ms::MessageClient::MessageBoxType::Outbox);

	////The spam filter
	//client.setSpamFilter( {from = "Scrooge"} );

  // Return the value Zero to the operating system
  // Indicating that your program terminated successfully without sideeffects
  return 0;
}
