# 18418번: いちご (Strawberry) - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/18418)


<p>Just Oishi Ichigo 農園 (以下 JOI 農園) は東西に細長いことで有名ないちご農園であり，その入り口は農園の最も西にある．以下では，入り口から東に&nbsp;<var>k</var>&nbsp;メートル進んだ場所を地点&nbsp;<var>k</var>&nbsp;と呼ぶことにする．</p>

<p>JOI 農園内には&nbsp;<var>N</var>&nbsp;個のいちごがなっている．それぞれ&nbsp;<var>1</var>&nbsp;から&nbsp;<var>N</var>&nbsp;の番号がつけられている．どのいちごも時刻&nbsp;<var>0</var>&nbsp;までは青い．いちご&nbsp;<var>i</var>&nbsp;(<var>1 ≦ i ≦ N</var>) は地点&nbsp;<var>A<sub>i</sub></var>&nbsp;に実をつけており，時刻&nbsp;<var>T<sub>i</sub></var>&nbsp;になると熟し赤い状態になる．</p>

<p>いちごは青い状態では収穫できない．つまり，いちご&nbsp;<var>i</var>&nbsp;は時刻&nbsp;<var>T<sub>i</sub></var>&nbsp;となるまで収穫できない．あなたは時刻&nbsp;<var>0</var>&nbsp;に地点&nbsp;<var>0</var>&nbsp;にある農園の入り口から出発して，最大秒速&nbsp;<var>1</var>&nbsp;メートルで東西方向に移動しながらいちごを収穫する．いちごを収穫するのにかかる時間は無視できるとする．</p>

<p>いちご農園についての情報が与えられるので，すべてのいちごを赤い状態で収穫したあと入り口に帰ってくるまでにかかる時間の最小値を求めるプログラムを作成せよ．</p>



## 입력


<p>入力は以下の形式で標準入力から与えられる．</p>

<pre><var>N</var>
<var>A<sub>1</sub></var> <var>T<sub>1</sub></var>
<var>A<sub>2</sub></var> <var>T<sub>2</sub></var>
<var>:</var>
<var>A<sub>N</sub></var> <var>T<sub>N</sub></var></pre>



## 출력


<p>すべてのいちごを赤い状態で収穫したあと入り口に帰ってくるまでにかかる時間の最小値を&nbsp;<var>1</var>&nbsp;行に出力せよ．</p>



## 소스코드

[소스코드 보기](いちご%20(Strawberry).cpp)