# 10690번: Compo - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/10690)


<p>Ahmed M El-Sayed is the head of systems in the Arab Collegiate Programming Contest (his colleagues used to call him compiler shortened as compo, that goes back to his college days when he used to quickly predict the output of different programs without compiling and running them).</p>

<p>Because of his valued skills and expertise, he is often being asked to help out in many of the national contests and he would almost always agree, the problem is that for a national contest C that would last from time C<sub>l</sub> to C<sub>r</sub> he must be present from the beginning of the contest till its end if he agrees to help in organizing this contest.</p>

<p>Here is the problem, sometimes two or more contests would overlap, that is, one contest would start before another one finishes and so Ahmed would have to choose to go to only one of the overlapping contests which leads to the contest managers fighting over who gets to have Ahmed help him.</p>

<p>Given the number of contests and the times at which each one starts and ends, please count the number of fights that would happen.</p>

<p>Note that if a contest overlaps with M other contests, the contest manager would fight with each of the managers of the overlapping contests and so M fights would occur. And a contest which ends at the exact starting time of another contest will cause a fight also, Ahmed is not that fast.</p>



## 입력


<p>Your program will be tested on one or more test cases. The first line of the input will be a single integer T, the number of test cases (1 ≤ T ≤ 100). Followed by T test case, each test case starts with a line containing a single integer N (1 ≤ N ≤ 10<sup>5</sup>) denoting the number of contests. Followed by one line for each contest, containing two space separated integers C<sub>l</sub> C<sub>r</sub> which signify the start and end times of that contest (1 ≤ C<sub>l</sub> ≤ C<sub>r</sub> ≤ 10<sup>9</sup>).</p>



## 출력


<p>For each test case print a single line containing “Case n:” (without the quotes) where n is the test case number (starting from 1) followed by a space then R which is the number of fights that would happen.</p>



## 소스코드

[소스코드 보기](Compo.cpp)