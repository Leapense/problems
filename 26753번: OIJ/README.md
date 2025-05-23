# 26753번: OIJ - <img src="https://static.solved.ac/tier_small/6.svg" style="height:20px" /> Silver V

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/26753)


<p>Szkoła Bajtka i Bitosi organizuje wielki festyn z okazji rozpoczęcia Olimpiady Informatycznej Juniorów. W ramach przygotowań, rodzeństwo podjęło się sporządzenia jak największej liczby transparentów z napisem <code>oij</code> (w Bajtocji używa się wyłącznie małych liter alfabetu angielskiego).</p>

<p>W piwnicy swojego domu Bajtek i Bitosia znaleźli stary, wielki i bardzo starannie wykonany transparent, pochodzący z czasów młodości ich rodziców, zawierający długi napis w dziwnym języku (rodzice nie chcą niestety przyznać się, do czego im służył). Bajtek zauważył, że można spróbować zamalować na transparencie niektóre znaki tak, aby pozostały tylko trzy literki: <code>o</code>, <code>i</code> oraz <code>j</code>, w tej kolejności. Bitosia jeszcze poprawiła ten plan – transparent zostanie najpierw pocięty na kilka fragmentów tak, aby z każdego z nich dało się uzyskać napis <code>oij</code> metodą Bajtka.</p>

<p>Na przykład, transparent głoszący <code>koligacjeomijaj</code> można podzielić na dwa takie kawałki:</p>

<p style="text-align: center;"><code>koligacjeomijaj</code> → <code>koligacje|omijaj</code> → <code>▪️o▪️i▪️▪️▪️j▪️|o▪️ij▪️▪️</code>.</p>

<p>Na ile najwięcej fragmentów można podzielić napis na starym transparencie, aby z każdego dało się uzyskać <code>oij</code>?</p>



## 입력


<p>W pierwszym (jedynym) wierszu wejścia znajduje się napis – ciąg małych liter alfabetu angielskiego, długości co najmniej 1 i co najwyżej 1 000 000.</p>



## 출력


<p>W pierwszym (jedynym) wierszu wyjścia należy wypisać jedną liczbę całkowitą – największą liczbę fragmentów, na jakie można podzielić napis z wejścia.</p>

<p>Jeśli taki podział jest w ogóle niemożliwy, zamiast tego należy wypisać tylko jedno słowo <code>NIE</code>.</p>



## 소스코드

[소스코드 보기](OIJ.cpp)