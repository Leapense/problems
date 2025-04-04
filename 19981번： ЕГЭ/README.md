# 19981번: ЕГЭ - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/19981)


<p>Соня --- одиннадцатиклассница, и в этом году ей надо сдавать единый государственный экзамен по информатике. Она решила начать готовиться заранее и стала решать задачи из вариантов прошлых лет.&nbsp;</p>

<p>В многих заданиях требуется перевести число из одной системы счисления в другую. Соня с легкостью справляется с такими заданиями, но недавно в одном из вариантов ей попалась задача, которая показалась довольно интересной: число $x$, заданное в десятичной системе счисления, требуется перевести в ($-2$)-ичную систему счисления.&nbsp;</p>

<p>Формально, записью числа в ($-2$)-ичной системе счисления называется набор чисел $a_0, a_1, \ldots, a_{n-1}$, каждое из которых равно 0 или 1, причем $n = 1$ или $a_{n-1} \ne 0$ и выполнено равенство: $$x=\sum_{i=0}^{n-1} a_i (-2)^i.$$</p>

<p>Например, 3 в ($-2$)-ичной системе счисления представляется набором $(1, 1, 1)$: действительно, $1\cdot(-2)^0+1\cdot(-2)^1+1\cdot(-2)^2=1-2+4=3$.</p>

<p>В задаче предлагается перевести в ($-2$)-ичную систему счисления только одно число, но Соне стало интересно решение этой задачи в общем случае.</p>

<p>После долгих раздумий она обратилась к вам за помощью. Помогите ей перевести заданное число в ($-2$)-ичную систему счисления.</p>



## 입력


<p>В единственной строке входного файла записано одно целое число $x$ --- число, которое Соня хочет представить в ($-2$)-ичной системе счисления ($-10^{18} \le x \le 10^{18}$).</p>



## 출력


<p>В первой строке выходного файла выведите число $n$ ($n \ge 1$).</p>

<p>Во второй строке выходного файла через пробел выведите $n$ чисел $a_0, a_1, \ldots, a_{n-1}$ --- цифры числа $x$ в ($-2$)-ичной системе счисления ($0 \le a_i \le 1$).</p>

<p>Если существует несколько ответов, выведите любой из них.</p>



## 소스코드

[소스코드 보기](ЕГЭ.cpp)