//
// Program Name: ChatBot 1
// Description: This is a simple version of ChatBot program written in c++ programming language, this one will
// try a littlebit more to uderstand what the user is trying to say and will also try to avoid 
// repeating himself. Will definetly improve this into next one.
//


#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int main()
{
    string Response[] = {
        "I HEARD YOU!",
        "SO, YOU ARE TALKING TO ME.",
        "CONTINUE, I’M LISTENING.",
        "VERY INTERESTING CONVERSATION.",
        "TELL ME MORE..."
    };

    srand((unsigned) time(NULL));

    string sInput = "";
    string sResponse = "";

    while(1) {
        cout << ">";
        getline(std::cin, sInput);
        int nSelection = rand() % 5;
        sResponse = Response[nSelection];
        cout << sResponse << endl;
    }

    return 0;
}
