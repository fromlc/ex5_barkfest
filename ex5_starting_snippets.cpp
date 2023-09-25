//------------------------------------------------------------------------------
// ex5_starting_snippets.cpp
//------------------------------------------------------------------------------

// number of barks will be in range 1-20
constexpr int BARK_COUNT = 20;

// array of bark sounds
string barkfest[] = {
    "Bark bark bark! ",
    "Woooof! ",
    "Yip! ",
    "Yap yap! ",
    "Arf! Arf! ",
    "Hooowwwwwllll!! ",
};

// how many elements are there in barkfest[] array?
int highest_bark_index = sizeof(barkfest) / sizeof(string);

// seed random number generator with # seconds since 12am on 1/1/1970
srand((unsigned int)time(0));
