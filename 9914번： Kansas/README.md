# 9914번: Kansas - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/9914)


<p>The road map of Kansas, USA, is a grid where there are straight roads North-South and straight roads East-West each 1 mile apart. &nbsp;A truck driver gets instructions in the following form. &nbsp;Drive for two hours north at 45 miles per hour, then for 5 hours west at 65 miles per hour, etc. &nbsp;The driver will have to take a break of 1 hour after 5 hours of continuous driving. &nbsp;The aim is to compute, after how many breaks the driver for the first time passes through or finally returns to the place where she started from.</p>



## 입력


<p>The first line contains an integer (≤ 1000) which is the number of instructions, followed by one line for each instruction, indicating the direction, the number of hours h (1 ≤ h ≤ 200) and the speed s (1 ≤ s ≤ 200) in miles per hour in this order. &nbsp;The geographical directions are indicated by the position of the small hand on an analog clock; 12 stands for north, 6 for south, 9 for west, and 3 for east.</p>



## 출력


<p>The output contains an integer which is the number of breaks taken before the driver for the first time passes through or finally returns to the place where she started from. &nbsp;If the driver does not reach or pass through the place where she started from after following all instructions, the output file should contain the number -1.</p>



## 소스코드

[소스코드 보기](Kansas.cpp)