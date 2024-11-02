# 31844번: 창고지기 - <img src="https://static.solved.ac/tier_small/4.svg" style="height:20px" /> Bronze II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/31844)


<p>인하대학교의 자료구조 · 알고리즘 연구 소모임 CTP는 스터디에 필요한 비품들을 비좁은 창고에 보관하고 있다. 창고는 아래의 그림과 같이 일렬로 나열된 $1\times1$ 크기의 칸 $10$개로 이루어져 있다. 각 칸에는 로봇 또는 박스가 하나 있을 수 있으며, 창고에는 로봇과 박스가 정확히 하나씩 있다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/5e262bc1-2767-4909-baec-62519e075145/-/preview/" style="height: 120px; width: 524px;"></p>

<p>CTP의 창고지기 시은이는 로봇에게 명령을 내려 박스를 원하는 칸으로 옮기려고 한다. 로봇에게 내릴 수 있는 명령은 다음 두 종류이다.</p>

<ul>
<li>인접한 빈칸으로 이동한다.</li>
<li>인접한 칸의 박스를 밀고 박스가 있던 칸으로 이동한다. 박스는 밀려날 때 로봇이 없는 인접한 칸으로 이동한다. 이 명령은 박스가 밀려날 수 있는 칸이 없다면 실패한다.</li>
</ul>

<p>위 그림의 경우 두 번의 명령으로 박스를 원하는 칸(깃발로 표시)으로 이동시킬 수 있다. 창고의 상태가 주어지면 적어도 몇 번의 명령을 해야 박스를 원하는 칸에 둘 수 있을지 알아보자.</p>



## 입력


<p>첫 번째 줄에 창고의 상태를 나타내는 $10$개의 문자가 주어진다.</p>

<p>각 문자는 ‘<span style="color:#e74c3c;"><code>.</code></span>’, ‘<span style="color:#e74c3c;"><code>@</code></span>’, ‘<span style="color:#e74c3c;"><code>#</code></span>’, ‘<span style="color:#e74c3c;"><code>!</code></span>’ 중 하나로, 각각 빈칸, 로봇이 있는 칸, 박스가 있는 칸, 박스를 놓아야 하는 칸을 뜻한다. </p>

<p>‘<span style="color:#e74c3c;"><code>@</code></span>’, ‘<span style="color:#e74c3c;"><code>#</code></span>’, ‘<span style="color:#e74c3c;"><code>!</code></span>’는 정확히 하나씩 주어진다. 즉, 박스가 처음부터 목표 지점에 있는 경우는 주어지지 않는다.</p>



## 출력


<p>적어도 몇 번의 명령을 해야 박스를 원하는 칸에 둘 수 있는지 출력한다.</p>

<p>몇 번의 명령을 내려도 박스를 원하는 칸으로 옮길 수 없다면 대신 ‘<span style="color:#e74c3c;"><code>-1</code></span>’을 출력한다.</p>



## 소스코드

[소스코드 보기](창고지기.py)