# 23394번: Handling the Blocks - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/23394)


<p>A friend of yours invented a game and wants to know if you can solve it or if it’s impossible.</p>

<p>He assembled a sequence of N blocks. Each block has a number engraved on it and some color. All numbers are distinct and between 1 and N, and different blocks can be of the same color.</p>

<p>The game works as follows: you can play as many turns as you want. In one turn, you choose two different blocks that share the same color and swap them.</p>

<p>You have to tell whether it is possible to get the entire sequence to be sorted into ascending order by numbers engraved on the blocks.</p>



## 입력


<p>The first line contains two integers N and K (1 ≤ N ≤ 10<sup>5</sup>, 1 ≤ K ≤ N), representing the number of blocks in the sequence and the number of different colors, respectively.</p>

<p>Each of the next N lines contains two integers n<sub>i</sub> and c<sub>i</sub> (1 ≤ n<sub>i</sub> ≤ N, 1 ≤ c<sub>i</sub> ≤ K), representing the number and color of the i-th block, respectively.</p>



## 출력


<p>Output one line containing one character. If the sequence can be arranged in ascending order, write the upper case letter ‘<code>Y</code>’; otherwise write the uppercase letter ‘<code>N</code>’.</p>



## 소스코드

[소스코드 보기](Handling%20the%20Blocks.cpp)