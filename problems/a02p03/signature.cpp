// Include needed standard library functions
#include <iostream>

// sizeof: bool,char,int,float and double
std::tuple<size_t, size_t, size_t, size_t, size_t> getTypeSizes() {
    return {
        sizeof(bool),
        sizeof(char),
        sizeof(int),
        sizeof(float),
        sizeof(double)
    };
}

// The main function is the entry point for any program written in C++
//int main(int /*argc*/, char** /*argv*/)
//{
//    using namespace std;
//
//    cout << "Size of bool: " << get<0>(getTypeSizes()) << "\n";
//    cout << "Size of char: " << get<1>(getTypeSizes()) << "\n";
//    cout << "Size of int: " << get<2>(getTypeSizes()) << "\n";
//    cout << "Size of float: " << get<3>(getTypeSizes()) << "\n";
//    cout << "Size of double: " << get<4>(getTypeSizes()) << "\n";
//
//    // Return the value Zero to the operating system
//    // Indicating that your program terminated successfully without sideeffects
//    return 0;
//}