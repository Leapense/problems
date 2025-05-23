# 30174번: Filling Diamonds - <img src="https://static.solved.ac/tier_small/4.svg" style="height:20px" /> Bronze II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/30174)


<p>You have integer $n$. Calculate how many ways are there to fully cover belt-like area of $4n-2$ triangles with diamond shapes. </p>

<p>Diamond shape consists of two triangles. You can move, rotate or flip the shape, but you cannot scale it. </p>

<p>$2$ coverings are different if some $2$ triangles are covered by the same diamond shape in one of them and by different diamond shapes in the other one.</p>

<p>Please look at pictures below for better understanding.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/eb83ed1d-df58-4d9b-88a3-2e01f1680640/-/preview/" style="width: 471px; height: 170px;"></p>

<p style="text-align: center;">On the left you can see the diamond shape you will use, and on the right you can see the area you want to fill.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/84667493-d7a0-462b-a959-1db88a652ab8/-/preview/" style="width: 300px; height: 450px;"></p>

<p style="text-align: center;">These are the figures of the area you want to fill for $n = 1, 2, 3, 4$.</p>

<p>You have to answer $t$ independent test cases.</p>



## 입력


<p>The first line contains a single integer $t$ ($1 \le t \le 10^{4}$) --- the number of test cases.</p>

<p>Each of the next $t$ lines contains a single integer $n$ ($1 \le n \le 10^{9}$).</p>



## 출력


<p>For each test case, print the number of ways to fully cover belt-like area of $4n-2$ triangles using diamond shape. It can be shown that under given constraints this number of ways doesn't exceed $10^{18}$.</p>



## 소스코드

[소스코드 보기](Filling%20Diamonds.py)