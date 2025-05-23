# 8677번: Miasta - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/8677)


<p>Wzdłuż rzeki znajduje się <em>n</em>&nbsp;miast. Pomiędzy każdą parą sąsiednich miast wybudowana jest droga, niestety nie zawsze dwukierunkowa, dlatego nie zawsze da się dojechać z każdego miasta do wszystkich innych. Znając, które drogi są wybudowane, chcielibyśmy wiedzieć dla każdego miasta, do ilu innych miast da się z niego dojechać.</p>



## 입력


<p>Pierwszy wiersz standardowego wejścia zawiera jedną liczbę całkowitą <em>n</em>&nbsp;(1 ≤ <em>n</em> ≤ 10<sup>6</sup>), oznaczającą liczbę miast.</p>

<p>W kolejnym wierszu znajduje się <em>n</em> - 1&nbsp;liczb całkowitych <em>d</em><sub>1</sub>, <em>d</em><sub>2</sub>, ..., <em>d</em><sub><em>n</em>-1</sub>&nbsp;(0 ≤ <em>d<sub>i</sub></em> ≤ 2), gdzie&nbsp;<em>d<sub>i</sub></em>&nbsp;oznacza połączenie pomiędzy miastem <em>i</em>-tym, a <em>i</em>+1-wszym. Jeśli:</p>

<ul>
<li><em>d<sub>i</sub></em> = 0, to z miasta <em>i</em>-tego biegnie jednokierunkowa droga do miasta <em>i</em>+1-wszego,</li>
<li><em>d<sub>i</sub></em> = 1, to z miasta <em>i</em>+1-wszego biegnie jednokierunkowa droga do miasta&nbsp;<em>i</em>-tego,</li>
<li><em>d<sub>i</sub></em> = 2, to miasta <em>i</em>-te i <em>i</em>+1-wsze połączone są drogą dwukierunkową.</li>
</ul>



## 출력


<p>W pierwszym i jedynym wierszu wyjścia powinno znajdować się <em>n</em>&nbsp;liczb całkowitych <em>w</em><sub>1</sub>, <em>w</em><sub>2</sub>, ..., <em>w<sub>n</sub></em>, gdzie <em>w<sub>i</sub></em>&nbsp;oznacza liczbę miast, do których da się dojechać z miasta <em>i</em>-tego.</p>



## 소스코드

[소스코드 보기](Miasta.cpp)