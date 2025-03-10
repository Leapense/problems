# 5993번: Invasion of the Milkweed - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/5993)


<p>Farmer John has always done his best to keep the pastures full of luscious, delicious healthy grass for the cows. He has lost the battle, though, as the evil milkweed has attained a foothold in the northwest part of his farm.</p>

<p>The pasture, as usual, is partitioned into a rectilinear grid of height Y (1 &lt;= Y &lt;= 100) and width X (1 &lt;= X &lt;= 100) with (1,1) being in the lower left corner (i.e., arranged as a normal X,Y coordinate grid). The milkweed has initially begun growing at square (Mx,My). Each week the milkweed propagates to all non-rocky squares that surround any square it already occupies, as many as eight more squares (both the rectilinear squares and the diagonals). After only one week in those squares, it is ready to move on to more squares.</p>

<p>Bessie wants to enjoy all the grass she can before the pastures are taken over by milkweed. She wonders how long it can last. If the milkweed is in square (Mx,My) at time zero, at what time does it complete its invasion of the pasture (which, for the given input data, will always happen)?</p>

<p>The pasture is described by a picture with '.'s for grass and '*'s for boulders, like this example with X=4 and Y=3:</p>

<pre>     ....
     ..*.
     .**.</pre>

<p>If the milkweed started in the lower left corner (row=1, column=1), then the map would progress like this:</p>

<pre>     ....  ....  MMM.  MMMM  MMMM  
     ..*.  MM*.  MM*.  MM*M  MM*M  
     M**.  M**.  M**.  M**.  M**M  
week  0     1     2     3     4</pre>

<p>The milkweed has taken over the entire field after 4 weeks.</p>



## 입력


<ul>
<li>Line 1: Four space-separated integers: X, Y, Mx, and My</li>
<li>Lines 2..Y+1: Line y+1 describes row (Y+2-y) of the field with X characters ('.' for grass and '*' for a boulder)</li>
</ul>

<p>&nbsp;</p>



## 출력


<ul>
<li>Line 1: A single integer that is the week number when the milkweed takes over the last remaining non-boulder square of the pasture.</li>
</ul>

<p>&nbsp;</p>



## 소스코드

[소스코드 보기](Main.java)