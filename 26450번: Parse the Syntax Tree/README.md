# 26450번: Parse the Syntax Tree - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/26450)

<p>To evaluate a program efficiently, a language processor often transforms it into a syntax tree. In this problem you are given a syntax tree of a mathematical expression using ASCII characters. Please evaluate the expression</p>

<p>The syntax tree we consider in this problem is a rooted binary tree where each node has either zero or two children. If a node has zero children, it is an integer node that corresponds to a single integer between 0 and 9, inclusive. On the other hand, if a node has two children, the node is a binary operation node that corresponds to a binary operation of either addition, subtraction or multiplication. In this case the left and right children correspond to the left and right operands of the binary operation, respectively. For example, Figure B.1 represents the syntax tree of expression $(9-4) * ((7*2)+5)$.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/40bd83b1-d6d8-4531-85d9-f150f7411ebd/-/preview/"></p>

<p style="text-align: center;">Figure B.1: Example of a syntax tree</p>

<p>To represent such a syntax tree using ASCII characters, you are given $H$ strings of $W$ characters. Each character is either ‘<code>+</code>', ‘<code>-</code>', ‘<code>*</code>', a digit between ‘<code>0</code>' and ‘<code>9</code>', or a period that represents a blank. For example, here is the representation of the syntax tree of Figure B.1.</p>

<pre>...*.....
.-.....+.
9.4..*..5
....7.2..</pre>

<p>Figure B.2 shows the rules (similar to Backus-Naur Form) of such representation of a syntax tree.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/8e59413d-69c0-4c8a-ae1d-a25c187704ec/-/preview/"></p>

<p style="text-align: center;">Figure B.2: Rules of the representation of a syntax tree</p>

<p>More precisely, the rules are defined as follows.</p>

<ul>
<li>A “cell" is a rectangular region of characters that corresponds to a single node (i.e., either an integer node or a binary operation node) of a syntax tree.</li>
<li>A cell corresponding to an integer node contains only a single digit that is the same integer of the node. The height and width of such a cell are 1.</li>
<li>A cell $c$ corresponding to a binary operation node $v$ contains a single operator and two other cells as children. More precisely, let $v_1$ and $v_2$ be the left and right children of the binary operation node, respectively. And let $c_1$ and $c_2$ be the cells that correspond to $v_1$ and $v_2$, respectively. The height of $c$ is $\max{(h_1, h_2)} + 1$ where $h_1$ and $h_2$ are the heights of $c_1$ and $c_2$, respectively. On the other hand, the width of $c$ is $w_1 + w_2 + 1$ where $w_1$ and $w_2$ are the widths of $c_1$ and $c_2$, respectively. The topmost row of $c$ consists of $w_1$ periods followed by an operator followed by $w_2$ periods where the operator is either ‘<code>+</code>', ‘<code>-</code>' or ‘<code>*</code>'. $c_1$ is located from the second to the $(h_1+1)$-st rows (from the top) and the first to the $w_1$-st columns (from the left) of $c$. Similarly, $c_2$ is located from the second to the $(h_2+1)$-st rows (from the top) and the $(w_1+2)$-nd to the $(w_1+w_2+1)$-st columns (from the left) of $c$. Note that although $c_1$ and $c_2$ may have different heights, their top borders are always aligned.</li>
<li>It is guaranteed by the above rules that no two cells <em>partially</em> overlap each other. In other words, when two cells overlap, then one of them completely contains the other.</li>
<li>Any other characters that are not restricted by the above rules are filled by periods.</li>
<li>The entire region of characters is the “root" cell. In other words, the cell corresponding to the root node of the syntax tree has height $H$ and width $W$.</li>
</ul>

<p>Your task is to calculate the mathematical expression that corresponds to the given syntax tree formatted by the above rules.</p>

## 입력

<p>The input consists of a single test case of the following format.</p>

<blockquote>
<p>$H$ $W$</p>

<p>$s_1$</p>

<p>$\vdots$</p>

<p>$s_H$</p>
</blockquote>

<p>The first line contains two integers $H$ and $W$ ($1 \le H, W \le 37$), which represent the height and width of the representation of the given syntax tree. The following $H$ lines consist of strings of length $W$ where each character is either ‘<code>+</code>', ‘<code>-</code>', ‘<code>*</code>', a digit between ‘<code>0</code>' and ‘<code>9</code>', or a period. It is guaranteed that these strings represent a syntax tree of a mathematical expression in a valid form.</p>

## 출력

<p>Print the calculation result of the mathematical expression that corresponds to the given input.</p>

## 소스코드

[소스코드 보기](Parse%20the%20Syntax%20Tree.cpp)