# 24653번: Announcements - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/24653)


<p>There are $N$ billboards with announcements near Kyoto University.</p>

<p>The $i$-th billboard appears at day $S_i$. However, at each $T$-th day, all billboards installed before this day are removed. You may assume that, on those days, no new billboards will appear.</p>

<p>Find the minimal number of times you need to visit the university to see each billboard at least once.</p>



## 입력


<p>The first line of input contains one integer $N$ ($1 \le N \le 2 \cdot 10^5$). The second line contains $N$ integers $S_1, S_2, \ldots, S_N$. Here, $S_i$ is the day when the $i$-th billboard appears ($1 \le S_i \le 10^9$). The last line contains one integer $T$ ($2 \le T \le 10^9$, $S_i$ is not divisible by $T$ for any $i$): the interval between successive deletions. This means the billboards are removed on days $T$, $2T$, $3T$, and so on.</p>



## 출력


<p>Print one integer: the minimum number of visits you need to do to see each billboard at least once.</p>



## 소스코드

[소스코드 보기](Announcements.cpp)