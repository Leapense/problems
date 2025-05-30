# 15068번: Time is of the Essence - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/15068)


<p>Do you know how long one million seconds is? How about one billion seconds? Well, the answer to the first one is</p>

<p style="text-align:center">11 days, 13 hours, 46 minutes and 40 seconds</p>

<p>Accurate, but a little over-precise. A more reasonable answer might be “11 days, 14 hours" or just “12 days" (after rounding). As another example, if I asked how long three million inches were, you could approximate it by saying either “47 miles" or “47 miles, 613 yards". This sort of imprecision is what we’re looking for in this problem!</p>



## 입력


<p>Input consists of two lines. The first line has the form</p>

<pre>n name<sub>1</sub> c<sub>1</sub> name<sub>2</sub> c<sub>2</sub> . . . name<sub>n−1</sub> c<sub>n−1</sub> name<sub>n</sub></pre>

<p>Each name<sub>i</sub> is a unit of measurement and each ci is a conversion rate, telling you how many units of type name<sub>i+1</sub> are in a unit of type name<sub>i</sub>. For example, in the first sample input, this line tells you that there are 24 hours in one day, 60 minutes in each hour and 60 seconds in each minute. The value n indicates the total number of unit names and satisfies 2 ≤ n ≤ 10. All names are alphabetic strings with no blanks and always specify the plural form of the unit (which you should use for output no matter the value is associated with the unit). All conversion values are positive integers. Following this line is a single positive integer m ≤ 2,000,000,000 indicating an amount of the last unit (i.e., name<sub>n</sub>).</p>



## 출력


<p>Display two lines. The first line should give the closest conversion of the input amount to units specified by name<sub>1</sub>, rounded to the nearest integer. The second line should do the same, but be a bit more precise using the two largest units – name<sub>1</sub> and name<sub>2</sub>. When rounding, always round up when the fraction is ≥ 0.5. Note that there are no commas in the output.</p>



## 소스코드

[소스코드 보기](Time%20is%20of%20the%20Essence.cpp)