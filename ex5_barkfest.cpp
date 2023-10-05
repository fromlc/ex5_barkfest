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
// local function prototypes
//------------------------------------------------------------------------------
void app_setup();
void display_banner();
char get_char_input();
void generate_barkfests(string[], int);
int app_teardown();

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {

	// array is local to main
	string barkfest[] = {
		"Bark bark bark! ",
		"Woooof! ",
		"Yip! ",
		"Yap yap! ",
		"Arf! Arf! ",
		"Hooowwwwwllll!! ",
	};

	app_setup();

	// Local barkfest array will not be in function scope,
	// so we need pass the array and how many sounds it contains.
	generate_barkfests(barkfest, sizeof(barkfest) / sizeof(string));

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
// - generates random barkfests until user wants to quit
// - parameters: array of bark sound strings, number of elements in array
//------------------------------------------------------------------------------
void generate_barkfests(string bark_sounds[], int barks_avail) {

	// loop until user wants to quit
	while (true) {

		// generate number of barking sounds to make
		int bark_count = rand() % BARK_COUNT + 1;

		// each loop iteration makes one barking sound
		for (int i = 0; i < bark_count; ++i) {

			// select a random barking sound to display
			int bark_selected = rand() % barks_avail;
			cout << '\t' << bark_sounds[bark_selected] << '\n';
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

