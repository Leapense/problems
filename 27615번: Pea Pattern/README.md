# 27615번: Pea Pattern - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/27615)

<p>Do you see the pattern in the following sequence of numbers?</p>

<blockquote>
<p>$1, 11, 21, 1112, 3112, 211213, 312213, \ldots$</p>
</blockquote>

<p>Each term describes the makeup of the previous term in the list. For example, the term $3112$ indicates that the previous term consisted of three $1$'s (that's the $31$ in $3112$) and one $2$ (that's the $12$ in $3112$). The next term after $3112$ indicates that it contains two $1$'s, one $2$ and one $3$. This is an example of a <em>pea pattern</em>.</p>

<p>A pea pattern can start with any number. For example, if we start with the number $20902$ the sequence would proceed $202219$, $10113219$, $1041121319$, and so on.  Note that digits with no occurrences in the previous number are skipped in the next element of the sequence.</p>

<p>We know what you're thinking. You're wondering if $101011213141516171829$ appears in the sequence starting with $20902$. Well, this is your lucky day because you're about to find out.</p>

## 입력

<p>Input consists of a single line containing two positive integers $n$ and $m$, where $n$ is the starting value for the sequence and $m$ is a target value. Both values will lie between $0$ and $10^{100}-1$.</p>

## 출력

<p>If $m$ appears in the pea pattern that starts with $n$, display its position in the list, where the initial value is in position $1$. If $m$ does not appear in the sequence, display <code>Does not appear</code>.  We believe that all of these patterns converge on a repeating sequence within $100$ numbers, but if you find a sequence with more than $100$ numbers in it, display <code>I'm bored</code>.</p>

## 소스코드

[소스코드 보기](Pea%20Pattern.py)