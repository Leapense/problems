# 12453번: カードシャッフル (Small) - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/12453)


<p>フランクはカードゲームが好きで、週末は友達の家でゲームパーティーに参加しています。彼らがゲームに使うカードは&nbsp;<strong>M</strong>&nbsp;枚からなり、それぞれ 1 から&nbsp;<strong>M</strong>&nbsp;までの数字が重複しないように書かれています。フランクはパーティーで友人が使っている自動カードシャッフル装置と同じものを持っていて、どのように動作するか理解しています。その装置はカードの山を&nbsp;<strong>C</strong>&nbsp;回カットすることでシャッフルを行います。<strong>i</strong>&nbsp;回目のカットではカードの山の上から&nbsp;<strong>A<sub>i</sub></strong>&nbsp;番目から&nbsp;<strong>B<sub>i</sub></strong>&nbsp;枚、つまり&nbsp;<strong>A<sub>i</sub></strong>&nbsp;番目から&nbsp;<strong>A<sub>i</sub></strong>&nbsp;+&nbsp;<strong>B<sub>i</sub></strong>&nbsp;- 1 番目のカードがそのままの順番で山の上に移動します。</p>

<p>ある日、いつも使っているカードが汚れたため、新しいカードを使うことになりました。新しいカードは上から順番に 1 から&nbsp;<strong>M</strong>&nbsp;まで並んだ状態でそのままシャッフル装置にかけられました。フランクはシャッフル装置の性質を利用し、シャッフル後に上から&nbsp;<strong>W</strong>&nbsp;番目にあるカードが何かを知ろうとしています。</p>



## 입력


<p>最初の行はテストケースの個数&nbsp;<strong>T</strong>&nbsp;を表す正の整数です。続いて、各テストケースが次のようなフォーマットで与えられます。</p>

<pre>M C W
A<sub>1</sub> B<sub>1</sub>
...
A<sub>C</sub> B<sub>C</sub>
</pre>

<p>1行目では、1 つのスペースで区切られた 3 つの整数&nbsp;<strong>M</strong>,&nbsp;<strong>C</strong>,&nbsp;<strong>W</strong>&nbsp;が与えられます。ここで&nbsp;<strong>M</strong>&nbsp;はカードの枚数 、<strong>C</strong>&nbsp;はカットの回数、<strong>W</strong>&nbsp;は知りたいカードの位置です。 続く&nbsp;<strong>C</strong>&nbsp;行の各行では、1 つのスペースで区切られた 2 つの整数&nbsp;<strong>A<sub>i</sub></strong>,&nbsp;<strong>B<sub>i</sub></strong>&nbsp;が与えられます。 ここで&nbsp;<strong>A<sub>i</sub></strong>,&nbsp;<strong>B<sub>i</sub></strong>&nbsp;はカットの操作で、<strong>i</strong>&nbsp;回目の操作で上から&nbsp;<strong>A<sub>i</sub></strong>&nbsp;番目から&nbsp;<strong>B<sub>i</sub></strong>&nbsp;枚のカードを山の上に移動させることを意味しています。</p>

<h3>制約</h3>

<ul>
<li>1 ≤&nbsp;<strong>T</strong>&nbsp;≤ 200</li>
<li>1 ≤&nbsp;<strong>C</strong>&nbsp;≤ 100</li>
<li>1 ≤&nbsp;<strong>W</strong>&nbsp;≤&nbsp;<strong>M</strong></li>
<li>1 ≤&nbsp;<strong>A<sub>i</sub></strong>&nbsp;≤&nbsp;<strong>M</strong></li>
<li>1 ≤&nbsp;<strong>B<sub>i</sub></strong>&nbsp;≤&nbsp;<strong>M</strong></li>
<li>1 ≤&nbsp;<strong>A<sub>i</sub></strong>&nbsp;+&nbsp;<strong>B<sub>i</sub></strong>&nbsp;- 1 ≤&nbsp;<strong>M</strong></li>
<li>1 ≤&nbsp;<strong>M</strong>&nbsp;≤ 100</li>
</ul>



## 출력


<p>各テストケースに対し、</p>

<pre>Case #X: P
</pre>

<p>という内容を1行出力してください。ここで&nbsp;<strong>X</strong>&nbsp;は 1 から始まるテストケース番号、<strong>P</strong>&nbsp;はシャッフル後のカードの山の上から&nbsp;<strong>W</strong>&nbsp;番目にあるカードを表します。</p>



## 소스코드

[소스코드 보기](カードシャッフル%20(Small).py)