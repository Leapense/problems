# 4911번: Rotating Rings - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/4911)


<p><span style="line-height:1.6em"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/4911/1.png" style="float:right; height:368px; width:114px">Any square grid can be viewed as one or more rings, one inside the other. For example, as shown in figure (a), a 5 ∗ 5 grid is made of three rings, numbered 1,2 and 3 (from outside to inside.) A square grid of size N is said to be sorted, if it includes the values from 1 to N</span><sup style="line-height:1.6em">2</sup><span style="line-height:1.6em"> in a row-major order, as shown in figure (b) for N = 4. We would like to determine if a given square grid can be sorted by only rotating its rings. For example, the grid in figure (c) can be sorted by rotating the first ring two places counter-clockwise, and rotating the second ring one place in the clockwise direction.</span></p>



## 입력


<p>Your program will be tested on one or more test cases. The first input line of a test case is an integer N which is the size of the grid. N input lines will follow, each line made of N integer values specifying the values in the grid in a row-major order. Note than 0 &lt; N ≤ 1, 000 and grid values are natural numbers less than or equal to 1,000,000.</p>

<p>The end of the test cases is identified with a dummy test case with N = 0.</p>



## 출력


<p>For each test case, output the result on a single line using the following format:</p>

<p>k.␣result</p>

<p>Where k is the test case number (starting at 1,) ␣ is a single space, and result rings.(c|cpp|java) rings.in is "YES" or "NO" (without the double quotes.)</p>



## 소스코드

[소스코드 보기](Rotating%20Rings.cpp)