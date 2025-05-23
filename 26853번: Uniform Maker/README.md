# 26853번: Uniform Maker - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/26853)


<p>The International Costumes and Props Company (ICPC) received an order from a client to produce N pennants each containing the same word. However, due to some miscommunication between the account manager and the client, not all the produced pennants have the same word although all of them have a word of the same length. Reproducing those pennants is very costly as the ICPC only uses a certain type of rare fabric in their production.</p>

<p>Fortunately, the client didn’t specify the word that they want to be in the pennants. In fact, the client will be satisfied if and only if all the pennants have the same word.</p>

<p>The ICPC has a special technique to change one character in a word into some other character. It is expensive, albeit not as expensive as reproducing a new pennant. Therefore, the ICPC has to minimize the number of times they have to use such a technique. Your task in this problem is to help the ICPC to determine the minimum total number of characters that need to be changed so that the client will be satisfied.</p>

<p>For example, let there be N = 6 pennants with the following words: <code>calf</code>, <code>palm</code>, <code>book</code>, <code>icpc</code>, <code>ball</code>, and <code>room</code>. The total number of characters than need to be changed can be minimized if all the words are changed into <code>balm</code>.</p>

<ul>
<li><code>calf</code> → 2 characters: <code>b**m</code></li>
<li><code>palm</code> → 1 characters: <code>b***</code></li>
<li><code>book</code> → 3 characters: <code>*alm</code></li>
<li><code>icpc</code> → 4 characters: <code>balm</code></li>
<li><code>ball</code> → 1 characters: <code>***m</code></li>
<li><code>room</code> → 3 characters: <code>bal*</code></li>
</ul>

<p>The symbol <code>*</code> represents an unchanged character. There are a total of 14 characters that need to be changed in this example.</p>



## 입력


<p>Input begins with a line containing two integers N M (2 ≤ N ≤ 100; 1 ≤ M ≤ 100) representing the number of pennants and the length of each word in the pennant, respectively. The next N line each contains a string S<sub>i</sub> (|S<sub>i</sub>| = M) representing the word on the i<sup>th</sup> pennant. Each string only contains lowercase alphabetical characters.</p>



## 출력


<p>Output contains an integer in a line representing the minimum total number of characters that need to be changed so that the client will be satisfied.</p>



## 소스코드

[소스코드 보기](Uniform%20Maker.py)