# 31047번: Warehouse - <img src="https://static.solved.ac/tier_small/6.svg" style="height:20px" /> Silver V

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/31047)


<p>Elvira is processing shipments for the Christmas season! There are various shipments of toys coming into her warehouse throughout the day, and her boss wants a summary report at the end. Each shipment consists of some number of a single kind of toy.</p>

<p>The summary report is an aggregated list of all the toys that arrived at the warehouse over the day. The boss is most interested in the biggest sellers, so toys should be sorted in decreasing order of count. If the warehouse received the same number of two kinds of toys, sort them in alphabetical order<sup>1</sup>.</p>



## 입력


<p>The first line of input contains the number of test cases, $T$ ($1 \le T \le 100$).</p>

<p>Each test case begins with a line containing an integer, $N$ ($1 \le N \le 100$). This indicates that $N$ shipments are coming in for processing. Each of the next $N$ lines describes a single shipment. The line contains a string and an integer, the name of the toy and how many of that toy are in the given shipment. The name of a toy is a string of at most $10$ lowercase letters (<code>a</code>–<code>z</code>) and between $1$ and $10$ toys arrive in a given shipment.</p>



## 출력


<p>For each test case, output $K$, the number of unique toys that have arrived in the warehouse.</p>

<p>Then output $K$ lines, each containing the name of a toy and how many of that toy that have arrived, summed up over all the shipments. Output toys in decreasing order of count, breaking ties alphabetically.</p>



## 소스코드

[소스코드 보기](Warehouse.cpp)