# 30715번: Олимпиада - <img src="https://static.solved.ac/tier_small/5.svg" style="height:20px" /> Bronze I

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/30715)


<p>Маленький мальчик Гриша уже сам начал делать олимпиады, и ему как раз нужно подготовить Открытую Олимпиаду по Информатике. Для олимпиады нужно придумывать задачи, а Гриша как раз очень любит этим заниматься. Каждую задачу он характеризует ее сложностью, которая является неотрицательным целым числом. Сложность олимпиады Гриша оценивает как сумму сложностей всех задач в ней.</p>

<p>На Открытую Олимпиаду по Информатике Грише требуется придумать $n$ задач. Конечно, Гриша еще не дорос до того, чтобы составлять олимпиаду самому, поэтому за его действиями следит многоуважаемое начальство. Начальство любит отвергать некоторые задачи, но Гриша знает, что оно не может отклонить больше, чем $k$ из его задач. Также Гриша, исходя из своего большого опыта, считает, что давать олимпиаду со сложностью меньше чем $x$ будет бессмысленно, поэтому он не допустит такого.</p>

<p>Как мы уже говорили, Гриша --- настоящий специалист в придумывании задач и может придумать сколько угодно задач любой сложности. Он хочет придумать $n$ задач, понимая, что часть из них могут отклонить, и, конечно, он хочет, чтобы независимо от того, какие задачи его начальство отвергнет, сложность олимпиады из оставшихся задач была не меньше $x$. Конечно, Гриша является еще и лентяем, поэтому не хочет перетруждаться и планирует придумать $n$ задач с минимальной суммарной сложностью. К сожалению, сейчас он занят учебой и не может расчитать минимальную суммарную сложность этих задач. Помогите Грише, ведь до олимпиады осталось не так много времени.</p>



## 입력


<p>В первой строке заданы три целых числа $n$, $k$ и $x$  ($2 \le n \le 10^9$, $1 \le k &lt; n$, $1 \le x \le 10^9$) --- количество задач, которое хочет придумать Гриша, максимальное количество задач, которое может отвергнуть его начальство и минимальная допустимая сложность контеста по мнению Гриши.</p>



## 출력


<p>Выведите одно целое число --- минимальную суммарную сложность придуманных Гришей задач.</p>



## 소스코드

[소스코드 보기](Олимпиада.cpp)