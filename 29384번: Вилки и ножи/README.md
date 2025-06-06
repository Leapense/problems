# 29384번: Вилки и ножи - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/29384)


<p>В каждом волшебном лесу есть волшебное кафе. Обслуживают его, конечно же, волшебные белочки. Как известно, белочки --- очень ленивые существа, и готовить много разных блюд им лень. Поэтому, на выбор посетителям предлагается одно из двух блюд --- волшебный салат или же второе блюдо. Когда посетитель приходит в кафе, он заказывает одно из этих двух блюд. </p>

<p>Ввиду ухудшения дипломатических отношений с соседним лесом, этот волшебный лес переживает период экономического упадка, и кафе не на что закупать новую посуду. Поэтому, в кафе имеется всего $m$ ножей и $n$ вилок. Для того, чтобы есть салат, нужна только вилка, а для второго блюда же нужны и вилка, и нож. Из-за этого белочки не всегда могут обслужить всех посетителей. А имеено, если к приходу очередного посетителя на его заказ не хватает столовых приборов, белочки вынуждены извиниться перед посетителем, и посетитель идёт в другое кафе. Если же ему хватает приборов, то он ест, а после еды отдаёт их обратно белочкам. Помогите белочкам выяснить про каждого посетителя, хватит ли ему столовых приборов.</p>



## 입력


<p>Первая строка входного файла содержит три целых числа $n, m, k$ ($1 \le n, m, k \le 1000$) --- количество вилок, ножей и посетителей кафе, соответственно.</p>

<p>Следующие $k$ строк содержат описания посетелей. Каждое описание состоит из трех целых чисел $t_i$, $l_i$ и $a_i$ ($1 \le t_i, l_i \le 10000$) --- момент времени, в который придет $i$-ый посетитель, сколько он там будет находиться и что он закажет. $a_i$ равно $0$, если $i$-ый посетитель закажет только волшебный салат, для которого нужна только вилка или $1$, если он закажет второе блюдо, для которого помимо вилки понадобится нож.</p>

<p>Все посетители заданы в порядке возрастания времени прихода ($t_i &lt; t_{i+1}$ для $i = 1...{(k-1)}$). Никакие два посетителя не приходят одновременно. Если одновременно с приходом одного посетителя какие-то другие уходят, то новый гость может воспользоваться их приборами --- белочки умеют очень быстро мыть посуду.</p>



## 출력


<p>В выходной файл выведите $k$ строк --- по одной на каждого посетителя. В строке с номером $i$ выведите Yes, если белочки смогут обслужить $i$-го посетителя, и No в ином случае.</p>



## 소스코드

[소스코드 보기](Вилки%20и%20ножи.cpp)