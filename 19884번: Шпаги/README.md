# 19884번: Шпаги - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/19884)


<p>Археологический раздел НИИЧАВО решил заняться изучением древнефлатландских волшебных шпаг. После изучения всех имеющихся в наличии образцов было выяснено, что все почти все шпаги на самом деле являются копиями друг друга.</p>

<p>А именно, в глубокой древности была произведена первая волшебная шпага. После этого время от времени мастера занимались тем, что брали одну из существующих волшебных шпаг и изготавливали ее копию. Разумеется, копия отличалась от оригинала, но в целом наследовала некоторые его признаки.</p>

<p>Поскольку изготовление копии волшебной шпаги снижает ее магическую силу, ученые установили, что с каждой шпаги было сделано не более двух копий. Также было установлено, что копия могла быть изготовлена не ранее чем через $k$ лет после изготовления оригинала.</p>

<p>В распоряжении ученых оказались $n$ шпаг, про каждую из которых им известен ее возраст. Ученые хотят выяснить, какая из шпаг была изготовлена первой, а для всех остальных шпаг выяснить, с какой из шпаг она была скопирована. К сожалению, информации о возрасте может быть недостаточно, чтобы восстановить эту информацию однозначно, но ученых устроит любой возможный вариант.</p>



## 입력


<p>Первая строка входного файла содержит два числа $n$ и $k$ --- количество шпаг, имеющихся у ученых, и минимальный возраст, необходимый для того, чтобы со шпаги можно было сделать копию ($1 \le n \le 100\,000$, $1 \le k \le 10^8$). Следующая строка содержит $n$ чисел: $a_1, a_2, \ldots, a_n$, где $a_i$ ($0 \le a_i \le 10^{9}$) --- возраст $i$-й шпаги.</p>



## 출력


<p>Для каждого экземпляра шпаги выведите номер шпаги, с которой она была скопирована. Обратите внимание, с каждой шпаги могло быть снято не более двух копий.</p>

<p>Если экземпляр является первой изготовленной шпагой, то выведите для соответствующей шпаги число 0.</p>

<p>Если возможных решений несколько, выведите любое.</p>

<p>Если ученые ошибаются и искомой последовательности изготовления копий шпаг не существует, выведите единственное число $-1$.</p>



## 소스코드

[소스코드 보기](Шпаги.cpp)