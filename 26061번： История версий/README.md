# 26061번: История версий - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/26061)


<p>Группа компаний СКБ Контур давно работает над революционным проектом, который будет помогать всем предпринимателям: от маленьких бизнесов до больших фирм. Они ещё не готовы раскрыть его суть, но на недавней пресс-конференции сообщили, что сейчас проект имеет номер версии $N$.</p>

<p>По слухам вы знаете, что в СКБ Контур есть необычная конвенция наименования версий. Каждый месяц они работают над новой версией. Номер первой версии выбирается произвольно из всех натуральных чисел. А каждый следующей месяц номер увеличивается на $1$ <em>в каждом разряде</em>. То есть, если номер текущей версии состоит из $k$ цифр, то в следующем месяце номер версии будет на $111 \ldots 111$ больше, где $1$ повторено $k$ раз.</p>

<p>Например, если сейчас СКБ Контур работает над версией номер $13579$, то через меcяц будут работать над версией $24690$.</p>

<p>Узнав, что номер текущей версии --- $N$, вы тут же заинтересовались: какое наибольшее число месяцев могла идти работа над проектом? Попробуйте найти этот ответ.</p>



## 입력


<p>В единственной строке дано натуральное число $N$ --- текущий номер версии ($1 \le N \le 10^{18}$).</p>



## 출력


<p>Выведите единственное натуральное число --- наибольшее число месяцев, которое могла идти работа (считая текущий).</p>



## 소스코드

[소스코드 보기](Main.java)