# 15367번: Spirale - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/15367)


<p>Little Stjepan often likes to go out with his friends and have fun in a popular nightclub in Zagreb. However, Stjepan sometimes drinks too much soda and gets light headed from all the sugar. Last night was an example of this, which is why Stjepan had the same image in his mind the whole time. It was a scribble of number spirals of some sort. Since he can’t quite remember what the image looked like, but can describe it, he is asking you to reconstruct it for him.</p>

<p>Stjepan recalls that the image was of the shape of a table consisting of numbers written in N rows and M columns. Also, he recalls that there were K spirals in that table. For each spiral, the starting position is known, as well as the direction it’s moving in, which can be clockwise and counter-clockwise. An example is shown in the images below. The spirals created Stjepan’s image in exactly 10<sup>100</sup> steps in the following way:</p>

<ol>
<li>Initially, the table is empty, and each spiral is in its own starting position.</li>
<li>In each following step, each spiral moves to its next position. It is possible that, at times, the spirals leave the boundaries of the table, but also to return within it.</li>
<li>After exactly 10<sup>100</sup> steps, for each field in the table, the final value is the value of the earliest step in which one of the spirals touched that field.</li>
</ol>

<table class="table" style="width:100%">
<tbody>
<tr>
<td style="text-align:center; width:50%"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/15367/1.png" style="height:108px; width:138px"></td>
<td style="text-align:center; width:50%"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/15367/2.png" style="height:108px; width:138px"></td>
</tr>
<tr>
<td style="text-align:center; width:50%">Image 1: a spiral moving counter-clockwise</td>
<td style="text-align:center; width:50%">Image 2: a spiral moving clockwise</td>
</tr>
</tbody>
</table>



## 입력


<p>The first line of input contains positive integers N, M (1 ≤ N, M ≤ 50) and K (1 ≤ K ≤ N×M). Each of the following K lines contains three positive integers X<sub>i</sub>, Y<sub>i</sub> and T<sub>i</sub> (1 ≤ X ≤ N, 1 ≤ Y ≤ M, 0 ≤ T ≤ 1), the starting position of the i th spiral and its direction (0 - clockwise, 1 - counter-clockwise). No two spirals will begin in the same field.</p>



## 출력


<p>You must output N lines with M numbers, representing the table after each spiral makes 10<sup>100</sup> steps.</p>



## 소스코드

[소스코드 보기](Spirale.cpp)