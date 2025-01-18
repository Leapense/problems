# 20365번: 블로그2 - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/20365)


<p>neighbor 블로그를 운영하는 일우는 매일 아침&nbsp;풀고 싶은 문제를 미리 정해놓고&nbsp;글을 올린다. 그리고&nbsp;매일 밤&nbsp;각각의 문제에 대하여, 해결한 경우 파란색, 해결하지 못한 경우 빨간색으로 칠한다. 일우는&nbsp;각 문제를 칠할 때 아래와 같은 과정을 한 번의 작업으로 수행한다.</p>

<ol>
<li>연속된 임의의 문제들을 선택한다.</li>
<li>선택된 문제들을&nbsp;전부 원하는 같은 색으로 칠한다.</li>
</ol>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/72fda166-5e2c-42b4-a9c1-e52993a5c45e/-/preview/" style="height: 227px; width: 200px;"></p>

<section id="description">
<p>예를 들어, 각 문제를 위와&nbsp;같은 색으로&nbsp;칠하려고 할&nbsp;때, 1~2번 문제를 파란색, 3번을&nbsp;빨간색, 4번을&nbsp;파란색, 5번을&nbsp;빨간색, 6~7번을&nbsp;파란색, 8번을&nbsp;빨간색으로 칠하는 작업을 순서대로 수행하면 6번의 작업을 거쳐야 한다. 하지만,&nbsp;1~7번 문제를 파란색, 3번을 빨간색, 5번을 빨간색, 8번을 빨간색으로 순서대로&nbsp;칠한다면 작업 횟수는 4번으로 가장 적다.</p>

<p>일우는 매일 500,000문제까지 시도하기 때문에, 이 작업이 꽤나 귀찮아지기 시작했다. 그래서 가장 효율적인 방법으로 위 작업을 수행하기를 원한다. 일우를 도와 각 문제를 주어진 색으로 칠할 때 필요한 최소한의 작업 횟수를 구하는 프로그램을 작성하라.</p>
</section>



## 입력


<p>첫째 줄에 색을 칠해야 하는 문제의 수&nbsp;<em>N&nbsp;</em>(1 ≤&nbsp;<em>N</em>&nbsp;≤ 500,000)이 주어진다.</p>

<p>둘째 줄에&nbsp;<em>N</em>개의 문자가&nbsp;공백 없이 순서대로&nbsp;주어진다. 각 문자는&nbsp;<em>i</em>번째 문제를&nbsp;어떤 색으로 칠해야 하는지를 의미하며,&nbsp;<code>R</code>은 빨간색,&nbsp;<code>B</code>는 파란색을 나타낸다. 그 외에&nbsp;다른 문자는 주어지지 않는다.</p>



## 출력


<section id="output">
<p>첫째 줄에 일우가 주어진 모든 문제를&nbsp;원하는 색으로&nbsp;칠할 때까지 필요한 작업 횟수의 최솟값을 출력하라.</p>
</section>



## 소스코드

[소스코드 보기](블로그2.cpp)