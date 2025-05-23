# 11087번: Bobby’s Bet - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/11087)


<p>Bobby and Betty have a bet. Betty bets Bobby that he cannot roll an S-sided die (having values 1 through S) and obtain a value ≥ R on at least X out of Y rolls. Betty has a variety of dice with different numbers of sides S, and all her dice are fair (for a given die, each side’s outcome is equally likely). In order to observe statistically rare events while still giving Bobby a reason to bet, Betty offers Bobby W to 1 odds on each encounter. For example, suppose Betty bets Bobby 1 bitcoin that he can’t roll at least a 5 on a 6-sided die at least two out of three times; if Bobby does, she would give him 3 times his initial bet (i.e. she would give him 3 bitcoins). Should Bobby take the bet (is his expected return greater than his original bet)?</p>



## 입력


<p>Input begins with an integer 1 ≤ N ≤ 10 000, representing the number of cases that follow. The next N lines each contain five integers, R, S, X, Y , and W. Their limits are 1 ≤ R ≤ S ≤ 20, 1 ≤ X ≤ Y ≤ 10, and 1 ≤ W ≤ 100.</p>



## 출력


<p>For each case, output “yes” if Bobby’s expected return is greater than his bet, or “no” otherwise. Bobby is somewhat risk averse and does not bet if his expected return is equal to his bet.</p>



## 소스코드

[소스코드 보기](Bobby’s%20Bet.cpp)