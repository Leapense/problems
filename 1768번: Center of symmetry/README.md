# 1768번: Center of symmetry - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/1768)


<p>Given is a set of&nbsp;<em>n</em>&nbsp;points with integer coordinates. Your task is to decide whether the set has a center of symmetry.</p>

<p>A set of points&nbsp;<em>S</em>&nbsp;has the center of symmetry if there exists a point&nbsp;<em>s</em>&nbsp;(not necessarily in&nbsp;<em>S</em>) such that for every point&nbsp;<em>p</em>&nbsp;in&nbsp;<em>S</em>&nbsp;there exists a point&nbsp;<em>q</em>&nbsp;in&nbsp;<em>S</em>&nbsp;such that&nbsp;<em>p-s</em>&nbsp;=&nbsp;<em>s-q</em>.</p>



## 입력


<p>The first line of input contains a number&nbsp;<em>c</em>&nbsp;giving the number of cases that follow. The first line of data for a single case contains number 1&nbsp;≤&nbsp;<em>n</em>&nbsp;≤&nbsp;<em>10000</em>. The subsequent&nbsp;<em>n</em>&nbsp;lines contain two integer numbers each which are the&nbsp;<em>x</em>&nbsp;and&nbsp;<em>y</em>&nbsp;coordinates of a point. Every point is unique and we have that -10000000&nbsp;≤&nbsp;<em>x</em>,&nbsp;<em>y</em>&nbsp;≤&nbsp;10000000.</p>



## 출력


<p>For each set of input data print&nbsp;<tt>yes</tt>&nbsp;if the set of points has a center of symmetry and&nbsp;<tt>no</tt>&nbsp;otherwise.</p>




## 소스코드

[소스코드 보기](Center%20of%20symmetry.py)