# 32023번: Tightly Packed - <img src="https://static.solved.ac/tier_small/6.svg" style="height:20px" /> Silver V

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/32023)


<p>Consider packing widgets for shipping where widgets cannot be stacked upon each other (2D packing). Each widget has a 1x1 footprint and is 1 unit high.</p>

<p>Boxes are available in any $W$ by $H$ by 1 size such that $H/2 \leq W \leq 2H$, with $W$ and $H$ being integers. The company wants to minimize the amount of packing material that will be needed to fill empty squares in a box.</p>

<p>Given $N$, the number of widgets to be shipped, what is the smallest number of squares that will be left empty when those widgets are packed for shipping?</p>



## 입력


<p>Input consists of one line containing an integer $N$, the number of widgets to be packed.   $1 \leq N \leq 10^{16}$. </p>



## 출력


<p>Print a single line containing an integer denoting the minimum number of empty squares. </p>



## 소스코드

[소스코드 보기](Tightly%20Packed.cpp)