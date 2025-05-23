# 32589번: Flag Rotation - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/32589)


<p>A common pattern for country flags is three stripes. Some flags are really similar, and have exactly the same stripes in the same order, but the flag is rotated by $90$ degrees. Using a sequence of colours, we can make a flag on a square grid, covering each row with the colours in the sequence. Another way to make a similar flag (that is rotated by $90$ degrees), is by covering each column with the colours in the sequence.</p>

<p>In preparation for the Flags You Paint for Countries meeting, you notice a mistake for one of the flags: it should have been rotated counter-clockwise by $90$ degrees! The square canvas is already stuck to a wall using super glue, so you can not simply take it off and rotate it. Therefore, you want to know how much work it would be to repaint one flag to the other. In one second, you can repaint one of the $1 \times 1$ squares to any colour. What is the minimum number of seconds you need to repaint the flag? As an example, for the flag in the first sample input (shown in Figure F.1), $34$ squares need to be repainted.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/8971c643-53db-4a0a-ac5e-b895c85b73f8/-/preview/" style="width: 211px; height: 211px;"> <img alt="" src="https://upload.acmicpc.net/2c89212f-46fa-460c-9be3-9d3343a671a8/-/preview/" style="width: 211px; height: 211px;"></p>

<p style="text-align: center;">Figure F.1: Two flags corresponding to the first sample input. Colour $1$ corresponds to yellow, $2$ to red, $3$ to white, and $1000$ to blue. When the first flag should be rotated counter-clockwise by $90$ degrees without actually rotating the canvas, $34$ squares need to be repainted.</p>



## 입력


<p>The input consists of:</p>

<ul>
<li>One line with an integer $n$ ($1\leq n\leq 2 \cdot 10^5$), the number of stripes in the flag.</li>
<li>One line with $n$ integers $a$ ($1\leq a\leq 10^9$), the colours of the stripes.</li>
</ul>



## 출력


<p>Output the number of cells that need to be repainted when the flag should be rotated counter-clockwise by $90$ degrees.</p>



## 소스코드

[소스코드 보기](Main.java)