# 10575번: Top 25 - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/10575)


<p style="text-align:center"><img alt="" src="https://www.acmicpc.net/upload/images2/top25.png" style="height:148px; width:185px"></p>

<p>In college football, many different sources create a list of the Top 25 teams in the country. Since it’s subjective, these lists often differ, but they’re usually very similar. Your job is to compare two of these lists, and determine where they are similar. In particular, you are to partition them into sets, where each set represents the same consecutive range of positions in both lists, and has the same teams, and is as small as possible. If the lists agree completely, you’ll have 25 lists (or n, where n is an input). For these lists:</p>

<table class="table" style="width:30%">
<thead>
<tr>
<th>K&amp;R Poll</th>
<th>Lovelace Ranking</th>
</tr>
</thead>
<tbody>
<tr>
<td>A</td>
<td>A</td>
</tr>
<tr>
<td>B</td>
<td>C</td>
</tr>
<tr>
<td>C</td>
<td>D</td>
</tr>
<tr>
<td>D</td>
<td>B</td>
</tr>
<tr>
<td>E</td>
<td>E</td>
</tr>
</tbody>
</table>

<p>You’ll have 3 sets:</p>

<pre>  A
B C D
  E
</pre>



## 입력


<p>The input will start with a single integer on one line giving the number of test cases. There will be at least one but not more than 100 test cases. Each test case will begin with an integer N, 1 ≤ N ≤ 1,000,000, indicating the number of teams ranked. The next N lines will hold the first list, in order. The team names will appear one per line, consist of at most 8 capital letters only. After this will be N lines, in the same format, indicating the second list. Both lists will contain the same team names, and all N team names will be unique.</p>



## 출력


<p>For each test case, simply output the size of each set, in order, on one line, with the numbers separated by a single space. Do not output any extra spaces, and do not output blank lines between numbers.</p>



## 소스코드

[소스코드 보기](Top%2025.cpp)