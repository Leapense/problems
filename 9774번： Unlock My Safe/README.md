# 9774번: Unlock My Safe - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/9774)


<p>I forgot the password to my safe. There is a lot of money in it! Please help me unlock the safe. The keypad looks like this.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/8591603f-05d2-42c5-ad85-920b6c42f90c/-/preview/" style="width: 307px; height: 241px;"></p>

<p>I do not remember how long my password is. Hence, you need to try a different length of the password. However, there are some hints that I can recall.</p>

<ul>
<li>I never use characters *, #, 0 and 9 in my password.</li>
<li>Each digit in the password is distinct. That is, they never appear more than once.</li>
<li>My password is at most 8 digits (1 ≤ N ≤ 8, where N is a number of digits in the password).</li>
<li>Each digit i in the password always has the value less than or equal to N (that is, a password 132 is valid for N = 3 but a password such as 124 is invalid because the 3rd digit exceeds 3).</li>
</ul>

<p>Use the information above and generate all possible permutations. One permutation corresponds to one guess of a password to unlock my safe. Importantly, the correct password is deliberately fixed at position L\3 in the sorted array of permutations, where L is a number of all possible permutations and ‘\’ is an integer division. The sorted array of permutations is in ascending order and the starting index in the sorted array begins at 0 (not 1).</p>

<p>Write a program to find a correct password for a given length (a number of digits in the password).</p>



## 입력


<p>The first line of the input contains an integer T (1 ≤ T ≤ 6) denoting the number of test cases. After that T test cases follow. Each test case contains an integer N (1 ≤ N ≤ 8) denoting a number of digits in a password.</p>



## 출력


<p>Your program should output the N-digit password for each corresponding test case, one password per line.</p>



## 소스코드

[소스코드 보기](Unlock%20My%20Safe.cpp)