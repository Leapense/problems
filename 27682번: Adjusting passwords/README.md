# 27682번: Adjusting passwords - <img src="https://static.solved.ac/tier_small/5.svg" style="height:20px" /> Bronze I

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/27682)


<p>Another IPSC has just started and you are late! You rush to your PC only to discover that you locked the screen and now you have to enter your password quickly to unlock it.</p>

<p>You are presented with a password prompt. It only supports the following keys:</p>

<table class="table table-bordered">
<thead>
<tr>
<th align="left">Key</th>
<th align="left">Action</th>
</tr>
</thead>
<tbody>
<tr>
<td align="left"><code>a</code> to <code>z</code></td>
<td align="left">enters the character.</td>
</tr>
<tr>
<td align="left">enter</td>
<td align="left">submits the password.</td>
</tr>
<tr>
<td align="left">backspace</td>
<td align="left">erases the last entered character, if any.</td>
</tr>
</tbody>
</table>

<p>If you submit an invalid password, you will see an error message and a new, empty prompt will open.</p>

<p>Your password is <em>P</em>. In all the rush, you just typed the string <em>Q</em> into the prompt. It is possible that <em>Q</em> is not <em>P</em>: there may be a typo or two, or it can even be a completely different string.</p>

<p>Given <em>P</em> and <em>Q</em>, log in using as few additional keystrokes as possible.</p>



## 입력


<p>The first line of the input file contains an integer <em>t</em> specifying the number of test cases. (<em>t</em> ≤ 1000) Each test case is preceded by a blank line.</p>

<p>Each test case consists of two lines. The first line contains the correct password <em>P</em> and the second line contains the already typed string <em>Q</em>. Both are non-empty and have at most 50 characters.</p>



## 출력


<p>For each test case, output a line containing the list of keystrokes you want to press. Pressing enter is represented by <code>*</code> and pressing backspace is represented by <code>&lt;</code>.</p>

<p>If there are multiple optimal solutions, you may output any of them.</p>



## 소스코드

[소스코드 보기](Adjusting%20passwords.cpp)