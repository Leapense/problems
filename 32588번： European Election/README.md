# 32588번: European Election - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/32588)


<p>The European presidential election of 2042 are coming up soon. The First Presidential Committee has devised the most objective and representative election method. Every candidate is individually compared to every other candidate. The winner of the election is going to be the one candidate who is preferred over all other candidates.</p>

<p>To facilitate this, on their ballot, each voter lists candidates in order of preference. From those rankings, the head-to-head preferences of each voter are inferred. Not all candidates have to be ranked by every voter -- omitted candidates are considered to all be ranked last by the voter (with no preference between them). A candidate is better than another candidate if more people prefer that candidate over the other one. If a candidate is better than every other candidate, they win the election.</p>

<p>Consider the second sample input, where there are seven voters and three candidates. In the head-to-head battle between candidates $1$ and $2$, four voters prefer candidate $1$ and two voters prefer candidate $2$ (one voter is indifferent about both), so candidate $1$ wins that head-to-head match-up. Between candidates $1$ and $3$, four people prefer candidate $1$, and three people prefer candidate $3$, thus candidate $1$ is better. Therefore, candidate $1$ wins the election.</p>

<p>In case no candidate wins against all other candidates, then the results of the election are inconclusive -- there is no winner. If, in a head-to-head battle, two candidates have the same number of preferences, then neither of them is considered better than the other. Thus, neither of them would be able to win the election.</p>

<p>Given the contents of each ballot, determine whether the election has a conclusive winner, and if so, who that winner is.</p>



## 입력


<p>The input consists of:</p>

<ul>
<li>One line with integers $n$ and $k$ ($1 \leq n \leq 2000$, $1 \leq k \leq 200$), denoting the number of ballots cast and the number of candidates.</li>
<li>
<p>\item $n$ lines, one for each ballot.</p>

<p>Each line starts with an integer $v$ ($0 \leq v \leq 200$), the number of preferences on this ballot.</p>

<p>The remainder of this line has $v$ integers $p$ ($1 \leq p \leq k$), denoting the preferences of this voter -- the first integer is the number of the voter's first preference candidate, the second integer is their second preference, and so on.</p>

<p>All the candidates that are unranked (i.e. not mentioned in the ballot) are considered to be all ranked last (i.e.\ tied with each other).</p>
</li>
</ul>



## 출력


<p>If the election has a conclusive winner, output the number of the candidate who wins the election. Otherwise, output "<code>impossible</code>".</p>



## 소스코드

[소스코드 보기](Main.java)