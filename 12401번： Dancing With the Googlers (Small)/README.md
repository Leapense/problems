# 12401번: Dancing With the Googlers (Small) - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/12401)


<p>You're watching a show where Googlers (employees of Google) dance, and then each dancer is given a&nbsp;<em>triplet of scores</em>&nbsp;by three judges. Each triplet of scores consists of three integer scores from 0 to 10 inclusive. The judges have very similar standards, so it's&nbsp;<em>surprising</em>&nbsp;if a triplet of scores contains two scores that are 2 apart. No triplet of scores contains scores that are more than 2 apart.</p>

<p>For example: (8, 8, 8) and (7, 8, 7) are not surprising. (6, 7, 8) and (6, 8, 8) are surprising. (7, 6, 9) will never happen.</p>

<p>The&nbsp;<em>total points</em>&nbsp;for a Googler is the sum of the three scores in that Googler's triplet of scores. The&nbsp;<em>best result</em>&nbsp;for a Googler is the maximum of the three scores in that Googler's triplet of scores. Given the total points for each Googler, as well as the number of surprising triplets of scores, what is the maximum number of Googlers that could have had a best result of at least&nbsp;<strong>p</strong>?</p>

<p>For example, suppose there were 6 Googlers, and they had the following total points:&nbsp;<code>29, 20, 8, 18, 18, 21</code>. You remember that there were 2 surprising triplets of scores, and you want to know how many Googlers could have gotten a best result of 8 or better.</p>

<p>With those total points, and knowing that two of the triplets were surprising, the triplets of scores could have been:</p>

<pre>10 9 10
6 6 8 (*)
2 3 3
6 6 6
6 6 6
6 7 8 (*)
</pre>

<p>The cases marked with a (*) are the surprising cases. This gives us 3 Googlers who got at least one score of 8 or better. There's no series of triplets of scores that would give us a higher number than 3, so the answer is 3.</p>



## 입력


<p>The first line of the input gives the number of test cases,&nbsp;<strong>T</strong>.&nbsp;&nbsp;<strong>T</strong>&nbsp;test cases follow. Each test case consists of a single line containing integers separated by single spaces. The first integer will be&nbsp;<strong>N</strong>, the number of Googlers, and the second integer will be&nbsp;<strong>S</strong>, the number of surprising triplets of scores. The third integer will be&nbsp;<strong>p</strong>, as described above. Next will be&nbsp;<strong>N</strong>integers&nbsp;<strong>t<sub>i</sub></strong>: the total points of the Googlers.</p>

<h3>Limits</h3>

<ul>
<li>1 ≤&nbsp;<strong>T</strong>&nbsp;≤ 100.</li>
<li>0 ≤&nbsp;<strong>S</strong>&nbsp;≤ N.</li>
<li>0 ≤&nbsp;<strong>p</strong>&nbsp;≤ 10.</li>
<li>0 ≤&nbsp;<strong>t<sub>i</sub></strong>&nbsp;≤ 30.</li>
<li>At least&nbsp;<strong>S</strong>&nbsp;of the&nbsp;<strong>t<sub>i</sub></strong>&nbsp;values will be between 2 and 28, inclusive.</li>
<li>1 ≤&nbsp;<strong>N</strong>&nbsp;≤ 3.</li>
</ul>



## 출력


<p>For each test case, output one line containing "Case #x: y", where x is the case number (starting from 1) and y is the maximum number of Googlers who could have had a best result of greater than or equal to&nbsp;<strong>p</strong>.</p>



## 소스코드

[소스코드 보기](Dancing%20With%20the%20Googlers%20(Small).cpp)