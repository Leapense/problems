#include "testlib.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct TestCaseData {
    int a2;
    int a1;
    int a0;
    int c;
    int n0;
};

static int rndInRange(int lo, int hi) {
    return rnd.next(lo, hi);
}

static TestCaseData genRandomCase() {
    TestCaseData t;
    t.a2 = rndInRange(-100, 100);
    t.a1 = rndInRange(-100, 100);
    t.a0 = rndInRange(-100, 100);
    t.c = rndInRange(1, 100);
    t.n0 = rndInRange(1, 100);
    return t;
}

static TestCaseData genYesLinearCase() {
    TestCaseData t;
    t.c = rndInRange(1, 100);
    t.n0 = rndInRange(1, 100);
    t.a2 = t.c;
    int limit = 100 / t.n0;
    if (limit < 1) limit = 1;
    t.a1 = -rndInRange(1, limit);
    int upper = min(100, -t.a1 * t.n0);
    t.a0 = rndInRange(-100, upper);
    return t;
}

static TestCaseData genNoCase() {
    TestCaseData t;
    t.c = rndInRange(1, 100);
    t.n0 = rndInRange(1, 100);
    if (t.c < 100) {
        t.a2 = rndInRange(t.c + 1, 100);
        t.a1 = rndInRange(-100, 100);
        t.a0 = rndInRange(-100, 100);
    } else {
        t.a2 = 100;
        t.a1 = rndInRange(1, 100);
        t.a0 = rndInRange(-100, 100);
    }
    return t;
}

static TestCaseData genTightLinearCase() {
    TestCaseData t;
    t.c = rndInRange(1, 100);
    t.n0 = rndInRange(1, 100);
    t.a2 = t.c;
    int limit = 100 / t.n0;
    if (limit < 1) limit = 1;
    t.a1 = -rndInRange(1, limit);
    t.a0 = -t.a1 * t.n0;
    return t;
}

static TestCaseData genTightQuadraticCase() {
    TestCaseData t;
    t.c = rndInRange(1, 100);
    t.n0 = rndInRange(1, 10);
    int m = rndInRange(t.n0, 10);
    int absB2Max = 100 / (m * m);
    if (absB2Max < 1) absB2Max = 1;
    int b2 = -rndInRange(1, absB2Max);
    int b1 = -2 * b2 * m;
    int b0 = b2 * m * m;
    t.a2 = b2 + t.c;
    t.a1 = b1;
    t.a0 = b0;
    return t;
}

static TestCaseData genConcaveRightNoCase() {
    TestCaseData t;
    t.c = rndInRange(1, 100);
    t.n0 = rndInRange(1, 5);
    int m = rndInRange(t.n0 + 1, 10);
    int b2 = -rndInRange(1, 2);
    int b1 = -2 * b2 * m;
    int b0 = rndInRange(50, 100);
    t.a2 = b2 + t.c;
    t.a1 = b1;
    t.a0 = b0;
    return t;
}

static TestCaseData genEdgeCase() {
    int pick = rndInRange(0, 3);
    if (pick == 0) {
        TestCaseData t;
        t.a2 = 100;
        t.a1 = 100;
        t.a0 = 100;
        t.c = 100;
        t.n0 = 100;
        return t;
    } else if (pick == 1) {
        TestCaseData t;
        t.a2 = -100;
        t.a1 = -100;
        t.a0 = -100;
        t.c = 1;
        t.n0 = 100;
        return t;
    } else if (pick == 2) {
        return genTightLinearCase();
    } else {
        return genTightQuadraticCase();
    }
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    string mode = argc >= 2 ? string(argv[1]) : string("rnd");
    TestCaseData t;
    if (mode == "rnd") {
        t = genRandomCase();
    } else if (mode == "yes") {
        t = genYesLinearCase();
    } else if (mode == "no") {
        t = genNoCase();
    } else if (mode == "tightL") {
        t = genTightLinearCase();
    } else if (mode == "tightQ") {
        t = genTightQuadraticCase();
    } else if (mode == "concaveRightNo") {
        t = genConcaveRightNoCase();
    } else if (mode == "edge") {
        t = genEdgeCase();
    } else {
        t = genRandomCase();
    }
    cout << t.a2 << ' ' << t.a1 << ' ' << t.a0 << '\n';
    cout << t.c << '\n';
    cout << t.n0 << '\n';
    return 0;
}