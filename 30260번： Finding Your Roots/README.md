# 30260번: Finding Your Roots - <img src="https://static.solved.ac/tier_small/3.svg" style="height:20px" /> Bronze III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/30260)


<p>P-22’s father was P-1, the first mountain lion tagged in the Santa Monica Mountains. P-22’s mother is unknown. Unfortunately, we do not know anything about P-1’s parents, so we can only trace back P-22’s ancestry two generations (himself and his father). In some other cases, one can trace back ancestry quite a bit further, and you are supposed to find out just how far.</p>

<p>To keep things simple (and avoid exponential growth), we will assume that for each individual mountain lion, you are given only one parent (or none, when no information is available). You are to return the total number of generations in the ancestry of a specific mountain lion that can be traced back.</p>



## 입력


<p>The first line contains a number 1 ≤ K ≤ 100, which is the number of input data sets in the file. This is followed by K data sets of the following form:</p>

<p>The first line of a data set contains two integers 1 ≤ L ≤ n ≤ 10000. n is the total number of mountain lions in the database, and L is the mountain lion whose ancestry you are interested in.</p>

<p>This is followed by a single line with n integers p<sub>i</sub>, where 0 ≤ p<sub>i</sub> ≤ n is the parent of mountain lion i. A ’0’ denotes that the parent of lion i is unknown. Because these are parent relationships, there will never be cycles in the input.</p>



## 출력


<p>For each data set, first output “Data Set x:” on a line by itself, where x is its number. Then, output the number of generations of the ancestry of L that are in the database (including L himself/herself).</p>

<p>Each data set should be followed by a blank line.</p>



## 소스코드

[소스코드 보기](Finding%20Your%20Roots.py)