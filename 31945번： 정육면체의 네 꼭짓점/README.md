# 31945번: 정육면체의 네 꼭짓점 - <img src="https://static.solved.ac/tier_small/4.svg" style="height:20px" /> Bronze II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/31945)


<p>$3$차원 좌표공간 위의 $8$개의 점 $P_0 = (0,0,0)$, $P_1 = (0,0,1)$, $P_2 = (0,1,0)$, $P_3 = (0,1,1)$, $P_4 = (1,0,0)$, $P_5 = (1,0,1)$, $P_6 = (1,1,0)$, $P_7 = (1,1,1)$을 꼭짓점으로 하는 정육면체 $S$가 있다.</p>

<p>주어진 네 꼭짓점이 정육면체 $S$의 한 면 위에 있는지 판정해 보자.</p>



## 입력


<p>첫째 줄에 테스트 케이스의 개수 $T$가 주어진다. $( 1 \le T \le 2  000 )$</p>

<p>둘째 줄부터 $T$개의 줄에 걸쳐 정육면체 $S$의 각 꼭짓점을 의미하는 서로 다른 네 정수 $a$, $b$, $c$, $d$가 공백으로 구분되어 주어진다. $(0 \le a, b, c, d \lt 8)$</p>



## 출력


<p>각 테스트케이스마다 한 줄에 하나씩 $P_a$, $P_b$, $P_c$, $P_d$가 정육면체 $S$의 한 면 위에 있는 네 꼭짓점이면 <span style="color:#e74c3c;"><code>YES</code></span>, 그렇지 않으면 <span style="color:#e74c3c;"><code>NO</code></span>를 출력한다.</p>



## 소스코드

[소스코드 보기](정육면체의%20네%20꼭짓점.py)