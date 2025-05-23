# 9357번: Eligibility - <img src="https://static.solved.ac/tier_small/7.svg" style="height:20px" /> Silver IV

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/9357)


<p>Regional Contest Director Osama Ismail knows that an individual cannot participate in the regional contest more than 5 times. Given a list of contestant names and the previous years they participated in, print which contestant is eligible.</p>



## 입력


<p>The first line of the input contains a single integer T representing the number of the test cases</p>

<p>The first line of each test case contains a single integer N</p>

<p>N lines follow in this test case each having the format "Name Year" denoting that contestant Name participated in a regional contest in year Year</p>

<ul>
<li>T ≤ 100</li>
<li>0 ≤ N ≤ 500</li>
<li>Name is sequence of lowercase English letters, spaces and contains up to 20 characters&nbsp;</li>
<li>1970 ≤ Year ≤ 2070</li>
</ul>

<p>Note that since he collected the data from multiple sources it may contain duplicate records (if a contestant X have competed in year Y, you might find multiple lines "X Y" in the same test case)</p>



## 출력


<p>For each test case, print a line containing the test case number as formatted in the sample and then for each eligible contestant print his\her name on a single line and note that you must print the names of the contestants in lexicographic order</p>



## 소스코드

[소스코드 보기](Eligibility.cpp)