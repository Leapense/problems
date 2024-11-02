# 26769번: Deski - <img src="https://static.solved.ac/tier_small/6.svg" style="height:20px" /> Silver V

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/26769)


<p>Bajtek chce zbudować wielką, kwadratową piaskownicę. Do budowy piaskownicy są mu potrzebne zaledwie cztery deski, które muszą być równej długości. Niestety, podczas kupowania desek w tartaku Bajtek zupełnie zapomniał o tym fakcie i kupił N desek o niekoniecznie równych długościach. Bajtek może (ale nie musi) najpierw skrócić posiadane deski, a następnie wybrać cztery kawałki równej długości i zbudować z nich piaskownicę. Zauważ, że deska może jedynie być skracana, a nie dzielona, czyli nie można na przykład z jednej deski o długości 4 otrzymać dwóch desek o długości 2. Bajtek nie lubi ułamków, dlatego wszystkie długości desek są całkowite oraz wszystkie długości skróconych kawałków również muszą być całkowite.</p>

<p>Napisz program, który: wczyta długości desek posiadanych przez Bajtka, wyznaczy pole największej piaskownicy, którą może zbudować i wypisze wynik na standardowe wyjście.</p>



## 입력


<p>W pierwszym wierszu wejścia znajduje się jedna liczba naturalna N (1 ≤ N ≤ 1 000 000), określająca liczbę desek posiadanych przez Bajtka. W drugim (ostatnim) wierszu wejścia znajduje się ciąg N liczb naturalnych L<sub>1</sub>, L<sub>2</sub>,. . . , L<sub>N</sub> (1 ≤ L<sub>i</sub> ≤ 10<sup>9</sup>), pooddzielanych pojedynczymi odstępami. Są to długości desek posiadanych przez Bajtka.</p>



## 출력


<p>W pierwszym (jedynym) wierszu wyjścia powinna się znaleźć jedna liczba całkowita – pole powierzchni największej możliwej do uzyskania kwadratowej piaskownicy zgodnie z warunkami powyżej. Jeśli zbudowanie takiej piaskownicy nie jest możliwe, należy wypisać 0.</p>



## 소스코드

[소스코드 보기](Deski.cpp)