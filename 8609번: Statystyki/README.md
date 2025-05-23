# 8609번: Statystyki - <img src="https://static.solved.ac/tier_small/7.svg" style="height:20px" /> Silver IV

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/8609)


<p>W Bajtocji od niedawna wydawana jest nowa gazeta&nbsp;<i>BajtNews</i>. O dziwo, mieszkańcy Bajtocji wcale nie interesują się treścią publikowanych w niej artykułów, a jedynie statystykami, które ich dotyczą. Niektórzy z nich stali się już tak leniwi, że nie chcą sami tworzyć statystyk, dlatego poprosili Ciebie o napisanie programu, który będzie przygotowywał je automatycznie.</p>

<p>Bajtocjanie chcą znać liczby wystąpień następujących obiektów w artykułach:</p>

<ol>
<li><b>spacji</b>, czyli pojedynczych odstępów;</li>
<li><b>liczb</b>, czyli ciągłych (tzn. jednokawałkowych) fragmentów tekstu złożonych z cyfr (<code>0</code>&nbsp;-&nbsp;<code>9</code>), sąsiadujących z każdej strony ze znakiem niebędącym cyfrą lub z początkiem lub końcem tekstu;</li>
<li><b>słów</b>, czyli ciągłych fragmentów złożonych z małych (<code>a</code>&nbsp;-&nbsp;<code>z</code>) lub wielkich (<code>A</code>&nbsp;-&nbsp;<code>Z</code>) liter alfabetu angielskiego, sąsiadujących z każdej strony ze znakiem niebędącym literą lub z początkiem lub końcem tekstu;</li>
<li><b>zdań</b>, czyli spójnych fragmentów tekstu zakończonych kropką (i niezawierających innych kropek w środku), zawierających co najmniej jedno słowo; każde zdanie sąsiaduje z lewej strony albo z kropką, albo z początkiem tekstu;</li>
<li><b>palindromów</b>, czyli słów symetrycznych - takich słów (gdzie słowo jest rozumiane w sensie punktu trzeciego), które czytane wprost i wspak mogą się różnić co najwyżej wielkością liter, np.&nbsp;<code>Abba</code>.</li>
</ol>

<p>Napisz program, który:</p>

<ul>
<li>wczyta ze standardowego wejścia artykuł oraz spis rodzajów obiektów, które mają zostać przeanalizowane,</li>
<li>wyznaczy żądane statystyki,</li>
<li>wypisze wynik na standardowe wyjście.</li>
</ul>



## 입력


<p>W pierwszym wierszu wejścia znajduje się jedna liczba całkowita $n$&nbsp;($1 ≤ n ≤ 5$) oznaczająca liczbę żądanych rodzajów statystyk. W drugim wierszu znajduje się $n$&nbsp;liczb całkowitych $a_i$&nbsp;($1 ≤ a_i ≤ 5$), pooddzielanych pojedynczymi odstępami i oznaczających numery typów obiektów, które należy zliczyć. Numery odpowiadają kolejności, w jakiej różne rodzaje obiektów zostały opisane powyżej (np. $a_i = 3$&nbsp;oznacza żądanie zliczenia słów w tekście). Możesz założyć, że liczby $a_i$&nbsp;są parami różne.</p>

<p>Trzeci wiersz wejścia zawiera całą treść artykułu. Może się ona składać z następujących znaków:</p>

<ul>
<li>cyfr:&nbsp;<code>0</code>&nbsp;-&nbsp;<code>9</code>;</li>
<li>liter:&nbsp;<code>a</code>&nbsp;-&nbsp;<code>z</code>&nbsp;oraz&nbsp;<code>A</code>&nbsp;-&nbsp;<code>Z</code>;</li>
<li>odstępów (spacji) oraz tabulacji;</li>
<li>znaków interpunkcyjnych: '<code>,</code>' (przecinek), '<code>.</code>' (kropka), '<code>!</code>' (wykrzyknik), '<code>?</code>' (pytajnik).</li>
</ul>

<p>Liczba znaków w treści artykułu nie przekroczy $1\,000\,000$. Możesz również założyć, że:</p>

<ul>
<li>w co najmniej 20% przypadków testowych należy zliczać tylko statystyki pierwszego rodzaju (spacje),</li>
<li>w co najmniej 40% przypadków testowych należy zliczać tylko statystyki pierwszego oraz drugiego rodzaju (spacje i liczby),</li>
<li>w co najmniej 60% przypadków testowych należy zliczać tylko statystyki rodzajów od 1 do 3 (spacje, liczby i słowa),</li>
<li>w co najmniej 80% przypadków testowych należy zliczać tylko statystyki rodzajów od 1 do 4 (spacje, liczby, słowa oraz zdania).</li>
</ul>



## 출력


<p>W pierwszym i jedynym wierszu wyjścia Twój program powinien wypisać $n$&nbsp;liczb całkowitych pooddzielanych pojedynczymi odstępami, oznaczających kolejne żądane rodzaje statystyk.</p>



## 소스코드

[소스코드 보기](Statystyki.cpp)