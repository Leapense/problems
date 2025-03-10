# 4397번: Choose and divide - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/4397)


<p>The binomial coefficient C(m,n) is defined as</p>

<pre>            m!
C(m,n) = --------
         n!(m-n)!
</pre>

<p>Given four natural numbers p, q, r, and s, compute the the result of dividing C(p,q) by C(r,s).</p>



## 입력


<p>Input consists of a sequence of lines. Each line contains four non-negative integer numbers giving values for p, q, r, and s, respectively, separated by a single space. All the numbers will be smaller than 10,000 with p&gt;=q and r&gt;=s.</p>



## 출력


<p>For each line of input, print a single line containing a real number with 5 digits of precision in the fraction, giving the number as described above. You may assume the result is not greater than 100,000,000.</p>



## 소스코드

[소스코드 보기](Choose%20and%20divide.cpp)