# 8786번: Dalsze kłopoty z ogrodem - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/8786)


<p>W zadaniu&nbsp;<a href="/problem/8847">Kłopoty z ogrodem</a>&nbsp;(FallSpot 2009) mieliśmy okazję poznać pana Wincentego - właściciela ogrodu i wielkiego antymiłośnika grabienia opadłych liści.</p>

<p>Od czasu ostatnich kłopotów minęło już trochę czasu, zmniejszony (por. oryginalne zadanie) ogród nie wymaga już tyle uwagi jesienią. Niestety, wraz z nadejściem tegorocznej wiosny pojawiły się nowe problemy - w ogrodzie zaczęły plenić się chwasty, doprowadzając pana Wincentego do szaleństwa (świadkowie twierdzą, że widzieli pana Wincentego nucącego słowa&nbsp;<em>Chwasty chwaściki chwaściory chwaścięta - cała to roślinność wiecznie nie przycięta!&nbsp;</em>na melodię jednej z symfonii Beethovena). Pewnego dnia pan Wincenty po długich godzinach spędzonych w warsztacie stanął w ogrodzie z przenośnym miotaczem płomieni w rękach.</p>

<p>Ogród pana Wincentego składa się z&nbsp;<strong>N</strong>&nbsp;pól ponumerowanych od 1 do&nbsp;<strong>N</strong>. W każdym polu znajduje się liczba chwastów wyrażona liczbą całkowitą&nbsp;<strong>c</strong><sub>i</sub>. Jednokrotne użycie miotacza płomieni na polu&nbsp;<strong>i</strong>&nbsp;powoduje zmniejszenie o połowę liczby chwastów w polu&nbsp;<strong>i&nbsp;</strong>oraz w sąsiednich polach&nbsp;<strong>i</strong>-1 oraz&nbsp;<strong>i</strong>+1.&nbsp;</p>

<p>Przez zmniejszenie o połowę rozumiemy dzielenie całkowite przez 2, tj. z 8 chwastów zostają 4, z 5 zostają 2. Jako cel miotacza płomieni można wybrać także nieistniejące pola 0 i&nbsp;<strong>N</strong>+1, wtedy jedyne redukowane pola to - odpowiednio - 1 i&nbsp;<strong>N</strong>.</p>

<p>Oblicz ile minimalnie razy pan Wincenty musi skorzystać z miotacza ognia, aby usunąć wszystkie chwasty.</p>



## 입력


<p>W pierwszej linii wejścia znajduje się liczba naturalna&nbsp;<strong>Z</strong>&nbsp;( 1 &lt;=&nbsp;<strong>Z</strong>&nbsp;&lt;= 10 ) opisująca liczbę zestawów testowych. Następnie opisywane są kolejne zestawy.</p>

<p>Pierwsza linia opisu zestawu testowego zawiera jedną liczbę naturalną&nbsp;<strong>N</strong>&nbsp;( 1 &lt;=&nbsp;<strong>N</strong>&nbsp;&lt;= 1000000) oznaczającą liczbę pól w ogrodzie pana Wincentego.&nbsp;</p>

<p>W drugiej linii opisu zestawu znajduje się N oddzielonych spacjami liczb naturalnych&nbsp;<strong>c<sub>i</sub></strong>&nbsp;oznaczających liczbę chwastów w poszczególnych polach ogrodu ( 0 &lt;=&nbsp;<strong>c<sub>i</sub></strong>&nbsp;&lt;= 1000000 ).</p>



## 출력


<p>Dla każdego testu należy w osobnej linii wypisać ile minimalnie razy pan Wincenty będzie musiał użyć miotacza płomieni.</p>



## 소스코드

[소스코드 보기](Dalsze%20kłopoty%20z%20ogrodem.cpp)