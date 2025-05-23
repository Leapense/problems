# 22017번: イルミネーション 2 (Illumination 2) - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/22017)


<p>JOI 高校の生徒である葵は，文化祭で廊下に電飾を飾ることにした．</p>

<p>電飾は，<var>N</var>&nbsp;個の電球を東西方向に一列に並べて作る．電球には西側から順に&nbsp;<var>1</var>&nbsp;から&nbsp;<var>N</var>&nbsp;までの番号が付けられている．各電球にはオンとオフの&nbsp;<var>2</var>&nbsp;つの状態があり，はじめ電球はすべてオフの状態である．</p>

<p>葵が目標とする電飾の模様は数列&nbsp;<var>A<sub>1</sub>, A<sub>2</sub>, ..., A<sub>N</sub></var>&nbsp;で表され，<var>A<sub>i</sub>&nbsp;= 1</var>&nbsp;のときは電球&nbsp;<var>i</var>&nbsp;をオンに，<var>A<sub>i</sub>&nbsp;= 0</var>&nbsp;のときはオフにしたい．葵はできるだけ短い時間でこの模様にしようと考えた．</p>

<p>葵は最初に次の操作を&nbsp;<var>1</var>&nbsp;回だけ行うことができるが，行わなくてもよい．</p>

<ul>
<li>西側の端から連続した区間の電球をオンにする．すなわち，&nbsp;<var>1</var>&nbsp;以上&nbsp;<var>N</var>&nbsp;以下の整数&nbsp;<var>r</var>&nbsp;を&nbsp;<var>1</var>&nbsp;つ選び，電球&nbsp;<var>1, 2, ... , r</var>&nbsp;をオンにする．</li>
</ul>

<p>この操作を行うのにかかる時間は無視できる．</p>

<p>その後，次の操作を何回でも行うことができる．</p>

<ul>
<li>電球を&nbsp;<var>1</var>&nbsp;つ選び，その電球の状態を変更する (オンならばオフに，オフならばオンにする)．</li>
</ul>

<p>この操作を行うには&nbsp;<var>1</var>&nbsp;回につき&nbsp;<var>1</var>&nbsp;分かかる．</p>

<p>電球の個数，目標とする電飾の模様が与えられたとき，葵が目標の模様にするのに最短で何分かかるかを求めるプログラムを作成せよ．</p>



## 입력


<p>入力は以下の形式で標準入力から与えられる．</p>

<pre><var>N</var>
<var>A<sub>1</sub></var> <var>A<sub>2</sub></var> <var>…</var> <var>A<sub>N</sub></var></pre>



## 출력


<p>標準出力に，目標の模様にするのに最短で何分かかるかを&nbsp;<var>1</var>&nbsp;行で出力せよ．</p>



## 소스코드

[소스코드 보기](イルミネーション%202%20(Illumination%202).py)