#include "testlib.h"
#include <iostream>

using namespace std;

#define MIN_AB -10000
#define MAX_AB 10000
#define MIN_C -100000
#define MAX_C 100000
#define MIN_X1X2 -100000
#define MAX_X1X2 100000
#define MIN_Y1Y2 -100000
#define MAX_Y1Y2 100000

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    rnd.setSeed(time(NULL));

    int min_ab = opt<int>("min_ab");
    int max_ab = opt<int>("max_ab");
    int min_c = opt<int>("min_c");
    int max_c  = opt<int>("max_c");
    int min_x1x2 = opt<int>("min_x1x2");
    int max_x1x2 = opt<int>("max_x1x2");
    int min_y1y2 = opt<int>("min_y1y2");
    int max_y1y2 = opt<int>("max_y1y2");

    // min_ab가 -10000 보다 밑으로 가지 않았고, max_ab가 10000보다 위로 가지 않았으며, min_ab <= max_ab가 만족하는지 확인한다.(ensuref 활용)
    ensuref(min_ab <= max_ab, "min_ab must be less than or equal to max_ab");
    ensuref(min_ab >= MIN_AB && max_ab <= MAX_AB, "min_ab must be in [-10000, 10000] and max_ab must be in [-10000, 10000]");

    // min_c가 -100000 보다 밑으로 가지 않았고, max_c가 100000보다 위로 가지 않았는지 확인한다. (ensuref 활용)
    ensuref(min_c >= MIN_C && max_c <= MAX_C, "min_c must be in [-100000, 100000] and max_c must be in [-100000, 100000]");

    // min_x1x2가 -100000 보다 밑으로 가지 않았고, max_x1x2가 100000보다 위로 가지 않았는지 확인한다. min_x1x2 <= max_x1x2가 만족하는지도 확인한다. (ensuref 활용)
    ensuref(min_x1x2 <= max_x1x2, "min_x1x2 must be less than or equal to max_x1x2");
    ensuref(min_x1x2 >= MIN_X1X2 && max_x1x2 <= MAX_X1X2, "min_x1x2 must be in [-100000, 100000] and max_x1x2 must be in [-100000, 100000]");

    // min_y1y2가 -100000 보다 밑으로 가지 않았고, max_y1y2가 100000보다 위로 가지 않았는지 확인한다. min_y1y2 <= max_y1y2가 만족하는지도 확인한다. (ensuref 활용)
    ensuref(min_y1y2 <= max_y1y2, "min_y1y2 must be less than or equal to max_y1y2");
    ensuref(min_y1y2 >= MIN_Y1Y2 && max_y1y2 <= MAX_Y1Y2, "min_y1y2 must be in [-100000, 100000] and max_y1y2 must be in [-100000, 100000]");

    int A = rnd.next(min_ab, max_ab);
    int B = rnd.next(min_ab, max_ab);
    int C = rnd.next(min_c, max_c);
    int X1 = rnd.next(min_x1x2, max_x1x2);
    int X2 = rnd.next(X1 + 1, max_x1x2);

    int Y1 = rnd.next(min_y1y2, max_y1y2);
    int Y2 = rnd.next(Y1 + 1, max_y1y2);

    println(A, B, C);
    println(X1, X2, Y1, Y2);

    return 0;
}