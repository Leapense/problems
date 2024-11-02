# 4166번: HST - <img src="https://static.solved.ac/tier_small/7.svg" style="height:20px" /> Silver IV

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/4166)


<p>On July 1st, Ontario's Provincial Sales Tax (PST) was merged with the Federal Goods and Services Tax (GST), creating the Harmonized Sales Tax (HST). This changed the rate of tax Ontarians pay on various items.</p>

<p>Dalton would like to calculate how this change will affect his personal monthly budget.</p>



## 입력


<p>The first line of input contains a single integer, the number of test cases to follow. Each test case begins with a line containing two integers N, M, the number of categories of items and the number of purchases Dalton makes each month, respectively. Each of these integers is between 1 and 100000, inclusive. N lines follow, each describing a category of item. Each of these lines contains a category name, which is a string of at most 30 uppercase letters, followed by three percentages, giving the PST, GST, and HST rate on that category. Each percentage is a number with up to two digits after the decimal point, and each percentage is followed by the % symbol. Each percentage is at least 0% and at most 100%. These lines are followed by M more lines, each describing one of Dalton's purchases. Each of these lines contains a category name and a price in dollars and cents and prefixed by the \$ symbol. Each such line indicates the amount of pre-tax money that Dalton spends on an item in the specified category. The amount of each tax to be paid on an item is rounded to the nearest cent; if the tax amount is exactly half a cent more than a whole number of cents, it is rounded up to the nearest greater whole number of cents.</p>



## 출력


<p>For each test case, output the difference, in dollars and cents, between the total HST payable and the total sum of PST and GST payable on Dalton's monthly purchases. If the HST is more than the PST+GST, output a positive amount. If the HST is less than the PST+GST, output a negative amount.</p>



## 소스코드

[소스코드 보기](HST.cpp)