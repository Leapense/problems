# 27941번: 하이퍼 가지 따기 - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/27941)

<p>하이퍼 나라의 주민들은 매년 하이퍼 가지를 수확하여 특별한 하이퍼 상자에 담는다. 하이퍼 상자는 $11$차원 도형 $\left[L_1, R_1\right] \times$ $\left[L_2, R_2\right] \times$ $\cdots \times$ $\left[L_{11}, R_{11}\right]$로 구성되어 있다고 한다. 다시 말해, 상자 내부의 모든 점 $(x_1,$ $x_2,$ $\cdots,$ $x_{11})$는 모든 정수 $i$ $(1 \le i \le 11)$에 대해 $L_i \le x_i \le R_i$를 만족한다.</p>

<p>사악한 민규는 하이퍼 나라의 하이퍼 가지를 훔쳐가려고 하이퍼 상자를 탈취했다. 하지만 정작 하이퍼 가지를 꺼내지는 못하고 있는데, 이는 하이퍼 상자에서 하이퍼 가지를 넣거나 빼는 방법이 오직 하나, 미리 지정된 유일한 꼭짓점만을 입구로 삼는 것뿐이기 때문이다. 민규는 이 사실을 알아냈지만 입구를 찾지 못해 꼭짓점 하나하나에 손을 넣어 보기로 했고, 무려 $2047$개의 서로 다른 꼭짓점을 시도했지만 입구를 찾지 못하고 포기했다.</p>

<p>여러분은 이 광경을 지켜보고 있었다. 민규가 찾지 못한 하이퍼 상자의 입구를 대신 찾아보자.</p>

## 입력

<p>총 $2047$개의 줄에 걸쳐, $i$째 줄에 민규가 $i$번째로 시도한 꼭짓점의 좌표를 의미하는 $11$개의 정수 $x_{i,1},$ $x_{i,2},$ $\cdots,$ $x_{i,11}$가 주어진다. $(-10^6 \le x_{i, j}\le 10^6)$</p>

## 출력

<p>첫째 줄에 입구의 좌표를 의미하는 $11$개의 정수 $x_1,$ $x_2,$ $\cdots,$ $x_{11}$를 출력한다.</p>

## 소스코드

[소스코드 보기](Main.java)