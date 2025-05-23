# 12729번: Saving the Universe (Small) - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/12729)


<p>The urban legend goes that if you go to the Google homepage and search for "Google", the universe will implode. We have a secret to share... It is true! Please don't try it, or tell anyone. All right, maybe not. We are just kidding.</p>

<p>The same is not true for a universe far far away. In that universe, if you search on any search engine for that search engine's name, the universe does implode!</p>

<p>To combat this, people came up with an interesting solution. All queries are pooled together. They are passed to a central system that decides which query goes to which search engine. The central system sends a series of queries to one search engine, and can switch to another at any time. Queries must be processed in the order they're received. The central system must never send a query to a search engine whose name matches the query. In order to reduce costs, the number of switches should be minimized.</p>

<p>Your task is to tell us how many times the central system will have to switch between search engines, assuming that we program it optimally.</p>



## 입력


<p>The first line of the input file contains the number of cases,&nbsp;<strong>N</strong>.&nbsp;<strong>N</strong>&nbsp;test cases follow.</p>

<p>Each case starts with the number&nbsp;<strong>S</strong>&nbsp;-- the number of search engines. The next&nbsp;<strong>S</strong>&nbsp;lines each contain the name of a search engine. Each search engine name is no more than one hundred characters long and contains only uppercase letters, lowercase letters, spaces, and numbers. There will not be two search engines with the same name.</p>

<p>The following line contains a number&nbsp;<strong>Q</strong>&nbsp;-- the number of incoming queries. The next&nbsp;<strong>Q</strong>lines will each contain a query. Each query will be the name of a search engine in the case.</p>

<p>Limits</p>

<ul>
<li>0 &lt;&nbsp;<strong>N</strong>&nbsp;≤ 20</li>
<li>2 ≤&nbsp;<strong>S</strong>&nbsp;≤ 10</li>
<li>0 ≤&nbsp;<strong>Q</strong>&nbsp;≤ 100</li>
</ul>



## 출력


<p>For each input case, you should output:</p>

<pre>Case #<strong>X</strong>: <strong>Y</strong></pre>

<p>where&nbsp;<strong>X</strong>&nbsp;is the number of the test case and&nbsp;<strong>Y</strong>&nbsp;is the number of search engine switches. Do not count the initial choice of a search engine as a switch.</p>



## 소스코드

[소스코드 보기](Saving%20the%20Universe%20(Small).cpp)