# 14363번: Senate Evacuation (Small) - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/14363)


<p>A small fire started in the senate room, and it needs to be evacuated!</p>

<p>There are some senators in the senate room, each of whom belongs to of one of&nbsp;N&nbsp;political parties. Those parties are named after the first&nbsp;N&nbsp;(uppercase) letters of the English alphabet.</p>

<p>The emergency door is wide enough for up to two senators, so in each step of the evacuation, you may choose to remove either one or two senators from the room.</p>

<p>The senate rules indicate the senators in the room may vote on any bill at any time, even in the middle of an evacuation! So, the senators must be evacuated in a way that ensures that no party ever has an absolute majority. That is, it can never be the case after any evacuation step that more than half of the senators in the senate room belong to the same party.</p>

<p>Can you construct an evacuation plan? The senate is counting on you!</p>



## 입력


<p>The first line of the input gives the number of test cases,&nbsp;T.&nbsp;T&nbsp;test cases follow. Each test case consists of two lines. The first line contains a single integer&nbsp;N, the number of parties. The second line contains&nbsp;N&nbsp;integers,&nbsp;P<sub>1</sub>,&nbsp;P<sub>2</sub>, ...,&nbsp;P<sub>N</sub>, where&nbsp;P<sub>i</sub>&nbsp;represents the number of senators of the party named after the i-th letter of the alphabet.</p>

<h3>Limits</h3>

<ul>
<li>1 ≤&nbsp;T&nbsp;≤ 50.</li>
<li>No party will have an absolute majority before the start of the evacuation.</li>
<li>1 ≤&nbsp;P<sub>i</sub>&nbsp;≤ 1000, for all i.</li>
<li>2 ≤&nbsp;N&nbsp;≤ 3.</li>
<li>sum of all&nbsp;P<sub>i</sub>&nbsp;≤ 9.</li>
</ul>



## 출력


<p>For each test case, output one line containing&nbsp;<code>Case #x: y</code>, where&nbsp;<code>x</code>&nbsp;is the test case number (starting from 1) and&nbsp;<code>y</code>&nbsp;is the evacuation plan. The plan must be a space-separated list of instructions, in the order in which they are to be carried out, where each instruction is either one or two characters, representing the parties of the senators to evacuate in each step.</p>

<p>It is guaranteed that at least one valid evacuation plan will exist. If multiple evacuation plans are valid, you may output any of them.</p>



## 소스코드

[소스코드 보기](Senate%20Evacuation%20(Small).py)