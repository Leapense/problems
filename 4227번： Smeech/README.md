# 4227번: Smeech - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/4227)


<p>Professor Octastichs has invented a new programming language, Smeech. An expression in Smeech may be a positive or negative integer, or may be of the form (p e1 e2) where p is a real number between 0 and 1 (inclusive) and e1 and e2 are Smeech expressions. The value represented by a Smeech expression is as follows:</p>

<ul>
<li>An integer represents itself</li>
<li>With probability p, (p e1 e2) represents x+y where x is the value of e1 and y is the value of e2; otherwise it represents x-y.</li>
</ul>

<p>Given a Smeech expression, what is its expected value?</p>



## 입력


<p>Input consists of several Smeech expressions, one per line, followed by a line containing ().&nbsp;</p>



## 출력


<p>For each expression, output its expected value to two decimal places.</p>



## 소스코드

[소스코드 보기](Smeech.py)