# 7556번: Manhattan 2025 - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/7556)


<p>Manhattan in the year 2025 – it is so densely populated that its old two-dimensional grid of streets and avenues fails to provide enough space for all the traditional vehicles such as cars, bicycles, or busses. Accordingly, the newly developed 3D-Skyjetters become very popular, because they allow to pass the traffic jams on the ground by flying in the air. After a series of horrible accidents caused by 3D-Skyjetters cutting a corner, New York authorities have put into place new regulations of air traffic and are determined to enforce them rigorously. The key point of these regulations is that 3D-Skyjetters must follow virtual airways on a three-dimensional rectangular grid, easy enough for the New Yorkers who had to use the two-dimensional rectangular grid of roads on the ground all their life.</p>

<p>You own a company that rents out 3D-Skyjetters. As 3D-Skyjetters are in such an early state of development, they are far from being economical. So your customers keep running out of petrol at all the wrong places, and you need a system to inform them about their current range at all times.</p>

<p>You may assume that travelling from one intersection to the next in the grid takes one unit of petrol, no matter if the customer is moving horizontally or vertically, up or down. You may also assume that your customer is located at some intersection where his or her movements are not restricted by the ground or other obstacles, but just by the amount of remaining petrol.</p>

<p>Given the amount of petrol, provide a graphical representation of all the intersections in the range of your customer, along with the amount of petrol that is needed to go there.</p>



## 입력


<p>The first line of the input contains the number of scenarios. For each scenario, there is a line containing the units of remaining petrol, i.e an integer u satisfying 0 ≤ u ≤ 9. If more than 9 units of petrol remain, the customer will ignore the display anyway.</p>



## 출력


<p>Start the output for each scenario with a line containing “Scenario #i:”, where i is the number of the scenario starting at 1. Then print a graphical (or rather textual) representation of all intersections that can be reached with the given amount of petrol, along with the units of petrol necessary to go there. In this graphical representation, print the slices of the smallest axis-aligned three-dimensional cube containing all the intersections in the range, and label the slices from the bottom to the top starting at 1. For each slice, start the output with a line containing “slice #s:”, where s is the number of the slice. In the lines that follow, print a graphical representation of all the intersections in that slice, using</p>

<ul>
<li>the digits 0 to 9 for intersections in the range, representing the amount of petrol necessary to go there,</li>
<li>and the dot “.” for intersections not in the range.</li>
</ul>

<p>Print an additional blank line after each scenario.</p>



## 소스코드

[소스코드 보기](Main.java)