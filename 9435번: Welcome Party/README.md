# 9435번: Welcome Party - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/9435)


<p>For many summers, the Agile Crystal Mining company ran an internship program for students. They greatly valued interns' ability to self-organize into teams. So as a get-to-know-you activity during orientation, they asked the interns to form teams such that all members of a given team either have first names beginning with the same letter, or last names beginning with the same letter. To make it interesting, they asked the interns to do this while forming as few teams as possible.</p>

<p>As an example, one year there were six interns: Stephen Cook, Vinton Cerf, Edmund Clarke, Judea Pearl, Shafi Goldwasser, and Silvio Micali. They were able to self-organize into three teams:</p>

<ul>
<li>Stephen Cook, Vinton Cerf, and Edmund Clarke (whose last names all begin with C)</li>
<li>Shafi Goldwasser and Silvio Micali (whose first names begin with S)</li>
<li>Judea Pearl (not an interesting group, but everyone's first name in this group starts with J)</li>
</ul>

<p>As a historical note, the company was eventually shut down due to a rather strange (and illegal) hiring practice---they refused to hire any interns whose last names began with the letter S, T, U, V, W, X, Y, or Z. (First names were not subject to such a whim, which was fortunate for our friend Vinton Cerf.)</p>



## 입력


<p>Each year's group of interns is considered as a separate trial. A trial begins with a line containing a single integer <em>N</em>, such that 1 ≤ <em>N</em> ≤ 300, designating the number of interns that year. Following that are <em>N</em> lines---one for each intern---with a line having a first and last name separated by one space. Names will not have any punctuation, and both the first name and last name will begin with an uppercase letter. In the case of last names, that letter will have an additional constraint that it be in the range from 'A' to 'R' inclusive. The end of the input is designated by a line containing the value&nbsp;0. There will be at most 20 trials.</p>



## 출력


<p>For each trial, output a single integer, <em>k</em>, designating the minimum number of teams that were necessary.&nbsp;</p>



## 소스코드

[소스코드 보기](Welcome%20Party.cpp)