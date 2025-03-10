# 9620번: Meeting Room Arrangement - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/9620)


<p>Faculty of Engineering of PSU has a large meeting room for faculty staff to organize events and meetings. The use of the meeting room must be reserved in advance. Since the meeting room is available in 10 hours per day and there may be several events that want to use the meeting room, the best usage policy is to maximize the number of events in day.&nbsp;</p>

<p>Suppose that the meeting room is available from time 0 to 10 (10 hours). Given the list of start time and finish time of each candidate event, you are to write a program to select the events that fit in the meeting room (i.e. their times do not overlap) and give the maximum number of events in a day.&nbsp;</p>



## 입력


<p>The first line is a positive integer n (1&lt;=n&lt;=100) which determines the number of days (test cases). Each test case consists of the time of the candidate events (less than 20 events). Each event time includes 2 integers which are start time(s) and finish time(f), 0&lt;=s&lt;=9, 1&lt;=f&lt;=10 and s &lt;f . The line containing 0 0 indicates the end of each test case. Note that an event must use at least 1 hour.&nbsp;</p>



## 출력


<p>For each test case, print out the maximum number of events that can be arranged in the meeting room.</p>



## 소스코드

[소스코드 보기](Meeting%20Room%20Arrangement.cpp)