# 22066번: Турникеты в метро - <img src="https://static.solved.ac/tier_small/6.svg" style="height:20px" /> Silver V

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/22066)


<p>Вася и Петя каждый день ездят на метро, поэтому они решили купить себе проездные карты, чтобы каждый раз не покупать жетон. Каждая карта может использоваться в течение определенного количества дней, после чего она становится неактивной.</p>

<p>При каждом проходе через турникет высвечивается, сколько еще дней карта может быть использована (включая текущий день). Но, к сожалению, табло, на котором это количество дней отображается, может показывать только однозначные и двузначные числа. Если же в отображаемом числе хотя бы три цифры, на табло покажется число 99. Например, если на карте осталось 5 дней, то на турникете покажется число 5, если 12 дней, то число 12, а если 123 дня, то на турникете покажется число 99. Если на карте остается 0 дней, она становится неактивной и по ней больше нельзя проходить через турникет.</p>

<p>Сейчас у Васи на карте осталось&nbsp;<i>a</i>&nbsp;дней, а у Пети —&nbsp;<i>b</i>. Они каждый день ездят на метро и каждый день смотрят на числа, которые отображаются на турникете. И им стало интересно: через сколько дней в первый раз число на турникете у одного из них будет ровно в&nbsp;<i>k</i>&nbsp;раз больше, чем число на турникете у другого. Помогите друзьям выяснить ответ на этот вопрос.</p>



## 입력


<p>Первая строка входных данных содержит одно число&nbsp;<i>t</i>&nbsp;(1&nbsp;≤&nbsp;<i>t</i>&nbsp;≤&nbsp;100000)&nbsp;— количество тестов. Следующие&nbsp;<i>t</i>&nbsp;строк содержат по тесту каждая. Каждый тест задается тремя целыми числами:&nbsp;<i>a</i>,&nbsp;<i>b</i>,&nbsp;<i>k</i>&nbsp;(1&nbsp;≤&nbsp;<i>a</i>,&nbsp;<i>b</i>&nbsp;≤&nbsp;2·10<sup>9</sup>, 1&nbsp;≤&nbsp;<i>k</i>&nbsp;≤&nbsp;100)&nbsp;— количество оставшихся дней на карточках у Васи и Пети и требуемое отношение.</p>



## 출력


<p>Для каждого набора данных выведите единственное число: через сколько дней у одного из друзей на турникете будет показано в&nbsp;<i>k</i>&nbsp;раз больше поездок, чем у другого. Если такого не произойдет до того дня, когда у одного из друзей карта станет неактивной, выведите «<code>-1</code>».</p>



## 소스코드

[소스코드 보기](Турникеты%20в%20метро.cpp)