# 31613번: 繰り返し (Repetition) - <img src="https://static.solved.ac/tier_small/3.svg" style="height:20px" /> Bronze III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/31613)


<p>正の整数 <var>X</var>, <var>N</var> が与えられる．</p>

<p>最初，黒板に整数 <var>X</var> が書かれている．</p>

<p>JOI 君は，以下の<strong>操作</strong>を繰り返し行う．</p>

<p>操作: 今，黒板に書かれている数を <var>x</var> とする．<var>x</var> を <var>3</var> で割った余りを計算し，<var>r</var> とする．<var>r</var> の値に応じて，黒板に書かれている数を以下のように書き換える．</p>

<ul>
<li><var>r=0</var> のとき，黒板に書かれている数を，<var>x</var> に <var>1</var> を足した数に書き換える．</li>
<li><var>r=1</var> のとき，黒板に書かれている数を，<var>x</var> に <var>2</var> を掛けた数に書き換える．</li>
<li><var>r=2</var> のとき，黒板に書かれている数を，<var>x</var> に <var>3</var> を掛けた数に書き換える．</li>
</ul>

<p>黒板に書かれている数が <var>N</var> 以上になるまでに必要な操作の回数を求めよ．</p>



## 입력


<p>入力は以下の形式で与えられる．</p>

<pre><var>X</var>
<var>N</var></pre>



## 출력


<p>黒板に書かれている数が <var>N</var> 以上になるまでに必要な操作の回数を出力せよ．</p>

<p>答え以外は何も出力しないこと．(入力を促す文章なども出力しないこと．)</p>



## 소스코드

[소스코드 보기](繰り返し%20(Repetition).py)