# 32935번: 이상한 시행 - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/32935)


<p>길이가 $N$인 수열 $a$가 주어진다. 다음의 시행을 원하는 만큼 하여 $a$의 원소들의 합을 최대로 하려한다. 그 최댓값을 구하여라.</p>

<ul>
<li>현재 $a$의 원소들의 합을 $S$라고 하자. $1 \leq i \leq N$ 인 $i$를 하나 골라 $a_i$의 값을 $-S$로 바꾼다.</li>
</ul>

<p>단, 어떤 상황에서도 답이 무한대가 아님을 보일 수 있다.</p>



## 입력


<p>첫 번째 줄에 수열의 크기를 나타내는 정수 $N$이 주어진다. $(1 \leq N \leq 300\ 000)$</p>

<p>두 번째 줄에 $a_1, a_2, \cdots ,a_N$가 공백으로 구분되어 주어진다. $(-10^9 \leq a_i \leq 10^9)$</p>



## 출력


<p>문제의 답을 출력한다.</p>



## 소스코드

[소스코드 보기](이상한%20시행.cpp)