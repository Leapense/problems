# 19967번: Кафе - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/19967)


<p>Летнее кафе имеет форму прямоугольника размером $n\times m$ клеток, в каждой из которых может находиться стол или стул.</p>

<p>В кафе планируется проведение банкета на $k$ персон. Для этого требуется расставить ровно $k$ стульев так, чтобы рядом с каждым стулом (в одной из соседних клеток по вертикали, горизонтали или диагонали) был стол. Помогите администраторам кафе решить эту задачу или сообщите, что сделать это невозможно.</p>



## 입력


<p>Входной файл содержит три числа $n$, $m$ и $k$ ($1 \le n, m \le 50$, $1 \le k \le 10000$).</p>



## 출력


<p>Выходной файл должен содержать $n$ строк по $m$ символов --- план размещения столов и стульев для банкета. Символ &lt;&lt;<code>h</code>&gt;&gt; обозначает стул, символ &lt;&lt;<code>T</code>&gt;&gt; --- стол, символ &lt;&lt;<code>.</code>&gt;&gt; --- пустую клетку. Если решения нет, выведите строку &lt;&lt;<code>Impossible</code>&gt;&gt;.</p>



## 소스코드

[소스코드 보기](Кафе.cpp)