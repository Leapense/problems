# 21869번: Maximum Bishop - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/21869)


<p>체스에는 대각선 방향으로 움직일 수 있는 비숍(bishop)이 있다. 다음 그림과 같은 $5\times5$ 정사각형 체스판 위의&nbsp;B라고 표시된 곳에 비숍이 있을 때, 비숍은 대각선 방향으로 움직여 X로 표시된 칸에 있는 다른 말을 잡을 수 있다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/4864578c-b38e-4dbb-a0b5-2e056e63efcf/-/preview/"></p>

<p>$N$-Maximum Bishop 문제는 $N \times N$ 체스판 위에&nbsp;최대한 많은 비숍을 서로 공격할 수 없도록&nbsp;배치하는&nbsp;문제다.</p>

<p>$N$이 주어졌을 때, 최대한 많은 비숍을 서로 공격할 수 없도록&nbsp;배치해보자.</p>



## 입력


<p>첫째 줄에 N이 주어진다.&nbsp;($1 \leq N \leq 524\,288$)</p>



## 출력


<p>배치할&nbsp;수 있는 비숍의 최대&nbsp;개수 $M$을&nbsp;첫 번째 줄에 출력한다.&nbsp;이후 $M$개의&nbsp;줄에 걸쳐 비숍을 배치해야 하는 행의 번호와 열의 번호를 공백으로 구분해서 출력한다. 행과 열의 번호는 $1$부터 시작한다.</p>

<p>답이 여러 개인 경우에는 그중 아무거나 출력한다.</p>



## 소스코드

[소스코드 보기](Maximum%20Bishop.cpp)