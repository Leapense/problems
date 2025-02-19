# 4129번: Meganominoes - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/4129)


<p>A meganomino is a tile with two ends and a number of dots on each end. Each end can have as few as 0 and as many as 1000000000 dots. In this puzzle, you must place two meganominoes next to each other so that one end of one meganomino touches one end of the other meganomino. The number of dots on the touching ends must be the same on both meganominoes. In addition, the sum of the number of dots on the opposite (non-touching) ends of the meganominoes must be equal to a given number i.</p>



## 입력


<p>The first line of input contains two integers 0 &lt; n &lt; 10000 and 0 &lt; m &lt;= 100, the number of meganominoes and the number of queries. The next n lines each contain two integers, the number of dots on each end of a meganomino tile. No two meganomino tiles are the same. The next m lines each contain one of the given sums i.</p>



## 출력


<p>Output a total of m lines, one for each given sum i. On each such line, output a single integer, the number of (unordered) pairs of meganomino tiles that satisfy the constraints. The two tiles in a given pair must be distinct (i.e. a single tile cannot be used twice within a single pair).</p>



## 소스코드

[소스코드 보기](Main.java)