# 30435번: Die Hard - <img src="https://static.solved.ac/tier_small/5.svg" style="height:20px" /> Bronze I

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/30435)


<p>John and Hans are playing a game involving 3 dice. Even though they are all 6-sided, they are not guaranteed to be identical.</p>

<p>First John picks one of the dice and then Hans picks one of the remaining two. Then they both roll their chosen die. If they roll the same number, they both re-roll their die. Otherwise the winner is the one who rolled the highest number.</p>

<p>In case neither John or Hans can win with their chosen dice, they do not bother to re-roll the dice indefinitely and no winner is declared.</p>

<p>Can you help John pick a die that guarantees that he wins with a probability of at least $\frac{1}{2}$?</p>



## 입력


<p>The input consists of three lines. Line $i$ contains $6$ positive integers $x_j$ ($1 \leq x_j \leq 1000$), describing the sides of the $i$'th die.</p>



## 출력


<p>Output the smallest $i \in \{1, 2, 3\}$, such that John can pick die $i$ and be guaranteed to win with probability at least $\frac{1}{2}$. If no such die exists, output "No dice".</p>



## 소스코드

[소스코드 보기](Die%20Hard.cpp)