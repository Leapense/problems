# 12514번: Candy Splitting (Large) - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/12514)


<p>Sean and Patrick are brothers who just got a nice bag of candy from their parents. Each piece of candy has some positive integer value, and the children want to divide the candy between them. First, Sean will split the candy into two piles, and choose one to give to Patrick. Then Patrick will try to calculate the value of each pile, where the value of a pile is the sum of the values of all pieces of candy in that pile; if he decides the piles don't have equal value, he will start crying.</p>

<p>Unfortunately, Patrick is very young and doesn't know how to add properly. He&nbsp;<em>almost</em>knows how to add numbers in binary; but when he adds two 1s together, he always forgets to carry the remainder to the next bit. For example, if he wants to sum 12 (1100 in binary) and 5 (101 in binary), he will add the two rightmost bits correctly, but in the third bit he will forget to carry the remainder to the next bit:</p>

<pre>  1100
+ 0101
------
  1001
</pre>

<p>So after adding the last bit without the carry from the third bit, the final result is 9 (1001 in binary). Here are some other examples of Patrick's math skills:</p>

<pre>5 + 4 = 1
7 + 9 = 14
50 + 10 = 56
</pre>

<p>Sean is very good at adding, and he wants to take as much value as he can without causing his little brother to cry. If it's possible, he will split the bag of candy into two non-empty piles such that Patrick thinks that both have the same value. Given the values of all pieces of candy in the bag, we would like to know if this is possible; and, if it's possible, determine the maximum possible value of Sean's pile.</p>



## 입력


<p>The first line of the input gives the number of test cases,&nbsp;<strong>T</strong>.&nbsp;&nbsp;<strong>T</strong>&nbsp;test cases follow. Each test case is described in two lines. The first line contains a single integer&nbsp;<strong>N</strong>, denoting the number of candies in the bag. The next line contains the&nbsp;<strong>N</strong>&nbsp;integers&nbsp;<strong>C<sub>i</sub></strong>&nbsp;separated by single spaces, which denote the value of each piece of candy in the bag.</p>

<h3>Limits</h3>

<ul>
<li>1 ≤&nbsp;<strong>T</strong>&nbsp;≤ 100.</li>
<li>1 ≤&nbsp;<strong>C<sub>i</sub></strong>&nbsp;≤ 10<sup>6</sup>.</li>
<li>2 ≤&nbsp;<strong>N</strong>&nbsp;≤ 1000.</li>
</ul>



## 출력


<p>For each test case, output one line containing "Case #x: y", where x is the case number (starting from 1). If it is impossible for Sean to keep Patrick from crying, y should be the word "NO". Otherwise, y should be the value of the pile of candies that Sean will keep.</p>



## 소스코드

[소스코드 보기](Candy%20Splitting%20(Large).py)