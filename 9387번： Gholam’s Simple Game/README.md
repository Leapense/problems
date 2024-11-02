# 9387번: Gholam’s Simple Game - <img src="https://static.solved.ac/tier_small/4.svg" style="height:20px" /> Bronze II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/9387)


<p>The floor of Gholam’s bedroom is tiled with white and yellow tiles. Sometimes when he is bored, he stands on one of the tiles and starts to walk along the row he is standing on. He first decides on a number n and starts to walk n steps. If he reaches the wall, he turns back and continues to walk in the opposite direction. He continues until he takes n steps. Note that turning back besides a wall does not count as a step. He counts how many yellow tiles he steps on.</p>

<p><img alt="" src="https://www.acmicpc.net/upload/images2/gh.png" style="float:right; height:52px; width:139px">For example, the figure on the right shows a row in the floor. The colors of the tiles are shown with the characters ‘Y’ and ‘W’ for yellow and white tiles respectively. If he starts at tile 3 facing to the right, and decides to take 7 steps, he finally stops at tile 2. During this walk, he steps 3 times on yellow tiles.</p>



## 입력


<p>The input contains T test cases. The first line of input has only the integer T. Each test case contains two lines. The first line contains two integers m (3 ≤ m ≤ 100) and n (1 ≤ n ≤ 1000), which is the number of steps Gholam takes. The second line contains m integers describing the tiles in the row and is in the following format:</p>

<pre>a<sub>1</sub> a<sub>2</sub> ... a<sub>m</sub></pre>

<p>Each ai is either 0, 1, 2, or 3. If a<sub>i</sub> = 0, then a<sub>i</sub> has a yellow tile, and a<sub>i</sub> &gt; 0 indicates that ai has a white tile. If a<sub>i</sub> = 2, then Gholam is starting from the tile a<sub>i</sub>, facing to the right, and if a<sub>i</sub> = 3, then he is starting from the tile a<sub>i</sub>, facing to the left. The numbers are separated by space characters. You may assume that exactly one of the numbers is 2 or 3. Note that it is implied that Gholam always starts from a white tile.</p>



## 출력


<p>For each test case, write a single line in the output having a single number which is the number of times Gholam steps on a yellow tile.</p>



## 소스코드

[소스코드 보기](Gholam’s%20Simple%20Game.py)