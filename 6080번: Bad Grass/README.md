# 6080번: Bad Grass - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/6080)


<p>Bessie was munching on tender shoots of grass and, as cows do, contemplating the state of the universe. She noticed that she only enjoys the grass on the wide expanses of pasture whose elevation is at the base level of the farm. Grass from elevations just 1 meter higher is tougher and not so appetizing. The bad grass gets worse as the elevation increases.</p>

<p>Continuing to chew, she realized that this unappetizing food grows the sides of hills that form a set of 'islands' of bad grass among the sea of tender, verdant, delicious, abundant grass.</p>

<p>Bessie donned her lab coat and vowed to determine just how many islands of bad grass her pasture had. She created a map in which she divided the pasture into R (1 &lt; R &lt;= 1,000) rows and C (1 &lt; C &lt;= 1,000) columns of 1 meter x 1 meter squares. She measured the elevation above the base level for each square and rounded it to a non-negative integer. She noted hungrily that the tasty grass all had elevation 0.</p>

<p>She commenced counting the islands. If two squares are neighbors in any of the horizontal, vertical or diagonal directions then they are considered to be part of the same island.</p>

<p>How many islands of bad grass did she count for each of the supplied maps?</p>



## 입력


<ul>
<li>Line 1: Two space-separated integers: R and C</li>
<li>Lines 2..R+1: Line i+1 describes row i of the map with C space separated integers</li>
</ul>

<p>&nbsp;</p>



## 출력


<ul>
<li>Line 1: A single integer that specifies the number of islands.</li>
</ul>

<p>&nbsp;</p>



## 소스코드

[소스코드 보기](Main.java)