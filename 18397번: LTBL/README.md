# 18397번: LTBL - <img src="https://static.solved.ac/tier_small/6.svg" style="height:20px" /> Silver V

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/18397)


<p>The Afghanistan League of Football has grown larger in the last few years. Ranking the teams in the league is a very important part of every league, and people want to understand what the current status of the league is. The league administration wants to create a website and publish the match result for public access. They need a program that can generate the data for the ranking table based on the match results. Write a program to help them with this problem.</p>

<p>Note:</p>

<ul>
<li>A team wins if they score more goals than the other team</li>
<li>A match is a draw if both teams score the same number of goals</li>
<li>A team will receive 3 points for each win, 1 for each draw, and a 0 for each loss</li>
<li>Sort the table based on points (higher first), number of wins (higher first), number of draw (higher first), number of loss (lower first), number of scored goals (higher first), and number of received goals (lower first)</li>
<li>To teams can play multiple times with each other.</li>
<li>Some teams may play more games than other teams, e.g.: in the left every team played 4 games. And in the right with the same number of teams, each played different numbers of games.</li>
</ul>



## 입력


<p>First line contains the number of test cases (T): 0 &lt; T &lt; 1000</p>

<p>Next line contains the number of matches (M): 0 &lt; M &lt;= 256</p>

<p>Each next line contains the match result between two teams in this format:</p>

<ul>
<li>team1 [team1_goals_count - team2_goals_count] team2 0 &lt; len(team[1 and 2]) &lt; 100, 0 &lt;= team[1 and 2]_goals_count &lt; 20</li>
<li>E.g.: Shahin [2 - 2] Hariwa</li>
</ul>



## 출력


<p>Print the league table for each test case in the following format:</p>

<ul>
<li>team-name,points,wins,draw,loss,goals-scored,goals-received E.g.: Shahin,12,3,0,0,10,2</li>
</ul>

<p>Separate each test case output with an empty line (no empty line after the last testcase result).</p>



## 소스코드

[소스코드 보기](LTBL.cpp)