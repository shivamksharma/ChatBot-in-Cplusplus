//
// Program Name: ChatBot 1
// Description: This is a improved version of ChatBot program written in c++ programming language,where previous ChatBot1
//  in some more replies based on your preloaded question in program. 
//

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

const int MAX_RESP = 3;

typedef vector<string> vstring;

vstring find_match(string input);
void copy(char *array[], vstring &v);


typedef struct {
    char *input;
    char *responses[MAX_RESP];
}record;

record KnowledgeBase[] = {
    {"WHAT IS YOUR NAME",
    {"MY NAME IS CHATTERBOT.",
     "YOU CAN CALL ME CHATTERBOT.",
     "WHY DO YOU WANT TO KNOW MY NAME?"}
    },

    {"HI",
    {"HI THERE!",
     "HOW ARE YOU?",
     "Hi!"}
    },

    {"HOW ARE YOU",
    {"I'M DOING FINE!",
    "I'M DOING WELL AND YOU?",
    "WHY DO YOU WANT TO KNOW HOW AM I DOING?"}
    },

    {"WHO ARE YOU",
    {"I'M AN A.I PROGRAM WRITTEN IN C++ BY SHIVAM SHARMA.",
     "I THINK THAT YOU KNOW WHO I'M.",
     "WHY ARE YOU ASKING?"}
    },

    {"ARE YOU INTELLIGENT",
    {"YES,OFCOURSE.",
     "WHAT DO YOU THINK?",
     "ACTUALY,I'M VERY INTELLIGENT CAUSE I'VE KNOWLEDGE OF ARTIFICIAL INTELLIGENCE!"}
    },

    {"ARE YOU REAL",
    {"DOES THAT QUESTION REALLY MATERS TO YOU?",
     "MAY BE ITS, CAUSE I'M AN ARTIFICIAL INTELLIGENCE CHATBOT"
     "WHAT DO YOU MEAN BY THAT?",
     "I'M AS REAL AS I CAN BE."}
    }
};

size_t nKnowledgeBaseSize = sizeof(KnowledgeBase)/sizeof(KnowledgeBase[0]);

int main() {
    srand((unsigned) time(NULL));

    string sInput = "";
    string sResponse = "";

    while(1) {
        cout << ">";
        getline(cin, sInput);
        vstring responses = find_match(sInput);
        if(sInput == "BYE") {
            cout << "IT WAS NICE TALKING TO YOU USER, SEE YOU NEXTTIME!" << endl;
            break;
        }
        else if(responses.size() == 0)  {
            cout << "I'M NOT SURE IF I UNDERSTAND WHAT YOU'RE TALKING ABOUT."
                      << endl;
        }
        else {
            int nSelection = rand()  % MAX_RESP;
            sResponse =   responses[nSelection]; cout << sResponse << endl;
        }
    }

    return 0;
}

// make a  search for the  user's input
// inside the database of the program
vstring find_match(string  input) {
    vstring result;
    for(int i = 0; i < nKnowledgeBaseSize;  ++i) {
        if(string(KnowledgeBase[i].input) == input) {
            copy(KnowledgeBase[i].responses, result);
            return result;
        }
    }
    return result;
}

void copy(char  *array[], vstring &v) {
    for(int i = 0;  i < MAX_RESP; ++i) {
        v.push_back(array[i]);
    }
}
