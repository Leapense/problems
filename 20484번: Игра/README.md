# 20484번: Игра - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/20484)


<p>На планете Шелезяка катастрофа --- запасы смазки подходят в концу. В связи с этим правительство решило организовать всепланетное соревнование, главный приз в котором --- вагон смазочных материалов.</p>

<p>Соревнование проводится в несколько этапов, каждый из которых поделен на множество раундов. В каждом раунде принимают участие два игрока. Жюри предоставляет им большое целое число~$n$. Затем игроки делают ходы по очереди. Первый ход первого игрока заключается в том, что игрок выписывает на специальном поле цифру, причем первым ходом запрещается выписывать ноль. В дальнейшем ход игрока заключается в том, что он приписывает справа к уже написанному числу произвольную цифру. Выигрывает тот, после чьего хода выписанное число больше или равно~$n$.</p>

<p>Знаменитый ученый-робот &lt;&lt;ЩК-33&gt;&gt; считает, что результат игры легко предсказуем. Для доказательства он решил предоставить программу, которая определяет, кто выигрывает, если оба игрока действуют по оптимальной стратегии. К сожалению, из-за недостатка смазки, его манипуляторы вышли из строя, поэтому он просит вас о помощи.</p>



## 입력


<p>Первая строка входного файла содержит целое число $n$ ($1 \le n \le 10^{100\,000}$). Это число не содержит ведущих нулей.</p>



## 출력


<p>Выведите &lt;&lt;<code>First</code>&gt;&gt;, если при оптимальной игре выигрывает первый игрок, и &lt;&lt;<code>Second</code>&gt;&gt; в противном случае.</p>



## 소스코드

[소스코드 보기](Игра.cpp)