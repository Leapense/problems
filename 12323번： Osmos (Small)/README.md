# 12323번: Osmos (Small) - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/12323)


<p>Armin is playing Osmos, a physics-based puzzle game developed by Hemisphere Games. In this game, he plays a "mote", moving around and absorbing smaller motes.</p>

<p>A "mote" in English is a small particle. In this game, it's a thing that absorbs (or is absorbed by) other things! The game in this problem has a similar idea to Osmos, but does not assume you have played the game.</p>

<p>When Armin's mote absorbs a smaller mote, his mote becomes bigger by the smaller mote's size. Now that it's bigger, it might be able to absorb even more motes. For example: suppose Armin's mote has size 10, and there are other motes of sizes 9, 13 and 19. At the start, Armin's mote can only absorb the mote of size 9. When it absorbs that, it will have size 19. Then it can only absorb the mote of size 13. When it absorbs that, it'll have size 32. Now Armin's mote can absorb the last mote.</p>

<p>Note that Armin's mote can absorb another mote if and only if the other mote is <em>smaller</em>. If the other mote is the same size as his, his mote can't absorb it.</p>

<p>You are responsible for the program that creates motes for Armin to absorb. The program has already created some motes, of various sizes, and has created Armin's mote. Unfortunately, given his mote's size and the list of other motes, it's possible that there's no way for Armin's mote to absorb them all.</p>

<p>You want to fix that. There are two kinds of operations you can perform, in any order, any number of times: you can add a mote of any positive integer size to the game, or you can remove any one of the existing motes. What is the minimum number of times you can perform those operations in order to make it possible for Armin's mote to absorb every other mote?</p>

<p>For example, suppose Armin's mote is of size 10 and the other motes are of sizes [9, 20, 25, 100]. This game isn't currently solvable, but by adding a mote of size 3 and removing the mote of size 100, you can make it solvable in only 2 operations. The answer here is 2.</p>



## 입력


<p>The first line of the input gives the number of test cases, <strong>T</strong>. <strong>T</strong> test cases follow. The first line of each test case gives the size of Armin's mote, <strong>A</strong>, and the number of other motes, <strong>N</strong>. The second line contains the <strong>N</strong> sizes of the other motes. All the mote sizes given will be integers.</p>

<p>Limits</p>

<ul>
<li>1 ≤ <strong>T</strong> ≤ 100.</li>
<li>1 ≤ <strong>A</strong> ≤ 100.</li>
<li>1 ≤ all mote sizes ≤ 100.</li>
<li>1 ≤ <strong>N</strong> ≤ 10.</li>
</ul>



## 출력


<p>For each test case, output one line containing "Case #x: y", where x is the case number (starting from 1) and y is the minimum number of operations needed to make the game solvable.</p>



## 소스코드

[소스코드 보기](Osmos%20(Small).cpp)