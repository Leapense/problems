#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    rnd.setSeed(time(0));

    int T = rnd.next(1, 10);
    for (int t = 0; t < T; t++) {
        int d = rnd.next(1, 10);
        println(d);
        for (int i = 0; i < d; i++) {
            vector<int> row;
            for (int j = 0; j < d; j++) {
                row.push_back(rnd.next(-10, 10));
            }
            println(row);
        }
        int len = rnd.next(1, 80);
        string msg;

        for (int i = 0; i < len; i++) {
            int v = rnd.next(0, 29);
            char c;
            if (v < 26) c = char('A' + v);
            else if (v == 26) c = ' ';
            else if (v == 27) c = ',';
            else if (v == 28) c = '.';
            else c = '?';
            msg += c;
        }

        println(msg);
    }

    println(0);
}