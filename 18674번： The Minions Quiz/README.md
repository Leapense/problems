# 18674번: The Minions Quiz - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/18674)


<p>The minions have finally found their new master. This time, he is a Math professor and he is trying very hard to teach them math. He has been teaching them bitwise operators for over a year! They learnt about AND(&amp;) and OR (|) operators and it is time for a quiz to test them.</p>

<p>The quiz is very simple, they will be given a number A of AND(&amp;) operators, a number B of OR (|) operators and (A + B + 1) integers. They have to find the maximum number that can be obtained by inserting the ‘&amp;’ and ‘|’ operators between the given nonnegative integers without changing their order.</p>

<p>Finally, there is a special requirement for this quiz, they are required to evaluate the operators from left to right.</p>



## 입력


<p>The first line of the input will be a single integer T, the number of test cases (1 ≤ T ≤ 100), followed by T test cases.</p>

<p>Each test case will consist of 2 lines. The first line will contain 2 integers A and B (0 ≤ A, B ≤ 10, 000) representing the number of AND(&amp;) and OR (|) operators, respectively. The second line of input will consist of (A + B + 1) 64-bit nonnegative integers separated by single spaces.</p>



## 출력


<p>For each test case, output a single line containing the maximum number that can be obtained by inserting the operators between the given integers.</p>



## 소스코드

[소스코드 보기](The%20Minions%20Quiz.cpp)