# 13628번: Triangles - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/13628)


<p>You will be given N points on a circle. You must write a program to determine how many distinct equilateral triangles can be constructed using the given points as vertices.</p>

<p>The figure below illustrates an example: (a) shows a set of points, determined by the lengths of the circular arcs that have adjacent points as extremes; and (b) shows the two triangles which can be built with these points.</p>

<p style="text-align:center"><img alt="" src="https://onlinejudgeimages.s3.amazonaws.com/problem/13628/%EC%8A%A4%ED%81%AC%EB%A6%B0%EC%83%B7%202017-01-05%20%EC%98%A4%ED%9B%84%208.46.12.png" style="height:173px; width:455px"></p>

<p>&nbsp;</p>



## 입력


<p>The first line of the input contains an integer N, the number of points given. The second line contains N integers X<sub>i</sub>, representing the lengths of the circular arcs between two consecutive points in the circle: for 1 ≤ i ≤ (N − 1), X<sub>i</sub> represents the length of the arc between between points i and i + 1; X<sub>N</sub> represents the length of the arc between points N and 1.</p>

<p>Restrictions</p>

<ul>
<li>3 ≤ N ≤ 10<sup>5</sup></li>
<li>1 ≤ Xi ≤ 10<sup>3</sup>, for 1 ≤ i ≤ N</li>
</ul>



## 출력


<p>Your program must output a single line, containing a single integer, the number of distinct equilateral triangles that can be constructed using the given points as vertices.</p>



## 소스코드

[소스코드 보기](Triangles.cpp)