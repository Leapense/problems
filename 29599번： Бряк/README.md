# 29599번: Бряк - <img src="https://static.solved.ac/tier_small/7.svg" style="height:20px" /> Silver IV

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/29599)


<blockquote>
<p><em>--- Эй, Брейн, чем мы будем заниматься сегодня вечером?</em></p>

<p><em>--— Тем же, чем и всегда, Пинки… Попробуем завоевать мир!</em></p>

<p>Пинки и Брейн.</p>
</blockquote>

<p>Как-то раз, в одной очень секретной лаборатории две чрезвычайно сообразительные мыши выбрались из клетки и решили завоевать мир. Для этого они пробрались в хранилище, где в нескольких емкостях содержался раствор совершенно секретного вещества. В разных емкостях объемы и концентрации растворов могли различаться.</p>

<p>Для осуществления своего коварного плана мышам потребовался раствор определенной концентрации. Для того, чтобы получить его они стали переливать некоторые объемы раствора из одной емкости в другую. К большому сожалению, как раз в тот момент, когда нужный раствор уже был получен, пришли охранники, и мышам пришлось скрыться.</p>

<p>К несчастью для зверьков, камеры наблюдения записали все, что происходило в хранилище. Ученым, работающим в этой лаборатории крайне интересно, что же хотели сделать их подопытные, поэтому они хотят по записи действий мышей определить концентрацию раствора в каждой из емкостей.</p>



## 입력


<p>Первая строка входного файла содержит целое число $n$ --- количество емкостей в хранилище ($2 \le n \le 100$). Следующие $n$ строк содержат пары целых чисел $v_i$ и $c_i$, разделенные пробелом --- объем жидкости в $i$-й емкости в литрах и концентрация раствора в ней в процентах ($0 \le v_i \le 10^9$, $0 \le c_i \le 100$). Будем считать, что в пустой емкости концентрация равна нулю.</p>

<p>Следующая строка входного файла содержит целое число $m$ --- количество операций, произведенных мышами ($1 \le m \le 100$). Далее следует $m$ строк, содержащих три целых числа $a$, $b$ и $k$ ($1 \le a, b \le n$, $a \ne b$, $1 \le k \le 10^9$). Данная запись означает, что из сосуда с номером $a$ перелили $k$ литров в сосуд с номером $b$. При этом гарантируется, что в сосуде $a$ содержится хотя бы $k$ литров жидкости. Сосуды нумеруются с единицы в порядке их упоминания во входном файле. Будем считать, что все сосуды достаточно велики, чтобы в них поместился любой объем жидкости.</p>



## 출력


<p>В выходной файл выведите объемы и концентрации растворов в емкостях после всех переливаний в таком же формате, в каком они заданы во входном файле. Концентрация каждой жидкости должна отличаться от правильной не больше чем на $10^{-4}$ процента.</p>



## 소스코드

[소스코드 보기](Бряк.cpp)