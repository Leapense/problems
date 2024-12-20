# 29677번: ШАШКА - <img src="https://static.solved.ac/tier_small/5.svg" style="height:20px" /> Bronze I

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/29677)


<p>Петр является главным по подсчету рейтингов в Шахматной Ассоциации Шахматистов Конгломерата Антарктики (ШАШКА).</p>

<p>В ассоциации используется рейтинг Эло. Рейтинг --- это неотрицательное целое число. После каждой партии рейтинг пересчитывается по следующим правилам: $$ R_A' = R_A + 15 \cdot (S_A - E_A) $$ $$ E_A = \frac{1}{1 + 10^{\frac{R_B - R_A}{400}}} $$ Здесь $R_A$ и $R_B$ --- рейтинги игроков $A$ и $B$, участвующих в партии, до ее начала, $S_A$ --- количество очков, набранных игроком $A$ в партии ($0$ очков за проигрыш, $0,5$ --- за ничью и $1$ за победу), $R_A'$ --- новый рейтинг игрока $A$. При этом рейтинг округляется вниз до ближайшего целого числа. Если рейтинг стал меньше нуля, то он становится равным нулю.</p>

<p>Всего ШАШКА насчитывает $n$ игроков. Недавно в ассоциации состоялся турнир, в котором было сыграно $m$ партий. Петр не справился с подсчетом новых рейтингов, поэтому он просит Вас помочь ему.</p>



## 입력


<p>В первой строке входного файла находится одно целое число $n$ ($2 \le n \le 1000$). Далее следует $n$ строк, описывающих шахматистов. Каждая строка содержит неотрицательное целое число $r_i$ ($r_i \le 4000$) --- рейтинг $i$-го игрока до начала турнира, а также фамилию игрока. Рейтинг и фамилия разделены одним пробелом. Фамилия состоит из заглавных и строчных латинских букв, и ее длина не превышает $50$. Фамилии всех игроков непусты и различны.</p>

<p>Далее в отдельной строке следует целое число $m$ ($0 \le m \le 1000$) --- количество сыгранных матчей. Затем следует $m$ строк, в каждой из которых содержатся фамилии первого и второго игроков партии, а затем целое число $x$: $x = 1$ означает, что выиграл первый игрок, $x = 2$ --- второй, $x = 0$ --- ничья.</p>

<p>Гарантируется, что фамилии различны и игроки с указанными фамилиями состоят в ШАШКА. Партии заданы в том порядке, в котором они были сыграны.</p>



## 출력


<p>В выходной файл выведите игроков в порядке уменьшения рейтинга. В случае равенства рейтингов раньше должен идти игрок, фамилия которого лексикографически меньше. Следуйте формату входного файла.</p>



## 소스코드

[소스코드 보기](ШАШКА.py)