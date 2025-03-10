# 11218번: A1 Paper - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/11218)


<p>Björn likes the square root of two, √2 = 1.41421356 . . . very much. He likes it so much that he has decided to write down the first 10 000 digits of it on a single paper. He started doing this on an A4 paper, but ran out of space after writing down only 1250 digits. Being pretty good at math, he quickly figured out that he needs an A1 paper to fit all the digits. Björn doesn’t have an A1 paper, but he has smaller papers which he can tape together.</p>

<p>Taping two A2 papers together along their long side turns them into an A1 paper, two A3 papers give an A2 paper, and so on. Given the number of papers of different sizes that Björn has, can you figure out how much tape he needs to make an A1 paper? Assume that the length of tape needed to join together two sheets of papers is equal to their long side. An A2 paper is 2<sup>−5/4</sup> meters by 2<sup>−3/4</sup> meters and each consecutive paper size (A3, A4, . . . ) have the same shape but half the area of the previous one.advantage in the game. But unfortunately Leo died, so it is now up to you to finish this. Write a program which, when playing against Leo’s computer for several rounds, wins at least 80% of them.</p>



## 입력


<p>The first line of input contains a single integer 2 ≤ n ≤ 30, the A-size of the smallest papers Björn has. The second line contains n − 1 integers giving the number of sheets he has of each paper size starting with A2 and ending with An. Björn doesn’t have more than 10<sup>9</sup> sheets of any paper size.</p>



## 출력


<p>If Björn has enough paper to make an A1 paper, output a single floating point number, the smallest total length of tape needed in meters. Otherwise output “impossible”. The output number should have an absolute error of at most 10<sup>−5</sup>.</p>



## 소스코드

[소스코드 보기](A1%20Paper.cpp)