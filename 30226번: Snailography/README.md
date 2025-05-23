# 30226번: Snailography - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/30226)


<p>Snails have many enemies including snakes, turtles, and birds. So, snails need to communicate their travel paths using cryptography to avoid their routes being detected.</p>

<p><img alt="" src="https://upload.acmicpc.net/6e6b56cc-7696-454f-a019-2f378afb82ba/-/preview/" style="float: right; width: 245px; height: 216px;">The encryption technique: The message will contain only letters. Let’s assume the message length is L. We use the smallest odd integer N such that N×N ≥ L. Then, an N×N table is used to encrypt the message as follows: Put the first letter of the message in the cell at the center of the table and then put the remaining letters in the table by moving in a circular way (snail like) around the center cell. For example, the table to the right shows the order for placing the letters from the message in a 7×7 table. So, from the center cell, we move up, then move right, then move down, then move left, then move up, etc.</p>

<p>Below are some sample encryptions. To help with the illustrations, when encrypting the message, if there are more cells in the table than there are letters in the message, we put the character ‘#’ in the extra cells.</p>

<p>Message: <code>ABCDEFGH</code></p>

<p>Encryption:</p>

<pre>#BC
HAD
GFE</pre>

<p>Message: <code>ABCDEFGHIJKLMNOPQRSTUVW</code></p>

<p>Encryption:</p>

<pre>#JKLM
#IBCN
WHADO
VGFEP
UTSRQ</pre>

<p>Message: <code>ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuv</code></p>

<p>Encryption:</p>

<pre>#Zabcde
vYJKLMf
uXIBCNg
tWHADOh
sVGFEPi
rUTSRQj
qponmlk</pre>

<p>Given the size of the two-dimensional table to use and the original message, you are to encrypt the message (to help snails live longer lives).</p>



## 입력


<p>The first input line contains an odd integer, n (1 ≤ n ≤ 19), indicating the table size to use. The second input line will provide the message to encrypt, a string of 1-361 (19×19) letters (lowercase and uppercase). Assume that the message will fit in the table.</p>



## 출력


<p>Print the encrypted message on one output line using the row-major order, i.e., print Row 1 followed by Row 2, followed by Row 3, etc.</p>

<p>Remember to print a newline character after printing the last row.</p>

<p>The output should not include ‘#’ characters.</p>



## 소스코드

[소스코드 보기](Main.java)