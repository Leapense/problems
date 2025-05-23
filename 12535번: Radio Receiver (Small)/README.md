# 12535번: Radio Receiver (Small) - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/12535)


<p>You have a radio receiver and want to receive&nbsp;<strong>N</strong>&nbsp;messages. Each message is transmitted at a predetermined time measured in seconds since the epoch. Also each message is transmitted from a predetermined position representing the displacement in meters from the origin (you are in 1-dimensional space). Your radio is capable of receiving any message that is transmitted no farther than&nbsp;<strong>D</strong>&nbsp;meters from your current position, where&nbsp;<strong>D</strong>is a nonnegative real number.</p>

<p>You can start at any position of your choice and move at the rate of at most one meter per second. The action of receiving a message itself takes no time. Your task is to find the smallest&nbsp;<strong>D</strong>&nbsp;that allows you to get all messages.</p>



## 입력


<p>The first line of input gives the number of test cases,&nbsp;<strong>C</strong>.&nbsp;<strong>C</strong>&nbsp;test cases follow. For each test case there will be:</p>

<ul>
<li>One line containing the integer&nbsp;<strong>N</strong>, the number of messages.</li>
<li><strong>N</strong>&nbsp;lines corresponding to the&nbsp;<strong>N</strong>&nbsp;messages where each of them contains 2 integers&nbsp;<strong>P</strong>&nbsp;and&nbsp;<strong>T</strong>&nbsp;separated by one space.&nbsp;<strong>P</strong>&nbsp;is the position where the message is transmitted from and&nbsp;<strong>T</strong>&nbsp;is the time when this message is transmitted (The messages will have distinct transmission times).</li>
</ul>

<h3>Limits</h3>

<ul>
<li>1 ≤&nbsp;<strong>C</strong>&nbsp;≤ 100</li>
<li>1 ≤&nbsp;<strong>N</strong>&nbsp;≤ 1000</li>
<li>0 ≤&nbsp;<strong>P</strong>&nbsp;≤ 1000</li>
<li>0 ≤&nbsp;<strong>T</strong>&nbsp;≤ 1000</li>
</ul>

<p>&nbsp;</p>



## 출력


<p>For each test case, output one line containing "Case #<strong>x</strong>: ", where&nbsp;<strong>x</strong>&nbsp;is the number of the test case, followed by the minimum value&nbsp;<strong>D</strong>&nbsp;that allows you to get all messages. Answers with a relative or absolute error of at most 10<sup>-9</sup>&nbsp;will be considered correct.</p>



## 소스코드

[소스코드 보기](Radio%20Receiver%20(Small).py)