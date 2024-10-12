# 31618번: カードゲーム 2 (Card Game 2) - <img src="https://static.solved.ac/tier_small/4.svg" style="height:20px" /> Bronze II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/31618)


<p>ビ太郎は <var>N</var> 枚のカードを持っており，<var>i</var> 枚目 (<var>1 ≦ i ≦ N</var>) のカードには整数 <var>A<sub>i</sub></var> が書かれている． これらの中から次の条件を満たすような <var>3</var> 枚のカードを選びたい．</p>

<p><strong>条件:</strong> 選んだカードに書かれている整数が <var>3</var> ずつ離れている． 厳密には，選んだカードに書かれている整数が，ある整数 <var>x</var> を用いて <var>x, x+3, x+6</var> と表せる．</p>

<p>例えば，ビ太郎が <var>5</var> 枚のカードを持っており，それぞれに <var>2, 4, 5, 7, 10</var> が書かれているとき，<var>4, 7, 10</var> が書かれているカードを選ぶと，条件を満たす．</p>

<p>ビ太郎が持っているカードの情報が与えられたとき，条件を満たすように <var>3</var> 枚のカードを選ぶことができるかどうか判定するプログラムを作成せよ．</p>



## 입력


<p>入力は以下の形式で与えられる．</p>

<pre><var>N</var>
<var>A<sub>1</sub></var>   <var>A<sub>2</sub></var>   <var>…</var>   <var>A<sub>N</sub></var></pre>



## 출력


<p>条件を満たすように <var>3</var> 枚のカードを選ぶことができる場合 <code>Yes</code> を，そうでない場合 <code>No</code> を出力せよ．</p>



## 소스코드

[소스코드 보기](カードゲーム%202%20(Card%20Game%202).py)