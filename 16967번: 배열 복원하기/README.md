# 16967번: 배열 복원하기 - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/16967)


<p>크기가 H × W인 배열 A와 두 정수 X와 Y가 있을 때, 크기가 (H + X) × (W + Y)인 배열 B는 배열 A와&nbsp;배열 A를 아래로 X칸, 오른쪽으로 Y칸 이동시킨 배열을&nbsp;겹쳐 만들 수 있다. 수가 겹쳐지면 수가 합쳐진다.</p>

<p>즉, 배열 B의 (i, j)에 들어있는 값은 아래 3개 중 하나이다.</p>

<ul>
<li>(i, j)가 두 배열 모두에 포함되지 않으면, B<sub>i,j</sub> = 0이다.</li>
<li>(i, j)가 두 배열 모두에 포함되면, B<sub>i,j</sub> = A<sub>i,j</sub> + A<sub>i-X,j-Y</sub>이다.</li>
<li>(i, j)가 두 배열 중 하나에 포함되면, B<sub>i,j</sub> = A<sub>i,j</sub> 또는 A<sub>i-X,j-Y</sub>이다.</li>
</ul>

<p>배열 B와 정수 X, Y가 주어졌을 때, 배열 A를 구해보자.</p>



## 입력


<p>첫째 줄에 네 정수 H, W, X, Y가 주어진다. 둘째 줄부터 H + X개의 줄에 배열 B의 원소가 주어진다.</p>

<p>항상 배열 A가 존재하는 경우만 입력으로 주어진다.</p>



## 출력


<p>총 H개의 줄에 배열 A의 원소를 출력한다.</p>



## 소스코드

[소스코드 보기](배열%20복원하기.cpp)