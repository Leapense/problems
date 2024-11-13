# 31301번: Contest Advancement - <img src="https://static.solved.ac/tier_small/7.svg" style="height:20px" /> Silver IV

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/31301)


<p>You are the RCD for your regional contest. It just ended and you now need to decide which teams qualify for the next level of competition. The teams are uniquely ranked (there are no ties). The next level has a limit on how many teams from any given school can participate. However, if that limit causes there to be not enough teams advancing, the remaining slots will be filled by teams from schools over the limit. If this happens, you will always give preference to higher-ranking teams, even if it means many teams from the same school advancing.</p>

<p>Output, in rank order, the teams that qualify for the next contest.</p>



## 입력


<p>The first line of input contains three integers $n$, $k$ ($1 \leq k &lt; n \leq 10^5$) and $c$ ($ 1 \leq c \leq n$), where $n$ is the number of teams in the competition, $k$ is the number of teams that will advance, and $c$ is the limit on the number of teams that may advance from any given school.</p>

<p>Each of the next $n$ lines contains two integers $t$ and $s$ ($1 \le t,s \le n$). Each line describes a team, with $t$ being the team's unique ID, and $s$ indicating the team's school. All team IDs will be distinct. The teams will be listed in rank order, with the highest ranking teams first.</p>



## 출력


<p>Output $k$ lines. On each line output a single integer, which is the ID of a team. List the IDs of the teams that qualified to advance in rank order.</p>



## 소스코드

[소스코드 보기](Contest%20Advancement.py)