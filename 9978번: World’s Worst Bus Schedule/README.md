# 9978번: World’s Worst Bus Schedule - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/9978)


<p>You are a very impatient person, and hate to be kept waiting. You are on your way to visit a relative all the way in New Orleans. The problem is that the bus station you are at has the world’s worst bus schedule! There are no arrival or departure times listed, only route durations for each bus running. Being the impatient person you are, you whip out your laptop and attempt to write a program that will determine how long you will have to wait before the next bus comes. Hey, you have nothing better to do, right?</p>



## 입력


<p>Input to this problem will consist of a (non-empty) series of up to 100 data sets. Each data set will be formatted according to the following description, and there will be no blank lines separating data sets.</p>

<p>A single data set has 3 components:</p>

<ol>
<li>Start line – A single line, “START N”, where N is the number of buses running and 1 &lt;= N &lt;= 20.</li>
<li>Route Duration line – There will be N of these lines, and each line will consist of M route durations (where 1 &lt;= M &lt;= 10), which will signify how long it will take each bus to return to the bus station after completing a particular route. A route duration will be represented as an integer between 1 and 1000 (inclusive).</li>
<li>Arrival Time – There will only be one of these lines per data set. This line represents the time that you arrived at the bus station and began waiting. This is simply the number of time units that you arrived at the bus station after the buses began running (all buses begin running at time 0). This number is represented as a positive integer (yes, it can be 0 as well, this would signify arriving at the bus station as the buses begin running).</li>
<li>End line – A single line, "END".</li>
</ol>

<p>Following the final data set will be a single line, “ENDOFINPUT”.</p>



## 출력


<p>For each data set, there will be exactly one line of output. This line will simply be the number of time units you will have to wait before the next bus comes after you arrive. You hate waiting so much that you will just get on the first bus that returns to the station. Let’s hope this is the bus to New Orleans!</p>



## 소스코드

[소스코드 보기](World’s%20Worst%20Bus%20Schedule.cpp)