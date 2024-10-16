# 29308번: Закат - <img src="https://static.solved.ac/tier_small/3.svg" style="height:20px" /> Bronze III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/29308)


<p>Долгие переговоры руководства ФК &lt;&lt;Закат&gt;&gt; увенчались успехом: Брюс Бэннер присоединился к команде. Как и положено звезде мирового футбола, он получал немаленькую зарплату.</p>

<p>Однако, одному из прежних игроков команды это не понравилось. Стало ясно, что не избежать волны требований увеличения заработка. После некоторого раздумья, великий тренер Чулано Спагетти нашел способ решить эту проблему.</p>

<p>Всего в команде &lt;&lt;Закат&gt;&gt; $n$ игроков. Некоторые из них имеют российское гражданство, все остальные --- легионеры. К требованиям легионеров тренер относится с осторожностью и предпочтет увеличить им зарплату, чтобы не упустить ценного игрока. А вот российских игроков тренер будет стимулировать снижать их запросы следующим действием: в ближайшем матче не выпускать на поле того игрока с российским гражданством, который потребует себе наибольшую зарплату. Теперь ваша задача определить, кто из команды не выйдет на поле, зная фамилии игроков, их гражданство и зарплату, которую они требуют.</p>



## 입력


<p>В первой строке задано число футболистов $n$ ($1 \le n \le 100$). % n ≤ 100 Далее следуют $n$ строк, содержащих описания футболистов. Каждое описание состоит из перечисленных через пробел зарплаты, требуемой этим игроком, его фамилии и гражданства. Фамилия и гражданство --- строки, содержащие только строчные и прописные латинские символы. Длина фамилии и гражданства не превышает 20 символов. У игроков, имеющих российское гражданство, в соответствующем параметре значится &lt;&lt;Russia&gt;&gt;. Зарплата, которую требует игрок --- положительное число, не превышающее $10^9$. Гарантируется, что в команде есть хотя бы один игрок с российским гражданством.</p>



## 출력


<p>Выведите фамилию футболиста, который не выйдет на поле. Гарантируется, что такой игрок всегда один.</p>



## 소스코드

[소스코드 보기](Закат.py)