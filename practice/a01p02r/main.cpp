// Oppgave (repetisjon av a01p02 - samme tema: lese ett tall, forgrene pa
// en betingelse, skrive ett ord)
//
// Les ett heltall (en alder) fra standard input. Skriv ut "myndig" til
// standard out hvis alderen er 18 eller over, ellers "mindrearig".
//
// Eksempel: input 20 -> output "myndig"

#include <iostream>

int main(int /*argc*/, char** /*argv*/)
{
    // TODO: skriv losningen din her
    int number;
    std::cin >> number;

    if (number >= 18)
        std::cout << "myndig";
    else
        std::cout << "mindrearig";


    return 0;
}
