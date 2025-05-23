# 12519번: Music Collection (Small1) - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/12519)


<p>Audio Phil has a huge music collection, and he is very particular about the songs he listens to. Each song has a name that is a string of characters. His music player has a search feature that lets Phil type a substring into the search box, and the player then lists all songs whose names contain the substring. If there is exactly one song that matches the search, then Phil can hit the Enter key to play that song.</p>

<p>Phil hates using the mouse, and he doesn't like typing too much, so he insists on always typing the shortest possible substring that will match exactly the one song that he wants to play at this moment. Could you help him find his optimal search query?</p>



## 입력


<p>The first line of the input gives the number of test cases,&nbsp;<strong>T</strong>.&nbsp;&nbsp;<strong>T</strong>&nbsp;test cases follow. Each one starts with a line containing a single number&nbsp;<strong>N</strong>. The next&nbsp;<strong>N</strong>&nbsp;lines each contain one song name -- these are all of the songs in Phil's collection.</p>

<p>Each song name will consist of only letters, spaces and the hyphen character (-). All songs in Phil's collection will be unique and at most 100 characters in length. Song names are case insensitive, so "dZihan" is the same is "Dzihan". The search algorithm is also case insensitive.</p>

<h3>Limits</h3>

<ul>
<li>1 ≤&nbsp;<strong>T</strong>&nbsp;≤ 100.</li>
<li>1 ≤&nbsp;<strong>N</strong>&nbsp;≤ 10.</li>
</ul>



## 출력


<p>For each test case, output one line containing "Case #<strong>x</strong>:", where&nbsp;<strong>x</strong>&nbsp;is the case number (starting from 1). After that, print&nbsp;<strong>N</strong>&nbsp;lines, one for each song in Phil's collection, in the order that the songs were given in the input. For each song, print the shortest string of characters that will uniquely find that song. If there are several correct answers, print the lexicographically smallest one. Put double quotes around each string. If there is no correct answer, print ":(" without the double quotes.</p>

<p>Note that upper case letters come lexicographically before lower case letters, hyphen comes before all letters, and space comes before hyphen.</p>



## 소스코드

[소스코드 보기](Music%20Collection%20(Small1).py)