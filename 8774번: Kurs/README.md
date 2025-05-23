# 8774번: Kurs - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/8774)


<p>Hektor zainteresował się niedawno grą na giełdzie - świat akcji, obligacji, kursów i dywidend jest skomplikowany i pełen liczb, co czyni z niego idealnego kandydata na nowe hobby naszego bohatera.</p>

<p>Hektor dysponuje historią notowań pewnej spółki w postaci listy liczb naturalnych opisujących wartość kursu spółki na kolejnych notowaniach. Dla każdego notowania na liście Hektor chciałby obliczyć, kiedy (licząc od momentu rozważanego notowania) kurs spółki po raz pierwszy przekroczył kurs z tego dnia (tj. formalnie: dla każdej pozycji&nbsp;<strong>x</strong>&nbsp;na liście Hektor chciałby znać najmniejsze&nbsp;<strong>y</strong>, które jest większe od&nbsp;<strong>x</strong>&nbsp;i jednocześnie takie, że kurs na pozycji&nbsp;<strong>y</strong>&nbsp;był większy od kursu na pozycji&nbsp;<strong>x</strong>).</p>

<p>Czy potrafisz przygotować program, który będzie realizował takie obliczenia?</p>



## 입력


<p>W pierwszej linii wejścia znajduje się liczba naturalna&nbsp;<strong>Z</strong>&nbsp;( 1 &lt;=&nbsp;<strong>Z</strong>&nbsp;&lt;= 10 ) opisująca liczbę zestawów testowych. Następnie opisywane są kolejne zestawy.</p>

<p>Pierwsza linia opisu zestawu testowego zawiera liczbę naturalną&nbsp;<strong>N</strong>&nbsp;( 1 &lt;=&nbsp;<strong>N</strong>&nbsp;&lt;= 1000000), oznaczającą długość listy Hektora.</p>

<p>W drugiej linii opisu zestawu znajduje się&nbsp;<strong>N</strong>&nbsp;oddzielonych spacjami liczb naturalnych&nbsp;<strong>k</strong><strong><sub>i</sub></strong>&nbsp;( 1 &lt;=&nbsp;<strong>k</strong><strong><sub>i</sub>&nbsp;</strong>&lt;= 1000000000)&nbsp;oznaczających wysokość kursu spółki na kolejnych notowaniach.</p>



## 출력


<p>Dla każdego testu należy w osobnej linii wypisać&nbsp;<strong>N</strong>&nbsp;oddzielonych spacjami liczb całkowitych odpowiadających wpisom na liście Hektora. Dla pozycji, dla których istnieje dalsze notowanie o wyższym kursie, należy wypisać numer pierwszego takiego notowania; przy czym kolejne notowania na liście numerujemy od 0. Dla pozostałych pozycji należy wypisać liczbę -1.</p>



## 소스코드

[소스코드 보기](Kurs.cpp)