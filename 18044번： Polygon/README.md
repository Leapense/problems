# 18044번: Polygon - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/18044)


<p>You are given <em>n</em> segments of lengths <em>ℓ</em><sub>1</sub>, <em>ℓ</em><sub>2</sub>, . . . , <em>ℓ</em><em><sub>n</sub></em>, respectively. Determine the largest possible circumference of a convex polygon that can be constructed using these segments (in any order, and not neccessarily all of them). The polygon must be non-degenerate – in other words, its area must be positive.</p>



## 입력


<p>The first line of input contains the number of test cases <em>z</em> (1 ≤ <em>z</em> ≤ 100 000). The test cases follow, each one in the following format:</p>

<p>The first line of a test case contains the number of segments <em>n</em> (1 ≤ <em>n</em> ≤ 100 000). In the second line, there are <em>n</em> integers <em>ℓ</em><sub>1</sub>, <em>ℓ</em><sub>2</sub>, . . . , <em>ℓ</em><em><sub>n</sub></em> (1 ≤ <em>ℓ<sub>i</sub></em> ≤ 10<sup>9</sup> ) – the lengths of the segments.</p>

<p>The sum of <em>n</em> values over all test cases does not exceed 1 000 000.</p>



## 출력


<p>For each test case, output a single integer – the largest possible circumference of a convex polygon made of given segments. If no such polygon can be constructed at all, output 0.</p>



## 소스코드

[소스코드 보기](Polygon.cpp)