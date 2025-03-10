# 8627번: Żabka Bajtozja - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/8627)


<p>Żabka Bajtozja siedzi sobie na jednym z kamieni wystających ponad powierzchnię stawu i chce wskoczyć do wody. Jednak nie jest jej obojętne, w jakim miejscu to uczyni. Otóż chciałaby zanurzyć się możliwie jak najdalej od miejsca, w którym się w tym momencie znajduje.</p>

<p>Żabka jest jednak świadoma, że długość skoku, jaki może wykonać, jest ograniczona. Tak więc największa odległość, w jakiej mogłaby wskoczyć wody, byłaby równa właśnie długości jej najdłuższego skoku, gdyby nie wystające z wody kamienie. Bajtozja wpadła na pomysł, że może skakać po kamieniach, w ten sposób oddalić się i wskoczyć do wody w miejscu bardziej oddalonym od swojej początkowej pozycji. Pomóż jej i napisz program, który policzy, jak daleko od swojego aktualnego położenia żabka może się zanurzyć.</p>

<p>Napisz program, który:</p>

<ul>
<li>wczyta ze standardowego wejścia opis położeń kamieni wystających ponad powierzchnię wody, umiejscowienie kamienia, na którym siedzi Bajtozja oraz długość maksymalnego skoku, jaki jest ona w stanie wykonać,</li>
<li>wyznaczy największą odległość, jaką żabka może przebyć z miejsca, w którym aktualnie siedzi, do miejsca, w którym zanurzy się pod wodę,</li>
<li>wypisze wynik na standardowe wyjście.</li>
</ul>



## 입력


<p>W pierwszym wierszu wejścia znajdują się trzy liczby całkowite $n$, $p$&nbsp;oraz $s$&nbsp;($1 ≤ n ≤ 1\,000$, $1 ≤ p ≤ n$, $1 ≤ s ≤ 1\,000\,000\,000$), pooddzielane pojedynczymi odstępami i oznaczające odpowiednio: liczbę kamieni wystających ze stawu, numer kamienia, na którym siedzi Bajtozja oraz maksymalną długość skoku, jaki może ona wykonać, podaną w bajtymetrach.</p>

<p>W każdym z kolejnych $n$&nbsp;wierszy znajdują się dwie liczby całkowite $x_i$&nbsp;oraz $y_i$&nbsp;($-1\,000\,000\,000 ≤ x_i, y_i ≤ 1\,000\,000\,000$&nbsp;dla $1 ≤ i ≤ n$), oddzielone pojedynczym odstępem i oznaczające współrzędne w bajtymetrach $i$-tego wystającego ze stawu kamienia.</p>



## 출력


<p>Twój program powinien wypisać w pierwszym i jedynym wierszu wyjścia jedną liczbę, oznaczającą maksymalną odległość w bajtymetrach miejsca, w którym Bajtozja może się zanurzyć, od miejsca, w którym początkowo siedzi. Odległość tę należy wypisać z trzema cyframi po przecinku. Wypisana wartość może się różnić od dokładnej o co najwyżej $0.001$.</p>



## 소스코드

[소스코드 보기](Żabka%20Bajtozja.cpp)