# 17585번: Circuit Math - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/17585)


<p>You are enrolled in the Computer Organization and Architecture course at your university. You decide to write a program to help check your work by computing the output value of a combinational digital circuit, given its inputs.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/fb89c1bd-3caf-4f9d-9628-e9b0ca703efd/-/preview/" style="width: 304px; height: 186px;"></p>

<p style="text-align: center;">Figure A.1: An example of a combinational digital circuit. See the text for an explanation.</p>

<p>Consider the circuit shown in Figure A.1, which we use for illustration. This circuit has four inputs (letters A through D on the left), each of which is either true or false. There are four ‘gates’ each of which is one of three types: AND, OR, or NOT. Each gate produces either a true or false value, depending on its inputs. The last gate (the OR on the right) produces the output of the entire circuit. We can write these three types of gates in text by their equivalent <em>logical operators</em>: <code>*</code> for AND, <code>+</code> for OR, and <code>-</code> for NOT. In what follows, we’ll use the operators rather than gates to describe circuits.</p>

<p>Here is how these operators work. Given an assignment of true (<code>T</code>) or false (<code>F</code>) for each input, the operators produce the truth value indicated in the following tables:</p>

<table class="table table table-bordered table-center-30" style="margin-bottom: 22px;">
<thead>
<tr>
<th style="text-align: center;"><code>A</code></th>
<th style="text-align: center;"><code>B</code></th>
<th style="text-align: center;"><code>A B *</code></th>
<th style="text-align: center;"><code>A B +</code></th>
</tr>
</thead>
<tbody>
<tr>
<td style="text-align: center;"><code>T</code></td>
<td style="text-align: center;"><code>T</code></td>
<td style="text-align: center;"><code>T</code></td>
<td style="text-align: center;"><code>T</code></td>
</tr>
<tr>
<td style="text-align: center;"><code>F</code></td>
<td style="text-align: center;"><code>T</code></td>
<td style="text-align: center;"><code>F</code></td>
<td style="text-align: center;"><code>T</code></td>
</tr>
<tr>
<td style="text-align: center;"><code>T</code></td>
<td style="text-align: center;"><code>F</code></td>
<td style="text-align: center;"><code>F</code></td>
<td style="text-align: center;"><code>T</code></td>
</tr>
<tr>
<td style="text-align: center;"><code>F</code></td>
<td style="text-align: center;"><code>F</code></td>
<td style="text-align: center;"><code>F</code></td>
<td style="text-align: center;"><code>F</code></td>
</tr>
</tbody>
</table>

<table class="table table table-bordered table-center-10">
<thead>
<tr>
<th style="text-align: center;"><code>A</code></th>
<th style="text-align: center;"><code>A -</code></th>
</tr>
</thead>
<tbody>
<tr>
<td style="text-align: center;"><code>T</code></td>
<td style="text-align: center;"><code>F</code></td>
</tr>
<tr>
<td style="text-align: center;"><code>F</code></td>
<td style="text-align: center;"><code>T</code></td>
</tr>
</tbody>
</table>

<p>Notice that AND and OR take two inputs, whereas NOT operates on only one input. Also, we use <em>postfix notation</em> to write expressions involving operators (like <code>A B *</code>), where the operator comes <em>after</em> its input(s) (just as how in Figure A.1, each gate in the circuit diagram comes after its inputs).</p>

<p>When we describe a valid circuit in postfix notation, we use the following syntax.</p>

<ul>
<li>An uppercase letter (<code>A</code> through <code>Z</code>) is a valid circuit. In other words, an input alone (without any gates) is a valid circuit (which produces as output its own input value).</li>
<li>If <code>&lt;C1&gt;</code> and <code>&lt;C2&gt;</code> are valid circuits, then ‘<code>&lt;C1&gt; &lt;C2&gt; *</code>’ is a valid circuit that produces the AND of the outputs of the two subcircuits.</li>
<li>If <code>&lt;C1&gt;</code> and <code>&lt;C2&gt;</code> are valid circuits, then ‘<code>&lt;C1&gt; &lt;C2&gt; +</code>’ is a valid circuit that produces the OR of the outputs of the two subcircuits.</li>
<li>If <code>&lt;C1&gt;</code> is a valid circuit, then ‘<code>&lt;C1&gt; -</code>’ is a valid circuit that produces the NOT of <code>&lt;C1&gt;</code>’s output.</li>
</ul>

<p>No other description is a valid circuit.</p>

<p>Thus, one of the ways the circuit in Figure A.1 could be described using postfix notation is as the string:</p>

<p style="text-align: center;"><code>A B * C D + - +</code></p>

<p>Given a truth value (<code>T</code> or <code>F</code>) for each of the inputs (<code>A</code>, <code>B</code>, <code>C</code>, and <code>D</code> in this example), their values propagate through the gates of the circuit, and the truth value produced by the last gate is the output of the circuit. For example, when the above circuit is given inputs <code>A=T</code>, <code>B=F</code>, <code>C=T</code>, <code>D=F</code>, the output of the circuit is <code>F</code>.</p>

<p>Given an assignment to variables and a circuit description, your software should print the output of the circuit.</p>



## 입력


<p>The first line of the input consists of a single integer <em>n</em>, satisfying 1 ≤ <em>n</em> ≤ 26, denoting the number of input variables. Then follows a line with <em>n</em> space-separated characters. Each character is either <code>T</code> or <code>F</code>, with the <em>i</em>th such character indicating the truth value of the input that is labeled with the ith letter of the alphabet.</p>

<p>The last line of input contains a circuit description, which obeys the syntax described above. Each circuit is valid, uses only the first <em>n</em> letters of the alphabet as input labels, and contains at least 1 and at most 250 total non-space characters.</p>

<p>Note that while each variable is provided only one truth value, a variable may appear multiple times in the circuit description and serve as input to more than one gate.</p>



## 출력


<p>Print a single character, the output of the circuit (either <code>T</code> or <code>F</code>), when evaluated using the given input values.</p>



## 소스코드

[소스코드 보기](Circuit%20Math.cpp)