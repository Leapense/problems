# 8312번: Rectangles 2 - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/8312)


<p style="text-align:center"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/8312/1.gif" style="height:100px; width:150px"></p>

<p>We have found: 6 rectangles 1 × 1, 4 rectangles 2 × 1, 3 rectangles 1 × 2, 2 rectangles 2 × 2, 2 rectangles 3&nbsp;× 1&nbsp;and one rectangle 3 × 2, what gives 18 in total. Clearly, we are interested in rectangles with vertices in grid points, i.e., the points located at the intersections of vertical and horizontal line segments, and having vertical or horizontal sides. The above grid has dimensions 3 × 2.</p>

<p>And how many such rectangles of perimeter at least 6 can be found in the figure? You can find the answer in the Example section.</p>



## 입력


<p>The first and only line of the standard input contains three integers: n, m&nbsp;and p&nbsp;(1 ≤ n, m ≤ 5,000, 4 ≤ p ≤ 2(n+m)), representing the dimensions of the grid and the lower bound for the perimeter of the rectangles.</p>



## 출력


<p>In the first line of the standard output your program should output one integer: the number of rectangles with vertices in grid points of the grid n × m, having vertical or horizontal sides and which perimeter is at least p.</p>



## 소스코드

[소스코드 보기](Rectangles%202.cpp)