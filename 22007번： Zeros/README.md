# 22007번: Zeros - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/22007)


<p>Santa Claus is already preparing for Christmas 2021. He wants to buy some positive number of presents, such that he will be able to divide them evenly (without remainder) among all eligible (not naughty) children. However, he does not yet know how many eligible children there will be – he only knows that this number will be between $a$ and $b$. Therefore, he wants to buy the minimum positive number of presents that can be divided evenly between any number $x$ of children with $x \in \{a, a+1, \dots, b\}$.</p>

<p>He has computed this (possibly huge) number of presents, but he is unsure about the correctness, and he would like your help in performing the following basic sanity check. Are you able to tell him how many zero digits there should be at the end of this number?</p>



## 입력


<p>The first and only line of the input consists of two space-separated integers $a$ and $b$ ($1 \le a \le b \le 10^{18}$).</p>



## 출력


<p>Output a single integer -- the number of zeros at the end of the number of presents that Santa needs to buy.</p>



## 소스코드

[소스코드 보기](Zeros.py)