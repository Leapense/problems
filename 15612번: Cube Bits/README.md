# 15612번: Cube Bits - <img src="https://static.solved.ac/tier_small/4.svg" style="height:20px" /> Bronze II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/15612)


<p>The new computers are here! However, we made a mistake during the order: we thought we were ordering machines with qubits; in fact, we ordered several hundred computers powered by cube-bits.</p>

<p>The programs and data we had ready were prepared in base 10. To feed the data into the new computer, which uses a cubic system of counting, we will need to convert it to base 3 first.</p>

<p>Write a program to convert a stream of decimal numbers into ternary format, so they fit the new system’s input bus.</p>



## 입력


<p>The input consists of:</p>

<ul>
<li>One line with an integer n (1 ≤ n ≤ 10<sup>6</sup>), the size of the data stream.</li>
<li>n lines with one decimal integer v<sub>i</sub> (0 ≤ v &lt; 3<sup>20</sup>), the decimal representation of the i-th integer in the data stream.</li>
</ul>



## 출력


<p>Output n lines, giving the numbers converted to base-3, in the same order as given. In the interest of conserving disk space, do not print leading zeroes.</p>



## 소스코드

[소스코드 보기](Cube%20Bits.py)