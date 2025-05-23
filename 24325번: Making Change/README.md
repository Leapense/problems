# 24325번: Making Change - <img src="https://static.solved.ac/tier_small/5.svg" style="height:20px" /> Bronze I

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/24325)


<p>Anakin Skywalker is leaving Tatoonie, but before he can go he must program a droid to do his old job of making change for customers at Watto’s junk business. Given the price of an item and the payment determine the correct change using \$50, \$20, \$10, \$5, and \$1 bills. You don’t have to worry about change, because Watto always keeps the change.</p>



## 입력


<p>A positive integer, n, on the first line indicating the number of data sets to follow. Each data set will consist of two positive numbers. The first is the cost to the customer and the second is the payment made by the customer. The payment will always be greater than the cost.</p>



## 출력


<p>For each data set print the correct change on one line using the format</p>

<pre>v-$50, w-$20, x-$10, y-$5, z-$1</pre>

<p>where v, w, x, y, z are the number of bills needed to make the correct change. Of course, the correct change will always use larger bills when possible (i.e., 1-\$5 not 5-\$1)</p>



## 소스코드

[소스코드 보기](Making%20Change.cpp)