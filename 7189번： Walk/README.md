# 7189번: Walk - <img src="https://static.solved.ac/tier_small/6.svg" style="height:20px" /> Silver V

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/7189)


<p>Mart takes a walk every day and his sports watch registers the duration and speed of each segment of uniform movement of his walk. After the walk, Mart can download a log file to his computer. Find the total distance and the average speed of the walk based on this file.</p>



## 입력


<p>The first line of input contains an integer $N$ ($1 ≤ N ≤ 10\,000$) and each of the subsequent $N$ lines contains the following (space-separated) data about one segment:</p>

<ul>
<li>the duration of the segment in minutes and seconds in the form $M$<code>m</code>$S$<code>s</code>, where $M$ is the integer number of minutes (and the minutes part is omitted for times less than a minute) and $S$ is the integer number of seconds (which never exceeds 59);</li>
<li>the word <code>kiirusega</code>;</li>
<li>the speed on this segment expressed as minutes and seconds per kilometre in the form $M$<code>m</code>$S$<code>s/km</code>, where $M$ is the integer number of minutes and $S$ is the integer number of seconds (which never exceeds $59$), and you may assume Mart needs at least a minute, but less than an hour, per kilometre.</li>
</ul>

<p>You may also assume that the total of the durations of all segments does not exceed $24$ hours.</p>



## 출력


<p>The output should contain two lines</p>

<ul>
<li>on the first line the total distance of the walk, rounded to metres, in the form $L$<code>m</code>, where $L$ is the integer number of metres;</li>
<li>on the second line the average speed in the form $V$<code>km/h</code>, where $V$ is a real number; the output value must not differ from the correct answer by more than $0.001$.</li>
</ul>



## 소스코드

[소스코드 보기](Walk.cpp)