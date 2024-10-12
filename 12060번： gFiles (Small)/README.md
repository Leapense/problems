# 12060번: gFiles (Small) - <img src="https://static.solved.ac/tier_small/6.svg" style="height:20px" /> Silver V

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/12060)


<p>Alien tech company G has a very old file transfer tool that is still in use today. While the tool is running, it reassures users by giving status updates on both the percentage of files transferred so far and the number of files transferred so far. The status updates during the process might look like this:</p>

<pre> 20% |==&gt;-------|     1 files transferred
100% |==========|     5 files transferred
</pre>

<p>But the percentage isn't precise; it is simply truncated before the decimal point (i.e. floored to the next lowest or equal 1%). That is, both 1.2% and 1.7% would be displayed as 1%.</p>

<p>Some users may want to know the exact total number of files, so you want to modify the tool so that the status updates look like this:</p>

<pre> 20% |==&gt;-------|     1 out of <strong>5</strong> files transferred
100% |==========|     5 out of <strong>5</strong> files transferred
</pre>

<p>But you've realized that it may or may not be possible to know the number of files. Given the status updates that the tool displays, either figure out how many files there are, or determine that it can't be done (i.e., there are multiple possible values for the number of files). The status updates are not guaranteed to occur at regular intervals and are not guaranteed to occur whenever a file is transferred.</p>



## 입력


<p>The first line contains&nbsp;<strong>T</strong>, the number of test cases.&nbsp;<strong>T</strong>&nbsp;test cases follow. Each test case consists of one line with an integer&nbsp;<strong>N</strong>, the number of status updates output by the tool, followed by&nbsp;<strong>N</strong>&nbsp;lines with the format P<sub>i</sub>&nbsp;K<sub>i</sub>, where P<sub>i</sub>&nbsp;and K<sub>i</sub>&nbsp;are integers representing the percentage and number of files transferred at some point in the process. The updates are given listed in chronological order -- that is, both the P<sub>i</sub>&nbsp;values and the K<sub>i</sub>&nbsp;values are nondecreasing throughout a test case.</p>

<h3>Limits</h3>

<ul>
<li>1 ≤&nbsp;<strong>T</strong>&nbsp;≤ 50.</li>
<li>1 ≤&nbsp;<strong>N</strong>&nbsp;≤ 100.</li>
<li>0 ≤ P<sub>i</sub>&nbsp;≤ 100</li>
<li>0 ≤ K<sub>i</sub>&nbsp;≤ 2000</li>
<li>The answer is guaranteed not to exceed 2000.</li>
</ul>



## 출력


<p>For each case, output a line starts with "Case #x: y", where x is the number of the case (starting from 1), and y is either the total number of files, or&nbsp;<code>-1</code>&nbsp;if that number is ambiguous.</p>



## 소스코드

[소스코드 보기](gFiles%20(Small).cpp)