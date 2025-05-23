# 8594번: Program - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/8594)


<p>Bajtocki kontrwywiad od dawna usiłuje przechwycić program służący pewnemu wrogiemu państwu do szyfrowania wiadomości. Właśnie udało mu się zdobyć pewną część tego programu - sekwencję wszystkich pojawiających się w nim nawiasów.</p>

<p>W treści programu pojawiają się trzy rodzaje nawiasów:</p>

<ul>
<li>okrągłe:&nbsp;<code>(</code>&nbsp;i&nbsp;<code>)</code></li>
<li>kwadratowe:&nbsp;<code>[</code>&nbsp;i&nbsp;<code>]</code></li>
<li>klamrowe:&nbsp;<code>{</code>&nbsp;i&nbsp;<code>}</code></li>
</ul>

<p>Jakkolwiek jest to niewielka ilość informacji, bajtoccy agenci chcą wywnioskować z niej możliwie najwięcej. Najważniejszym parametrem danej sekwencji jest&nbsp;<i>stopień zagnieżdżenia nawiasów</i>. Przez stopień zagnieżdżenia sekwencji nawiasów rozumiemy maksymalny ciąg par nawiasów, z których każda znajduje się wewnątrz poprzedniej. Wyznaczenie stopnia zagnieżdżenia sprawiło jednak ogromną trudność bajtockim programistom, dlatego kontrwywiad zlecił to zadanie właśnie Tobie.</p>

<p>Bajtoccy agenci uprzedzili Cię, że kosztowny proces obliczania stopnia zagnieżdżenia ma sens tylko wtedy, gdy przechwycony ciąg nawiasów jest poprawny, czyli wtedy, gdy nawias otwierający każdego rodzaju można sparować z nawiasem zamykającym tego samego rodzaju, występującym dalej, tak aby ciąg nawiasów znajdujących się pomiędzy nimi również był poprawnym ciągiem nawiasowym.</p>



## 입력


<p>Pierwszy wiersz standardowego wejścia zawiera dokładnie jedną liczbę całkowitą $n$&nbsp;($1 ≤ n ≤ 1\,000\,000$) - jest to długość programu wroga. Drugi wiersz zawiera słowo składające się ze znaków: "<code>(</code>", "<code>)</code>", "<code>[</code>", "<code>]</code>", "<code>{</code>", "<code>}</code>". Są to kolejne nawiasy pojawiające się w programie wroga.</p>



## 출력


<p>Jeżeli słowo nawiasowe wczytane na wejściu jest poprawne, Twój program powinien wypisać na standardowe wyjście jedną liczbę całkowitą równą maksymalnemu poziomowi zagnieżdżenia nawiasów.</p>

<p>W przeciwnym wypadku należy wypisać jedno słowo&nbsp;<code>NIE</code>.</p>



## 소스코드

[소스코드 보기](Program.cpp)