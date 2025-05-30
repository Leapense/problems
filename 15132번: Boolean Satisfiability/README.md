# 15132번: Boolean Satisfiability - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/15132)


<p>Boolean satisfiability problem (SAT) is known to be a very hard problem in computer science. In this problem you are given a Boolean formula, and you need to find out if the variables of a given formula can be consistently replaced by the values <code>true</code> or <code>false</code> in such a way that the formula evaluates to true. SAT is known to be NP-complete problem. Moreover, it is NP-complete even in case of 3-CNF formula (3-SAT). However, for example, SAT problem for 2-CNF formulae (2-SAT) is in P.</p>

<p>#SAT is the extension of SAT problem. In this problem you need to check if it is possible, and count the number of ways to assign values to variables. This problem is known to be #P-complete even for 2-CNF formulae. We ask you to solve #1-DNF-SAT, which is #SAT problem for 1-DNF formulae.</p>

<p>You are given a Boolean formula in 1-DNF form. It means that it is a disjunction (logical or) of one or more clauses, each clause is exactly one literal, each literal is either variable or its negation (logical not).</p>

<p>Formally:</p>

<pre> ⟨formula⟩ ::= ⟨clause⟩ | ⟨formula⟩ ∨ ⟨clause⟩
  ⟨clause⟩ ::= ⟨literal⟩
 ⟨literal⟩ ::= ⟨variable⟩ | ¬ ⟨variable⟩
⟨variable⟩ ::= A . . . Z | a . . . z</pre>

<p>Your task is to find the number of ways to replace all variables with values <code>true</code> and <code>false</code> (all occurrences of the same variable should be replaced with same value), such that the formula evaluates to <code>true</code>.</p>



## 입력


<p>The only line of the input file contains a logical formula in 1-DNF form (not longer than 1000 symbols). Logical operations are represented by ‘|’ (disjunction) and ‘~’ (negation). The variables are ‘A’ . . . ‘Z’ and ‘a’ . . . ‘z’ (uppercase and lowercase letters are different variables). The formula contains neither spaces nor other characters not mentioned in the grammar.</p>



## 출력


<p>Output a single integer — the answer for #SAT problem for the given formula.</p>



## 소스코드

[소스코드 보기](Boolean%20Satisfiability.py)