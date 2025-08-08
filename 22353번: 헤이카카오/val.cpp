// val.cpp
#include "testlib.h"
int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int a = inf.readInt(1, 100, "a");
    inf.readSpace();
    int d = inf.readInt(1, 100, "d");
    inf.readSpace();
    int k = inf.readInt(1, 100, "k");
    inf.readEoln();
    inf.readEof();
    return 0;
}
