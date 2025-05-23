# 11969번: Breed Counting - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/11969)


<p>Farmer John's \(N\) cows, conveniently numbered \(1 \ldots N\), are all standing in a row (they seem to do so often that it now takes very little prompting from Farmer John to line them up). Each cow has a breed ID: 1 for Holsteins, 2 for Guernseys, and 3 for Jerseys. Farmer John would like your help counting the number of cows of each breed that lie within certain intervals of the ordering.</p>



## 입력


<p>The first line of input contains \(N\) and \(Q\) (\(1 \leq N \leq 100,000\), \(1 \leq Q \leq 100,000\)).</p>

<p>The next \(N\)&nbsp;lines contain an integer that is either 1, 2, or 3, giving the breed ID of a single cow in the ordering.</p>

<p>The next \(Q\) lines describe a query in the form of two integers \(a, b\) (\(a \leq b\)).</p>



## 출력


<p>For each of the \(Q\) queries \((a,b)\), print a line containing three numbers: the number of cows numbered \(a \ldots b\) that are Holsteins (breed 1), Guernseys (breed 2), and Jerseys (breed 3).</p>



## 소스코드

[소스코드 보기](Breed%20Counting.cpp)