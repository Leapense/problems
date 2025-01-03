# 29375번: Реагенты - <img src="https://static.solved.ac/tier_small/5.svg" style="height:20px" /> Bronze I

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/29375)


<p>Враги Агента 007 готовят новое химическое оружие! У них в запасе имеется $n$ реагентов. Каждый реагент характеризуется одним числом $a_i$ --- своей опасностью.</p>

<p>Новые реагенты создаются следующим образом: злые ученые берут $k$ реагентов ($k \ge 2$) и получают из них один новый (в разных реакциях можно использовать разное количество реагентов). Старые реагенты при этом выбрасываются. Опасность реагента, полученного в результате такой реакции, определяется как среднее арифметическое опасностйе реагентов, использованных для его создания. Эту операцию химики повторяют до тех пор, пока у них не останется ровно один реагент, который и станет новым химическим оружием.</p>

<p>Агент 007 собирается уничтожить это оружие. Для этого ему необходимо знать, насколько оно опасно. Известно, что вражеские ученые умны и коварны, и опасность нового оружия будет максимально возможной. Помогите Джеймсу Бонду вычислить опасность этого оружия.</p>



## 입력


<p>В первой строке входного файла находится целое число $n$ ($1 \le n \le 200{\,}000$) --- количество реагентов. В во второй строке находится $n$ чисел $a_i$ ($1 \le a_i \le 10^9$) --- опасность $i$ реагента.</p>



## 출력


<p>В единственной строке выходного файла выведите число $x$ --- максимальная опасность оружия, которую могут получить вражеские ученые. Ответ будет считаться правильным, если его относительная ошибка не превысит $10^{-9}$.</p>



## 소스코드

[소스코드 보기](Реагенты.py)