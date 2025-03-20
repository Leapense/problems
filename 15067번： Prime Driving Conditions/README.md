# 15067번: Prime Driving Conditions - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/15067)


<p>Meredith has just bought a new car and needs license plates. In Pennsylvania, license plates consist of three uppercase letters followed by four digits. License plates are given out in lexicographic order, meaning that plate AAA 0000 is first, followed by AAA 0001, AAA 0002, etc,. After AAA 9999 comes plates AAB 0000, AAB 0001, etc., and after plate AZZ 9999 comes plate BAA 0000. The very last plate is ZZZ 9999.</p>

<p>For most people, any old license plate will do, but not for Meredith. She insists that the 4 digit number on the plate must be a prime number. Recall that a prime number is a number &gt; 1 whose only factors are 1 and the number itself. The first few prime numbers are</p>

<p style="text-align:center">2, 3, 5, 7, 11, 13, 17, 19, 23, . . .</p>

<p>So if Meredith goes to the DMV to get a set of plates, and the next available plate is JPB 1285, she’ll wait until plate JPB 1289 becomes available, since 1289 is the first prime greater than or equal to 1285. If the next available plate had been JPB 9999, she would have waited for the plate JPC 0002.</p>

<p>Perhaps you see what we’re driving at here. Starting at a given license plate, find the first plate lexicographically equal or greater that contains a prime number.</p>

<p>As a side note, this past January the largest prime number known to date was discovered. It is equal to 2<sup>74,207,281</sup> − 1 and contains 22,338,618 digits. A little too large to fit on a license plate.</p>



## 입력


<p>The input file contains multiple test cases. Each test case is on a single line and contains a three character string followed by a 4 digit number. The three character string consists solely of uppercase letters other than the string “ZZZ". A line containing END 0000 terminates input.</p>



## 출력


<p>For each test case, display the license plate Meredith will accept.</p>



## 소스코드

[소스코드 보기](Prime%20Driving%20Conditions.cpp)