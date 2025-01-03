# 32089번: 部員の変遷 - <img src="https://static.solved.ac/tier_small/2.svg" style="height:20px" /> Bronze IV

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/32089)


<p>春は別れと出会いの季節．今年もまた，伝統ある芸楽部の歴史に新たな名前を刻むときが来た．</p>

<p>部活日誌には，この部活の <i>n</i> 年分の部員の推移が記録されている．記録によれば，初年度より前の部員数はもちろん 0 人であり，毎年部員は 4 月に新入生のみが入部しており，3 年後の 3 月に卒業するタイミングでのみ退部しているようだ．</p>

<p>部の変遷を紐解くために，<i>n</i> 年間の各年の新入部員の数のデータから在籍する部員の数が最大になった年度の部員数を調べてみよう．</p>



## 입력


<p>入力は複数のデータセットからなる．データセットの個数は 50 を超えない．各データセットは次の形式で表される．</p>

<blockquote>
<p><i>n</i> <i>a<sub>1</sub></i> <i>a<sub>2</sub></i> <i>…</i> <i>a<sub>n</sub></i></p>
</blockquote>

<p><i>n</i> は新入部員の数が記録されている年数を表す，<i>3</i> 以上 <i>1000</i> 以下の整数である．続く行は各年度の新入部員の数を表す <i>n</i> 個の整数からなり，<i>i</i> 年目の新入部員の数 <i>a<sub>i</sub></i> はそれぞれ <i>0 ≤ a<sub>i</sub> ≤ 10<sup>8</sup></i> を満たす．</p>

<p>入力の終わりは，ゼロ 1 つだけからなる行で表される．</p>



## 출력


<p>各データセットについて，在籍する部員の数が最大になった年度の部員数を 1 行に出力せよ．</p>



## 소스코드

[소스코드 보기](部員の変遷.py)