# 15276번: Palindromic Password - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/15276)


<p>The IT department at your school decided to change their password policy. Each password will have to consist of N 6-digit numbers separated by dashes, where N will be determined by the phase of the moon and the weather forecast for the day after it will be generated.</p>

<p>You realized that, if all of the numbers were palindromes (same numbers as the original ones if read backwards), you would have to remember a bunch of 3-digit numbers, which did not sound that bad (at the time).</p>

<p>In order to generate your password of N numbers, you get a list of N randomly generated 6-digit numbers and find the palindromic number closest to them.</p>

<p>Of course, you would like to automate this process...</p>



## 입력


<p>The first line of the input contains a single positive integer N ≤ 1000 indicating the number of six-digit numbers in the input. Each of the next N lines contains a six-digit number without leading zeroes.</p>



## 출력


<p>For each six-digit number in the input, output another six-digit number that is closest to it and is also a palindrome. “Closest” in this context means “a number having the smallest absolute difference with the original number”. If there are two different numbers satisfying the above condition, output the smaller one of the two. Remember, no leading zeroes.</p>



## 소스코드

[소스코드 보기](Palindromic%20Password.py)