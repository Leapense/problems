# 26762번: Pionki - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/26762)


<p>Bajtek gra w Pionki, prostą grę planszową dla jednego gracza. Na niektórych polach szachownicy o wymiarach N × M stoją pionki, na każdym polu co najwyżej jeden. W jednym ruchu można przesunąć pionek o dowolną liczbę pól w pionie lub poziomie, być może przeskakując inne pionki lub wskakując na pole, na którym stoją już jakieś pionki. Celem gry jest sprawić, aby wszystkie pionki stanęły na tym samym polu, wykonując przy tym jak najmniejszą liczbę ruchów.</p>

<p>Bajtek zastanawia się, czy gra w tę grę optymalnie. Pomóż mu i napisz program, który wczyta sytuację początkową na planszy i wyznaczy minimalną liczbę ruchów prowadzących do osiągnięcia celu.</p>



## 입력


<p>W pierwszym wierszu wejścia znajdują się dwie dodatnie liczby całkowite N i M (1 ≤ N · M ≤ 1 000 000) oddzielone pojedynczym odstępem i określające kolejno: wysokość i szerokość szachownicy. W kolejnych N wierszach znajduje się opis sytuacji początkowej na szachownicy. Każdy z tych wierszy zawiera po M znaków. Znak . (kropka) oznacza, że dane pole jest puste, zaś # (hasz) oznacza, że na tym polu stoi pionek.</p>



## 출력


<p>W pierwszym (jedynym) wierszu wyjścia należy wypisać jedną liczbę całkowitą – minimalną liczbę ruchów potrzebną do sprowadzenia wszystkich pionków na to samo pole.</p>



## 소스코드

[소스코드 보기](Pionki.cpp)