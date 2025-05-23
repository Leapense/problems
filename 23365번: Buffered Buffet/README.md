# 23365번: Buffered Buffet - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/23365)


<p>Finally, you are allowed again to invite your friends over for a delicious buffet! However, you still need to take social distancing measures into account. To complicate matters further, your friends are coming from various different countries. Each of these countries has slightly different social distancing rules. For example, your friends from the US are required to sit at least $2$ meters from another person, while your friends from France only need to sit $1$ meter apart from others.</p>

<p>You would like for all your friends to sit around one large circular table. You want to position your friends at this table in such a way that everyone complies with the social distancing requirements of their respective country. To make matters a bit easier, the distance between two people sitting at the table is calculated along the circumference. What is the minimum circumference of the table such that everyone can comply with their social distancing requirement?</p>



## 입력


<p>The input consists of:</p>

<ul>
<li>One line containing an integer $n$ ($2 \le n \le 10^{5}$), the number of people sitting at the table (yourself included).</li>
<li>One line containing $n$ integers $d_1, \dots, d_n$ ($1 \le d_i \le 10^{9}$), how many meters each person needs to sit apart from others (measured along the circumference of the table).</li>
</ul>



## 출력


<p>Output the minimum circumference of the table in meters such that everyone can sit at the table while respecting their social distancing measures.</p>



## 소스코드

[소스코드 보기](Buffered%20Buffet.cpp)