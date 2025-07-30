#include "testlib.h"
#include <vector>
#include <string>
using namespace std;

static const vector<string> cycle = {
    "Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse",
    "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"
};

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n = rnd.next(1, 100);
    println(n);

    vector<string> names = { "Bessie" };
    for (int i = 1; i <= n; i++) {
        string name1 = (i == n ? "Elsie" : "Cow" + to_string(i));
        int idx2 = rnd.next(0, (int)names.size() - 1);
        string name2 = names[idx2];

        string relation = rnd.next(0, 1) ? "next" : "previous";

        int idxA = rnd.next(0, (int)cycle.size() - 1);
        string animal = cycle[idxA];
        println(name1, "is the", relation, animal, "relative to", name2);

        names.push_back(name1);
    }

    return 0;
}