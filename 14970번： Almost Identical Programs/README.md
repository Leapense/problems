# 14970번: Almost Identical Programs - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/14970)


<p>The programming contest named&nbsp;<em>Concours de Programmation Comtemporaine Interuniversitaire</em>&nbsp;(CPCI) has a judging system similar to that of ICPC; contestants have to submit correct outputs for two different inputs to be accepted as a correct solution. Each of the submissions should include the program that generated the output. A pair of submissions is judged to be a correct solution when, in addition to the correctness of the outputs, they include an identical program.</p>

<p>Many contestants, however, do not stop including a different version of their programs in their second submissions, after modifying a single string literal in their programs representing the input file name, attempting to process different input. The organizers of CPCI are exploring the possibility of showing a special error message for such&nbsp;<em>close</em>&nbsp;submissions, indicating contestants what's wrong with such submissions. Your task is to detect such close submissions.</p>



## 입력


<p>The input consists of at most 100 datasets, each in the following format.</p>

<pre><em>s</em><sub>1</sub> 
<em>s</em><sub>2</sub> 
</pre>

<p>Each of&nbsp;<em>s</em><sub>1</sub>&nbsp;and&nbsp;<em>s</em><sub>2</sub>&nbsp;is a string written in a line, with the length between 1 and 200, inclusive. They are the first and the second submitted programs respectively. A program consists of lowercase letters (<code>a</code>,&nbsp;<code>b</code>, ...,&nbsp;<code>z</code>), uppercase letters (<code>A</code>,&nbsp;<code>B</code>, ...,&nbsp;<code>Z</code>), digits (<code>0</code>,&nbsp;<code>1</code>, ...,&nbsp;<code>9</code>), double quotes (<code>"</code>), and semicolons (<code>;</code>). When double quotes occur in a program, there are always even number of them.</p>

<p>The end of the input is indicated by a line containing one ‘<code>.</code>’ (period).</p>



## 출력


<p>For each dataset, print the judge result in a line.</p>

<p>If the given two programs are identical, print&nbsp;<code>IDENTICAL</code>. If two programs differ with only one corresponding string literal, print&nbsp;<code>CLOSE</code>. Otherwise, print&nbsp;<code>DIFFERENT</code>. A string literal is a possibly empty sequence of characters between an odd-numbered occurrence of a double quote and the next occurrence of a double quote.</p>



## 소스코드

[소스코드 보기](Almost%20Identical%20Programs.cpp)