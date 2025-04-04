# 21938번: 영상처리 - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/21938)


<p>간단하지만 귀찮은&nbsp;영상처리 과제가 주어졌다. 과제의 명세는 다음과 같다.</p>

<p>세로 길이가 $N$이고 가로 길이가 $M$인 화면은 총 $N$ ×&nbsp;$M$개의 픽셀로 구성되어 있고 $(i, j)$에 있는&nbsp;픽셀은 $R_{i,j}$ (Red), $G_{i,j}$ (Green), $B_{i,j}$ (Blue) 3가지 색상의 의미를 담고 있다. 각 색상은 0이상 255이하인 값으로 표현 가능하다.</p>

<p>모든 픽셀에서 세 가지 색상을 평균내어 경계값 $T$보다 크거나 같으면 픽셀의 값을 255로, 작으면 0으로 바꿔서 새로운 화면으로 저장한다.</p>

<p>새로 만들어진 화면에서 값이 255인 픽셀은&nbsp;물체로 인식한다. 값이 255인 픽셀들이 상하좌우로 인접해있다면 이 픽셀들은 같은 물체로 인식된다.</p>

<p>화면에서 물체가 총 몇 개 있는지 구하는 프로그램을 작성하시오.</p>



## 입력


<p>화면의 세로 $N$, 가로 $M$ 값이 공백으로 구분되어 주어진다.</p>

<p>두 번째 줄부터 $N + 1$줄까지 $i$번째 가로를 구성하고 있는 픽셀의 $R_{i,j}$, $G_{i,j}$, $B_{i,j}$의 값이 공백으로 구분되어 총 $M$개 주어진다.</p>

<p>마지막 줄에는 경계값 $T$가 주어진다.</p>



## 출력


<p>화면에 있는 물체의 개수를 출력하라. 만약 물체가 없으면 0을 출력하면 된다.</p>



## 소스코드

[소스코드 보기](영상처리.cpp)