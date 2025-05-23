# 6651번: Calendar of Events - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/6651)


<p>Marketing people are very creative and must regularly attend many creative meetings. In the past, the meetings used to repeat every week. Now, there are so many of them, that the period must have been changed to one month.</p>

<p>The monthly schedule of ACM now contains one meeting for each of the first N days in every month (including weekends). Meetings are identified by non-negative integer numbers. Recently, ACM found out that the schedule must be reorganized and the order of meetings changed. The new order has already been chosen. The only problem is that the meeting-planning department has very limited privileges and must follow many directives that are in effect.</p>

<p>It fact, the only change that the department is allowed to do, is to issue a request to reverse the order of meetings in the first D days of the month (D may be selected arbitrarily). For example, if the current schedule is “1 2 3 4 5” and the department issues a request to reverse the first 3 days, the new schedule will be “3 2 1 4 5”.</p>

<p>Another limitation is that the department is allowed to issue only one request per week. Since they need the whole reorganization to finish in one year, the number of requests may not exceed 52. As you can see, their situation is not easy. Will you help?</p>



## 입력


<p>The input contains a sequence of several reorganizations, the last one followed by a line with zero.</p>

<p>Each reorganization consists of three lines: the first line contains a positive integer N — the number of days in month that are considered, 1 ≤ N ≤ 30. The second line describes the old schedule and the third line the new schedule, each of them contains N meeting identifiers, separated with spaces. Some meetings may appear more than once.</p>



## 출력


<p>For each reorganization, output a single line containing at most 52 positive integer numbers D<sub>1</sub>, D<sub>2</sub>, ..., D<sub>k</sub> separated by a space (1 ≤ D<sub>i</sub> ≤ N). The numbers must form a valid sequence of requests that will be issued to transform the old schedule to the new one.</p>

<p>You are guaranteed that such a sequence will exist. If there are more valid sequences, feel free to output any of them.</p>



## 소스코드

[소스코드 보기](Main.java)