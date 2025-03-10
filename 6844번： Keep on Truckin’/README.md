# 6844번: Keep on Truckin’ - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/6844)


<p>A truck driver is planning to drive along the Trans-Canada highway from Vancouver to St. John’s, a distance of 7000 km, stopping each night at a motel. The driver has been provided with a list of locations of eligible motels, with the respective distance of each motel, measured in km, from the starting point in Vancouver. Some of the motel locations are:</p>

<p>0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000</p>

<p>but more motel locations may be added just before the trip begins.</p>

<p>Determine if it is possible to complete the journey if:</p>

<ol>
<li>the trucking company insists that the driver travels a minimum distance of A km per day,</li>
<li>the law sets a maximum distance of B km per day, and</li>
<li>each night, the driver must stay at an eligible motel (from the above list or the additional locations described below).</li>
</ol>

<p>The driver is interested in different options when making the trip, and you are to write the program to calculate how many different options there are.</p>

<p>For example, if no new motel locations are added, A = 1 and B = 500, then it is impossible to make the trip, i.e., the number of options is 0. If A = 970 and B = 1030 then there is one way to make the trip, but if A = 970 and B = 1040 then there are four ways to make the trip. There are two ways to make the trip if A = 970, B = 1030, and we add one stop at 4960.</p>



## 입력


<p>The first two lines of the input are the minimum distance A and the maximum distance B (1  A  B  7000), both of which are integers. The third line of the input is an integer N (0  N  20), followed by N lines, each giving the location m of an additional eligible motel (0 &lt; m &lt; 7000). You should note that no two motels are located at the same distance from Vancouver.</p>



## 출력


<p>Output the number of different ways the driver can choose the motels to make the trip, under the given constraints.</p>



## 소스코드

[소스코드 보기](Main.java)