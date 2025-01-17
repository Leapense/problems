# 29585번: Даты - <img src="https://static.solved.ac/tier_small/5.svg" style="height:20px" /> Bronze I

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/29585)


<p>Вася конструирует свой собственный автоматический электронный календарь, который будет отображать текущую дату в формате &lt;&lt;ДД.ММ.ГГГГ&gt;&gt;. Для этого ему нужно уметь отображать различные цифры. На данный момент его календарь умеет отображать $k$ различных цифр. Поскольку добавление поддержки каждой новой цифры --- процесс очень трудоемкий, то Вася решил, что если его календарь будет отображать довольно большое количество дат, то он будет доволен. Поэтому на данный момент Васю крайне интересует следующий вопрос: сколько дней из данного промежутка его календарь будет отображать дату. </p>

<p>Например, если Васин календарь может отображать только цифры <code>0</code>, <code>2</code> и <code>9</code>, то он сможет отобразить дату &lt;&lt;второе февраля 2009 года&gt;&gt; и не сможет отобразить дату &lt;&lt;третье февраля 2009 года&gt;&gt;. </p>

<p>Стоит отметить, что программировать Вася умеет неплохо, поэтому он не забывает, что существует такое понятие, как високосный год, в котором в феврале 29 дней. Напомним, что год является високосным, если его номер кратен 4 и при этом не кратен 100, либо кратен 400.</p>



## 입력


<p>Первая строка входного файла состоит из одного целого числа $k$ ($0 \le k \le 10$). Во второй строке входного файла перечислены через пробел $k$ различных цифр, которые Васин календарь умеет отображать. Следующие две строки содержат описание первой и последней даты интересующего его промежутка в формате &lt;&lt;ДД.ММ.ГГГГ&gt;&gt;.</p>



## 출력


<p>В выходной файл выведите одно целое число --- количество дней в промежутке включая концы, в которые календарь может показать дату.</p>



## 소스코드

[소스코드 보기](Даты.cpp)