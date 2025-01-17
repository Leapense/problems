# 29002번: Космический корабль - <img src="https://static.solved.ac/tier_small/3.svg" style="height:20px" /> Bronze III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/29002)


<p>На пути к спасению городка Энджел Гроув черный рейнджер Зак Тейлор столкнулся с очередным препятствием. Рейнджер оказался на инопланетном космическом корабле в окружении врагов, и теперь, чтобы освободиться, ему необходимо уничтожить всех врагов в определенном порядке.</p>

<p>Каждый из $n$ врагов обладает силой $f_i$. Однако среди них имеется главный враг --- босс, чья сила равняется сумме сил всех остальных врагов. Так как уничтожение босса требует полной концентрации и сосредоточенности, Зак сможет справиться с ним только после того, как уничтожит всех остальных врагов.</p>

<p>В запасе у рейнджера мало времени, так что он не успевает понять, кто босс. Ему необходима ваша помощь. Восстановите порядок, в котором Заку Тейлору необходимо уничтожать врагов, чтобы выбраться на свободу.</p>



## 입력


<p>В первой строке входного файла находится натуральное число $n$ --- количество врагов ($3 \le n \le 10^5$).</p>

<p>Во второй строке находятся $n$ целых чисел $f_i$, задающих силу каждого врага ($-10^9 \le f_i \le 10^9$). Силы врагов заданы в случайном порядке.</p>



## 출력


<p>В единственной строке выходного файла выведите числа $f_i$ в порядке, в котором соответствующие им враги будут уничтожаться рейнджером. Если существует несколько порядков, выведите любой.</p>

<p>Гарантируется, что решение всегда существует, а также существует ровно один враг, который может быть боссом.</p>



## 소스코드

[소스코드 보기](Космический%20корабль.cpp)