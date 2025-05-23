# 11151번: Civilization - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/11151)


<p>Emperor Montezuma of the ancient civilization of the Aztecs has a hard time planning the productivity of his capital city. The city is divided into square-shaped regions of the same size. Each region has three important properties: Workforce (number of people able to work), income (the amount of money Montezuma can earn from this region, given in Quetzal, the Aztec currency) and the number of farms. A region needs an administrator in order to contribute to the city. Otherwise, the region is selfsufficient and not officially a part of the city (and hence, Montezuma doesn’t earn taxes, cannot utilize the work force and cannot access food produced from the region’s farms).</p>

<p>Montezuma wants to make sure that his capital city is sufficiently prosperous, and he wants to achieve this prosperity by using as few administrators as possible. The capital city is prosperous if the sums of the workforces, income and farms for all administered regions exceed or are equal to the given values in each category.</p>

<p>Alas, Montezuma was born rather early and didn’t have access to computers. However, you have read about Montezuma’s exploits in the Civilopedia of the latest installment of the computer game Civilization. You found this scenario interesting enough that you have decided to write a computer program that calculates the fewest number of regions Montezuma would need to administer in order to have a city which is prosperous with regard to workforce, taxes and farms.</p>



## 입력


<p>The first line of the input consists of a single integer T, the number of test cases. Each test case begins with a line containing a single integer N, the number of regions near the capital city. The next line contains three integers W, C, F, representing the number of workers, tax income and number of farms which is needed for the city to be considered prosperous. The next N lines contains three integers w<sub>i</sub>, c<sub>i</sub>, f<sub>i</sub>, the number of workers, the tax income and the number of farms that region i offers, respectively.</p>

<ul>
<li>0 &lt; T ≤ 100</li>
<li>0 &lt; N ≤ 18</li>
<li>0 &lt; W, C, F ≤ 1000</li>
<li>0 &lt; w<sub>i</sub>, c<sub>i</sub>, f<sub>i</sub> ≤ 1000</li>
</ul>



## 출력


<p>For each test case, output the minimal number of regions that need to be administered. If it is impossible for the city to be prosperous, output “game over” instead (without quotes).</p>



## 소스코드

[소스코드 보기](Civilization.cpp)