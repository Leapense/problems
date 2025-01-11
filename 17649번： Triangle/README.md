# 17649번: Triangle - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/17649)


<p>In the plane are given N distinct points with coordinates that are decimal fractions. Write program that handles Q queries. Each query is given with two fractional numbers x and y. For each query, the program has to calculate the number of epsilon-isosceles triangles such that each of them has a vertex with coordinates - the point (x, y) and the other two vertices are two different points among the given N points.</p>

<p>We say that a triangle is epsilon-isosceles when the absolute value of the difference between the lengths of two of its sides is less than 0.0001 and for that triangle we do not require for a pair of its vertices to be necessarily non-coincident points and we do not require its three vertices to be necessarily non-collinear.</p>



## 입력


<p>The first line of the input contains the integers N and Q. Each of the next N lines of the input contains two decimal fractions - coordinates of the next given point. There are following Q lines, each containing two decimal fractions - the coordinates of a point in the next query.</p>



## 출력


<p>The program should output Q lines, each containing a single integer, equal to the answer to each of the queries printed in the order of the input.</p>



## 소스코드

[소스코드 보기](Triangle.cpp)