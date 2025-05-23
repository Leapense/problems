# 8607번: Naszyjniki - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/8607)


<p>Pasją małej Małgosi jest zbieranie naszyjników złożonych z różnorodnych koralików. Jej kolekcja jest już na tyle duża, że postanowiła ją opisać. Każdy naszyjnik został zapisany jako ciąg liter alfabetu angielskiego. Kolejnym literom odpowiadają kolejne koraliki naszyjnika, przy czym pierwszy i ostatni koralik sąsiadują ze sobą.</p>

<p>Małgosia dzieli koraliki na małe i duże oraz na jasne i ciemne. Przy zapisywaniu małych koralików korzystała z małych liter alfabetu, natomiast przy zapisywaniu dużych koralików używała liter wielkich. Do oznaczania koralików jasnych używała samogłosek (czyli liter&nbsp;<i>a, e, i, o, u, y</i>), natomiast do ciemnych - spółgłosek.</p>

<p>Dziewczynka zamierza podzielić każdy ze swoich naszyjników na najmniejszą możliwą liczbę segmentów (czyli kawałków naszyjnika złożonych z kolejnych koralików), z których każdy ma się składać z koralików o tej samej wielkości i o tym samym odcieniu. Zastanawia się, jak w prosty sposób, mając dany jedynie opis naszyjnika, dowiedzieć się, jaki jest jego najdłuższy i najkrótszy segment. Może się co prawda zdarzyć, że jeden naszyjnik będzie zawierać kilka segmentów o minimalnej bądź maksymalnej długości, jednak w takim wypadku dziewczynkę interesuje zawsze segment złożony z większych koralików, bądź z koralików jaśniejszych, jeżeli rozmiar koralików w "remisowych" segmentach jest taki sam.</p>

<p>Pomóż Małgosi rozwiązać ten problem! Dla danych naszyjników określ długości segmentów interesujących Małgosię oraz charakterystykę składających się na nie koralików.</p>



## 입력


<p>W pierwszym wierszu standardowego wejścia znajduje się jedna liczba całkowita $n$&nbsp;($1 ≤ n ≤ 20$) oznaczająca liczbę naszyjników do zbadania. W każdym z kolejnych $n$&nbsp;wierszy znajduje się opis jednego naszyjnika w postaci ciągu małych i wielkich liter alfabetu angielskiego (bez żadnych odstępów).</p>

<p>Sumaryczna długość wszystkich ciągów stanowiących opisy naszyjników w żadnych teście nie przekroczy $1\,000\,000$.</p>



## 출력


<p>Twój program powinien dla każdego wczytanego naszyjnika wypisać na standardowe wyjście dokładnie dwa wiersze, zawierające odpowiednio opis najdłuższego i najkrótszego segmentu tego naszyjnika. W przypadku istnienia kilku segmentów równej długości (minimalnych bądź maksymalnych), należy wypisać informację o segmencie o większych koralikach, jeżeli zaś również rozmiar koralików w segmentach jest taki sam, to należy wybrać segment jaśniejszy.</p>

<p>Każdy opis segmentu powinien składać się z jednej liczby całkowitej oraz jednego słowa, oddzielonych pojedynczym odstępem, oznaczających odpowiednio liczbę koralików wchodzących w skład segmentu oraz jego rodzaj. Rodzaj segmentu powinien być jednym ze słów:</p>

<ul>
<li><code>jasne</code>, jeśli segment składa się z jasnych, małych koralików,</li>
<li><code>JASNE</code>, jeśli segment składa się z jasnych, dużych koralików,</li>
<li><code>ciemne</code>, jeśli segment składa się z ciemnych, małych koralików,</li>
<li><code>CIEMNE</code>, jeśli segment składa się z ciemnych, dużych koralików.</li>
</ul>



## 소스코드

[소스코드 보기](Naszyjniki.cpp)