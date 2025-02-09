# 22456번: Equation - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/22456)


<p>論理演算では，値は T と F の2種類だけを扱う．</p>

<p>"-"を単項演算子（入力が 1 つの演算を表す記号）， "*", "+", "-&gt;" を 2 項演算子（入力が 2 つの演算を表す記号）とする． "-" は論理否定(NOT)， "*" は論理積(AND)， "+" は論理和(OR)， "-&gt;" は論理包含(IMP)を表す演算子である． これらの論理演算の真理値表を下の表に示す．</p>

<table class="table table-bordered table-center-40">
<thead>
<tr>
<th>x</th>
<th>y</th>
<th>-x</th>
<th>(x*y)</th>
<th>(x+y)</th>
<th>(x-&gt;y)</th>
</tr>
</thead>
<tbody>
<tr>
<td>T</td>
<td>T</td>
<td>F</td>
<td>T</td>
<td>T</td>
<td>T</td>
</tr>
</tbody>
<tbody>
<tr>
<td>T</td>
<td>F</td>
<td>F</td>
<td>F</td>
<td>T</td>
<td>F</td>
</tr>
</tbody>
<tbody>
<tr>
<td>F</td>
<td>T</td>
<td>T</td>
<td>F</td>
<td>T</td>
<td>T</td>
</tr>
</tbody>
<tbody>
<tr>
<td>F</td>
<td>F</td>
<td>T</td>
<td>F</td>
<td>F</td>
<td>T</td>
</tr>
</tbody>
</table>

<p>論理式は以下のいずれかの形式である． X, Yは論理式とし， 2 項演算子は必ず括弧で囲むものとする．</p>

<ul>
<li>定数: T, F</li>
<li>変数: a, b, c, d, e, f, g, h, i, j, k</li>
<li>論理否定: -X</li>
<li>論理積: (X*Y)</li>
<li>論理和: (X+Y)</li>
<li>論理包含: (X-&gt;Y)</li>
</ul>

<p>2 つの論理式を等号 "=" で結合した等式が与えられる． 恒等式とは，式に現れる変数がどのような値であっても成立する等式のことである． 与えられた等式が恒等式であるかを判定するプログラムを作りたい．</p>



## 입력


<p>入力は複数の行で構成され，各行は 1 つのデータセットである． データセットはT, F, a, b, c, d, e, f, g, h, i, j, k, (, ), =, -, +, *, &gt; から成る文字列であり， 空白など他の文字を含まない． 1 行の文字数は 1000 文字以下と仮定してよい．</p>

<p>1 つのデータセットは等式ひとつを含む． 等式の文法は次の BNF で与えられる． すべての等式はこの構文規則に従う．</p>

<pre>&lt;equation&gt; ::= &lt;formula&gt; "=" &lt;formula&gt;
&lt;formula&gt;  ::= "T" | "F" |
"a" | "b" | "c" | "d" | "e" | "f" |
"g" | "h" | "i" | "j" | "k" |
"-" &lt;formula&gt; |
"(" &lt;formula&gt; "*" &lt;formula&gt; ")" |
"(" &lt;formula&gt; "+" &lt;formula&gt; ")" |
"(" &lt;formula&gt; "-&gt;" &lt;formula&gt; ")"
</pre>

<p>入力の終わりは "#" だけからなる行で示されており，この行はデータセットではない．</p>



## 출력


<p>各データセットについて，等式が恒等式であれば“YES”を， そうでなければ“NO”をそれぞれ1行に出力しなさい． 出力には余分な文字を含んではならない．</p>



## 소스코드

[소스코드 보기](Equation.cpp)