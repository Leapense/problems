# 32314번: Christmas Tree Adapter - <img src="https://static.solved.ac/tier_small/1.svg" style="height:20px" /> Bronze V

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/32314)


<p>Adapters (Transformers) are used with many devices (e.g., cell phones) to convert the 110 volt coming out of the outlet. The adapter for Dr. Orooji's Christmas Tree broke and Dr. O could not find that model online or in stores. The tree adapter was showing the “ampere” but the adapters online were showing “watt” and “volt”! So, Dr. O had to refer to the “Electricity 101 Book” to figure out what to buy:</p>

<ul>
<li>Watt: measure of power</li>
<li>Volt: measure of electric potential</li>
<li>Ampere: measure of current</li>
<li>watt = ampere × volt → ampere = watt / volt</li>
</ul>

<p>Given the ampere for Dr. O’s Christmas tree, and the watt and volt for a candidate adapter, determine if the candidate adapter will work with the tree. The adapter will work if its ampere is greater than or equal to the tree’s ampere.</p>



## 입력


<p>The first input line contains an integer, a (1 ≤ a ≤ 20), indicating the ampere for the Christmas tree. The second input line contains two integers: w (1 ≤ w ≤ 2000), indicating the watt for the candidate adapter and v (1 ≤ v ≤ 100), indicating the volt for the candidate adapter. Assume that the input will not result in fractions in divisions.</p>



## 출력


<p>Print 1 if the candidate adapter will work with the tree, 0 (zero) otherwise.</p>



## 소스코드

[소스코드 보기](Christmas%20Tree%20Adapter.cpp)