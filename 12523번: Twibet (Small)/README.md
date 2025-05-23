# 12523번: Twibet (Small) - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/12523)


<p>The holy country of Twibet has&nbsp;<strong>N</strong>&nbsp;monks. Each monk has a unique number, from 1 to&nbsp;<strong>N</strong>. They do not use names for religious reasons. The monks are constantly on the move, slowly walking around Twibet. Each monk follows exactly one other monk.</p>

<p>Most of the time, every monk is silent, but on day K, monk number K stops, turns around and whispers the 140 Words of Wisdom. The whisper is quiet, so only the monk's immediate followers can hear it. At that point, each of his followers stops, turns around and whispers the same words to each of his own followers. This chain continues -- each follower who has just heard the Words, but has not yet whispered the Words today, stops and whispers to his followers.</p>

<p>After all of the monks who could have heard the words have whispered them, they all turn back around and continue walking as usual... until the next day, when this all starts again, but this time starting with a different monk.</p>

<p>How many monks will whisper the 140 Words of Wisdom on day K, for each K between 1 and&nbsp;<strong>N</strong>?</p>



## 입력


<p>The first line of the input gives the number of test cases,&nbsp;<strong>T</strong>.&nbsp;&nbsp;<strong>T</strong>&nbsp;test cases follow. Each one starts with a line containing a single integer&nbsp;<strong>N</strong>. The next line contains&nbsp;<strong>N</strong>&nbsp;space-separated integers&nbsp;<strong>F<sub>1</sub></strong>,&nbsp;<strong>F<sub>2</sub></strong>, ...,&nbsp;<strong>F<sub>N</sub></strong>. Monk 1 follows monk&nbsp;<strong>F<sub>1</sub></strong>. Monk 2 follows monk&nbsp;<strong>F<sub>2</sub></strong>, etc.</p>

<h3>Limits</h3>

<ul>
<li>1 ≤&nbsp;<strong>T</strong>&nbsp;≤ 100.</li>
<li>No monk will immediately follow himself (<strong>F<sub>k</sub></strong>&nbsp;is never equal to&nbsp;<strong>k</strong>).</li>
<li>2 ≤&nbsp;<strong>N</strong>&nbsp;≤ 10.</li>
</ul>



## 출력


<p>For each test case, output one line containing "Case #x:", where x is the case number (starting from 1). Then output&nbsp;<strong>N</strong>&nbsp;lines, one for each day. The first line should contain the number of monks who will whisper the Words on day 1. The next line -- on day 2, etc.</p>



## 소스코드

[소스코드 보기](Twibet%20(Small).py)