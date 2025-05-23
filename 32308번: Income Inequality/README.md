# 32308번: Income Inequality - <img src="https://static.solved.ac/tier_small/6.svg" style="height:20px" /> Silver V

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/32308)


<p>According to Wikipedia, in 2021, the top 1% of households own 32.3% of the wealth in the United States. More generally, for any given percentage x, we could look at the data and state that the top x% of households own y% of the wealth.</p>

<p>It's obvious that for all societies with some inequality, it is always the case that y &gt; x, except for x = 0 and x = 100. Of all possible choices for x, what is the maximum value of y – x?</p>

<p>Given the incomes of all people in a society, determine the maximum value of y – x where the top x% of the people have y% of the society's wealth.</p>



## 입력


<p>The first input line contains a single integer, n (2 ≤ n ≤ 10<sup>6</sup>), indicating the number of people in the society.</p>

<p>The second input line contains n integers; each integer, m (1 ≤ m ≤ 10<sup>12</sup>), provides the wealth of a household in the society. Please note that the income values are not necessarily distinct.</p>



## 출력


<p>Print the maximum possible value of y – x, where the top x% of households in the society own y% of the society's wealth. Any answer within an absolute or relative error of 10<sup>-6</sup> will be accepted.</p>



## 소스코드

[소스코드 보기](Income%20Inequality.cpp)