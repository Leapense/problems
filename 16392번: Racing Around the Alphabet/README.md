# 16392번: Racing Around the Alphabet - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/16392)


<p>Soccer coach Joe has invented a new fitness game that he thinks will help his players’ agility and fitness. The center circle of the soccer pitch has a diameter of 60 feet. He marks 28 evenly-spaced points on the circumference of the circle. On the first point (arbitrarily chosen) he places a pile of tokens all inscribed with the letter ’A’. On the second point he places a pile of ’B’ tokens, and so on, covering 26 of the 28 points. He places a pile of blanks (or space-characters) on the 27th point and a pile of disks imprinted with single quotation marks, on the last point.</p>

<p>He gives each player a slip of paper containing an aphorism, such as “WINNING ISN’T EVERYTHING IT’S THE ONLY THING” Notice that the only punctuation marks allowed are spaces and single quotation marks. Each player gets a different aphorism.</p>

<p>A player starts outside the circle next to the first letter of his aphorism and, on Joe’s “GO” signal, the player picks up his first disk and then takes off running around the outside of the circle, picking up the remaining disks in the order that the corresponding letters appear in the aphorism. A smart player will take the shortest route, possibly changing direction, between consecutive letters of his aphorism.</p>

<p>One of the assistant coaches makes a note of the player’s time. Although Joe initially envisioned all of his 20 players running around the circle simultaneously, this idea was scrapped due to contusions and fractures.</p>

<p>Joe wants you to write a program to estimate the expected time for one smart player to complete each of the aphorisms. Assume for simplicity that the player runs at 15 feet per second between stops for pickups and that each pickup takes 1 second.</p>



## 입력


<p>The input begins with a number N, (1 ≤ N ≤ 20) giving the number of aphorisms to follow. N lines follow, each one containing an aphorism made up of upper-case letters, single quotation marks, and spaces. Each aphorism will be between 8 and 120 characters inclusive.</p>



## 출력


<p>For each aphorism give the time for a smart player to complete the task. Your answer should be accurate to within 10<sup>−6</sup> seconds.</p>



## 소스코드

[소스코드 보기](Racing%20Around%20the%20Alphabet.cpp)