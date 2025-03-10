# 9845번: Housing - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/9845)


<p>For the Youth Olympic Games in Singapore, the administration is considering to house each team in several units with at least 5 people per unit. A team can have from 5 to 100 members, depending on the sport they do. For example, if there are 16 team members, there are 6 ways to distribute the team members into units: (1) one unit with 16 team members; (2) two units with 5 and 11 team members, respectively; (3) two units with 6 and 10 team members, respectively; (4) two units with 7 and 9 team members, respectively; (5) two units with 8 team members each; (6) two units with 5 team members each plus a third unit with 6 team members. This list might become quite lengthy for a large team size.</p>

<p>In order to see how many choices to distribute the team members there are, the administration would like to have a computer program that computes for a number n the number m(n) of possible ways to distribute the team members into the units allocated, with at least 5 people per unit. Note that equivalent distributions like 5 + 5 + 6, 5 + 6 + 5 and 6 + 5 + 5 are counted only once. So m(16) = 6 (as seen above), m(17) = 7 (namely 17, 5 + 12, 6 + 11, 7 + 10, 8 + 9, 5 + 5 + 7, 5 + 6 + 6) and m(20) = 13.</p>

<p>The computer program should read the number n and compute m(n).</p>



## 입력


<p>The input contains just one number which is the number n as described above, where 5 ≤ n ≤ 100. A sample file is the following.</p>



## 출력


<p>The output consists of a single integer that is the number m(n) as specified above. As n is at most 100, one can estimate that m(n) has at most 7 decimal digits. A sample file (for the input n = 20) is the following.</p>



## 소스코드

[소스코드 보기](Housing.cpp)