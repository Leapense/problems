# 23730번: Guessing Answers - <img src="https://static.solved.ac/tier_small/6.svg" style="height:20px" /> Silver V

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/23730)


<p>Yunee did not study for the final exam. So Yunee decided to guess the answers to all problems in the final exam. The final exam consists of $N$ single choice questions numbered from $1$ to $N$, each with a choice of $1$ to $5$.</p>

<p>Yunee gets anxious when the answers to two successive problems are the same. So Yunee always selects an answer different from the answer to the previous problem (except for the first problem). After submitting the answers, Yunee received the grading result, which stated whether each answer was correct.</p>

<p>Given the correct answers to all problems and the $M$ problems that Yunee guessed correctly, reconstruct a possible sequence of Yunee's answers. It is guaranteed that at least one such sequence exists for each input.</p>



## 입력


<p>The first line contains two integers $N$ and $M$ $(1 \leq N \leq 100,000, 1\leq M \leq N)$. $N$ is the total number of problems. $M$ is the number of problems that Yunee guessed correctly.</p>

<p>The second line contains $N$ integers from $1$ to $5$. The $i$-th integer represents the correct answer to the $i$-th problem.</p>

<p>The third line contains $M$ distinct integers from $1$ to $N$. They represent the $M$ problems that Yunee guessed correctly.</p>



## 출력


<p>Output a possible sequence of Yunee's answers. Each number should be separated by a blank.</p>



## 소스코드

[소스코드 보기](Guessing%20Answers.cpp)