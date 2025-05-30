# 21741번: Ожерелье - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/21741)


<p>В витрине ювелирного магазина стоит манекен, на шею которого надето ожерелье. Оно состоит из N колечек, нанизанных на замкнутую нить. Все колечки имеют разные размеры. В зависимости от размера &nbsp;колечки пронумерованы числами от 1 до N, начиная с самого маленького и до самого большого. Колечки можно передвигать вдоль нити и протаскивать &nbsp;одно через другое, но только в том случае, если номера этих колечек отличаются более чем на единицу.&nbsp;</p>

<p>Продавец хочет упорядочить колечки так, чтобы они располагались по возрастанию номеров вдоль нити по часовой стрелке. Снимать ожерелье с манекена нельзя.</p>

<p>Требуется написать программу, которая по заданному начальному расположению колечек находит последовательность протаскиваний колечек одно через другое, приводящую исходное расположение колечек в желаемое.</p>



## 입력


<p>В первой строке входного файла записано число N (2 ≤ N ≤ 50).&nbsp;</p>

<p>Во второй строке через пробел следуют N различных чисел от 1 до N — номера колечек, расположенных вдоль нити по часовой стрелке.&nbsp;</p>



## 출력


<p>Выходной файл должен содержать описание процесса упорядочения.</p>

<p>В каждой строке, кроме последней, должны быть записаны через пробел два числа, указывающие номера колечек, протаскиваемых друг через друга. В последней строке должен стоять ноль.</p>

<p>Количество строк выходного файла не должно превышать 50000.</p>

<p>Если требуемого упорядочения колечек достичь не удается, в выходной файл нужно вывести одно число &nbsp;–1.</p>



## 소스코드

[소스코드 보기](Ожерелье.cpp)