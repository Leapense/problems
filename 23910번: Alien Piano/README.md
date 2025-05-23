# 23910번: Alien Piano - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/23910)


<p>An alien has just landed on Earth, and really likes our music. Lucky for us.</p>

<p>The alien would like to bring home its favorite human songs, but it only has a very strange instrument to do it with: a piano with just 4 keys of different pitches.</p>

<p>The alien converts a song by writing it down as a series of keys on the alien piano. Obviously, this piano will not be able to convert our songs completely, as our songs tend to have many more than 4 pitches.</p>

<p>The alien will settle for converting our songs with the following rules instead:</p>

<ul>
<li>The first note in our song can be converted to any key on the alien piano.</li>
<li>For every note after,
<ul>
<li>if its pitch is higher than the previous note, it should be converted into a higher-pitched key than the previous note's conversion;</li>
<li>if lower, it should be converted into a lower-pitched key than the previous note's conversion;</li>
<li>if exactly identical, it should be converted into the same key as the previous note's conversion.</li>
</ul>
</li>
</ul>

<p>Note: two notes with the same pitch do not need to be converted into the same key if they are not adjacent.</p>

<p>What the alien wants to know is: how often will it have to break its rules when converting a particular song?</p>

<p>To elaborate, let us describe one of our songs as having&nbsp;<b>K&nbsp;</b>notes. The first note we describe as "note 1", the second note "note 2", and the last note "note&nbsp;<b>K</b>."</p>

<p>So note 2 comes immediately after note 1.</p>

<p>Now if note 2 is lower than note 1 in our version of the song, yet converted to an equally-pitched or lower-pitched key (relative to note 2's conversion) in the alien's version of the song, then we consider that a single rule break.</p>

<p>For each test case, return the minimum amount of times the alien must necessarily break one of its rules in converting that song.</p>



## 입력


<p>The first line of the input gives the number of test cases,&nbsp;<b>T</b>.&nbsp;<b>T</b>&nbsp;test cases follow.</p>

<p>Each test case consists of two lines.</p>

<p>The first line consists of a single integer,&nbsp;<b>K</b>.</p>

<p>The second line consists of&nbsp;<b>K</b>&nbsp;space-separated integers,&nbsp;<b>A<sub>1</sub></b>,&nbsp;<b>A<sub>2</sub></b>&nbsp;...&nbsp;<b>A<sub>K</sub></b>, where&nbsp;<b>A<sub>i</sub></b>&nbsp;refers to the pitch of the i-th note for this test case.</p>



## 출력


<p>For each test case, output one line containing&nbsp;<code>Case #x: y</code>, where&nbsp;<code>x</code>&nbsp;is the test case number (starting from 1) and&nbsp;<code>y</code>&nbsp;is the minimum number of times that particular test case will require the alien to break its own rules during the conversion process.</p>



## 소스코드

[소스코드 보기](Alien%20Piano.cpp)