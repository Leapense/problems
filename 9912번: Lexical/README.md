# 9912번: Lexical - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/9912)


<p>A permutation of a set is a sequence in which every element of the set occurs exactly once. &nbsp;For example, the sequence 3201 is a permutation of the set {0, 1, 2, 3}, where the number 3 appears first, the number 2 appears second, the number 0 appears third and the number 1 appears last in the sequence. &nbsp;We can order the permutations of a set in a “lexicon” by looking at the first position where the permutations are different. &nbsp;For example, the permutation 3201 appears before 3210 in the lexicon, because at the first position where the permutations are different, the first permutation has a 0 whereas the second permutation has a bigger number, namely 1.</p>

<p>Given an integer n (1 ≤ n ≤ 13) and a permutation of the set { 0, 1, 2, …, n – 1 }, determine the position of the permutation in the lexicon.</p>

<p>Example: For n = 4, the lexicon has 24 entries and looks like this:</p>

<p style="text-align: center;">0123, &nbsp; 0132, &nbsp; 0213, &nbsp; 0231, &nbsp; 0312, &nbsp; 0321, &nbsp; 1023, &nbsp; 1032, &nbsp; 1203, … , &nbsp; 3201, &nbsp; 3210.</p>

<p>The permutation 3 2 0 1 appears at position 23.</p>

<p>The task is to determine at which position a given permutation appears in the lexicon.</p>

<p>Hint: If n is close to 13, it will be too slow to construct the entire lexicon, because the size of the lexicon is 1 × 2 × 3 × ... × n.</p>



## 입력


<p>The input consists of the following two lines:</p>

<ol>
<li>The first line contains an integer indicating the number n.</li>
<li>The second line consists of a permutation, namely a sequence of numbers from { 0, 1, 2, …, n – 1 } separated by a space.</li>
</ol>



## 출력


<p>The output contains a single integer value, which is the position of the permutation in the lexicon.</p>



## 소스코드

[소스코드 보기](Lexical.cpp)