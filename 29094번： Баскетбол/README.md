# 29094번: Баскетбол - <img src="https://static.solved.ac/tier_small/4.svg" style="height:20px" /> Bronze II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/29094)


<p>В Вестеросе существует игра, сильно похожая на баскетбол. Тирион Ланнистер не может в неё играть, зато он любит следить её ходом.</p>

<p>В вестероский баскетбол играют $n$ человек. Есть два кольца, каждый игрок может забить мяч в любое из них и получить за это одно, два или три очка. Тирион ведет записи, в которых он фиксирует, как изменился счет, и кто забил мяч. Счёт представляет собой два числа --- сколько очков было забито в первое и во второе кольцо соответсвенно. Для красоты он разделяет эти два числа двоеточием. Таким образом одна строчка в записях Тириона может выглядеть так: &lt;&lt;30:41 Lannister&gt;&gt;.</p>

<p>После игры Тирион захотел узнать, кто же набрал больше всех очков. Но, к сожалению, обязанности мастера над монетой отнимают у него много времени. Ланнистеры всегда платят долги, поэтому у Вас есть все основания, чтобы помочь ему.</p>



## 입력


<p>В первой строке входного файла задано число $n$ ($1 \le n \le 50$) --- количество игроков.</p>

<p>В следующих $n$ строках записаны имена игроков $s_i$ ($1 \le |s_i| \le 15$). Имена состоят только из больших и маленьких букв латинского алфавита.</p>

<p>В строке с номером $n+2$ дано число $m$ ($1 \le m \le 500$) --- количество записей Тириона.</p>

<p>В следующих $m$ строках даны записи в виде &lt;&lt;$a_i$:$b_i$ $t_i$&gt;&gt; без кавычек, где $a_i$ --- очки, забитые в первое кольцо, $b_i$ --- во второе, $t_i$ --- имя игрока, сделавшего счёт таким. Тирион никогда не ошибается в подсчетах, поэтому гарантируется, что его записи верны.</p>

<p>Начальный счет, как и во всех играх, 0:0.</p>



## 출력


<p>В единственной строке выходного файла выведите имя игрока, который набрал больше всех очков, и количество очков, которые он набрал. При наличии нескольких ответов разрешается вывести любой.</p>



## 소스코드

[소스코드 보기](Баскетбол.py)