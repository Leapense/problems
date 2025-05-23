# 10678번: Meeting Time - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/10678)


<p>Bessie and her sister Elsie want to travel from the barn to their favorite field, such that they leave at exactly the same time from the barn, and also arrive at exactly the same time at their favorite field.</p>

<p>The farm is a collection of N fields (1 &lt;= N &lt;= 16) numbered 1..N, where field 1 contains the barn and field N is the favorite field. The farm is built on the side of a hill, with field X being higher in elevation than field Y if X &lt; Y. &nbsp;An assortment of M paths connect pairs of fields. &nbsp;However, since each path is rather steep, it can only be followed in a downhill direction. For example, a path connecting field 5 with field 8 could be followed in the 5 -&gt; 8 direction but not the other way, since this would be uphill. &nbsp;Each pair of fields is connected by at most one path, so M &lt;= N(N-1)/2.</p>

<p>It might take Bessie and Elsie different amounts of time to follow a path; for example, Bessie might take 10 units of time, and Elsie 20. Moreover, Bessie and Elsie only consume time when traveling on paths between fields -- since they are in a hurry, they always travel through a field in essentially zero time, never waiting around anywhere.</p>

<p>Please help determine the shortest amount of time Bessie and Elsie must take in order to reach their favorite field at exactly the same moment.</p>



## 입력


<p>The first input line contains N and M, separated by a space.</p>

<p>Each of the following M lines describes a path using four integers A B C D, where A and B (with A &lt; B) are the fields connected by the path, C is the time required for Bessie to follow the path, and D is the time required for Elsie to follow the path. &nbsp;Both C and D are in the range 1..1000.</p>



## 출력


<p>A single integer, giving the minimum time required for Bessie and Elsie to travel to their favorite field and arrive at the same moment. If this is impossible, or if there is no way for Bessie or Elsie to reach the favorite field at all, output the word IMPOSSIBLE on a single line.</p>



## 소스코드

[소스코드 보기](Meeting%20Time.cpp)