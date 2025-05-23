# 8810번: Studnia - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/8810)


<p>Pan Michał chce wykopać nową studnię. Dysponuje planem terenu swojej działki, na którym przedstawione są dwa zarysy: powierzchni gruntu oraz początku warstwy wodonośnej, które mają kształt linii łamanych. Pan Michał wynajął już specjalne wiertło, które może wiercić jedynie w pionie. Koszty wiercenia są całkiem spore, nic dziwnego więc, że zastanawia się, na jaką głębokość co najmniej musi wykonać odwiert, by dotrzeć z powierzchni do warstwy wodonośnej.</p>



## 입력


<p>W pierwszej linii znajduje się jedna liczba naturalna&nbsp;<strong>Z</strong>&nbsp;( 1 &lt;=&nbsp;<strong>Z</strong>&nbsp;&lt;= 5 ) oznaczająca liczbę zestawów testowych. Następnie opisywane są kolejne zestawy.</p>

<p>W pierwszej linii znajduje się jedna liczba naturalna&nbsp;<strong>n&nbsp;</strong>( 2 &lt;=&nbsp;<strong>n</strong>&nbsp;&lt;= 100 000 ), oznaczająca liczbę punktów łamanej opisującej powierzchnię gruntu na działce pana Michała. W drugim wierszu występuje&nbsp;<strong>n</strong>&nbsp;par liczb naturalnych&nbsp;<strong>x<sub>i</sub></strong>,&nbsp;<strong>y<sub>i</sub></strong>&nbsp;( 1 &lt;=&nbsp;<strong>x<sub>i</sub></strong>,&nbsp;<strong>y<sub>i</sub></strong>&nbsp;&lt;= 10<sup>9</sup>&nbsp;), pooddzielanych pojedynczymi odstępami. Dla każdego 1 &lt;=&nbsp;<strong>i&nbsp;</strong>&lt;&nbsp;<strong>n&nbsp;</strong>zachodzi:&nbsp;<strong>x</strong><sub><strong>i</strong>&nbsp;</sub>&lt;&nbsp;<strong>x<sub>i+1</sub></strong>.</p>

<p>W kolejnych dwóch liniach znajduje się analogiczny opis łamanej opisującej początek warstwy wodonośnej pod działką pana Michała. W pierwszej z nich znajduje się liczba naturalna&nbsp;<strong>m&nbsp;</strong>( 2 &lt;=&nbsp;<strong>m&nbsp;</strong>&lt;<strong>&nbsp;n+m</strong>&nbsp;&lt;= 100 000 ), oznaczająca liczbę punktów, a w drugiej z linii jest&nbsp;<strong>m</strong>&nbsp;par liczb naturalnych&nbsp;<strong>u<sub>i</sub></strong>,&nbsp;<strong>v<sub>i</sub></strong>&nbsp;( 1 &lt;=&nbsp;<strong>u<sub>i</sub></strong>,&nbsp;<strong>v<sub>i</sub></strong>&nbsp;&lt;= 10<sup>9</sup>&nbsp;), pooddzielanych pojedynczymi odstępami. Dla każdego 1 &lt;=&nbsp;<strong>i&nbsp;</strong>&lt;&nbsp;<strong>m&nbsp;</strong>zachodzi:&nbsp;<strong>u</strong><sub><strong>i</strong>&nbsp;</sub>&lt;&nbsp;<strong>u<sub>i+1</sub></strong>.</p>

<p>Warstwa wodonośna znajduje się w całości pod powierzchnią gruntu ( te dwie łamane nie mają punktów wspólnych ). Ponadto zachodzą równości:&nbsp;<strong>x<sub>1</sub></strong>&nbsp;=&nbsp;<strong>u<sub>1</sub></strong>&nbsp;oraz&nbsp;<strong>x<sub>n</sub></strong>&nbsp;=&nbsp;<strong>u<sub>m</sub></strong>.</p>



## 출력


<p>Dla każdego zestawu testowego w osobnej linii należy wypisać jedną liczbę rzeczywistą dodatnią - minimalną głębokość dzielącą powierzchnię od warstwy wodonośnej. Wartość tę należy zaokrąglić do dokładnie dwóch miejsc po przecinku.</p>



## 소스코드

[소스코드 보기](Studnia.cpp)