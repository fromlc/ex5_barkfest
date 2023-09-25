//------------------------------------------------------------------------------
// ex5_barkfest.cpp
//
// Creates a cacophony of barking sounds
//      - generates a random number of sounds to make
//      - random number of sounds ranges from 1 to BARK_COUNT
//      - selects each random sound from global barkfest[] array
//------------------------------------------------------------------------------
#include <iostream>

using namespace std;

//------------------------------------------------------------------------------
// constants
//------------------------------------------------------------------------------
// number of barks will be in range 1-20
constexpr int BARK_COUNT = 20;

//------------------------------------------------------------------------------
// globals
//------------------------------------------------------------------------------
namespace bf {
    string barkfest[] = {
        "Bark bark bark! ",
        "Woooof! ",
        "Yip! ",
        "Yap yap! ",
        "Arf! Arf! ",
        "Hooowwwwwllll!! ",
    };
}

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {

    // app banner
    cout << "\nWelcome to the neighborhood barkfest!\n\n";

    while (true) {

        // seed random number generator for different sequence each run
        srand((unsigned int)time(0));

        // generate number of barking sounds to make
        int bark_count = rand() % BARK_COUNT + 1;

        // determine how many barking sounds the barkfest array contains
        int barks_avail = sizeof(bf::barkfest) / sizeof(string);

        // each loop iteration makes one barking sound
        for (int i = 0; i < bark_count; ++i) {

            // select a random barking sound to display
            int bark_selected = rand() % barks_avail;
            cout << '\t' << bf::barkfest[bark_selected] << '\n';
        }

        cout << "\nAnother barkfest? (y/n) ";
        char another;
        cin >> another;
        
        if (toupper(another) != 'Y')
            break;

        cout << '\n';
    }

    cout << "\nGoodbye!\n";
    return 0;
}
