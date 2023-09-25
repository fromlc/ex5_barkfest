//------------------------------------------------------------------------------
// ex5_barkfest.cpp
//
// Creates a cacophony of barking sounds
//      - generates a random number of sounds to make
//      - random number of sounds ranges from 1 to BARK_COUNT
//      - selects random sounds from global barkfest[] array
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
string barkfest[] = {
    "Bark bark bark! ",
    "Woooof! ",
    "Yip! ",
    "Yap yap! ",
    "Arf! Arf! ",
    "Hooowwwwwllll!! ",
};

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {

    srand((unsigned int)time(0));

    int bark_count = rand() % BARK_COUNT + 1;
    int barks_avail = sizeof(barkfest) / sizeof(string);

    for (int i = 0; i < bark_count; ++i) {
        int bark_selected = rand() % barks_avail;
        cout << barkfest[bark_selected] << "\n";
    }

    cout << "\n";

    return 0;
}
