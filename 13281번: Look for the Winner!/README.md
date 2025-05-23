# 13281번: Look for the Winner! - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/13281)


<p>The citizens of TKB City are famous for their deep love in elections and vote counting. Today they hold an election for the next chairperson of the electoral commission. Now the voting has just been closed and the counting is going to start. The TKB citizens have strong desire to know the winner as early as possible during vote counting.</p>

<p>The election candidate receiving the most votes shall be the next chairperson. Suppose for instance that we have three candidates A, B, and C and ten votes. Suppose also that we have already counted six of the ten votes and the vote counts of A, B, and C are four, one, and one, respectively. At this moment, every candidate has a chance to receive four more votes and so everyone can still be the winner. However, if the next vote counted is cast for A, A is ensured to be the winner since A already has five votes and B or C can have at most four votes at the end. In this example, therefore, the TKB citizens can know the winner just when the seventh vote is counted.</p>

<p>Your mission is to write a program that receives every vote counted, one by one, identifies the winner, and determines when the winner gets ensured.</p>



## 입력


<p>The input consists of at most 1500 datasets, each consisting of two lines in the following format.</p>

<pre>n
c<sub>1</sub> c<sub>2</sub> … c<sub>n</sub></pre>

<p>n in the first line represents the number of votes, and is a positive integer no greater than 100. The second line represents the n votes, separated by a space. Each c<sub>i</sub> (1 ≤ i ≤ n) is a single uppercase letter, i.e. one of 'A' through 'Z'. This represents the election candidate for which the i-th vote was cast. Counting shall be done in the given order from c<sub>1</sub> to c<sub>n</sub>.</p>

<p>You should assume that at least two stand as candidates even when all the votes are cast for one candidate.</p>

<p>The end of the input is indicated by a line containing a zero.</p>



## 출력


<p>For each dataset, unless the election ends in a tie, output a single line containing an uppercase letter c and an integer d separated by a space: c should represent the election winner and d should represent after counting how many votes the winner is identified. Otherwise, that is, if the election ends in a tie, output a single line containing `TIE'.</p>




## 소스코드

[소스코드 보기](Look%20for%20the%20Winner!.py)