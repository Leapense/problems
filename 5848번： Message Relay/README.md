# 5848번: Message Relay - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/5848)


<p>Farmer John's N cows (1 &lt;= N &lt;= 1000) are conveniently numbered from 1..N. Using an old-fashioned communicating mechanism based on tin cans and strings, the cows have figured out how to communicate between each-other without Farmer John noticing.</p><p>Each cow can forward messages to at most one other cow: for cow i, the value F(i) tells you the index of the cow to which cow i will forward any messages she receives (this number is always different from i).  If F(i) is zero, then cow i does not forward messages.</p><p>Unfortunately, the cows have realized the possibility that messages originating at certain cows might ultimately get stuck in loops, forwarded around in a cycle forever.  A cow is said to be "loopy" if a message sent from that cow will ultimately get stuck in a loop.  The cows want to avoid sending messages from loopy cows.  Please help them by counting the total number of FJ's cows that are not loopy.</p>


## 입력


<ul><li>Line 1: The number of cows, N.</li><li>Lines 2..1+N: Line i+1 contains the value of F(i).</li></ul>


## 출력


<ul><li>Line 1: The total number of non-loopy cows.</li></ul>


## 소스코드

[소스코드 보기](Message%20Relay.cpp)