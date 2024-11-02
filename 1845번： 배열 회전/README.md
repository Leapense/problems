# 1845번: 배열 회전 - <img src="https://static.solved.ac/tier_small/30.svg" style="height:20px" /> Ruby I

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/1845)


<p>1부터 N까지의 자연수가 차례로 적혀 있는 배열이 있다. 아래의 배열은 N=6인 경우의 예이다.</p>

<table class="table table-bordered table-center-30 td-center">
<tbody>
<tr>
<td style="width:5%">1</td>
<td style="width:5%">2</td>
<td style="width:5%">3</td>
<td style="width:5%">4</td>
<td style="width:5%">5</td>
<td style="width:5%">6</td>
</tr>
</tbody>
</table>

<p>이러한 배열에서 임의의 구간 (a, b)를 잡아, 그 구간에 포함되는 수들을 회전시킬 수 있다. 회전을 하게 되면 a번째 칸부터 b번째 칸까지 적혀 있는 수의 순서가 뒤집히고, 부호 또한 바뀌게 된다. (1 ≤ a ≤ b ≤ N) 예를 들어 위의 배열에서 (1, 4)에서 회전을 수행한 결과는 아래와 같이 된다.</p>

<table class="table table-bordered table-center-30 td-center">
<tbody>
<tr>
<td style="width:5%">-4</td>
<td style="width:5%">-3</td>
<td style="width:5%">-2</td>
<td style="width:5%">-1</td>
<td style="width:5%">5</td>
<td style="width:5%">6</td>
</tr>
</tbody>
</table>

<p>이미 회전을 수행한 배열에 대해서도 물론 계속 회전을 수행할 수 있다. 다시 (3, 5)에서 회전을 수행하면 최종 배열 상태는 아래와 같이 된다.</p>

<table class="table table-bordered table-center-30 td-center">
<tbody>
<tr>
<td style="width:5%">-4</td>
<td style="width:5%">-3</td>
<td style="width:5%">-5</td>
<td style="width:5%">1</td>
<td style="width:5%">2</td>
<td style="width:5%">6</td>
</tr>
</tbody>
</table>

<p>초기 배열에는 1부터 N까지의 자연수가 차례로 적혀 있다. 최종 배열 상태가 주어졌을 때 가급적 적은 횟수의 회전 연산을 수행하여 초기 배열에서 최종 배열을 만드는 프로그램을 작성하시오.</p>



## 입력


<p>첫째 줄에 배열의 크기 N(1 ≤ N ≤ 250)이 주어진다. 둘째 줄에는 최종 배열 상태가 빈 칸을 사이에 두고 순서대로 주어진다. 주어지는 수열에는 절댓값이 1 이상 N 이하인 수들이 모두 한 번씩 등장한다.</p>



## 출력


<p>첫 줄에 회전 연산의 사용 횟수 K를 출력한다. 이어서 K줄에 걸쳐 연산을 사용한 순서대로 회전 연산을 사용한 구간 (a, b)를 나타내는 두 정수 a와 b를 빈 칸을 사이에 두고 출력한다. (1 ≤ a ≤ b ≤ N)</p>



## 소스코드

[소스코드 보기](배열%20회전.cpp)