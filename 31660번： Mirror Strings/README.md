# 31660번: Mirror Strings - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/31660)


<p>A character is called a “mirror character” if it looks the same when flipped up and down, and the same when flipped left and right. The uppercase mirror characters, <code>H</code>, <code>I</code>, <code>O</code>, <code>X</code>. The lowercase mirror characters are <code>l</code> (since people often write this as a vertical line), <code>o</code>, and <code>x</code>.</p>

<p>In the same way, a string that looks the same when flipped up and down or when flipped left and right is called a “mirror string”. For example, <code>XXOOOOXX</code> is a mirror string.</p>

<p>The height of the character affects the construction of the mirror string. For example, <code>llll</code> and <code>oooo</code> are both mirror strings. However, <code>lool</code> is not a mirror string because it looks different when it is flipped up and down. The uppercase characters <code>H</code>, <code>I</code>, <code>O</code>, <code>X</code> and the lowercase character <code>l</code> are both of height $2$ while the lowercase letters <code>x</code> and <code>o</code> are of height 1.</p>

<p>Tommy wants to construct mirror strings with lower characters and upper characters. He wants to know how many different mirror strings have length in the range $[L, R]$ (i.e. how many mirror strings have a length $m$ satisfying $L \leq m \leq R$).</p>

<p>For example, the $7$ mirror strings of length $1$ are <code>H</code>, <code>I</code>, <code>O</code>, <code>X</code>, <code>l</code>, <code>o</code>, or <code>x</code>. There are also $7$ mirror strings of length $2$, namely <code>HH</code>, <code>II</code>, <code>OO</code>, <code>XX</code>, <code>ll</code>, <code>oo</code>, and <code>xx</code>. But there are many more mirror strings of bigger lengths, for example there are $29$ mirror strings of length $3$.</p>



## 입력


<p>The first and only line of input contains two integers $L$ and $R$ ($1 \leq L \leq R \leq 10^6$), indicating the range of the lengths of mirror strings that Tommy wants to count.</p>



## 출력


<p>Output the number of mirror strings that have a length $m$ satisfing $L \leq m \leq R$. Since there can be many such strings, you should output the answer modulo $10^9 + 7$ (i.e. the remainder of the answer when it is divided by $10^9 + 7$).</p>



## 소스코드

[소스코드 보기](Mirror%20Strings.cpp)