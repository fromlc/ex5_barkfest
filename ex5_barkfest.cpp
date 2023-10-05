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
// local function prototypes
//------------------------------------------------------------------------------
void app_setup();
void display_banner();
char get_char_input();
void generate_barkfests(int);
int app_teardown();

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {

    app_setup();

    // pass how many sounds the barkfest array contains
    generate_barkfests(sizeof(bf::barkfest) / sizeof(string));

    return app_teardown();
}

//------------------------------------------------------------------------------
// app setup tasks
//------------------------------------------------------------------------------
void app_setup() {
    
    // seed random number generator for different sequence each run
    srand((unsigned int)time(0));

    display_banner();
}

//------------------------------------------------------------------------------
// display app banner and user instructions
//------------------------------------------------------------------------------
void display_banner() {
    cout << "\nWelcome to the neighborhood barkfest!\n\n";
}

//------------------------------------------------------------------------------
// returns first type char from user input as UPPER CASE
//------------------------------------------------------------------------------
char get_char_input() {
    char ch;
    cin >> ch;
    return toupper(ch);
}

//------------------------------------------------------------------------------
// generate random barkfests until user wants to quit
//------------------------------------------------------------------------------
void generate_barkfests(int barks_avail) {

    // loop until user wants to quit
    while (true) {

        // generate number of barking sounds to make
        int bark_count = rand() % BARK_COUNT + 1;

        // each loop iteration makes one barking sound
        for (int i = 0; i < bark_count; ++i) {

            // select a random barking sound to display
            int bark_selected = rand() % barks_avail;
            cout << '\t' << bf::barkfest[bark_selected] << '\n';
        }

        cout << "\nAnother barkfest? (y/n) ";
        if (get_char_input() != 'Y')
            break;

        cout << '\n';

    } // while user wants another
}

//------------------------------------------------------------------------------
// - performs tasks needed before exiting app
// - returns status of completed tasks
//------------------------------------------------------------------------------
int app_teardown() {
    cout << "\nGoodbye!\n";

    return 0;
}

