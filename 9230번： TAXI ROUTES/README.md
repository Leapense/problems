# 9230번: TAXI ROUTES - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/9230)


<p>In the town of Gridville the road network is a perfect rectangular grid. Since the founders of Gridville were computer scientists, this grid is numbered starting from 0 in both the East-West (EW) and North-South (NS) directions. The roads running EW are called streets, and those running NS are called avenues. A taxi company has its depot in the SW corner of the grid (i.e. at the intersection of 0th St and 0th Ave.) The problem is to determine how many routes are available to the NE corner of the city driving only in an eastward or northward direction (that is, no backtracking is allowed). The situation is complicated by the fact that certain intersections are under construction and are therefore impassable. Note that we will guarantee that the number of routes will never exceed 2147483647 (2^31-1).</p>



## 입력


<p>Input will consists of a sequence of ‘maps’. Each map begins with a line consisting of a pair of integers in the range from 1 to 30 giving the number of streets and avenues respectively. This is followed by a sequence of lines also containing pairs of integers which denote the impassable intersections (the first element of a pair is the street number, the second the avenue number). Note that neither the home nor the destination intersections will appear on this list. Input for a single map is terminated by the pair 0 0. Input as a whole is terminated by another line containing pair 0 0.</p>



## 출력


<p>For each map in the input, output a single line in the following form: Map &lt;mapId&gt;: &lt;num&gt;</p>

<p>Here &lt;mapId&gt; is the identification number of the map (an integer, beginning from 1), and &lt;num&gt; is the number of routes available. Note that &lt;num&gt; will never exceed 2147483647 (2^31-1).</p>



## 소스코드

[소스코드 보기](TAXI%20ROUTES.cpp)