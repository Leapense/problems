# 20378번: Cyclic Numbers - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/20378)


<p>A <em>cyclic number</em> is a positive integer n digits in length which, when multiplied by any integer from 1 to n, yields a "cycle" of the digits of the original number. That is, if you consider the number after the last digit to "wrap around" back to the first digit, the sequence of digits in both numbers will be the same, though they may start at different positions.</p>

<p>For example, the number 142857 is cyclic, as illustrated by the following table:</p>

<ul>
<li>142857 × 1 = 142857</li>
<li>142857 × 2 = 285714</li>
<li>142857 × 3 = 428571</li>
<li>142857 × 4 = 571428</li>
<li>142857 × 5 = 714285</li>
<li>142857 × 6 = 857142</li>
</ul>

<p>Write a program which will determine whether or not numbers are cyclic.</p>



## 입력


<p>The input is a list of integers from 2 to 1000 digits in length (preceding zeroes are legal).</p>



## 출력


<p>In the output, display each integer and indicate whether or not it is cyclic.</p>



## 소스코드

[소스코드 보기](Cyclic%20Numbers.cpp)