# 30163번: Plus from Picture - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/30163)


<p>You have a given picture with size $w \times h$. Determine if the given picture has a single "<code>+</code>" shape or not. A "<code>+</code>" shape is described below:</p>

<ul>
<li>A "<code>+</code>" shape has one center nonempty cell.</li>
<li>There should be some (at least one) consecutive non-empty cells in each direction (left, right, up, down) from the center. In other words, there should be a ray in each direction. </li>
<li>All other cells are empty.</li>
</ul>

<p>Find out if the given picture has single "<code>+</code>" shape.</p>



## 입력


<p>The first line contains two integers $h$ and $w$ ($1 \le h$, $w \le 500$) --- the height and width of the picture.</p>

<p>The $i$-th of the next $h$ lines contains string $s_{i}$ of length $w$ consisting "<code>.</code>" and "<code>*</code>" where "<code>.</code>" denotes the empty space and "<code>*</code>" denotes the non-empty space.</p>



## 출력


<p>If the given picture satisfies all conditions, print "<code>YES</code>". Otherwise, print "<code>NO</code>".</p>



## 소스코드

[소스코드 보기](Main.java)