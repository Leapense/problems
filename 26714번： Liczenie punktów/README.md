# 26714번: Liczenie punktów - <img src="https://static.solved.ac/tier_small/3.svg" style="height:20px" /> Bronze III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/26714)


<p>Jury Potyczek Algorytmicznych jest zmęczone ciągłym liczeniem punktów dla wszystkich zgłoszeń. Pomóż im zautomatyzować ten proces.</p>

<p>W każdym zadaniu można zdobyć od 0 do 10 punktów. Do pewnego zadania przygotowane jest n testów, gdzie n jest podzielne przez 10. Jeśli rozwiązanie poprawnie rozwiąże wszystkie spośród pierwszych n/10 testów, dostaje 1 punkt. Jeśli poprawnie rozwiąże kolejne n/10 testów, również dostaje 1 punkt. Za każdą grupę n/10 testów można niezależnie uzyskać 1 punkt, o ile poprawnie rozwiązane zostaną wszystkie testy z tej grupy. Jeśli zrobi się choć jeden błąd w grupie, nie uzyskuje się za tę grupę punktu.</p>

<p>Uwaga: Dla uproszczenia przyjmujemy, że każda grupa testów zawiera tyle samo testów. W rzeczywistym konkursie może to nie być prawdą.</p>

<p>Uwaga2: Każdy kod, który napiszesz, może być użyty przeciwko Tobie.<sup>∗</sup></p>

<hr>
<p><sup>∗</sup>Żarcik kosmonaucik.</p>



## 입력


<p>W pierwszym wierszu standardowego wejścia znajduje się liczba całkowita n (10 ≤ n ≤ 100; n jest podzielne przez 10), oznaczająca liczbę testów.</p>

<p>W drugim wierszu wejścia znajduje się napis złożony z n liter ‘T’ lub ‘N’. Litera ‘T’ oznacza, że dany test został rozwiązany poprawnie. Litera ‘N’ oznacza, że nie został rozwiązany poprawnie.</p>



## 출력


<p>W jedynym wierszu standardowego wyjścia powinna znaleźć się jedna liczba całkowita równa liczbie uzyskanych punktów.</p>



## 소스코드

[소스코드 보기](Liczenie%20punktów.py)