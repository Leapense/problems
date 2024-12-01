# 8600번: Pociąg - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/8600)


<p>Na pewną bajtocką wyspę co roku trafia duży transport surowców. Dostarczane są one do portu, skąd dalej rozwożone są pociągiem do wszystkich miast na całej wyspie. Miasta znajdują się tylko przy brzegu i są ponumerowane kolejno od $1$&nbsp;do $n$. Trasa pociągu prowadzi wokół całej wyspy przez wszystkie miasta.</p>

<p>Pociąg składa się z lokomotywy ciągnącej pewną liczbę wagonów. W każdym wagonie przewożony jest inny rodzaj surowca. Ponadto, do każdego miasta dostarczany jest inny surowiec. Wagonów jest dokładnie tyle co miast. Dotychczas wagony były zawsze tak ustawiane, że pociąg w każdym mieście odczepiał ostatni wagon i ruszał do następnego miasta. W ten sposób wykonywał tylko jedno okrążenie. Niestety tym razem surowce zostały źle oznaczone i pomylono kolejność ustawienia wagonów.</p>

<p>Maszynista zastanawia się, ile minimalnie okrążeń będzie musiał wykonać, aby rozwieźć wszystkie surowce do odpowiednich miast, wiedząc, że może zawsze odczepiać tylko ostatni wagon oraz nie może doczepiać już odczepionych. Stacją początkową i końcową jest miasto numer 1, w którym również znajduje się port. Nowe okrążenie liczone jest wtedy, gdy pociąg wyruszy do miasta numer 2.</p>



## 입력


<p>W pierwszym wierszu standardowego wejścia znajduje się jedna liczba całkowita $n$&nbsp;($2 ≤ n ≤ 1\,000\,000$), oznaczająca liczbę miast położonych na wyspie. W kolejnym wierszu znajduje się $n$&nbsp;liczb całkowitych $w_1, w_2, \dots , w_n$&nbsp;($1 ≤ w_i ≤ 1\,000\,000$, $w_i \ne w_j$&nbsp;dla $i \ne j$), przy czym $w_i$&nbsp;oznacza rodzaj surowca znajdującego się w $i$-tym wagonie od lokomotywy. W kolejnym wierszu znajduje się $n$&nbsp;parami różnych liczb całkowitych $m_1, m_2, \dots , m_n$, oznaczających surowce zamawiane przez miasta o numerach $1, 2, \dots , n$. Liczby w drugim i trzecim wierszu są pooddzielane pojedynczymi odstępami. Można założyć, że zbiory liczb $w_i$&nbsp;oraz $m_i$&nbsp;są takie same, tzn. $\{w_1, w_2, \dots , w_n\} = \{m_1, m_2, \dots , m_n\}$.</p>



## 출력


<p>W pierwszym i jedynym wierszu standardowego wyjścia powinna znaleźć się jedna liczba całkowita oznaczająca minimalną liczbę okrążeń, które pozwolą rozwieźć wszystkie surowce do odpowiednich miast.</p>



## 소스코드

[소스코드 보기](Pociąg.cpp)