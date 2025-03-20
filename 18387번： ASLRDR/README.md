# 18387번: ASLRDR - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/18387)


<p>Suppose an assembly line in a factory with N stations. In each station, workers do an activity on the product that might be the same as previous or next stations’ activity. The order of these stations is not important but they should be ordered such that the product insert to line from one side (Left or Right) and exit from other side (Right or Left) without reverse movement in line. Your job is writing a program to reorder an existing assembly line so that it passed the mentioned rule. You may reorder the assembly line in several “station swapping” but you only allow swap two adjacent stations.</p>



## 입력


<p>The first line of input gives n, the number of assembly lines (Test Cases).</p>

<p>For each test case, one line of input follows, containing a string of up to 100 letters or digits that are the name of stations.</p>



## 출력


<p>Output consists of one line per test case. This line will contain the least possible number of swaps, or "Impossible" if it is not possible to reorder the stations for passing the rule.</p>

<p>For example, assume we have 3 actions that are named 2,a and D which currently are ordered in an assembly line as "2a2aD". To pass the mentioned rule it should reorder to "2aDa2" with 3 swaps as follows:</p>

<ul>
<li>swap "aD" to yield "2a2Da"</li>
<li>swap "2D" to yield "2aD2a"</li>
<li>swap "2a" to yield "2aDa2"</li>
</ul>



## 소스코드

[소스코드 보기](ASLRDR.cpp)