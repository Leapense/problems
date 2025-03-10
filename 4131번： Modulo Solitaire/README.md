# 4131번: Modulo Solitaire - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/4131)


<p>Modulo Solitaire is a game that can be played when you are bored. You can even play it without a phone, just on paper. First, you pick a number <code>m</code>. Then you pick two sequences of numbers <code>a<sub>i</sub></code> and <code>b<sub>i</sub></code>. Finally, you pick a starting number <code>s<sub>0</sub></code>. Now, your goal is to go from <code>s<sub>0</sub></code> to 0 in as few moves as possible. In each move, you choose an <code>i</code>, then multiply your current number by <code>a<sub>i</sub></code>, add <code>b<sub>i</sub></code> to it, and reduce the result modulo <code>m</code>. That is, <code>s<sub>j</sub> = (s<sub>j-1</sub> * a<sub>i<sub>j</sub></sub> + b<sub>i<sub>j</sub></sub>) % m</code>.</p>



## 입력


<p>The first line of input contains three integers <code>0 &lt; m ≤ 1000000</code>, <code>0 ≤ n ≤&nbsp;10</code>, and <code>0 &lt; s<sub>0</sub> &lt; m</code>. The next <code>n</code> lines each contain two integers, a pair <code>0 ≤ a<sub>i</sub> ≤ 1000000000</code> and <code>0 ≤ b<sub>i</sub> ≤ 1000000000</code>.</p>



## 출력


<p>Output a single integer, the shortest number of moves needed to reach 0 starting from <code>s<sub>0</sub></code>. If it is not possible to reach 0 in any number of moves, output <code>-1</code>.</p>



## 소스코드

[소스코드 보기](Main.java)