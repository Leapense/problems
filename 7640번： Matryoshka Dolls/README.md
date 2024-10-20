# 7640번: Matryoshka Dolls - <img src="https://static.solved.ac/tier_small/7.svg" style="height:20px" /> Silver IV

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/7640)


<p>Adam just got a box full of Matryoshka dolls (Russian traditional) from his friend Matryona. When he opened the box, tons of dolls poured out of the box with a memo from her:</p>

<blockquote>
<p>Hi Adam, I hope you enjoy these dolls. But sorry, I didn’t have enough time to sort them out. You’ll notice that each doll has a hollow hole at the bottom which allows it to contain a smaller doll inside.<br>
...<br>
Yours,<br>
Matryona</p>
</blockquote>

<p>Adam, who already has so many things in his showcase already, decides to assemble the dolls to reduce the number of outermost dolls. The dolls that Matryona sent have the same shape but different sizes. That is, doll i can be represented by a single number h<sub>i</sub> denoting its height. Doll i can fit inside another doll j if and only if h<sub>i</sub> &lt; h<sub>j</sub>. Also, the dolls are designed such that each doll may contain at most one doll right inside it. While Adam is stacking his gigantic collection of Matryoshka dolls, can you write a program to compute the minimum number of outermost dolls so that he can figure out how much space he needs in his showcase?</p>



## 입력


<p>The input consists of multiple test cases. Each test case begins with a line with an integer N, 1 ≤ N ≤ 10<sup>5</sup>, denoting the number of Matryoshka dolls. This is followed by N lines, each with a single integer h<sub>i</sub>, 1 ≤ h<sub>i</sub> ≤ 10<sup>9</sup>, denoting the height of the ith doll in cm. Input is followed by a single line with N = 0, which should not be processed.</p>



## 출력


<p>For each test case, print out a single line that contains an integer representing the minimum number of outermost dolls that can be obtained by optimally stacking the given dolls.</p>



## 소스코드

[소스코드 보기](Matryoshka%20Dolls.cpp)