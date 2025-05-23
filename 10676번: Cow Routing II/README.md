# 10676번: Cow Routing II - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/10676)


<p>Tired of the cold winter weather on her farm, Bessie the cow plans to fly to a warmer destination for vacation. &nbsp;Unfortunately, she discovers that only one airline, Air Bovinia, is willing to sell tickets to cows, and that these tickets are somewhat complicated in structure.</p>

<p>Air Bovinia owns N planes (1 &lt;= N &lt;= 500), each of which flies on a specific "route" consisting of two or more cities. &nbsp;For example, one plane might fly on a route that starts at city 1, then flies to city 5, then flies to city 2, and then finally flies to city 8. &nbsp;No city appears multiple times in a route. &nbsp;If Bessie chooses to utilize a route, she can board at any city along the route and then disembark at any city later along the route. &nbsp;She does not need to board at the first city or disembark at the last city. &nbsp;Each route has a certain cost, which Bessie must pay if she uses any part of the route, irrespective of the number of cities she visits along the route, and Bessie may make use of a route only once (that is, she cannot use a route and then later use a different part of the same route).</p>

<p>Bessie would like to find the cheapest way to travel from her farm (in city A) to her tropical destination (city B). Since she does not want to be confused by a complicated itinerary, she wants to use at most two routes. &nbsp;Please help her decide what is the minimum cost she must pay.</p>

<p>[Note that the only difference between this problem and the preceding bronze problem is that here Bessie can use up to two routes, versus only one route in the preceding problem]</p>



## 입력


<p>The first line of input contains A, B, and N, separated by spaces.</p>

<p>The next 2N lines describe the available routes, in two lines per route. The first line contains the cost of using the route (an integer in the range 1..1000), and the number of cities along the route (an integer in the range 1..500). &nbsp;The second line contains a list of the cities in order along the route. &nbsp;Each city is identified by an integer in the range 1..10,000.</p>



## 출력


<p>Output the minimum cost of an itinerary using at most two routes that Bessie can use to travel from city A to city B. &nbsp;If there is no such solution, output -1.</p>



## 소스코드

[소스코드 보기](Cow%20Routing%20II.cpp)