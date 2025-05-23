# 15428번: Imperfect GPS - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/15428)


<p>Lots of runners use personal Global Positioning System (GPS) receivers to track how many miles they run. No GPS is perfect, though: it only records its position periodically rather than continuously, so it can miss parts of the true running path. For this problem we’ll consider a GPS that works in the following way when tracking a run:</p>

<ul>
<li>At the beginning of the run, the GPS first records the runner’s starting position at time 0.</li>
<li>It then records the position every t units of time.</li>
<li>It always records the position at the end of the run, even if the total running time is not a multiple of t.</li>
</ul>

<p>The GPS assumes that the runner goes in a straight line between each consecutive pair of recorded positions. Because of this, a GPS can underestimate the total distance run.</p>

<p>For example, suppose someone runs in straight lines and at constant speed between the positions on the left side of Table 1. The time they reach each position is shown next to the position. They stopped running at time 11. If the GPS records a position every 2 units of time, its readings would be the records on the right side of Table 1.</p>

<table class="table table-bordered" style="width:40%">
<thead>
<tr>
<th>Time</th>
<th>Position</th>
<th>Time</th>
<th>Position</th>
</tr>
</thead>
<tbody>
<tr>
<td>0</td>
<td>(0,0)</td>
<td>0</td>
<td>(0,0)</td>
</tr>
<tr>
<td>3</td>
<td>(0,3)</td>
<td>2</td>
<td>(0,2)</td>
</tr>
<tr>
<td>5</td>
<td>(-2,5)</td>
<td>4</td>
<td>(-1,4)</td>
</tr>
<tr>
<td>7</td>
<td>(0,7)</td>
<td>6</td>
<td>(-1,6)</td>
</tr>
<tr>
<td>9</td>
<td>(2,5)</td>
<td>8</td>
<td>(1,6)</td>
</tr>
<tr>
<td>11</td>
<td>(0,3)</td>
<td>10</td>
<td>(1,4)</td>
</tr>
<tr>
<td>&nbsp;</td>
<td>&nbsp;</td>
<td>11</td>
<td>(0,3)</td>
</tr>
</tbody>
</table>

<p>Table 1: Actual Running Path on the left, GPS readings on the right.</p>

<p>The total distance run is approximately 14.313708 units, while the GPS measures the distance as approximately 11.650281 units. The difference between the actual and GPS distance is approximately 2.663427 units, or approximately 18.607525% of the total run distance.</p>

<p>Given a sequence of positions and times for a running path, as well as the GPS recording time interval t, calculate the percentage of the total run distance that is lost by the GPS. Your computations should assume that the runner goes at a constant speed in a straight line between consecutive positions.</p>



## 입력


<p>The input consists of a single test case. The first line contains two integers n (2 ≤ n ≤ 100) and t (1 ≤ t ≤ 100), where n is the total number of positions on the running path, and t is the recording time interval of the GPS (in seconds).</p>

<p>The next n lines contain three integers per line. The i-th line has three integers x<sub>i</sub>, y<sub>i</sub> (−10<sup>6</sup> ≤ x<sub>i</sub>, y<sub>i</sub> ≤ 10<sup>6</sup>), and t<sub>i</sub> (0 ≤ t<sub>i</sub> ≤ 10<sup>6</sup>), giving the coordinates of the i-th position on the running path and the time (in seconds) that position is reached. The values of t<sub>i</sub>’s are strictly increasing. The first and last positions are the start and end of the run. Thus, t<sub>1</sub> is always zero.</p>

<p>It is guaranteed that the total run distance is greater than zero.</p>



## 출력


<p>Output the percentage of the actual run distance that is lost by the GPS. The answer is considered correct if it is within 10<sup>−5</sup> of the correct answer.</p>



## 소스코드

[소스코드 보기](Imperfect%20GPS.cpp)