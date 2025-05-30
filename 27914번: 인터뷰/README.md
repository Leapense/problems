# 27914번: 인터뷰 - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/27914)

<p>서울과학고의 급식실은 줄이 깁니다. 은호는 줄을 선 사람들 중 연속한 위치에 있는 몇 명을 골라 인터뷰를 하려고 합니다. 단, 은호와 같은 학년의 학생은 인터뷰를 할 수 없습니다.</p>

<p>현재 급식실에는 $N$명의 학생이 줄을 서 있습니다. 은호는 문득 자신이 인터뷰를 할 수 있는 방법이 몇 가지나 될지 궁금해졌습니다. 다음과 같은 $Q$개의 질문에 답해 은호의 궁금증을 풀어 줍시다.</p>

<ul>
<li>앞 $X_i$명의 학생들 중 연속한 몇 명을 골라 인터뷰를 할 때, 자신과 같은 학년의 학생이 한 명도 없도록 고르는 방법의 수는 몇 가지인가?</li>
</ul>

## 입력

<p>첫 줄에 학생의 수 $N$과 은호의 학년을 나타내는 정수 $K$, 그리고 질문의 수 $Q$가 주어집니다. 둘째 줄에 줄을 서 있는 학생들의 학년 $A_1$, $A_2$, $\cdots$, $A_N$이 띄어쓰기를 사이에 두고 주어집니다. $i$번 학생은 앞에서부터 $i$번째에 서 있는 학생을 말합니다. 셋째 줄에 $Q$개의 질문에 대한 정수 $X_1$, $X_2$, $\cdots$, $X_Q$가 띄어쓰기를 사이에 두고 주어집니다.</p>

## 출력

<p>각 경우에 대해 가능한 인터뷰 대상의 가짓수를 한 줄에 하나씩 출력합니다.</p>

## 소스코드

[소스코드 보기](인터뷰.py)