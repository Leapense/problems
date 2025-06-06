# 16065번: Down the Pyramid - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/16065)


<p>Do you like number pyramids? Given a number sequence that represents the base, you are usually supposed to build the rest of the “pyramid” bottom-up: For each pair of adjacent numbers, you would compute their sum and write it down above them. For example, given the base sequence [1, 2, 3], the sequence directly above it would be [3, 5], and the top of the pyramid would be [8]:</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/5f3258d9-6971-4977-801f-a5334a4086f7/-/preview/" style="width: 191px; height: 100px;"></p>

<p>However, I am not interested in completing the pyramid – instead, I would much rather go underground. Thus, for a sequence of n non-negative integers, I will write down a sequence of n + 1 non-negative integers below it such that each number in the original sequence is the sum of the two numbers I put below it. However, there may be several possible sequences or perhaps even none at all satisfying this condition. So, could you please tell me how many sequences there are for me to choose from?</p>



## 입력


<p>The input consists of:</p>

<ul>
<li>one line with the integer n (1 ≤ n ≤ 10<sup>6</sup>), the length of the base sequence.</li>
<li>one line with n integers a<sub>1</sub>, . . . , a<sub>n</sub> (0 ≤ a<sub>i</sub> ≤ 10<sup>8</sup> for each i), forming the base sequence.</li>
</ul>



## 출력


<p>Output a single integer, the number of non-negative integer sequences that would have the input sequence as the next level in a number pyramid.</p>



## 소스코드

[소스코드 보기](Down%20the%20Pyramid.cpp)