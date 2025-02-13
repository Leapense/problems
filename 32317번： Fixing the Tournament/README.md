# 32317번: Fixing the Tournament - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/32317)


<p>The most common type of tournament is a single elimination tournament that occurs in rounds. In order to run one of these tournaments, the total number of teams initially included must be a perfect power of 2. For example, if a tournament starts with 16 (2<sup>4</sup>) teams, in the first round there will be 8 matches, resulting in 8 winning teams and 8 losing teams. In the second round, the 8 winning teams from the first round get paired up into four match ups. The process of pairing the winners continues until the final round when two teams remain and play in the championship match.</p>

<p>For the purposes of this problem, assume that:</p>

<ul>
<li>the teams are ranked from 1 to 2<sup>n</sup>, for a positive integer n</li>
<li>the best team is ranked 1 and the worst team is ranked 2<sup>n</sup> (this is referred to as “one-based ranking”)</li>
<li>any time a team with a better rank (lower numbered ranking) plays a team with a worse ranking, the better ranked team wins.</li>
</ul>

<p>The only thing not set for a tournament is which teams are going to play which teams in each round. You've hacked into the tournament software and can choose any set of pairings of the remaining teams for the matches in each round. Naturally, you'd like to figure out the latest round in the tournament your favorite team might make it to!</p>

<p>Given the number of rounds for a single elimination tournament and your team's one-based ranking, determine the highest round number your team could reach if you are able to create the match ups for each round optimally.</p>



## 입력


<p>There is only one input line; it contains two integers: n (2 ≤ n ≤ 20), indicating the number of rounds for the tournament and r (1 ≤ r ≤ 2<sup>n</sup>), indicating your team's one-based ranking.</p>



## 출력


<p>Print, on a line by itself, the highest number round your team could reach.</p>



## 소스코드

[소스코드 보기](Fixing%20the%20Tournament.cpp)