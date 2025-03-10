# 6737번: Parsing Real Numbers - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/6737)


<p>Write a program that read a line of input and checks if the line contains a valid real number. Real numbers may have a decimal point, an exponent (starting with the character e or E), or both. Additionally, it has the usual collection of decimal digits. If there is a decimal point, there must be at least one digit on each side of the point. There may be a plus or minus sign in front of the number, or the exponent, or both (without any blank characters after the sign). Exponents are integers (not having decimal points). There may be blank characters before or after a number, but not inside it. Note that there is no bound on the range of the numbers in the input, but for the sake of simplicity, you may assume the input strings are not longer than 1000 characters.</p>



## 입력


<p>The first line of the input contains a single integer <em>T</em> which is the number of test cases, followed by <em>T</em> lines each containing the input line for a test case.</p>



## 출력


<p>The output contains <em>T</em> lines, each having a string which is LEGAL or ILLEGAL.</p>



## 소스코드

[소스코드 보기](Main.java)