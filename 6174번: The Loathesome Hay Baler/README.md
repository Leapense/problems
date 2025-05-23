# 6174번: The Loathesome Hay Baler - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/6174)


<p>Farmer John has purchased the world's most loathesome hay baler. Instead of having a drive-roller that drives maybe an idler roller that drives the power take-off for the baler, it has N rollers (2 &lt;= N &lt;= 1050) which drive and are driven by various rollers.</p>

<p>FJ has meticulously cataloged data for each roller i: X_i,Y_i are the center of the roller (-5000 &lt;= X_i &lt;= 5000; -5000 &lt;= Y_i &lt;= 5000); R_i is the roller's radius (3 &lt;= R_i &lt;= 800). The drive-roller is located at 0,0; the baler power take-off is located at X_t,Y_t (numbers supplied in the input).</p>

<p>The drive-roller turns clockwise at 10,000 revolutions per hour. Your job is to determine the speeds of all the rollers that are in the power-train: from the drive-roller through the power take-off roller. Rollers that do not transfer power to the take-off roller are to be ignored. A roller of radius Rd that is turning at S rph and driving another roller of radius Rx will cause the second roller to turn at the speed -S*Rd/Rx (where the sign denotes whether the roller is turning clockwise or counterclockwise (anticlockwise for our British friends)).</p>

<p>Determine the power-train path and report the sum of the absolute values of all those rollers' speeds. All the rollers in the input set except the driver-roller are driven by some other roller; power is never transferred to a roller from more than one other roller.</p>

<p>Report your answer as an integer that is the truncated value after summing all the speeds.</p>



## 입력


<ul>
<li>Line 1: Three space-separated integers: N, X_t, and Y_t</li>
<li>Lines 2..N+1: Line i+1 describes roller i's properties: X_i, Y_i, and R_i</li>
</ul>

<p>&nbsp;</p>



## 출력


<ul>
<li>Line 1: A single integer that is the truncated version of the sum of the absolute value of the speeds of the rollers in the power-train including the drive-roller, all the driven rollers, and the power take-off roller.</li>
</ul>



## 소스코드

[소스코드 보기](The%20Loathesome%20Hay%20Baler.py)