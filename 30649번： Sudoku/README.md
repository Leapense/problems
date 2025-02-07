# 30649번: Sudoku - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/30649)


<p>Sudoku is a logic-based, combinatorial number-placement puzzle. The objective is to fill a 9 × 9 grid with digits from 1 to 9 in such a way that the following statements hold:</p>

<ul>
<li>Each row contains exactly one occurrence of each digit from 1 to 9.</li>
<li>Each column contains exactly one occurrence of each digit from 1 to 9.</li>
<li>Each of the nine 3 × 3 subgrids contains exactly one occurrence of each digit from 1 to 9.</li>
</ul>

<p>For a given not yet finished sudoku grid, determine if there is a mistake in it.</p>

<p>Note: It is not necessary to check whether the sudoku grid is solvable.</p>



## 입력


<p>The input describes the sudoku grid.</p>

<p>The characters ’|’, ’-’ and ’+’ frame the 3 × 3 subgrids.</p>

<p>The character ’.’ represents an empty cell.</p>

<p>All the other characters in the input will be digits from ’1’ to ’9’.</p>

<p>See the examples for clarification.</p>



## 출력


<p>Output the word <code>GRESKA</code> if there is a mistake in the sudoku board. Otherwise, output the word <code>OK</code>.</p>



## 소스코드

[소스코드 보기](Main.java)