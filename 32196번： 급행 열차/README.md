# 32196번: 급행 열차 - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/32196)


<p>서울특별시의 한 전철 노선을 급행화하려고 한다. 급행이란, 모든 역을 정차하는 일반(완행) 열차와 다르게 일부 역만 정차하는 방식으로 운행하는 열차이다. 이때, 대피선은 급행 열차가 일반 열차를 앞지르기 위해 설치한다.</p>

<p>이 노선을 일반 열차와 급행 열차 두 종류로 운행하려 한다. 현재 1번 역부터 $N$번 역까지 $N$개의 역이 있는 노선을 운행하는 데 일반 열차와 급행 열차 모두 똑같이 $K$분이 걸린다. $i$ ($1 \le i \le N$)번째 역에 대피선을 설치하면, 일반 열차의 운행 시간은 $A_i$분만큼 증가하고, 급행 열차의 운행 시간은 $B_i$분만큼 감소한다. 대피선은 역마다 최대 한 번만 설치할 수 있다.</p>

<p>이 노선에는 $X$개의 일반 열차와 $Y$개의 급행 열차가 운행하고 있다. 모든 열차의 운행 시간의 합은 $($일반 열차의 운행 시간$) \times X + ($급행 열차의 운행 시간$) \times Y$으로 정의된다. $N$개의 역 중에 <strong>정확히</strong> $M$개의 역을 골라 대피선을 설치하려고 한다. 적절히 대피선을 설치했을 때, 모든 열차의 운행 시간의 합의 최솟값을 구하여라.</p>



## 입력


<p>첫째 줄에 $N$, $M$, $K$, $X$, $Y$가 공백으로 구분되어 주어진다.</p>

<p>둘째 줄부터 $N$개의 줄에 걸쳐, $i$ ($1 \le i \le N$)번째 줄에는 $A_i$, $B_i$가 공백으로 구분되어 주어진다.</p>



## 출력


<p>첫째 줄에 적절히 대피선을 설치하고 난 후, 모든 열차의 운행 시간의 합의 최솟값을 출력한다.</p>



## 소스코드

[소스코드 보기](급행%20열차.cpp)