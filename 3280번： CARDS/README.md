# 3280번: CARDS - <img src="https://static.solved.ac/tier_small/6.svg" style="height:20px" /> Silver V

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/3280)


<p>Dave and Hal are playing one interesting game with cards. Dave has N cards (N is divisible by three, N=3K) with numbers from 1 to N written on them.</p>

<p>Each card has the same number written on both sides, and no two cards share the same number. Cards are sorted.</p>

<p>First Hal thinks of one number from set {1, 2, ..., N}.</p>

<p>Then Dave lays cards in K rows and three columns on a table starting with card numbered by 1 filling the first row from left to right, then second row, and so on till he finishes with the last row.</p>

<p>Hal then says in which column Dave put the card with a number he thought of.</p>

<p>Dave then picks up the cards from the first column (firstly taking card from the first row, then from the second and so on to the last row), then from the second and finally from the third column in the same way. He then lays them, without shuffling, to the table again the same way as the first time.</p>

<p>Each time Dave puts all the cards on the table, Hal tells him in which column is the card with his number.</p>

<p>Dave’s task is to guess Hal’s number.</p>

<p>Write a program that will use Hal’s answers to help Dave to determine the smallest set of numbers that are candidates for Hal’s number,&nbsp;</p>



## 입력


<p>The first line of input file contains a natural number N, 3 ≤ N ≤ 999, the number of all cards.</p>

<p>The second line contains a natural number D, 1 ≤ D ≤ 10, the numbers of dealings (i.e. the number of Hal’s answers).</p>

<p>The following D lines contain words 'first', 'second' or 'third', denoting Hal’s answers – one word in each line.</p>



## 출력


<p>To the first and only line of output file should be written all the numbers from the smallest set of numbers that are candidates for Hal’s number. The numbers can be written in any order, and must be separated by a space.</p>



## 소스코드

[소스코드 보기](CARDS.cpp)