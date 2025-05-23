# 28586번: Воссоединение c Веномом - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/28586)


<p>Эдди Брок и Веном ссорятся и расходятся по каждому мелкому поводу. В этот раз они снова наконец-то помирились, и теперь им нужно воссоединиться.</p>

<p>Как известно, человек может воссоединиться с симбиотом, если показатели трех главных гормонов: <em>тироксина</em>, <em>адреналина</em> и <em>серотонина</em>, находятся в равновесии. Гормоны находятся в равновесии тогда и только тогда, когда все три показателя равны между собой.</p>

<p>Эдди (не без помощи Венома) умеет изменять свои показатели гормонов. Одно изменение показателей представляется так: </p>

<ol>
<li>Из трех гормонов выбирается один;</li>
<li>Показатель выбранного гормона уменьшается ровно на один;</li>
<li>Показатели двух других гормонов увеличиваются ровно на один каждый.</li>
</ol>

<p>По заданным показателям гормонов определите, возможно ли описанной выше операцией достичь равновесия гормонов, и если да, то за какое минимальное количество изменений. Обратите внимание, что все три шага выполняются по очереди в рамках одной операции и не могут выполняться независимо друг от друга.</p>



## 입력


<p>В первой и единственной строке ввода через пробел даны три целых числа $t$, $a$ и $s$ --- показатели тироксина, адреналина и серотонина соответственно ($-10^{18} \leqslant t, a, s \leqslant 10^{18}$).</p>



## 출력


<p>Выведите минимальное количество изменений, за которое можно достичь равновесия гормонов для воссоединения с Веномом. Если достичь равновесия невозможно, выведите $-1$.</p>



## 소스코드

[소스코드 보기](Воссоединение%20c%20Веномом.cpp)