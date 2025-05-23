# 8606번: Klasy - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/8606)


<p>W Bajtocji dzieci grają w ciekawą odmianę gry w klasy. Na chodniku jest namalowany kwadrat o boku $n$, podzielony na $n^2$&nbsp;jednakowych pól. Zadaniem jednego z dzieci, zwanego dalej zawodnikiem, jest ponumerowanie wszystkich pól w ściśle określony sposób. Przed grą zawodnikowi wyznaczany jest kierunek świata: północ, południe, zachód lub wschód oraz dozwolony rodzaj skrętu: prawo lub lewo.</p>

<p>Wyznaczone dziecko wchodzi na wybrane przez siebie pole - jedno z czterech pól przy wierzchołkach kwadratu, zwraca się w wyznaczonym kierunku świata i rozpoczyna numerowanie od postawienia liczby $1$&nbsp;na polu startowym. W każdym ruchu zawodnik:</p>

<ul>
<li>idzie naprzód o jedno pole, o ile w wyniku tego ruchu pozostanie nadal wewnątrz kwadratu, a pole, na które przejdzie, jest wolne, tj. jeszcze nieponumerowane;</li>
<li>w przeciwnym przypadku wykonuje skręt w dozwolonym kierunku, ale tylko jeden, i idzie naprzód o jedno pole.</li>
</ul>

<p>Każde kolejne odwiedzone pole zawodnik numeruje kolejną liczbą naturalną. Dodatkowo zakładamy, że w pierwszym ruchu zawodnik nie może wykonać skrętu, a jedynie pójść naprzód w wyznaczonym kierunku. Pole startowe musi więc zostać wybrane z rozwagą. Jeżeli na przykład kwadrat ma bok długości $5$, zadany został kierunek północ i skręt w prawo, to doświadczony zawodnik wybrałby jako pole startowe róg południowo-zachodni, a cały ponumerowany kwadrat wyglądałby tak:</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/adabf349-f983-4575-91d8-50383d71b1ab/-/preview/"></p>

<p>Twoim zadaniem jest napisanie programu, który wypisze zawartość pewnego zadanego wycinka kwadratu wypełnionego przez dzieci.</p>



## 입력


<p>W pierwszym wierszu standardowego wejścia znajdują się pooddzielane pojedynczymi odstępami: liczba całkowita $n$&nbsp;($2 ≤ n ≤ 5\,000$), oznaczająca długość boku kwadratu, oraz dwa wyrazy oznaczające kierunek świata (jedno ze słów:&nbsp;<code>POLNOC</code>,&nbsp;<code>POLUDNIE</code>,&nbsp;<code>ZACHOD</code>&nbsp;lub&nbsp;<code>WSCHOD</code>) i dozwolony skręt (jedno ze słów:&nbsp;<code>PRAWO</code>&nbsp;lub&nbsp;<code>LEWO</code>).</p>

<p>W drugim wierszu wejścia znajdują się cztery liczby całkowite $x_1$, $x_2$, $y_1$, $y_2$&nbsp;($1 ≤ x_1 ≤ x_2 ≤ n$, $1 ≤ y_1 ≤ y_2 ≤ n$, $(x_2-x_1) \cdot (y_2 - y_1) ≤ 1\,000\,000$) oznaczające odpowiednio pierwszą i ostatnią kolumnę oraz pierwszy i ostatni wiersz wycinka, który należy wypisać. Kolumny są ponumerowane od $1$&nbsp;do $n$&nbsp;z zachodu na wschód, zaś wiersze - od $1$&nbsp;do $n$&nbsp;z południa na północ.</p>



## 출력


<p>Twój program powinien wypisać na standardowe wyjście dokładnie $y_2 - y_1 + 1$&nbsp;wierszy, a w każdym z nich po $x_2 - x_1 + 1$&nbsp;liczb pooddzielanych pojedynczymi odstępami. Mają one przedstawiać kolejne wiersze wycinka ponumerowanego kwadratu, podane w kolejności od najbardziej wysuniętego na północ do położonego najbardziej na południu.</p>



## 소스코드

[소스코드 보기](Klasy.cpp)