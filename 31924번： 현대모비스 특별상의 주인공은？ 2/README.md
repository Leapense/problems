# 31924번: 현대모비스 특별상의 주인공은？ 2 - <img src="https://static.solved.ac/tier_small/6.svg" style="height:20px" /> Silver V

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/31924)


<p style="text-align: center;"><img data-image="2bac06c4-3e43-4a4e-a817-0115df85cc78" src="https://upload.acmicpc.net/2bac06c4-3e43-4a4e-a817-0115df85cc78/-/preview/" style="width: 300px; height: 105px;"></p>

<p>올해도 어김없이 현대모비스는 실력 있는 소프트웨어 인재를 양성하고 독려하기 위해 APC의 주최 동아리인 A.N.S.I.를 후원하고 있다. 올해 현대모비스는 2024 APC에 참가한 여러분들을 위해 특별상을 준비하였다.</p>

<p>현대모비스는 $N \times N$ 크기의 격자판을 준비하였다. 격자판의 각 칸에는 알파벳 대문자가 한 글자씩 적혀있다. 특별상은 이 격자판에서 가장 많은 <span style="color:#e74c3c;"><code>MOBIS</code></span>를 찾은 사람에게 주어지는데, <code><span style="color:#e74c3c;">MOBIS</span></code>를 찾는 것은 다음의 규칙을 따른다.</p>

<ul>
<li>격자 위의 임의 위치에서 시작하여 상, 하, 좌, 우, 대각선의 8방향 중 한 방향으로 격자에 적힌 글자들을 차례로 5개 이어 붙였을 때, 이어 붙인 글자가 <span style="color:#e74c3c;"><code>MOBIS</code></span>여야 한다.</li>
</ul>

<p>현빈이는 어떻게든 특별상의 주인공이 되고 싶다. 현빈이를 도와 주어진 격자판에서 <span style="color:#e74c3c;"><code>MOBIS</code></span>를 최대 몇 번 찾을 수 있는지 구해보자.</p>



## 입력


<p>첫 번째 줄에 정수 $N$이 주어진다. $(1 \leq N \leq 100)$</p>

<p>두 번째 줄부터 $N+1$번째 줄까지, 현대모비스가 준비한 격자판의 정보가 주어진다. 각 줄은 $N$개의 알파벳 대문자로 이루어져 있다.</p>



## 출력


<p>주어진 격자판에서 찾을 수 있는 <span style="color:#e74c3c;"><code>MOBIS</code></span>의 개수를 출력한다.</p>



## 소스코드

[소스코드 보기](현대모비스%20특별상의%20주인공은？%202.cpp)