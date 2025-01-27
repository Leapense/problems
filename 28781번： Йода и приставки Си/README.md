# 28781번: Йода и приставки Си - <img src="https://static.solved.ac/tier_small/6.svg" style="height:20px" /> Silver V

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/28781)


<p>Магистр Йода известен тем, что использует необычный порядок слов. Эта особенность имеет еще одно следствие. Когда магистр называет какое-то расстояние, площадь или объем, он использует множество приставок системы Си. Каждая приставка системы Си умножает единицу измерения на некоторую степень десяти. Например, он может сказать &lt;&lt;<code>megananokilogigamicrometer</code>&gt;&gt;, что будет соответствовать $10^3$ метрам. Если речь идет об объёме, то он может сказать &lt;&lt;<code>millimeter^3</code>&gt;&gt;, что будет соответствовать $10^{-9}$ метрам кубическим.</p>

<p>Магистр использует только следующие приставки:</p>

<table class="table table-bordered th-center td-center table-center-30">
<tbody>
<tr>
<th>Приставка</th>
<th>Степень десяти</th>
</tr>
<tr>
<td>tera</td>
<td>12</td>
</tr>
<tr>
<td>giga</td>
<td>9</td>
</tr>
<tr>
<td>mega</td>
<td>6</td>
</tr>
<tr>
<td>kilo</td>
<td>3</td>
</tr>
<tr>
<td>deci</td>
<td>-1</td>
</tr>
<tr>
<td>centi</td>
<td>-2</td>
</tr>
<tr>
<td>milli</td>
<td>-3</td>
</tr>
<tr>
<td>micro</td>
<td>-6</td>
</tr>
<tr>
<td>nano</td>
<td>-9</td>
</tr>
</tbody>
</table>

<p>Например, если Йода сказал &lt;&lt;<code>megananokilogigamicrometer</code>&gt;&gt;, то это равно $10^6 \cdot 10^{-9} \cdot 10^3 \cdot 10^9 \cdot 10^{-6}$ метрам или $10^3$ метрам. Правила применения приставок к квадратным и кубическим величинам также являются стандартными. Например, один кубический метр равен $10^6$ кубическим сантиметрам.</p>

<p>К сожалению, C-3PO рядом не оказалось, и вам нужно самостоятельно расшифровать, что именно сказал Йода. Переведите единицу измерения, которую назвал Йода, в метры, метры квадратные или метры кубические, в зависимости от разрядности исходной единицы измерения. Несложно показать, что у вас получится величина, равная $10^x$ (метров, метров квадратных или метров кубических), где $x$ --- целое число. Выведите $x$.</p>



## 입력


<p>Входные данные содержат единственную строку --- слово, сказанное магистром Йодой. Длина слова не превосходит $10^5$. Гарантируется, что слово было получено последовательным приписыванием нескольких приставок из таблицы к &lt;&lt;<code>meter</code>&gt;&gt;, &lt;&lt;<code>meter^2</code>&gt;&gt; или &lt;&lt;<code>meter3</code>&gt;&gt;.</p>



## 출력


<p>Выведите целое число $x$, такое что если перевести единицу измерения, названную магистром Йодой, в метры, метры квадратные или метры кубические, получится $10^x$.</p>



## 소스코드

[소스코드 보기](Йода%20и%20приставки%20Си.cpp)