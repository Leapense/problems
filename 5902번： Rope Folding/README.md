# 5902번: Rope Folding - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/5902)


<p>Farmer John has a long rope of length L (1 &lt;= L &lt;= 10,000) that he uses for various tasks around his farm. The rope has N knots tied into it at various distinct locations (1 &lt;= N &lt;= 100), including one knot at each of its two endpoints.</p>

<p>FJ notices that there are certain locations at which he can fold the rope back on itself such that the knots on opposite strands all line up exactly with each-other:</p>

<p><img alt="" src="https://www.acmicpc.net/upload/images2/fig_knots.png" style="height:29px; width:246px"></p>

<p>Please help FJ count the number of folding points having this property. Folding exactly at a knot is allowed, except folding at one of the endpoints is not allowed, and extra knots on the longer side of a fold are not a problem (that is, knots only need to line up in the areas where there are two strands opposite each-other). FJ only considers making a single fold at a time; he fortunately never makes multiple folds.</p>



## 입력


<ul>
<li>Line 1: Two space-separated integers, N and L.</li>
<li>Lines 2..1+N: Each line contains an integer in the range 0...L specifying the location of a single knot. Two of these lines will always be 0 and L.</li>
</ul>



## 출력


<ul>
<li>Line 1: The number of valid folding positions.</li>
</ul>



## 소스코드

[소스코드 보기](Rope%20Folding.cpp)