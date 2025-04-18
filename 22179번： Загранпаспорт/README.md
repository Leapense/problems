# 22179번: Загранпаспорт - <img src="https://static.solved.ac/tier_small/5.svg" style="height:20px" /> Bronze I

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/22179)


<p>Многим знакома ситуация, когда для получения какого-либо документа, например, загранпаспорта, требуется в строго определенном порядке обойти несколько мест, в каждом из которых требуется совершить какое-либо действие: получить справку, написать заявление, заверить ксерокопию и т.д. Для удобства граждан такие места стали объединяться в единые центры, где каждое место превращается в отдельное окно. Но все равно есть проблема: каждое окно имеет свой режим работы.</p>

<p>Один человек планирует придти за своим загранпаспортом в&nbsp;<code>hh</code>&nbsp;часов&nbsp;<code>mm</code>&nbsp;минут. Он знает, что ему требуется обойти в определенном порядке ровно&nbsp;<i>n</i>&nbsp;окон, и знает их режим работы. В конце обслуживания в последнем из них он получит загранпаспорт. Человек хочет узнать, успеет ли он получить паспорт до конца дня, если кроме него в едином центре не будет других посетителей.</p>

<p>Про каждое окно известно его время открытия и время закрытия. Также известно, сколько минут занимает обслуживание одного посетителя в каждом окне.</p>

<p>Считается, что посетитель подходит к окну в начале некоторой минуты. Время открытия окна — это первая минута, во время которой оно уже работает, а время закрытия — первая минута, когда оно уже не работает. Например, если окно открывается в 12:00 и закрывается в 20:00, а обслуживание занимает 11 минут, то если человек подошел к окну между 12:00 и 19:49, включительно, то его обслужат сразу, если в 11:59 или раньше, то его начнут обслуживать в 12:00, а если в 19:50 или позже, то его уже не обслужат.</p>

<p>Человек перемещается между окнами мгновенно. Таким образом, например, если обслуживание в некотором окне занимает 10 минут, и человек подошел к нему в 12:45, то обслуживание в следующем окне для него может начаться в 12:55 или позже.</p>

<p>Все окна открываются не раньше, чем в 00:00, и закрываются не позже, чем в 23:00. В окне не обслуживают посетителя, если до конца рабочего времени окна осталось меньше времени, чем требуется на обслуживание.</p>

<p>Требуется выяснить, успеет ли человек получить загранпаспорт, и если да, то в какой самый ранний момент времени он сможет покинуть единый центр, получив загранпаспорт.</p>



## 입력


<p>Первая строка содержит время, когда человек планирует придти в единый центр, в формате&nbsp;<code>hh:mm</code>. Вторая строка содержит одно целое число&nbsp;<i>n</i>&nbsp;— количество окон, которые требуется обойти (1 ≤&nbsp;<i>n</i>&nbsp;≤ 100).</p>

<p>Следующие&nbsp;<i>n</i>&nbsp;строк содержат описание работы всех окон в том порядке, в котором их нужно обходить. Строка, описывающая окно номер&nbsp;<i>i</i>, содержит время открытия этого окна в формате&nbsp;<code>hh:mm</code>, затем через пробел время закрытия в том же формате, и через пробел одно целое число&nbsp;<i>t<sub>i</sub></i>&nbsp;— количество минут, которые займет обслуживание посетителя в этом окне (1 ≤&nbsp;<i>t<sub>i</sub></i>&nbsp;≤ 1440). Время закрытия каждого окошка строго больше времени его открытия.</p>



## 출력


<p>В случае, если человек успеет получить загранпаспорт, выведите в первой строке&nbsp;<code>Yes</code>, а во второй — время, когда он сможет покинуть единый центр в формате&nbsp;<code>hh:mm</code>. Иначе выведите в первой строке&nbsp;<code>No</code>.</p>



## 소스코드

[소스코드 보기](Загранпаспорт.py)