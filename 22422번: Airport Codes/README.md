# 22422번: Airport Codes - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/22422)


<p>JAG王国では国内の空港にそれぞれ空港コードを割り当てて識別をしている．</p>

<p>空港コードは，小文字の英語アルファベットで表記した空港の名前をもとに以下の規則で割り当てられる:</p>

<ol>
<li>名前の最初の文字と，母音 (a,i,u,e,o) の直後の文字を順に取り出す．</li>
<li>取り出した文字列が&nbsp;<var>k</var>&nbsp;文字未満ならそれを空港コードとし，&nbsp;<var>k</var>&nbsp;文字以上なら，その取り出した文字列の先頭&nbsp;<var>k</var>&nbsp;文字を空港コードとして使う．</li>
</ol>

<p>例えば&nbsp;<var>k</var>&nbsp;= 3 のとき，haneda には hnd ， oookayama には ooo ， tsu には t というコードが割り当てられる．</p>

<p>しかしこのコードの割り当て方では，違う名前の空港でも同じコードが割り当てられることがあり，混乱を招いてしまう． 空港の名前の一覧が与えられるので，すべての空港のコードが異なるようにできるか判定して，可能な場合はすべての空港コードが異なるようにできる最小の&nbsp;<var>k</var>&nbsp;を求め，不可能な場合はその旨を伝えるプログラムを作成せよ．</p>



## 입력


<p>入力は100個以下のデータセットからなる． それぞれのデータセットは次の形式で与えられる．</p>

<pre><var>n</var>
<var>s</var><sub>1</sub>
...
<var>s<sub>n</sub></var></pre>

<p>1行目に空港の数&nbsp;<var>n</var>&nbsp;(2 ≤&nbsp;<var>n</var>&nbsp;≤ 50) が整数で与えられ，続く&nbsp;<var>n</var>&nbsp;行にはそれぞれ空港の名前&nbsp;<var>s<sub>i</sub></var>&nbsp;が文字列で与えられる． 空港の名前は'<samp>a</samp>'から'<samp>z</samp>'の小文字の英語アルファベットのみで構成され，いずれも文字数は1以上50以下である． また，与えられる空港の名前はすべて異なる．すなわち，1 ≤&nbsp;<var>i</var>&nbsp;&lt;&nbsp;<var>j</var>&nbsp;≤&nbsp;<var>n</var>&nbsp;のとき&nbsp;<var>s<sub>i</sub></var>&nbsp;≠&nbsp;<var>s<sub>j</sub></var>&nbsp;を満たす．</p>

<p>入力の終わりは1つのゼロだけからなる行で示される．</p>



## 출력


<p>それぞれのデータセットについて，すべての空港に相異なる空港コードを割り当てられるときは，そのような最小の&nbsp;<var>k</var>&nbsp;を1行に出力せよ． 不可能な場合は，-1を1行に出力せよ．</p>



## 소스코드

[소스코드 보기](Airport%20Codes.py)