# 29105번: Забег - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/29105)


<p>Команда Людей Икс решила выяснить, кто из них самый быстрый бегун. Для этого они организовали трассу, состоящую из контрольных точек. Трасса представлена в виде неориентированого графа с $n$ вершинами, обозначающими контрольные точки, и $m$ рёбрами. Для каждого ребра известна его длина. </p>

<p>По правилам забега каждый участник должен пробежать $k$ контрольных точек так, чтобы последовательность вершин, соответствующих им, представляла простой путь. Однако Профессор Икс выяснил, что в системе, регистрирующей участника на контрольной точке, есть ошибка. Для каждого участника система запоминает только последнюю посещённую контрольную точку. Профессор Икс решил схитрить --- он решил составить не кратчайший простой путь, а такой маршрут минимальной длины из $k$ контрольных точек, что каждые две последовательные точки различны, и между ними есть ребро.</p>



## 입력


<p>В первой строке входного файла дано два числа $n$ и $m$ ($1 \le n \le 100000, 1 \le m \le 200000$) --- количество вершин и количество ребер в графе. В следующей строке дано целое число $k$ ($2 \le k \le 100000$) --- длина маршрута. В $i$-й из следующих $m$ строк дана тройка чисел $a_i, b_i, w_i$ ($1 \le a_i, b_i \le n, 1 \le w_i \le 10000$) --- описание $i$-го ребра. Гарантируется, что в графе нет петель.</p>



## 출력


<p>Выведите минимальную длину маршрута.</p>



## 소스코드

[소스코드 보기](Забег.cpp)