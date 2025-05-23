# 24939번: Boardle - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/24939)


<p>Boardle 게임은 $N \times M$ 크기의 격자판에서 이루어집니다. 격자판의 마주보는 두 꼭짓점은 $(1, 1)$과 $(N, M)$입니다. 격자판의 $NM$개 칸 중 하나에 보물이 숨겨져 있습니다. 보물을 찾으면 게임에서 승리합니다.</p>

<p>보물을 찾기 위해, 당신은 아래와 같이 $Q$회의 질문을 했습니다.</p>

<ul>
<li>점 $(x, y)$를 기준으로, 보물이 어느 방향에 숨겨져 있습니까?</li>
</ul>

<p>그 결과는 동/서/남/북/북동/북서/남동/남서/일치 중 하나로 나타낼 수 있습니다. 이때 동쪽은 $+x$,&nbsp;서쪽은 $-x$, 북쪽은 $+y$, 남쪽은 $-y$에 해당하는 방향입니다. $Q$개의 질문에 대한 대답을 통해, 보물이 있을 수 있는 격자 칸의 후보의 수를 구해 봅시다.</p>



## 입력


<p>첫 줄에는 격자판의 크기를 나타내는 정수 $N$과 $M$이 주어집니다.</p>

<p>둘째 줄에는 질의의 수 $Q$가 띄어쓰기를 사이에 두고 주어집니다.</p>

<p>셋째 줄부터 $Q+2$번 줄까지, $i+2$번 줄에는 $i$번 질문에 대한 정보가 $x_i$ $y_i$ $d_i$의 형태로 주어집니다. $x_i$와 $y_i$는 $i$번째로 질문한 점의 위치를 나타냅니다. $d_i$는 1 이상 9 이하의 정수로, 아래와 같이 각 방향에 대응됩니다.</p>

<table border="1" cellpadding="1" cellspacing="1" class="table table-bordered" style="width: 500px;">
<tbody>
<tr>
<td style="text-align: center;">1</td>
<td style="text-align: center;">2</td>
<td style="text-align: center;">3</td>
<td style="text-align: center;">4</td>
<td style="text-align: center;">5</td>
<td style="text-align: center;">6</td>
<td style="text-align: center;">7</td>
<td style="text-align: center;">8</td>
<td style="text-align: center;">9</td>
</tr>
<tr>
<td style="text-align: center;">동쪽</td>
<td style="text-align: center;">서쪽</td>
<td style="text-align: center;">남쪽</td>
<td style="text-align: center;">북쪽</td>
<td style="text-align: center;">북동쪽</td>
<td style="text-align: center;">북서쪽</td>
<td style="text-align: center;">남동쪽</td>
<td style="text-align: center;">남서쪽</td>
<td style="text-align: center;">일치</td>
</tr>
</tbody>
</table>

<p>$1 \le d_i \le 4$인 경우&nbsp;<strong>정확히 해당 방향</strong>에 있다는 의미입니다. 즉, $d_i =4$인 경우 보물은 선택한 점의 북서쪽이나 북동쪽이 아닌 정북 방향에 위치합니다.</p>

<table border="1" cellpadding="1" cellspacing="1" class="table table-bordered" style="width: 500px;">
<tbody>
<tr>
<td style="text-align: center;">+</td>
<td style="text-align: center;">6</td>
<td style="text-align: center;">4</td>
<td style="text-align: center;">5</td>
</tr>
<tr>
<td style="text-align: center;">y</td>
<td style="text-align: center;">2</td>
<td style="text-align: center;"><strong>9</strong></td>
<td style="text-align: center;">1</td>
</tr>
<tr>
<td style="text-align: center;">-</td>
<td style="text-align: center;">8</td>
<td style="text-align: center;">3</td>
<td style="text-align: center;">7</td>
</tr>
<tr>
<td style="text-align: center;">&nbsp;</td>
<td style="text-align: center;">-</td>
<td style="text-align: center;">x</td>
<td style="text-align: center;">+</td>
</tr>
</tbody>
</table>



## 출력


<p>보물이 숨겨져 있을 수 있는 칸의 개수를 출력합니다. 이러한 후보 칸이 반드시 존재함이 보장됩니다.</p>



## 소스코드

[소스코드 보기](Boardle.py)