# 7638번: Betting Sets - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/7638)


<p>Your local casino (which here in California is a fair distance away) has decided to try out a new betting game. The player is given a table on a card with N rows and M columns. Each entry ij of the table corresponds to a coin flip with a probability p<sub>ij</sub> of coming up heads. All the coin flips are independent of each other. The player must choose N sets of M entries, with each set having exactly one entry from each column, and each entry being used exactly once. For each chosen set where all M coins come up heads, the player wins 1 dollar. The casino is feeling uncharacteristically generous, and so as part of the promotion of this new game, they have been handing out one card to each patron. Since you have nothing to lose, you’re going to give this game a shot. How can you maximize your expected winnings from this card?</p>



## 입력


<p>The input consists of multiple test cases. Each test case begins with a line with two integers N and M, 1 ≤ N ≤ 100, 1 ≤ M ≤ 10, separated by a space. This is followed by N lines with M space-separated numbers each, denoting the entries p<sub>ij</sub> of the table. Input is followed by a single line with N = M = 0, which should not be processed.</p>



## 출력


<p>For each test case, print out a single line with the maximum expected winnings from the given table, accurate to 4 decimal places.</p>



## 소스코드

[소스코드 보기](Main.java)