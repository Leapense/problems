# 22542번: Moonlight Farm - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/22542)


<p>あなたは大人気webゲーム「ムーンライト牧場」に熱中している．このゲームの目的は，畑で作物を育て，それらを売却して収入を得て，その収入によって牧場を大きくしていくことである．</p>

<p>あなたは速く畑を大きくしたいと考えた．そこで手始めにゲーム中で育てることのできる作物を，時間あたりの収入効率にもとづいて並べることにした．</p>

<p>作物を育てるには種を買わなければならない．ここで作物&nbsp;<i>i</i>&nbsp;の種の名前は&nbsp;<i>L<sub>i</sub></i>&nbsp;，値段は&nbsp;<i>P<sub>i</sub></i>&nbsp;でそれぞれ与えられる．畑に種を植えると時間&nbsp;<i>A<sub>i</sub></i>&nbsp;後に芽が出る．芽が出てから時間&nbsp;<i>B<sub>i</sub></i>&nbsp;後に若葉が出る．若葉が出てから時間&nbsp;<i>C<sub>i</sub></i>&nbsp;後に葉が茂る．葉が茂ってから時間&nbsp;<i>D<sub>i</sub></i>&nbsp;後に花が咲く．花が咲いてから時間&nbsp;<i>E<sub>i</sub></i>&nbsp;後に実が成る．一つの種から&nbsp;<i>F<sub>i</sub></i>&nbsp;個の実が成り，それらの実は一つあたり<i>S<sub>i</sub></i>&nbsp;の価格で売れる．一部の作物は多期作であり，計&nbsp;<i>M<sub>i</sub></i>&nbsp;回実をつける．単期作の場合は&nbsp;<i>M<sub>i</sub></i>&nbsp;= 1で表される．多期作の作物は，<i>M<sub>i</sub></i>&nbsp;回目の実が成るまでは，実が成ったあと葉に戻る．ある種に対する収入は，その種から成った全ての実を売った金額から，種の値段を引いた値である．また，その種の収入効率は，その収入を，種を植えてから全ての実が成り終わるまでの時間で割った値である．</p>

<p>あなたの仕事は，入力として与えられる作物の情報に対して，それらを収入効率の降順に並べ替えて出力するプログラムを書くことである．</p>



## 입력


<p>入力はデータセットの列であり，各データセットは次のような形式で与えられる．</p>

<pre><i>N
</i><i>L<sub>1</sub></i> <i>P<sub>1</sub></i> <i>A<sub>1</sub></i> <i>B<sub>1</sub></i> <i>C<sub>1</sub></i> <i>D<sub>1</sub></i> <i>E<sub>1</sub></i> <i>F<sub>1</sub></i> <i>S<sub>1</sub></i> <i>M<sub>1</sub></i>
<i>L<sub>2</sub></i> <i>P<sub>2</sub></i> <i>A<sub>2</sub></i> <i>B<sub>2</sub></i> <i>C<sub>2</sub></i> <i>D<sub>2</sub></i> <i>E<sub>2</sub></i> <i>F<sub>2</sub></i> <i>S<sub>2</sub></i> <i>M<sub>2</sub></i>
...
<i>L<sub>N</sub></i> <i>P<sub>N</sub></i> <i>A<sub>N</sub></i> <i>B<sub>N</sub></i> <i>C<sub>N</sub></i> <i>D<sub>N</sub></i> <i>E<sub>N</sub></i> <i>F<sub>N</sub></i> <i>S<sub>N</sub></i> <i>M<sub>N</sub></i></pre>

<p>一行目はデータセットに含まれる作物の数&nbsp;<i>N</i>&nbsp;である (1 ≤ N ≤ 50)．</p>

<p>これに続く&nbsp;<i>N</i>&nbsp;行には，各行に一つの作物の情報が含まれる．各変数の意味は問題文中で述べた通りである．作物の名前&nbsp;<i>L<sub>i</sub></i>&nbsp;はアルファベット小文字のみからなる20文字以内の文字列であり，また 1 ≤&nbsp;<i>P<sub>i</sub></i>&nbsp;,&nbsp;<i>A<sub>i</sub></i>&nbsp;,&nbsp;<i>B<sub>i</sub></i>&nbsp;,&nbsp;<i>C<sub>i</sub></i>&nbsp;,&nbsp;<i>D<sub>i</sub></i>&nbsp;,&nbsp;<i>E<sub>i</sub></i>&nbsp;,&nbsp;<i>F<sub>i</sub></i>&nbsp;,&nbsp;<i>S<sub>i</sub></i>&nbsp;≤ 100, 1 ≤&nbsp;<i>M<sub>i</sub></i>&nbsp;≤ 5である．一つのケース内に同一の名前を持つ作物は存在しないと仮定して良い．</p>

<p>入力の終りはゼロを一つだけ含む行で表される．</p>



## 출력


<p>各データセットについて，各行に一つ，作物の名前を収入効率の降順に出力せよ．収入効率が同じ作物に対しては，それらの名前を辞書順の昇順に出力せよ．</p>

<p>各データセットの出力の後には“#”のみからなる1行を出力すること．</p>



## 소스코드

[소스코드 보기](Moonlight%20Farm.cpp)