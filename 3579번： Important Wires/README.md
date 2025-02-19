# 3579번: Important Wires - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/3579)


<p>Nick bought a new motherboard for his computer and it seems that it does not work properly. The motherboard is pretty complicated but it has only few important wires that have binary states: live or dead. Nick wants to know the states of these wires.</p>

<p>Unfortunately, important wires are not directly accessible. But Nick found a maintenance socket. Each output pin of this socket is connected to some of important wires via an integrated circuit. Fortunately, Nick found the circuit layout in the Internet. To specify it, he marked important wires by lowercase letters and socket’s output pins by uppercase letters. After that he wrote down Boolean formula for each output pin. In these formulae live wires and pins are represented by true and dead wires — by <em>false</em>.</p>

<p>Nick used following notation for formulae (operations are listed from the highest priority to the lowest):</p>

<ul>
<li>Pin names — letters from ‘<code>a</code>’ to ‘<code>k</code>’;</li>
<li>Parentheses — if <em>E</em> is a formula, then (<em>E</em>) is another;</li>
<li>Negation — ¬<em>E</em> is a formula for any formula <em>E</em>;</li>
<li>Conjunction — <em>E</em><sub>1</sub> ∧<em>E</em><sub>2</sub> ∧···∧<em>E<sub>n</sub></em>;</li>
<li>Disjunction — <em>E</em><sub>1</sub> ∨<em>E</em><sub>2</sub> ∨···∨<em>E<sub>n</sub></em>;</li>
<li>Implication — <em>E</em><sub>1</sub> ⇒ <em>E</em><sub>2</sub> ⇒ · · · ⇒ <em>E<sub>n</sub></em>. Implication is evaluated from right to left: <em>E</em><sub>1</sub> ⇒ <em>E</em><sub>2</sub> ⇒ <em>E</em><sub>3</sub>&nbsp;means <em>E</em><sub>1</sub> ⇒ (<em>E</em><sub>2</sub> ⇒<em>E</em><sub>3</sub>);</li>
<li>Equivalence — <em>E</em><sub>1</sub> ≡ <em>E</em><sub>2</sub> ≡ ··· ≡ <em>E<sub>n</sub></em>. This expression is by definition computed as follows: (<em>E</em><sub>1</sub> ≡ <em>E</em><sub>2</sub>) ∧ (<em>E</em><sub>2</sub> ≡ <em>E</em><sub>3</sub>) ∧ ··· ∧ (<em>E</em><sub><em>n</em>−1</sub> ≡ <em>E<sub>n</sub></em>).</li>
</ul>

<p>Nick has lots of various gates at hand, so he can build a new circuit that implements any formula. The variables of this formula are states of maintenance socket’s pins. First of all, Nick wants to construct a circuit that takes all maintenance socket’s pins as inputs and has a single output wire that is always live. Write a program to help him.</p>



## 입력


<p>The first line of the input file contains a single integer number <em>n</em> — the number of pins in the maintenance socket (1 ≤ <em>n</em> ≤ 10). The following n lines contain description of one pin each.</p>

<p>Each pin description consists of a pin name and corresponding formula delimited by ‘<code>:=</code>’ token. Pin name is a uppercase English letter. Formula is represented by a string consisting of tokens ‘<code>a</code>’..‘<code>k</code>’, ‘<code>(</code>’, ‘<code>)</code>’, ‘<code> </code>’, ‘<code>&amp;</code>’, ‘<code>|</code>’, ‘<code>=&gt;</code>’, and ‘<code>&lt;=&gt;</code>’. The last five tokens stand for ¬, ∧, ∨, ⇒ and ≡ respectively. Tokens can be separated by an arbitrary number of spaces. Each pin description contains 1 000 characters at most.</p>



## 출력


<p>The first line of the output file must contain “Yes” if there exists a circuit which output wire is always live and “No” otherwise.</p>

<p>In the former case the following line must contain the formula for the constructed circuit in the same format as in the input file. Remember that the formula must contain each of pin names at least once and it must not contain the wire names. The line must not exceed 1 000 characters.</p>



## 소스코드

[소스코드 보기](Important%20Wires.py)