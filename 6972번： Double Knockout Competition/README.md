# 6972번: Double Knockout Competition - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/6972)


<p>In a number of sports, a championship may be determined by a double knockout competition. A team is eliminated on its second loss, so the winner is the last remaining team with one or fewer losses. The competition is played is a series of rounds: in each round, teams that have not been eliminated are paired subject to the constraint that an undefeated team never plays a team with one loss. As many teams as possible are paired in each round. After a number of rounds only two teams remain. These teams play in a round by themselves, although one is undefeated and the other is not. If neither is eliminated, they play again in a final round. For our analysis we assume that this extra round is always necessary.</p>

<p>Write a program to report on a Double Knockout Competition.</p>



## 입력


<p>The first line of input contains one positive integer n which is the number of test cases which follow it. The next n lines each contain one positive integer t, t &lt; 32768, which is the number of teams in the competition for that test case.</p>



## 출력


<p>For each case there should be an initial line which has the form: Round 0:</p>

<p>2 undefeated, 0 one-loss, 0 eliminated</p>

<p>This is followed by a similar line for each round of the competition, followed by a single line saying how my rounds were played. The output for different test cases is to be separated by a single blank line.</p>



## 소스코드

[소스코드 보기](Double%20Knockout%20Competition.cpp)