# 26676번: Wybór zadań - <img src="https://static.solved.ac/tier_small/3.svg" style="height:20px" /> Bronze III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/26676)


<p>Przygotowanie rund zdalnych Potyczek Algorytmicznych jest dla Mateusza nie lada wyzwaniem. Podczas konkursu uczestnicy biorą udział w pięciu rundach, numerowanych liczbami od 1 do 5, a w każdej rundzie rozwiązują zadania z trzech dywizji, zwanych A, B i C. Podczas każdej z pierwszych czterech rund w każdej dywizji pojawia się jedno zadanie, a podczas ostatniej, piątej rundy w każdej dywizji pojawiają się po dwa zadania. Należy więc wymyślić i przygotować aż osiemnaście zadań i przypisać je do piętnastu różnych pozycji, przy czym do trzech pozycji (5A, 5B i 5C) trzeba przypisać po dwa zadania. Przez pozycję rozumiemy tu kombinację numeru rundy oraz nazwy dywizji.</p>

<p>Mateusz jest świadomy, że nie można tak po prostu użyć osiemnastu dowolnych zadań. Ich trudność powinna pasować do rundy oraz do dywizji, w której się pojawią. Chłopak przez cały rok zebrał n pomysłów na zadania. Dla każdego z nich wie, na którą pozycję pasowałoby to zadanie (przy czym nie pasowałoby na żadną inną pozycję).</p>

<p>Mateusz zastanawia się więc, czy możliwe jest wybranie osiemnastu spośród jego pomysłów i przypisanie ich do pozycji w poprawny sposób. Mając dostęp do jego notatek, pomóż mu to stwierdzić!</p>



## 입력


<p>W pierwszym wierszu wejścia znajduje się jedna liczba całkowita n (1 ≤ n ≤ 100), oznaczająca liczbę pomysłów Mateusza.</p>

<p>W drugim wierszu znajduje się n słów oznaczających pozycje, na które pasują kolejne zadania Mateusza. Każde z tych słów składa się z dokładnie dwóch znaków i jako pierwszy znak zawiera cyfrę ze zbioru {1, 2, 3, 4, 5}, a jako drugi literę ze zbioru {A, B, C}.</p>



## 출력


<p>Na wyjściu powinno znaleźć się jedno słowo <code>TAK</code> lub <code>NIE</code>, oznaczające czy z pomysłów Mateusza można ułożyć poprawny zestaw zadań na rundy zdalne Potyczek Algorytmicznych.</p>



## 소스코드

[소스코드 보기](Wybór%20zadań.py)