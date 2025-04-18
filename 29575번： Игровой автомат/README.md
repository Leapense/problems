# 29575번: Игровой автомат - <img src="https://static.solved.ac/tier_small/4.svg" style="height:20px" /> Bronze II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/29575)


<p>Недавно в игровой зоне, расположенной в одном из отдаленных уголков нашей страны, установили новый игровой автомат. Принцип его работы прост: нужно опустить жетон (ценой в десять рублей) и дернуть ручку, после чего на экране высветятся четыре цифры. Таким образом, стоимость каждой игры на автомате составляет десять рублей.</p>

<p>Существует специальная таблица выигрышных комбинаций, по которой можно определить, принесла ли попытка игроку деньги. Афанасий решил опробовать новый автомат, но поскольку с устным счетом у него не слишком хорошо, он попросил Вас ему помочь.</p>

<p>Напишите программу, которая вычислит, как за вечер изменился капитал Афанасия.  Можно считать, что у Афанасия достаточно денег, чтобы купить жетоны сразу для всех попыток.</p>



## 입력


<p>В первой строке входного файла находится число $n$ ($1 \le n \le 1000$) --- количество записей в таблице выигрышей. Далее идет $n$ строк, в каждой из которых приведено два числа: $c_i$ ---комбинация и $w_i$ --- выигрыш за нее. Никакая комбинация не встречается в таблице выигрышей более одного раза. $c_i$ состоит ровно из четырех цифр, $1 \le w_i \le 1000000$. В следующей строке находится число $m$ ($1 \le m \le 1000$) --- сколько раз Афанасий попытал удачу. В каждой из последующих $m$ строк содержится комбинация, выпавшая на автомате.</p>



## 출력


<p>В выходной файл выведите изменение капитала Афанасия за эти $m$ игр на автомате.</p>



## 소스코드

[소스코드 보기](Игровой%20автомат.py)