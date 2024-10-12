# 8582번: Park - <img src="https://static.solved.ac/tier_small/6.svg" style="height:20px" /> Silver V

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/8582)


<p>Bajtocki Park Narodowy słynie z długiego (choć niezbyt szerokiego) pasma górskiego, rozciągającego się przez cały park z zachodu na wschód. Co roku przyjeżdżają do niego tłumy turystów, którzy często nie są zbyt rozgarnięci. Dlatego zarząd parku postanowił przygotować mapę całego pasma, podzieloną na fragmenty równej długości. Przy każdym punkcie podziału zarząd zamierza umieścić wysokość tego punktu oraz dwie inne liczby: wysokość najwyższego punktu podziału na zachód od niego oraz na wschód od niego.</p>

<p>Cała mapa jest już właściwie gotowa. Pozostaje jedynie obliczyć maksymalne wysokości na zachód i na wschód od każdego punktu podziału. Zarząd parku poprosił Cię o napisanie programu, który wyznaczy te wartości.</p>



## 입력


<p>W pierwszym wierszu standardowego wejścia znajduje się jedna liczba całkowita $n$&nbsp;($1 ≤ n ≤ 1\,000\,000$) oznaczająca długość pasma górskiego. W każdym z następnych $n$&nbsp;wierszy znajduje się po jednej liczbie całkowitej $w_i$&nbsp;($1≤ w_i ≤ 1\,000\,000\,000$) oznaczającej wysokość $i$-tego punktu podziału. Punkty te podane są w kolejności z zachodu na wschód.</p>



## 출력


<p>Twój program powinien wypisać na standardowe wyjście dokładnie $n$&nbsp;wierszy, odpowiadających kolejnym punktom podziału (w kolejności z zachodu na wschód). W każdym z tych wierszy powinny znaleźć się dwie liczby całkowite $a_i$&nbsp;oraz $b_i$&nbsp;oddzielone pojedynczym odstępem - wysokość najwyższego punktu podziału na zachód od punktu $i$&nbsp;oraz na wschód od niego. W przypadku, gdy na zachód od punktu $i$&nbsp;nie ma szczytu wyższego niż $w_i$, przyjmujemy $a_i = w_i$. Podobnie, jeśli na wschód od punktu $i$&nbsp;nie ma szczytu wyższego niż $w_i$, to przyjmujemy $b_i = w_i$.</p>



## 소스코드

[소스코드 보기](Park.cpp)