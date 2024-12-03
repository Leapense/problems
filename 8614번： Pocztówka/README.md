# 8614번: Pocztówka - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/8614)


<p>W czasie ferii zimowych w górach Wojtek kupił ogromną pocztówkę z panoramą gór. Po powrocie do domu oprawił ją w ramkę i powiesił na ścianie, aby móc ją codziennie podziwiać. Jednak po kilku tygodniach znudził się widokiem z pocztówki.</p>

<p>Pamiątka z gór już miała powędrować na strych, kiedy Wojtek wpadł na genialny pomysł, aby odciąć kilka gór z lewej strony i kilka z prawej i otrzymać nową, ciekawszą panoramę. Jednak gdyby odciął za dużo, nowy widok mógłby być mało efektowny. Aby temu zapobiec, Wojtek chciałby zostawić na pocztówce co najmniej jedną górę o wysokości nie mniejszej niż $m$.</p>

<p>Teraz Wojtek musi wybrać najładniejszą z możliwych kompozycji. Jednak nie wie jeszcze, jak trudne jest to zadanie - aby go o tym przekonać, policz, na ile sposobów może otrzymać nową, ciekawszą panoramę. W szczególności powinieneś uwzględnić, że Wojtek może się rozmyślić i pozostawić pocztówkę w stanie niezmienionym, o ile tylko zawiera ona górę wysokości co najmniej $m$.</p>



## 입력


<p>W pierwszym wierszu standardowego wejścia znajdują się dwie liczby całkowite $n$&nbsp;i $m$&nbsp;($1 ≤ n ≤ 1\,000\,000$, $1 ≤ m ≤ 1\,000\,000\,000$), oddzielone pojedynczym odstępem i oznaczające odpowiednio liczbę gór na pocztówce i minimalną wysokość góry, która czyni panoramę efektowną. Drugi wiersz zawiera $n$&nbsp;liczb całkowitych $h_i$&nbsp;($1 ≤ h_i ≤ 1\,000\,000\,000$, $h_i \ne h_j$&nbsp;dla $i \ne j$), pooddzielanych pojedynczymi odstępami. Są to wysokości gór w kolejności od lewej do prawej.</p>



## 출력


<p>Na standardowe wyjście Twój program powinien wypisać dokładnie jedną liczbę całkowitą - liczbę wszystkich kompozycji, które spełniają podane warunki.</p>



## 소스코드

[소스코드 보기](Pocztówka.cpp)