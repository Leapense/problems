# 27260번: Красивые перестановки - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/27260)


<p>Перестановкой размера $n$ называется массив $\langle a_1, a_2, \ldots, a_n \rangle$ различных чисел от $1$ до $n$. Каждое число в перестановке встречается ровно один раз.</p>

<p>Сеня называет <em>красотой</em> перестановки $\langle a_1, a_2, \ldots, a_n \rangle$ число $(a_1a_2 + a_2a_3 + \ldots + a_{n-1}a_n)$. Он хочет посчитать количество перестановок, красота которых делится на $k$.</p>

<p>Даны числа $n$ и $k$, найдите количество перестановок размера $n$, красота которых делится на $k$.</p>

<p>Например, для $n = 3$ существует $6$ перестановок. Рассмотрим все эти перестановки и их красоту.</p>

<table class="table table-bordered table-center-30 th-center td-center">
<tbody>
<tr>
<th>Перестановка</th>
<th>Красота</th>
</tr>
<tr>
<td>$\langle 1, 2, 3\rangle$</td>
<td>$1\cdot2 + 2\cdot3 = 8$</td>
</tr>
<tr>
<td>$\langle 1, 3, 2\rangle$</td>
<td>$1\cdot3 + 3\cdot2 = 9$</td>
</tr>
<tr>
<td>$\langle 2, 1, 3\rangle$</td>
<td>$2\cdot1 + 1\cdot3 = 5$</td>
</tr>
<tr>
<td>$\langle 2, 3, 1\rangle$</td>
<td>$2\cdot3 + 3\cdot1 = 9$</td>
</tr>
<tr>
<td>$\langle 3, 1, 2\rangle$</td>
<td>$3\cdot1 + 1\cdot2 = 5$</td>
</tr>
<tr>
<td>$\langle 3, 2, 1\rangle$</td>
<td>$3\cdot2 + 2\cdot1 = 8$</td>
</tr>
</tbody>
</table>



## 입력


<p>Входные данные содержат два целых числа: $n$ и $k$ ($1 \le n \le 10$, $2 \le k \le 1000$).</p>



## 출력


<p>Выведите одно целое число: количество перестановок размера $n$, красота которых делится на $k$.</p>



## 소스코드

[소스코드 보기](Красивые%20перестановки.py)