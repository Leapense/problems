# 24718번: Kemija - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/24718)


<p>Fran didn’t pay attention in school during chemistry class and now he needs your help in doing his homework. His homework consists of $n$ chemical equations for which he needs to check if they are balanced. A chemical equation is a way of representing chemical reactions using symbols and formulas. In a chemical reaction, some set of initial molecules react to produce a new set of molecules.</p>

<p>A chemical equation has a left side and a right side. The left side contains chemical formulas of the initial molecules, while the right side contains chemical formulas of the product molecules. The left and the right sides of the equation are separated by an arrow (characters <code>-&gt;</code>). Different molecules appearing on the left or the right side are separated by a <code>+</code>.</p>

<p>Molecules are substances made from atoms, tiny particles which are denoted with capital letters of the Latin alphabet (for the purposes of this task). The formula of a molecule is written by listing the labels of all the different atoms which make up the molecule. If a molecule has multiple instances of some atom, then the number of occurrences of this atom is written after the atom in the formula. For example, <code>AC4B</code> is a formula for a molecule which has one atom <code>A</code>, 4 atoms <code>C</code> and one atom <code>B</code>. If on one side of the equation a molecule appears more than once, then this number of occurrences is written as a coefficient in front of the formula. For example, <code>3AC4B</code> denotes 3 molecules of <code>AC4B</code>, for a total of 3 atoms <code>A</code>, 12 atoms <code>C</code> and 3 atoms <code>B</code>.</p>

<p>A chemical equation is said to be balanced if the right side and the left side contain an equal number of atoms of each kind. Your task is to determine whether or not each of the $n$ chemical equations is balanced. The test cases will be such that all the numbers appearing in the reactions (the numbers of atoms in molecules and the numbers of molecules in the ractions) will have only a <strong>single digit</strong> (and they will be larger than 1).</p>



## 입력


<p>The first line contains a positive integer $n$ ($1 ≤ n ≤ 10$), the number of chemical equations.</p>

<p>Each of the next $n$ lines contains a sequence of characters representing a chemical equation. Each equation consists of at most $1000$ characters. The equations will not necessarily be balanced, but they will be correctly written as described in the statement.</p>



## 출력


<p>For each of the $n$ equations print <code>DA</code> if it is balanced, and <code>NE</code> if it is not, in separate lines.</p>



## 소스코드

[소스코드 보기](Kemija.py)