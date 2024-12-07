# 8847번: Kłopoty z ogrodem - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/8847)


<p>Pan Wincenty bardzo lubi swój ogród, niestety - bardzo nie lubi w nim pracować. A już szczególnie nie lubi grabić opadłych (jak to jesienią) liści. Po kilku latach (i - co za tym idzie - kilku spędzonych na grabieniu liści jesieniach) pan Wincenty uznał, że miarka się przebrała - jego ogród jest po prostu za duży. Postanowił więc oddać część swojego terenu sąsiadom (i niech oni już sobie grabią liście).</p>

<p>Ogród pana Wincentego jest dość nietypowy - ma (ogród, nie pan Wincenty) kształt prostokąta o wymiarach 1 na N i dzieli się na N kolejnych pól o wymiarach 1 na 1.&nbsp; W każdym z tych pól rośnie albo trawa, albo drzewo kasztanowe. Pan Wincenty chce pozostawić sobie jak największą część ogrodu, z zachowaniem następujących zastrzeżeń:</p>

<ul>
<li>W pozostawionej części ogrodu musi być co najwyżej K drzew kasztanowych</li>
<li>Pozostawiona część ogrodu musi być spójna, to znaczy stanowić ciąg kolejnych pól</li>
</ul>

<p>Jaka jest maksymalna długość fragmentu ogrodu, który pan Wincenty może sobie pozostawić?</p>



## 입력


<p>W pierwszej linii wejścia podana jest liczba testów L (L &lt;= 5). Następnie podawane są opisy poszczególnych testów.</p>

<p>Jeden test składa się z dwóch linii - w pierwszej znajdują się opisane w treści liczby naturalne N i K (0 &lt; K &lt;= N &lt;= 1000000).</p>

<p>W drugiej znajduje się opis ogrodu pana Wincentego - ciąg znaków długości N. Każdy znak ciągu to 'K' lub 'T', w zależności od tego, czy w danym polu rośnie kasztanowiec, czy tylko trawa.</p>



## 출력


<p>Dla każdego testu w osobnej linii wypisz maksymalną długość fragmentu ogrodu, jaki pan Wincent może sobie pozostawić.</p>



## 소스코드

[소스코드 보기](Kłopoty%20z%20ogrodem.cpp)