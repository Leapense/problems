# 14809번: Ample Syrup (Small) - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/14809)


<p>The kitchen at the Infinite House of Pancakes has just received an order for a stack of&nbsp;<strong>K</strong>pancakes! The chef currently has&nbsp;<strong>N</strong>&nbsp;pancakes available, where&nbsp;<strong>N</strong>&nbsp;≥&nbsp;<strong>K</strong>. Each pancake is a cylinder, and different pancakes may have different radii and heights.</p>

<p>As the sous-chef, you must choose&nbsp;<strong>K</strong>&nbsp;out of the&nbsp;<strong>N</strong>&nbsp;available pancakes, discard the others, and arrange those&nbsp;<strong>K</strong>&nbsp;pancakes in a stack on a plate as follows. First, take the pancake that has the largest radius, and lay it on the plate on one of its circular faces. (If multiple pancakes have the same radius, you can use any of them.) Then, take the remaining pancake with the next largest radius and lay it on top of that pancake, and so on, until all&nbsp;<strong>K</strong>&nbsp;pancakes are in the stack and the centers of the circular faces are aligned in a line perpendicular to the plate, as illustrated by this example:</p>

<p style="text-align:center"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/14809/1.png" style="height:136px; width:320px"></p>

<p>You know that there is only one thing your diners love as much as they love pancakes: syrup! It is best to maximize the total amount of exposed pancake surface area in the stack, since more exposed pancake surface area means more places to pour on delicious syrup. Any part of a pancake that is not touching part of another pancake or the plate is considered to be exposed.</p>

<p>If you choose the&nbsp;<strong>K</strong>&nbsp;pancakes optimally, what is the largest total exposed pancake surface area you can achieve?</p>



## 입력


<p>The first line of the input gives the number of test cases,&nbsp;<strong>T</strong>.&nbsp;<strong>T</strong>&nbsp;test cases follow. Each begins with one line with two integers&nbsp;<strong>N</strong>&nbsp;and&nbsp;<strong>K</strong>: the total number of available pancakes, and the size of the stack that the diner has ordered. Then,&nbsp;<strong>N</strong>&nbsp;more lines follow. Each contains two integers&nbsp;<strong>R<sub>i</sub></strong>&nbsp;and&nbsp;<strong>H<sub>i</sub></strong>: the radius and height of the i-th pancake, in millimeters.</p>

<p>Limits</p>

<ul>
<li>1 ≤&nbsp;<strong>T</strong>&nbsp;≤ 100.</li>
<li>1 ≤&nbsp;<strong>K</strong>&nbsp;≤&nbsp;<strong>N</strong>.</li>
<li>1 ≤&nbsp;<strong>R<sub>i</sub></strong>&nbsp;≤ 10<sup>6</sup>, for all i.</li>
<li>1 ≤&nbsp;<strong>H<sub>i</sub></strong>&nbsp;≤ 10<sup>6</sup>, for all i.</li>
<li>1 ≤&nbsp;<strong>N</strong>&nbsp;≤ 10.</li>
</ul>



## 출력


<p>For each test case, output one line containing&nbsp;<code>Case #x: y</code>, where&nbsp;<code>x</code>&nbsp;is the test case number (starting from 1) and&nbsp;<code>y</code>&nbsp;is the maximum possible total exposed pancake surface area, in millimeters squared.&nbsp;<code>y</code>&nbsp;will be considered correct if it is within an absolute or relative error of 10<sup>-6</sup>&nbsp;of the correct answer.</p>



## 소스코드

[소스코드 보기](Ample%20Syrup%20(Small).cpp)