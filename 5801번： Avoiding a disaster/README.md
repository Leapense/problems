# 5801번: Avoiding a disaster - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/5801)


<p>Percy likes to be punctual. So much so that he always keeps three watches with him, so that he can be sure exactly what the time is. However, Percy's having a bad day. He found out that one of his watches was giving the wrong time. What's worse, when he went to correct the watch, he corrected the wrong one! That is, one watch was running x minutes behind (where x ≤ 480) and he wound one of the other watches x minutes forward. He now has three watches reading three different times, and hence is in serious danger of being tardy. Can you help Percy by writing a program that takes in the three times displayed on the watches and returns the correct time?</p>



## 입력


<p>The input begins with an integer T indicating the number of cases that follow (0 &lt; T &lt; 100). Each of the following T lines contains one test case, made up of three readings, separated by single space characters: H1:M1 H2:M2 H3:M3 In each reading H1,H2,H3 represent the hours displayed (0 &lt; H1,H2,H3 &lt; 13), and M1,M2,M3 represent the minutes displayed (0 &lt; M1,M2,M3 &lt; 60).</p>

<p>If the number of minutes is less than 10, a leading 0 is added.</p>



## 출력


<p>For each test case, one line should be produced, formatted exactly as follows: "The correct time is Hi:Mi". If the number of minutes is less than 10, a leading 0 should be added. If the number of hours is less than 10, a leading 0 should NOT be added. If it is impossible to tell the time from the three readings, print the string: "Look at the sun".</p>



## 소스코드

[소스코드 보기](Avoiding%20a%20disaster.py)