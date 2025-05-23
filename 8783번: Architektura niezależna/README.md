# 8783번: Architektura niezależna - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/8783)


<p>Monika jest artystką - architektem. Każdy z zaprojektowanych przez nią budynków to dzieło sztuki. Monika jest pełna pasji i tworzy jeden projekt za drugim, zawsze jednak realizuje własne pomysły, w ogóle nie projektując budynków na zamówienie.</p>

<p>Jak jednak wiadomo, trzeba z czegoś żyć. Monika postanowiła sprzedawać swoje prace zainteresowanym, nie łamiąc przy tym swoich zasad - jeśli ktoś chce kupić od Moniki projekt, musi liczyć na to, że stworzyła już kiedyś coś, co będzie odpowiadało jego potrzebom.&nbsp;Aby ułatwić przeszukiwanie zbioru projektów pod kątem potrzeb klienta, Monika chciałaby sprawnie obliczyć powierzchnię każdego z zaprojektowanych przez siebie budynków.</p>

<p>Każdy projekt ma postać regularnej siatki na planie kwadratu o wymiarach&nbsp;<strong>N</strong>&nbsp;wierszy na&nbsp;<strong>N</strong>&nbsp;kolumn, zawierającej&nbsp;<strong>N</strong><sup>2</sup>&nbsp;pól, z których każde jest albo wolnym polem, albo ścianą budynku. Wolne pola oznaczamy znakiem kropki ('.'), natomiast ściany budynku znakiem hash ('#') (por. przykład).</p>

<p>Ściany budynku tworzą łamaną zamkniętą bez samoprzecięć - każde pole zawierające ścianę sąsiaduje (od góry, dołu, z prawej lub lewej strony) z dokładnie dwoma polami zawierającymi ściany, które stanowią sąsiadów danego pola na łamanej opisującej kształt budynku.</p>

<p>Znając projekt budynku oblicz jego powierzchnię, tj. łączną liczbę pól stanowiących ścianę budynku oraz wolnych pól wewnątrz budynku.</p>



## 입력


<p>W pierwszej linii znajduje się liczba naturalna&nbsp;<strong>Z</strong>&nbsp;( 1 &lt;=&nbsp;<strong>Z</strong>&nbsp;&lt;= 10 ) opisująca liczbę zestawów testowych. Następnie opisywane są kolejne zestawy.</p>

<p>W pierwszej linii opisu pojedynczego zestawu testowego znajduje się jedna liczba naturalna&nbsp;<strong>N</strong>&nbsp;( 3 &lt;=&nbsp;<strong>N</strong>&nbsp;&lt;= 1000 ) oznaczająca wymiary projektu Moniki. W&nbsp;<strong>N</strong>&nbsp;kolejnych liniach podawany jest opis projektu wg opisanej w treści zadania składni.</p>



## 출력


<p>Dla każdego zestawu testowego należy w osobnej linii wypisać powierzchnię budynku opisywanego przez projekt.</p>



## 소스코드

[소스코드 보기](Architektura%20niezależna.cpp)