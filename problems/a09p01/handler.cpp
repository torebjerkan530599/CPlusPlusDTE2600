#include "header.h"
#include <iostream>

namespace ms::backend
{
    class MessageBackendSimulator {
    public:

        // Types
        using SPtr = std::shared_ptr<MessageBackendSimulator>;
        using WPtr = std::weak_ptr<MessageBackendSimulator>;

        // Insantiation
        static WPtr instance();

        // Communication API
        Messages retrieveMessages();

        void sendMessage(Message const& message);
        void sendMessages(Messages const& messages);
    };
}

// Include needed standard library functions (STL)
using namespace std;
// The main function is the entry point for any program written in C++
int main(int /*argc*/, char** /*argv*/)
{
	std::ostream& operator<<(std::ostream & stream, ms::Message const& msg);

	ms::Messages backendRecieveSomeMessages() 
	{ 
		/* ... */ 
	}
	
	void     backendSendSomeMessage( /* ... */) 
	{ 
		/* ... */ 
	}



  // Return the value Zero to the operating system
  // Indicating that your program terminated successfully without sideeffects
  return 0;
}
