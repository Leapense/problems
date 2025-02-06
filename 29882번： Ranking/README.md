# 29882번: Ranking - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/29882)


<p>Charlotte Michelle Simone is organizing the Especially Interesting Olympiad. Now she has the solutions of all the participants and needs to compile the ranking.</p>

<p>There are several tasks in the olympiad. Each participant can submit any number of solutions for each task, and each solution scores some number of points. The score of a participant for a task is the maximum of the scores of their solutions for that task (or zero, if they did not submit any solutions for that task). The total score of a participant is the sum of their scores over all tasks.</p>

<p>Write a program to compile the ranking of the participants according to their total scores.</p>



## 입력


<p>The first line contains an integer $N$, the number of solutions submitted ($1 \le N \le 200\,000$).</p>

<p>Each of the following $N$ lines describes one solution, giving the account name of the participant, the name of the task, and the number of points the solution scored, separated from each other by spaces. Each account name and each task name consists of 1 to 20 lower-case letters of the Latin alphabet. Each solution may score 0 to 100 points (always an integer).</p>

<p>You may assume that there are no more than $10\,000$ participants and no more than $10$ tasks.</p>



## 출력


<p>Output one line per participant, listing their account name and total score, separated by a space. The lines should be ordered in the non-increasing order of the scores. The lines with equal scores may be listed in any order.</p>



## 소스코드

[소스코드 보기](Ranking.cpp)