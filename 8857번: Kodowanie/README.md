# 8857번: Kodowanie - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/8857)


<p>Pawła, studenta informatyki na Uniwersytecie Wrocławskim, w ostatnim semestrze bardzo zaciekawiły problemy poruszane na przedmiocie Kompresja danych. Jako zdolny uczeń, Paweł postanowił wymyślić nowy sposób na kompresję sekwencji liczb naturalnych.</p>

<p>Pierwszym krokiem algorytmu Pawła jest zamiana ciągów liczb naturalnych na ciągi liczb zapisanych binarnie. Nie można zrobić tego tak po prostu - trzeba umieć oddzielać kolejne kodowane liczby używając tylko zer i jedynek. W tym celu, Paweł postanowił wykorzystać dwie sąsiednie jedynki jako znacznik końca pojedynczej liczby. Ta metoda pociąga za sobą jednak pewne konsekwencje. Aby móc rozdzielać kolejne elementy ciągu, binarny kod żadnej z liczb nie może zawierać dwóch sąsiednich jedynek, a także musi zaczynać się od jedynki.</p>

<p>Chcąc zbadać skuteczność kompresji, Paweł potrzebuje wiedzieć ile różnych liczb jest w stanie zakodować używając&nbsp;<strong>n</strong>&nbsp;bitów. Niestety, Paweł w obecnym semestrze ma sporo pracy - poprosił więc Ciebie o pomoc. Twoim zadaniem jest napisanie programu, który dla podanej wartości&nbsp;<strong>n</strong>&nbsp;obliczy ile jest różnych, binarnych kodów długości&nbsp;<strong>n</strong>, które zaczynają się od jedynki i nie zawierają dwóch jedynek koło siebie.</p>



## 입력


<p>W pierwszej linii wejścia znajduje się jedna liczba całkowita&nbsp;<strong>T</strong>&nbsp;(1&lt;=<strong>T</strong>&lt;=100), oznaczająca ilość zestawów danych. Następnie na wejściu podane są opisy kolejnych zestawów danych. Pojedynczy zestaw danych składa się z jednej linii. Znajduje się w niej jedna liczba całkowita&nbsp;<strong>n</strong>&nbsp;(1&lt;=<strong>n</strong>&lt;=45).<strong>&nbsp;</strong></p>



## 출력


<p>Dla każdego zestawu danych Twój program powinien wypisać pojedynczą linię zawierającą jedną liczbę całkowitą. Jest to liczba różnych ciągów zero-jedynkowych długości&nbsp;<strong>n</strong>, które zaczynają się od jedynki i nie zawierają dwóch sąsiednich jedynek.</p>



## 소스코드

[소스코드 보기](Kodowanie.cpp)