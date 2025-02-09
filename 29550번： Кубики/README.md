# 29550번: Кубики - <img src="https://static.solved.ac/tier_small/7.svg" style="height:20px" /> Silver IV

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/29550)


<p>Серёжа --- обычный мальчик. Он ещё маленький, поэтому пока не умеет читать. И вот, однажды, родители подарили ему набор параллелепипедов размером $2 \times 1 \times 1$ с буквами на гранях каждого единичного кубика. Однако, Серёжа ещё очень маленький, и родителям не хочется шокировать его огромным количеством разных букв. Поэтому, на кубиках написаны только первые две буквы алфавита --- <code>A</code> и <code>B</code>. На каждом параллелепипеде написаны обе эти буквы, по одной букве на всех гранях каждого единичного кубике.</p>

<p>Обрадовавшись подарку, Серёжа начал ими играть. Он играл ими как-то неправильно, и разломал некоторые параллелепипеды на кубики. После этого, ему не понравились кубики, на которых написана буква <code>B</code>, поэтому он их все потерял. Таким образом, у него остались несколько параллелепипедов, на которых написано <code>AB</code> или <code>BA</code> и несколько кубиков с буквой <code>A</code>.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/a7b4862d-ad2c-4df3-aeef-16cf8e94096d/-/preview/" style="width: 300px; height: 78px;"></p>

<p>После этого, пока родителей не было дома, Серёжа нашёл клей. Как и любой сообразительный мальчик, он сразу понял его предназначение и склеил все имеющиеся у него кубики и параллелепипеды в несколько линий $1 \times 1 \times l_i$. Вернувшиеся родители заинтересовались, могли ли данные конструкции получиться из имеющихся у Серёжи объектов, или нет.</p>



## 입력


<p>В первой строке входного файла задано число $N$ ($1 \leq N \leq 10$) --- количество линий, в которые склеил кубики Серёжа. </p>

<p>Далее, в каждой из следующих $N$ строк входного файла задана строка, состоящая только из букв <code>A</code> и <code>B</code> --- полученная Серёжей линия из кубиков.</p>

<p>Суммарная длина всех строк во входном файле не превышает $100,000$ символов.</p>



## 출력


<p>В выходной файл выведите $n$ строк. В $i$-й строке выходного файла должно быть написано &lt;&lt;<code>YES</code>&gt;&gt;, если Серёжа мог получить $i$-ю линию, и &lt;&lt;<code>NO</code>&gt;&gt; в противном случае.</p>



## 소스코드

[소스코드 보기](Кубики.cpp)