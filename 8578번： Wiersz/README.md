# 8578번: Wiersz - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/8578)


<p>Bajtłomiej zabrał się za pisanie wierszy. Jest nowatorskim i oryginalnym twórcą. Jego głównym problemem jest dobieranie słów i wersów tak, by się rymowały. Bajtłomiej uznaje za rymujące się takie dwa wersy, które zawierają po tyle samo samogłosek (Za samogłoski uznajemy litery&nbsp;<code>a</code>, <code>e</code>, <code>i</code>, <code>o</code>, <code>u</code>, <code>y</code>), a ich fragmenty złożone z ostatnich $k$&nbsp;liter (z pominięciem odstępów) są takie same. Wersy składające się z mniej niż $k$&nbsp;liter uznaje za zbyt krótkie, by je było traktować jako rymujące się z czymkolwiek.</p>

<p>Twoim zadaniem jest określenie, ile z podanych par wersów rymuje się (zgodnie z definicją Bajtazara).</p>



## 입력


<p>W pierwszym wierszu standardowego wejścia znajdują się dwie liczby, $n$&nbsp;i $k$&nbsp;($1 ≤ n ≤ 1\,000$, $1 ≤ k ≤ 1\,000$), oznaczające liczbę par wersów do sprawdzenia i długość fragmentów końcowych, decydujących o tym, czy słowa mogą się rymować. W kolejnych $2n$&nbsp;wierszach znajdują się pary wersów, z których każdy wers zapisany jest w osobnym wierszu i składa się z małych liter alfabetu angielskiego.</p>

<p>Długość wersu (wliczając odstępy) nigdy nie przekroczy $2\,000$. Możesz założyć, że w przypadkach testowych wartych łącznie co najmniej $80\%$&nbsp;punktów w żadnym wersie nie pojawią się odstępy.</p>



## 출력


<p>Na standardowe wyjście wypisz liczbę rymujących się par wersów.</p>



## 소스코드

[소스코드 보기](Wiersz.cpp)