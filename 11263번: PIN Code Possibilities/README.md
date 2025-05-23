# 11263번: PIN Code Possibilities - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/11263)


<p>PIN (Personal Identification Number) is a secret code that is known only by its owner. PIN is widely used for authentication in many applications such as ATM, telephone call center service, etc. A PIN code usually contains 4 digits or more, depending on the level of security checking. The more digits the PIN has, the harder it is to guess the right code.</p>

<p>The total possibilities of the PIN codes are easy to compute. Since each digit has 10 possible numbers (0 - 9), a PIN code with n digits has 10n possibilities. However, suppose that you know something about the PIN, for example the sum of all digits is a certain value, you will find less possibilities of the PIN code.</p>

<p>For example, for a 3-digit PIN, if the sum of all digits is 1, you will find out that there are only 3 possible codes i.e. 001,010 and 100, whereas if the sum is 2 you will find 6 possibilities i.e. 011, 101, 110, 002, 020 and 200.</p>

<p>Given n for the number of digits of a PIN code and s for the sum of all digits of the PIN, your task is to write a program to compute the number of possible PIN codes.</p>



## 입력


<p>Each line of the input contains a test case including the number n (2&lt;=n&lt;=7), the number of digits of the PIN code and s, the sum of all digits.</p>



## 출력


<p>For each test case, print out the number of possibilities of the PIN code. If there is no possible PIN code that can satisfy such condition then print out 0.</p>



## 소스코드

[소스코드 보기](PIN%20Code%20Possibilities.cpp)