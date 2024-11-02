# 31663번: Mean Words - <img src="https://static.solved.ac/tier_small/3.svg" style="height:20px" /> Bronze III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/31663)


<p>Little Timmy got caught by his teacher using some mean words. After getting sent to the principal, little Timmy learned his lesson - he should do his best to not get caught next time!</p>

<p>What Timmy decided to do is to take all the mean words that he wants to say, and combine them all together into a single "mean" word by getting the average of all the characters in the same position across all the words that have a character in that position, and then rounding this average down to get the character in that position.</p>

<p>Note: The value of a character is its ASCII value, so the value of <code>a</code> is $97$, the value of <code>b</code> is $98$ and so on up to <code>z</code>, which has value $122$. So when we average characters, we are averaging their ASCII values, rounding this down to the nearest integer, and then using the corresponding character as the result of this averaging.</p>

<p>Help Timmy create his mean mean words!</p>



## 입력


<p>The first line contains a single integer $N$ ($2 \leq N \leq 1\, 000$), which represents the number of words that follow. The next $N$ lines contain a single word between $1$ and $45$ lowercase English characters each.</p>



## 출력


<p>Output the mean word obtained by following Timmy’s procedure.</p>



## 소스코드

[소스코드 보기](Mean%20Words.py)