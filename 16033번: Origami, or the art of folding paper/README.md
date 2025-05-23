# 16033번: Origami, or the art of folding paper - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/16033)


<p>Master Grus is a famous <i>origami</i> (paper folding) artist, who is enthusiastic about exploring the possibility of origami art. For future creation, he is now planning fundamental experiments to establish the general theory of origami.</p>

<p>One rectangular piece of paper is used in each of his experiments. He folds it horizontally and/or vertically several times and then punches through holes in the folded paper.</p>

<p>The following figure illustrates the folding process of a simple experiment, which corresponds to the third dataset of the Sample Input below. Folding the 10 × 8 rectangular piece of paper shown at top left three times results in the 6 × 6 square shape shown at bottom left. In the figure, dashed lines indicate the locations to fold the paper and round arrows indicate the directions of folding. Grid lines are shown as solid lines to tell the sizes of rectangular shapes and the exact locations of folding. Color densities represent the numbers of overlapping layers. Punching through holes at A and B in the folded paper makes nine holes in the paper, eight at A and another at B.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/94d3d9f6-c5d0-4dce-a805-68083b2705cc/-/preview/" style="width: 600px; height: 440px;"></p>

<p>Your mission in this problem is to write a computer program to count the number of holes in the paper, given the information on a rectangular piece of paper and folding and punching instructions.</p>



## 입력


<p>The input consists of at most 1000 datasets, each in the following format.</p>

<pre><i>n</i> <i>m</i> <i>t</i> <i>p</i>
<i>d</i><sub>1</sub> <i>c</i><sub>1</sub>
...
<i>d<sub>t</sub></i> <i>c<sub>t</sub></i>
<i>x</i><sub>1</sub> <i>y</i><sub>1</sub>
...
<i>x<sub>p</sub></i> <i>y<sub>p</sub></i></pre>

<p><i>n</i> and <i>m</i> are the width and the height, respectively, of a rectangular piece of paper. They are positive integers at most 32. <i>t</i> and <i>p</i> are the numbers of folding and punching instructions, respectively. They are positive integers at most 20. The pair of <i>d<sub>i</sub></i> and <i>c<sub>i</sub></i> gives the <i>i</i>-th folding instruction as follows:</p>

<ul>
<li><i>d<sub>i</sub></i> is either 1 or 2.</li>
<li><i>c<sub>i</sub></i> is a positive integer.</li>
<li>If <i>d<sub>i</sub></i> is 1, the left-hand side of the vertical folding line that passes at <i>c<sub>i</sub></i> right to the left boundary is folded onto the right-hand side.</li>
<li>If <i>d<sub>i</sub></i> is 2, the lower side of the horizontal folding line that passes at <i>c<sub>i</sub></i> above the lower boundary is folded onto the upper side.</li>
</ul>

<p>After performing the first <i>i</i>−1 folding instructions, if <i>d<sub>i</sub></i> is 1, the width of the shape is greater than <i>c<sub>i</sub></i>. Otherwise the height is greater than <i>c<sub>i</sub></i>. (<i>x<sub>i</sub></i> + 1/2, <i>y<sub>i</sub></i> + 1/2) gives the coordinates of the point where the <i>i</i>-th punching instruction is performed. The origin (0, 0) is at the bottom left of the finally obtained shape. <i>x<sub>i</sub></i> and <i>y<sub>i</sub></i> are both non-negative integers and they are less than the width and the height, respectively, of the shape. You can assume that no two punching instructions punch holes at the same location.</p>

<p>The end of the input is indicated by a line containing four zeros.</p>



## 출력


<p>For each dataset, output <i>p</i> lines, the <i>i</i>-th of which contains the number of holes punched in the paper by the <i>i</i>-th punching instruction.</p>



## 소스코드

[소스코드 보기](Origami,%20or%20the%20art%20of%20folding%20paper.cpp)