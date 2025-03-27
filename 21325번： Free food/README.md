# 21325번: Free food - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/21325)


<p>Tonight Hsara is going out for a dinner at a restaurant with his organisation and Hsara is thinking about the chances of someone else paying for the dinner. Exactly one person will pay for the entire dinner (everyone's food), but not any person. It is only allowed to pay for dinner if no supperior (possibly indirect, for example, your boss' boss) in the organisation is present at the table.</p>

<p>The organisation consists of $N$ people numbered from $1$ to $N$. Each person, except for the CEO, has exactly one boss. Given each person's boss and a list of people present at the table, determine how many people are able to pay for the dinner.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/522f8b91-f56a-4ab0-a225-7aea3b7c9fde/-/preview/" style="width: 83px; height: 143px;"></p>

<p style="text-align: center;">Figure 1:&nbsp;Illustration of the organisation in the first sample.</p>



## 입력


<p>The first line consists of two integers, $N$ - the number of people in the organisation and $1 \le M \le N$ - the number of people at the table.</p>

<p>The second line consists of $N$ integers. The $i$:th integer is the boss of person $i$. 0 means that person $i$ is the CEO. There will be exactly one CEO.</p>

<p>The third line consists of $M$ integers indicating the people present at the table.</p>



## 출력


<p>Print an integer - the number of people at the table who would be able to pay for the dinner.</p>



## 소스코드

[소스코드 보기](Free%20food.cpp)