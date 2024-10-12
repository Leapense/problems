# 8761번: Metro - <img src="https://static.solved.ac/tier_small/7.svg" style="height:20px" /> Silver IV

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/8761)


<p>W malowniczym szwajcarskim mieście Lozanna działa nowoczesne metro. Jednym z przykładów ciekawego rozwiązania inżynieryjnego jest jednotorowa, a jednak dwukierunkowa&nbsp;<a href="http://en.wikipedia.org/wiki/Lausanne_Metro#Line_M1" target="_blank">linia M1</a>. Pociągi poruszają się w obu kierunkach po pojedynczym torze, mijając się na dwuperonowych stacjach, w których tor rozwidla się na krótką chwilę.</p>

<p>W zadaniu rozważamy linię metra podobną do lozańskiego M1. Rozważana linia składa się z&nbsp;<strong>N</strong>&nbsp;stacji połączonych pojedynczym torem: pierwsza stacja połączona jest z drugą, druga z pierwszą i trzecią, trzecia z drugą i czwartą, itd. Zakładamy, że odległości pomiędzy stacjami są równe i przejazd pociągu pomiędzy sąsiednimi stacjami zawsze trwa dokładnie jedną minutę.</p>

<p>Niektóre spośród stacji są dwuperonowe - na takiej stacji mogą bezkolizyjnie spotkać się dwa pociągi jadące w przeciwne strony. Pozostałe stacje są jednoperonowe i ew. spotkanie pociągów na takiej stacji byłoby zdarzeniem wyjątkowo niefortunnym (szczególnie dla maszynistów i pasażerów tych pociągów).</p>

<p>Z dwóch końców linii w przeciwnych kierunkach jednocześnie odjeżdżają dwa pociągi. Twoim zadaniem jest wyznaczenie pociągom dodatkowych postojów (dowolnej długości wyrażonej w całkowitej nieujemnej liczbie minut) na dowolnej liczbie stacji tak, aby ich spotkanie wypadło na stacji dwuperonowej (pociągi mogą jednocześnie z dwóch stron wjechać na taką stację, możliwe jest także, że jeden z pociągów będzie oczekiwał na drugi na takiej stacji).</p>

<p>Jaki jest minimalny czas jazdy pociągów przy którym nie dochodzi do kolizji? Przez minimalny czas jazdy rozumiemy minimalny czas po którym oba pociągi, całe, niezderzone i niewykolejone zakończą jazdę na przeciwległych końcach toru. W przypadku, w którym jeden z pociągów kończy jazdę wcześniej, wynikiem jest czas jazdy drugiego pociągu.</p>



## 입력


<p>W pierwszej linii znajduje się liczba naturalna&nbsp;<strong>Z</strong>&nbsp;( 1 &lt;=&nbsp;<strong>Z</strong>&nbsp;&lt;= 10 ) oznaczająca liczbę zestawów testowych. Następnie opisywane są kolejne zestawy.</p>

<p>Opis pojedynczego zestawu testowego składa się z dwóch linii. W pierwszej linii znajduje się pojedyncza dodatnia liczba całkowita&nbsp;<strong>N</strong>&nbsp;oznaczająca liczbę stacji metra na linii (2 &lt;=&nbsp;<strong>N</strong>&nbsp;&lt;= 1000000). W drugiej linii znajduje się&nbsp;<strong>N</strong>&nbsp;dodatnich liczb całkowitych&nbsp;<strong>s<sub>i</sub></strong>&nbsp;oddzielonych pojedynczymi spacjami, które odpowiadają kolejnym stacjom. Każda z nich jest równa 1 lub 2 i oznacza liczbę peronów na&nbsp;<strong>i</strong>-tej stacji metra. Co najmniej jedna stacja będzie miała dwa perony.</p>



## 출력


<p>Dla każdego zestawu testowego należy w osobnej linii wypisać minimalny czas bezkolizyjnego przejazdu pociągów. Kolejność wypisywanych odpowiedzi musi odpowiadać kolejności zestawów na wejściu.</p>



## 소스코드

[소스코드 보기](Metro.cpp)