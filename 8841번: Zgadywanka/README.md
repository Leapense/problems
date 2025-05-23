# 8841번: Zgadywanka - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/8841)


<p>Hektor lubi opiekować się swoją młodszą siostrą Kornelią - nigdy nie brakuje im pomysłów na zabawy. Dzisiaj grają w zgadywankę.</p>

<p>Do zabawy potrzebne jest N kwadratowych pól, ułożonych jedno za drugim. Na początku Kornelia zamalowuje kilka początkowych pól (na przykład pierwsze 5, pierwsze 2 - oczywiście może zamalować wszystkie pola, albo żadne z nich). Kiedy Kornelia skończy zamalowywać pola, przykrywa każde z nich kawałkiem papieru, tak, że nie widać czy zostało zamalowane.</p>

<p>Wtedy przychodzi kolej na Hektora - jego zadaniem jest dowiedzieć się, ile pól zamalowała Kornelia. Hektor może odkrywać wybrane przez siebie pola w kolejnych rundach zgadywanki. W każdej z nich może odkryć (jednocześnie!) co najwyżej K do tej pory zakrytych pól.</p>

<p>Oblicz minimalną liczbę rund, dla której istnieje sposób wybierania odkrywanych pól dający gwarancję ustalenia liczby zamalowanych kwadratów.&nbsp;</p>



## 입력


<p>W pierwszej linii wejścia znajduje się liczba zestawów testowych Z ( 1 &lt;= Z &lt;= 10 ). W kolejnych Z liniach znajdują się po dwie, opisane w treści liczby naturalne N &nbsp;i K ( 1 &lt;= N, K &lt;= 1000000 ).</p>



## 출력


<p>Dla każdego zestawu testowego należy w osobnej lini wypisać opisaną w treści minimalną liczbę rund dającą gwarancję sukcesu.</p>



## 소스코드

[소스코드 보기](Zgadywanka.cpp)