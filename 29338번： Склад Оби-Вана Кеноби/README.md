# 29338번: Склад Оби-Вана Кеноби - <img src="https://static.solved.ac/tier_small/7.svg" style="height:20px" /> Silver IV

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/29338)


<p>Оби-Ван Кеноби --- один из последних представителей ордена рыцарей джедаев. Оби-Ван Кеноби родом с планеты Стьюджон, где абсолютно все жители чтут порядок, и Оби-Ван Кеноби --- не исключение.</p>

<p>Во всех эпизодах &lt;&lt;Звездных войн&gt;&gt; Оби-Ван Кеноби орудует синим световым мечом, но мало кто знает, что на самом деле у него их много, причем все мечи Кеноби пронумерованы. Оби-Ван Кеноби хранит все свои мечи на очень длинном столе. Когда он хочет вооружиться, то он берет самый правый меч со стола, и идет по своим делам. Оби-Ван Кеноби орудует взятым мечом пока не потеряет или не сломает его.</p>

<p>Иногда кто-нибудь дарит Оби-Вану Кеноби новый меч, и тогда он просто кладет его на стол справа к тем, что уже лежат там. Но самое страшное случается тогда, когда к столу подходит мама Оби-Вана Кеноби. Мама тоже житель планеты Стьюджон, и поэтому она всегда возмущается, что мечи лежат неупорядоченно. Чтобы исправить это, она забирает всю левую половину мечей (если мечей на столе было нечетное количество, то мама забирает наибольшее целое число мечей, меньшее половины их общего количества) и начинает их подкладывать справа к оставшимся. Причем сначала она кладет меч, который изначально был самым левым, потом правее от него кладет второй меч и так далее.</p>

<p>Определите, в каком порядке лежат мечи у Оби-Вану Кеноби на данный момент. У каждого меча есть свой личный номер, который известен только Оби-Вану Кеноби. Ну и, конечно, вам. </p>



## 입력


<p>В первой строке входного файла дано натуральное числа $n$ --- количество изменений, произошедших на столе ($1 \le n \le 10^6$). В следующих $n$ строках заданы описания изменений в следующем формате:</p>

<ul>
<li>если строка начинается со слова <code>add</code>, то в той же строке через пробел находится число $x$ ($1 \le x \le n$) --- личный номер меча, подаренного Оби-Вану Кеноби. Гарантируется, что мечей с таким номером Оби-Вану Кеноби раньше не дарили и больше не подарят.</li>
<li>если строка содержит единственное слово <code>take</code>, то это обозначает, что Оби-Ван Кеноби забрал самый правый меч со стола с собой. Если на столе не было мечей, то ничего не произошло.</li>
<li>если же строка содержит единственное слово <code>mum!</code>, то это обозначает, что к столу подошла мама и навела порядок. Если на столе было меньше двух мечей, то ничего не произошло. </li>
</ul>

<p>Изначально стол был пуст.</p>



## 출력


<p>В первой строке выходного файла выведите число $k$ --- количество мечей, лежащих на данный момент на столе у Оби-Вана Кеноби. В следующей строке выведите $k$ чисел через пробел --- личные номера мечей, лежащих на столе, в том порядке, в котором они на нем лежат (слева направо).</p>



## 소스코드

[소스코드 보기](Склад%20Оби-Вана%20Кеноби.cpp)