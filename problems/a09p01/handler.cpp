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
	InMessage hint = "z";
	DateInterval date_interval = { January / 1 / 2022, March / 5 / 2022 };
	
	//compare message and criteria
	auto is_match = criteriaMatcher({ hint }, msg);

	if(is_match)
		std::cout << "A perfect Match!" << std::endl;

	// Construct the client
	MessageClient client("Donald \"the dev\" Duck");

	// Sync against the "world".
	//client.sync();
	////Send a message
	client.sendMessage("Dolly", April / 4 / 2022, "Quack Quack !!");

	//Find messages
	auto result = client.findMessages(MessageClient::MessageBoxType::Outbox, { to = "Dolly"});

	////Delete messages
	//client.deleteMessages(ms::MessageClient::MessageBoxType::Outbox);

	////The spam filter
	//client.setSpamFilter( {from = "Scrooge"} );

  // Return the value Zero to the operating system
  // Indicating that your program terminated successfully without sideeffects
  return 0;
}
