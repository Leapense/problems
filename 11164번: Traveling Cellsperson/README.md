# 11164번: Traveling Cellsperson - <img src="https://static.solved.ac/tier_small/6.svg" style="height:20px" /> Silver V

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/11164)


<p>You have solved every problem from Project Euler in your head. Now it is time for a problem you might have heard of, namely The Traveling Salesperson, whose decision version is NP-complete. We consider the Traveling Salesperson problem in a 2D rectangular grid where every cell can be reached from their neighboring cells (up, down, left and right) and you can visit a cell as many times as you like (though, most of the cells aren’t that interesting, so you might prefer not to visit them a lot).</p>



## 입력


<p>The first line of the input consists of a single integer T, the number of test cases. Then follow two integers X and Y , marking the width and height of the grid, respectively. Then follow Y lines with X characters, where the character ’C’ is a cell and the character ’S’ is the starting point.</p>

<ul>
<li>0 &lt; T ≤ 50</li>
<li>0 &lt; X ≤ 100</li>
<li>0 &lt; Y ≤ 100</li>
<li>All characters in a test case are ’C’, except for exactly one, which is ’S’.</li>
</ul>



## 출력


<p>For each test case, output the minimum number of steps required to make a full roundtrip of the grid, starting and ending at S, and visiting each cell at least once.</p>

<p>Since you realize that this won’t lead anywhere, finish off the output with “LOL” (without quotes) on a line of its own (one per run, not per test case).</p>



## 소스코드

[소스코드 보기](Traveling%20Cellsperson.cpp)