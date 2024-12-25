# 12457번: ビット数 (Small) - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/12457)


<p>f(x) を 「x を 2進数表記した時の "1" の個数を返す関数」と定義します。 例えば、5 は 101<sub>2</sub>&nbsp;と 2 進数表記されるので、f(5) = 2 です。</p>

<p>正の整数&nbsp;<strong>N</strong>&nbsp;が与えられるので、 a + b =&nbsp;<strong>N</strong>&nbsp;を満たす 0 以上の整数 a, b の組の中で f(a) + f(b) が最大になるものを求め、その時の f(a) + f(b) の値を出力してください。</p>



## 입력


<p>最初の行はテストケースの個数&nbsp;<strong>T</strong>&nbsp;を表す正の整数です。 各テストケースは1行の文字列で表現され、それぞれの行には&nbsp;<strong>N</strong>&nbsp;を表す正の整数が1つだけ含まれています。</p>

<h3>制約</h3>

<ul>
<li>1 ≤&nbsp;<strong>T</strong>&nbsp;≤ 1000</li>
<li><strong>N</strong>&nbsp;≤ 10000</li>
</ul>



## 출력


<p>各テストケースごとに、</p>

<pre>Case #X: P
</pre>

<p>という内容を1行出力してください。ここで&nbsp;<strong>X</strong>&nbsp;は 1 から始まるテストケース番号、<strong>P</strong>&nbsp;は f(a) + f(b) の最大値です。</p>



## 소스코드

[소스코드 보기](ビット数%20(Small).cpp)