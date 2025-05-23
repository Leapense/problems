# 8631번: Żołnierze - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/8631)


<p>Na porannym apelu w koszarach wszyscy przebywający tam żołnierze muszą ustawić się w szeregu. Nie mogą jednak stanąć w dowolnej kolejności, tylko od najwyższego do najniższego. Najwyższy może przy tym stać zarówno z lewej, jak i z prawej strony. Pomóż im wyznaczyć liczbę sposobów, na jakie mogą ustawić się poprawnie.</p>

<p>Dwa ustawienia żołnierzy uważamy za identyczne wtedy i tylko wtedy, gdy każdy żołnierz w obu ustawieniach ma tego samego sąsiada po lewej stronie (lub w obu nie ma go wcale) oraz w obu ustawieniach ma tego samego sąsiada po prawej stronie (lub w obu nie ma go wcale).</p>

<p>Napisz program, który:</p>

<ul>
<li>wczyta ze standardowego wejścia opis wszystkich przebywających w koszarach żołnierzy,</li>
<li>wyznaczy liczbę ustawień żołnierzy w jednym rzędzie w kolejności od najwyższego do najniższego,</li>
<li>wypisze cztery ostatnie cyfry dziesiętne wyniku na standardowe wyjście.</li>
</ul>



## 입력


<p>W pierwszym wierszu wejścia znajduje się jedna liczba całkowita $n$&nbsp;($1 ≤ n ≤ 200\,000$), oznaczająca liczbę żołnierzy w koszarach. Drugi wiersz wejścia zawiera $n$&nbsp;liczb całkowitych $w_i$&nbsp;($1 ≤ w_i ≤ 10^9$), pooddzielanych pojedynczymi odstępami i oznaczających wysokości kolejnych żołnierzy.</p>



## 출력


<p>Twój program powinien wypisać w pierwszym i jedynym wierszu wyjścia cztery ostatnie cyfry dziesiętne liczby ustawień żołnierzy w jednym rzędzie w kolejności posortowanej względem ich wysokości. Jeżeli wynik jest mniejszy niż $1\,000$, to należy wypisać wszystkie jego cyfry.</p>



## 소스코드

[소스코드 보기](Main.java)