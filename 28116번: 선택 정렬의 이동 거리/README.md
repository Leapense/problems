# 28116번: 선택 정렬의 이동 거리 - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/28116)


<p>$1$부터 $N$까지의 정수가 한 번씩 등장하는 수열 $A$가 주어진다. 이 수열에서 선택 정렬 알고리즘을 수행할 때, 각 수의 이동 거리를 출력하라.</p>

<p>선택 정렬 알고리즘이 무엇인지 잘 모르는 친구들은 친절한 주원이가 준비한 아래 설명을 읽어보도록 하자.</p>

<ul>
<li>길이가 $N$인 수열 $A=\left\{ A_1,A_2,\cdots ,A_N \right\}$을 오름차순으로 정렬하는 선택 정렬 알고리즘은 아래 동작을 $N-1$번 반복해서 수행한다.
<ol>
<li>지금이 $i$번째 동작이라면, $A_i,A_{i+1},\cdots ,A_N$ 중 최솟값 $A_j$를 찾는다.</li>
<li>$A_i$와 $A_j$의 위치를 교환한다. 이때 $A_i$와 $A_j$의 이동 거리가 각각 $(j-i)$만큼 증가한다.</li>
</ol>
</li>
</ul>

<p>예를 들어 $\left\{ 1,3,5,2,4 \right\}$와 같은 수열이 주어졌다고 하자. 처음에 모든 수의 이동 거리는 $0$으로 같다. 선택 정렬 알고리즘은 다음과 같은 과정을 거쳐 수행된다.</p>

<ol>
<li>$A_1=1$과 $A_1=1$을 교환해서 $\left\{ 1,3,5,2,4 \right\}$가 된다. 이때 $1$의 이동 거리는 $0$만큼 증가한다.</li>
<li>$A_2=3$과 $A_4=2$를 교환해서 $\left\{ 1,2,5,3,4 \right\}$가 된다. 이때 $2$와 $3$의 이동 거리는 $2$만큼 증가한다.</li>
<li>$A_3=5$와 $A_4=3$을 교환해서 $\left\{ 1,2,3,5,4 \right\}$가 된다. 이때 $3$과 $5$의 이동 거리는 $1$만큼 증가한다.</li>
<li>$A_4=5$와 $A_5=4$를 교환해서 $\left\{ 1,2,3,4,5 \right\}$가 된다. 이때 $4$와 $5$의 이동 거리는 $1$만큼 증가한다.</li>
</ol>

<p>따라서 $1$은 $0$만큼, $2$는 $2$만큼, $3$은 $3$만큼, $4$는 $1$만큼, $5$는 $2$만큼 이동한다.</p>



## 입력


<p>첫째 줄에 수열의 길이 $N$이 주어진다.</p>

<p>둘째 줄에 수열의 원소 $A_1,A_2,\cdots ,A_N$이 차례대로 공백으로 구분되어 주어진다.</p>



## 출력


<p>첫째 줄에 $N$개의 정수를 공백으로 구분하여 출력한다. $i$번째 정수는 $i$의 이동 거리를 의미한다.</p>



## 소스코드

[소스코드 보기](Main.java)