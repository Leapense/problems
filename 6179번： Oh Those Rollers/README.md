# 6179번: Oh Those Rollers - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/6179)


<p>Farmer John has installed a new winch that gives him mechanical advantage when lifting bales of hay into the barn. The winch was manufactured by the Rube Goldberg Winch Company and has way too many rollers to make any sense at all. The winch has a huge steel plate with a number of rollers whose ultimate source of power is the drive-roller whose location FJ has denoted as the origin (0,0). This roller drives a roller that drives another roller, etc. etc. until the final roller is driven. FJ is trying to find that final roller and wants to know which one it is.</p>

<p>FJ has recorded the x_i,y_i (-5,000 &lt;= x_i &lt;= 5,000; -5,000 &lt;= y_i &lt;= 5,000) coordinates and the radius r_i (3 &lt;= r_i &lt;= 1024) of each of the N (2 &lt;= N &lt;= 1080) rollers. Tell him the x,y coordinate of the last roller in the chain (the roller that is driven but drives no other roller). Every roller except the drive-roller is driven by exactly one other roller.</p>



## 입력


<ul>
<li>Line 1: A single integer: N</li>
<li>Lines 2..N+1: Line i+1 describes roller i with three space separated integers: x_i, y_i, and r_i</li>
</ul>

<p>&nbsp;</p>



## 출력


<ul>
<li>Line 1: A single line with two space-separated integers that are respectively the x,y coordinates of the last roller in the chain of driven rollers.</li>
</ul>



## 소스코드

[소스코드 보기](Oh%20Those%20Rollers.py)