# 12715번: Increasing Speed Limits (Small) - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/12715)


<p>You were driving along a highway when you got caught by the road police for speeding. It turns out that they've been following you, and they were amazed by the fact that you were accelerating the whole time without using the brakes! And now you desperately need an excuse to explain that.</p>

<p>You've decided that it would be reasonable to say "all the speed limit signs I saw were in increasing order, that's why I've been accelerating". The police officer laughs in reply, and tells you all the signs that are placed along the segment of highway you drove, and says that's unlikely that you were so lucky just to see some part of these signs that were in increasing order.</p>

<p>Now you need to estimate that likelihood, or, in other words, find out how many different subsequences of the given sequence are strictly increasing. The empty subsequence does not count since that would imply you didn't look at any speed limits signs at all!</p>

<p>For example, (1, 2, 5) is an increasing subsequence of (1, 4, 2, 3, 5, 5), and we count it twice because there are two ways to select (1, 2, 5) from the list.</p>



## 입력


<p>The first line of input gives the number of cases,&nbsp;<strong>N</strong>.&nbsp;<strong>N</strong>&nbsp;test cases follow. The first line of each case contains&nbsp;<strong>n</strong>,&nbsp;<strong>m</strong>,&nbsp;<strong>X</strong>,&nbsp;<strong>Y</strong>&nbsp;and&nbsp;<strong>Z</strong>&nbsp;each separated by a space.&nbsp;&nbsp;<strong>n</strong>&nbsp;will be the length of the sequence of speed limits.&nbsp;<strong>m</strong>&nbsp;will be the length of the generating array A. The next&nbsp;<strong>m</strong>lines will contain the&nbsp;<strong>m</strong>&nbsp;elements of A, one integer per line (from A[0] to A[<strong>m</strong>-1]).</p>

<p>Using A,&nbsp;<strong>X</strong>,&nbsp;<strong>Y</strong>&nbsp;and&nbsp;<strong>Z</strong>, the following pseudocode will&nbsp;<em>print</em>&nbsp;the speed limit sequence in order. mod indicates the remainder operation.</p>

<pre><code>for i = 0 to n-1
  <em>print</em> A[i mod <strong>m</strong>]
  A[i mod <strong>m</strong>] = (<strong>X</strong> * A[i mod <strong>m</strong>] + <strong>Y</strong> * (i + 1)) mod <strong>Z</strong>
</code></pre>

<p>&nbsp;</p>

<p>Note: The way that the input is generated has nothing to do with the intended solution and exists solely to keep the size of the input files low.</p>

<p>Limits</p>

<ul>
<li>1 ≤&nbsp;<strong>N</strong>&nbsp;≤ 20</li>
<li>1 ≤&nbsp;<strong>m</strong>&nbsp;≤ 100</li>
<li>0 ≤&nbsp;<strong>X</strong>&nbsp;≤ 10<sup>9</sup></li>
<li>0 ≤&nbsp;<strong>Y</strong>&nbsp;≤ 10<sup>9</sup></li>
<li>1 ≤&nbsp;<strong>Z</strong>&nbsp;≤ 10<sup>9</sup></li>
<li>0 ≤&nbsp;<strong>A[i]</strong>&nbsp;&lt;&nbsp;<strong>Z</strong></li>
<li>1 ≤&nbsp;<strong>m</strong>&nbsp;≤&nbsp;<strong>n</strong>&nbsp;≤ 1000</li>
</ul>



## 출력


<p>For each test case you should output one line containing "Case #<strong>T</strong>:&nbsp;<strong>S</strong>" (quotes for clarity) where&nbsp;<strong>T</strong>&nbsp;is the number of the test case and&nbsp;<strong>S</strong>&nbsp;is the number of non-empty increasing subsequences mod 1<sub>&nbsp;</sub>000<sub>&nbsp;</sub>000<sub>&nbsp;</sub>007.</p>



## 소스코드

[소스코드 보기](Increasing%20Speed%20Limits%20(Small).cpp)