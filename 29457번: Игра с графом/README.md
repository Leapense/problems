# 29457번: Игра с графом - <img src="https://static.solved.ac/tier_small/7.svg" style="height:20px" /> Silver IV

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/29457)


<p>В одном из очень известных графств завелись два азартных игрока: Алиса и Боб. Граф очень встревожен этим, потому что от таких игроков страдают люди и его графство. Вот и на этот раз Алиса и Боб придумали новую игру.</p>

<p>Опишем правила игры. Игроки делают ходы по очереди. На каждом ходе игрок выбирает дорогу, которая еще не разрушена, и разрушает ее. Если после хода игрока, граф видит, что из какого-то города нельзя добраться во все остальные по неразрушенным дорогам, то он выгоняет этого игрока из графства за порчу имущества, и этот игрок проигрывает в игре своему оппоненту.</p>

<p>Известно, что графство состоит из городов и дорог, причем каждая дорога соединяет ровно два города. По дорогам можно перемещаться в обоих направлениях. Не существует дорог, которые соединяет город сам с собой, и каждую пару городов соединяет не более одной дороги. Из каждого города можно добраться во все другие города.</p>

<p>Известно, что каждый из игроков хочет выиграть, поэтому действует всегда оптимально.</p>

<p>Вам задано графство и известно, что Боб, как джентельмен, уступает первый ход Алисе. Вам нужно понять, кто проиграет в данной игре.</p>



## 입력


<p>В первой строке входного файла заданы два целых числа $n$ и $m$ ($1 \le n \le 100$, $0 \le m \le 500$) --- количество городов и дорог соответственно. В следующих $m$ строках заданы дороги --- два числа: $a$ и $b$ ($1 \le a &lt; b \le n$) --- номера городов, которые соединяет соответствующая дорога.             </p>

<p>Гарантируется, что никакая пара городов не встречается во входном файле дважды и что из любого города можно добраться до всех остальных по заданным дорогам.</p>



## 출력


<p>В выходной файл выведите имя игрока, который проиграл: Alice или Bob, либо Draw, если никто не проиграл.</p>



## 소스코드

[소스코드 보기](Игра%20с%20графом.cpp)