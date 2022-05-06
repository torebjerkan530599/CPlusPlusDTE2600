// Include needed standard library functions
#include <iostream>
using namespace std;

// The main function is the entry point for any program written in C++
int main(int /*argc*/, char** /*argv*/)
{
	int n;
	std::cin >> n;

	switch (n) {
		case 1: cout << "If it were done when 'tis done, then 'twere well" << endl;
			break;
		case 2: cout << "It were done quickly : if the assassination" << endl;
			break;
		case 3: cout << "Could trammel up the consequence, and catch" << endl;
			break;
		case 4: cout << "With his surcease success; that but this blow" << endl;
			break;
		case 5: cout << "Might be the be-all and the end-all here," << endl;
			break;
		case 6: cout << "But here, upon this bank and shoal of time," << endl;
			break;
		case 7: cout << "We'ld jump the life to come. But in these cases" << endl;
			break;
		case 8: cout << "We still have judgment here; that we but teach" << endl;
			break;
		case 9: cout << "Bloody instructions, which, being taught, return" << endl;
			break;
		case 10: cout << "To plague the inventor: this even-handed justice" << endl;
			break;
		case 11: cout << "Commends the ingredients of our poison'd chalice" << endl;
			break;
		case 12: cout << "To our own lips. He's here in double trust;" << endl;
			break;
		case 13: cout << "First, as I am his kinsman and his subject," << endl;
			break;
		case 14: cout << "Strong both against the deed; then, as his host," << endl;
			break;
		case 15: cout << "Who should against his murderer shut the door" << endl;
			break;
		case 16: cout << "Not bear the knife myself. Besides, this Duncan" << endl;
			break;
		case 17: cout << "Hath borne his faculties so meek, hath been" << endl;
			break;
		case 18: cout << "So clear in his great office, that his virtues" << endl;
			break;
		case 19: cout << "Will plead like angels, trumpet-tongued, against" << endl;
			break;
		case 20: cout << "The deep damnation of his taking-off;" << endl;
			break;
		case 21: cout << "And pity, like a naked new-born babe" << endl;
			break;
		case 22: cout << "Striding the blast, or heaven's cherubim, horsed" << endl;
			break;
		case 23: cout << "Upon the sightless couriers of the air," << endl;
			break;
		case 24: cout << "Shall blow the horrid deed in every eye," << endl;
			break;
		case 25: cout << "That tears shall drown the wind. I have no spur" << endl;
			break;
		case 26: cout << "To prick the sides of my intent, but only" << endl;
			break;
		case 27: cout << "Vaulting ambition, which o'erleaps itself" << endl;
			break;
		case 28: cout << "And falls on the other." << endl;
			break;
		default:
			cout << "Not a valid choice" << endl;
			break;
	}

	// Return the value Zero to the operating system
	// Indicating that your program terminated successfully without sideeffects
	return 0;
}
