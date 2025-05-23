# 32316번: Ready for Contest - <img src="https://static.solved.ac/tier_small/5.svg" style="height:20px" /> Bronze I

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/32316)


<p>Whenever the UCF Programming Team Coaches prepare for the UCF Local Programming Contest, each problem requires valid judge solutions in C++ and Java. Python solutions may be written as well, but these are optional. Thus, the coaches consider a problem to be ready for the contest if it has at least one C++ solution and at least one Java solution.</p>

<p>Unfortunately, instead of writing solutions for the problems that need them, the coaches just pick their favorite problems and write solutions for those instead. Naturally, they use their favorite language as well instead of checking to see what solutions hasn't been written yet.</p>

<p>Although many solutions have been written, it may be the case that some problems aren't ready for the contest yet. Write a program to determine which problems are ready to go!</p>

<p>Given the number of problems that have been proposed, and a list of every solution written (which problem and which language), determine the problems that are contest ready (have both a C++ and a Java solution written).</p>



## 입력


<p>The first input line contains two integers: n (1 ≤ n ≤ 10<sup>5</sup>), indicating the number of problems proposed and m (2 ≤ m ≤ 3×10<sup>5</sup>), indicating the number of solutions written. The problems are numbered 1 through n.</p>

<p>The information about each solution written are provided in the following m input lines, with each line specifying a single solution written. Each of these input lines contains two integers: p (1 ≤ p ≤ n), and L (1 ≤ L ≤ 3), indicating that a solution has been written for problem number p in language L. If L = 1, the language is C++; if L = 2, the language is Java; if L = 3, the language is Python.</p>



## 출력


<p>Print a list of the problems that are ready for contest, sorted in numerical order, with one number outputted per line. It is guaranteed that at least one problem will be ready for contest so there will be some output.</p>



## 소스코드

[소스코드 보기](Ready%20for%20Contest.cpp)