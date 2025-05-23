# 20338번: Jigsaw - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/20338)


<p>You have found an old jigsaw puzzle in the attic of your house, left behind by the previous occupants. Because you like puzzles, you decide to put this one together. But before you start, you want to know whether this puzzle was left behind for a reason. Maybe it is incomplete? Maybe the box contains pieces from multiple puzzles?&nbsp;</p>

<p>If it looks like a complete puzzle, you also need to know how big your work surface needs to be. Nothing worse than having to start a jigsaw over because you started on a small table.</p>

<p>The box does not tell you the dimensions $w \times h$ of the puzzle, but you can quickly count the three types of pieces in the box:</p>

<p>&nbsp;</p>

<ul>
<li>Corner pieces, which touch two of the edges of the puzzle.</li>
<li>Edge pieces, which touch one of the edges of the puzzle.</li>
<li>Centre pieces, which touch none of the edges of the puzzle.</li>
</ul>

<p>Do these pieces add up to a complete jigsaw puzzle? If so, what was the original size of the jigsaw puzzle?</p>



## 입력


<ul>
<li>One line containing three integers $c$, $e$, and $m$ ($0\leq c,e,m\leq10^9$), the number of corner pieces, edge pieces, and centre pieces respectively.</li>
</ul>



## 출력


<p>If there exist numbers $w$ and $h$ satisfying $w\geq h\geq 2$ such that the original size of the jigsaw puzzle could have been $w\times h$, then output a single line containing $w$ and $h$. Otherwise, output "<code>impossible</code>".</p>

<p>If there are multiple valid solutions, you may output any one of them.</p>



## 소스코드

[소스코드 보기](Jigsaw.cpp)