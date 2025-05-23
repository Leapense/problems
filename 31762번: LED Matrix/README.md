# 31762번: LED Matrix - <img src="https://static.solved.ac/tier_small/6.svg" style="height:20px" /> Silver V

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/31762)


<p>A LED matrix is a two-dimensional array of LEDs that is used to display information. This is achieved by turning on the LEDs that form a desired pattern. The figure below represents a LED matrix displaying a smiling-face pattern. LEDs that are turned off are shown in white, while LEDs that are turned on appear colored.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/bdb2c1da-3f3d-4a69-87fc-9c8ab3aad05c/-/preview/" style="width: 169px; height: 150px;"></p>

<p>Some LED matrices scroll the pattern from right to left across the matrix, turning on just the appropriate LEDs at each step. Thus, any pattern with the same height than the matrix can be displayed, even patterns that are wider than the matrix. The pattern scrolling works as follows: Initially, all the LEDs in the matrix are turned off. The next step, the last column of the matrix displays the first column of the pattern. At each new step the pattern is moved one column to the left across the matrix, until the first column of the matrix displays the last column of the pattern. Finally, all the LEDs in the matrix are turned off again. If a LED matrix is equipped with pattern scrolling, the scrolling occurs even if the pattern if not wider than the matrix.</p>

<p>The picture below shows all the step required to display a pattern of an arrow that is pointing to the left.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/6c14128e-56b1-45c0-af9d-6924223ed87b/-/preview/" style="width: 439px; height: 250px;"></p>

<p>Astrid has just received an old LED matrix with pattern scrolling, and she thinks that some LEDs might be broken. Since broken LEDs cannot be turned on, she is worried that some patterns will not display properly. Given the description of the state of each LED, and the pattern to display, you must tell whether the appropriate LEDs can be turned on at every step of the pattern scrolling.</p>



## 입력


<p>The first line contains three integers $R$, $C$ and $K$ ($1 ≤ R, C, K ≤ 1000$), indicating respectively the number of rows of both the LED matrix and the pattern, the number of columns of the matrix, and the number of columns of the pattern.</p>

<p>The next $R$ lines describe the matrix and the pattern from top to bottom. Each of these lines contains a string $M$ of length $C$ and a string $P$ of length $K$, describing respectively a row of the matrix and a row of the pattern. Each character of both $M$ and $P$ is either “<code>*</code>” (asterisk) or “<code>-</code>” (hyphen). For $M$, the character “<code>*</code>” indicates a good LED while the character “<code>-</code>” represents a broken LED. For $P$, the character “<code>*</code>” indicates a LED the must be turned on while the character “<code>-</code>” represents a LED that must be turned off.</p>



## 출력


<p>Output a single line with the uppercase letter “<code>Y</code>” if the appropriate LEDs can be turned on at every step of the pattern scrolling, and the uppercase letter “<code>N</code>” otherwise.</p>



## 소스코드

[소스코드 보기](LED%20Matrix.py)