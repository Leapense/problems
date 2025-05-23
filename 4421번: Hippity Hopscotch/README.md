# 4421번: Hippity Hopscotch - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/4421)


<p>The game of hopscotch involves chalk, sidewalks, jumping, and picking things up. Our variant of hopscotch involves money as well. The game is played on a square grid of dimension n: each grid location is labelled (p,q) where 0 &lt;= p &lt; n and 0 &lt;= q &lt; n. Each grid location has on it a stack of between 0 and 100 pennies.</p>

<p>A contestant begins by standing at location (0,0). The contestant collects the money where he or she stands and then jumps either horizontally or vertically to another square. That square must be within the jumping capability of the contestant (say, k locations) and must have more pennies than those that were on the current square.</p>

<p>Given n, k, and the number of pennies at each grid location, compute the maximum number of pennies that the contestant can pick up before being unable to move.</p>



## 입력


<ul>
<li>a line containing two integers between 1 and 100: n and k</li>
<li>n lines, each with n numbers: the first line contains the number of pennies at locations (0,0) (0,1) ... (0,n-1); the next line contains the number of pennies at locations (1,0), (1,1), ... (1,n-1), and so on.</li>
</ul>

<p>&nbsp;</p>



## 출력


<ul>
<li>a single integer giving the number of pennies collected</li>
</ul>



## 소스코드

[소스코드 보기](Hippity%20Hopscotch.cpp)