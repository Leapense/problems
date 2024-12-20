# 28984번: Поиски - <img src="https://static.solved.ac/tier_small/6.svg" style="height:20px" /> Silver V

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/28984)


<p>У Ньюта Саламандера пропало одно из его существ, и теперь он пытается срочно его найти. К счастью, он узнал, куда оно делось --- каким-то образом оно переместилось в одномерное пространство и теперь ходит туда-сюда по числовой прямой в надежде найти оттуда выход. Ньют также узнал, что сразу после перемещения существо оказалось в координате 0 числовой прямой и что перемещаться в новом пространстве оно могло только по целым числам.</p>

<p>Саламандер может отслеживать перемещения существа по GPS, однако из-за искажения пространственных метрик верно отображается только информация о направлении перемещения --- влево или вправо, а длина неизвестна (однако она точно ненулевая). Имея полный список перемещений, Ньют хочет узнать, могло ли существо после них всех оказаться в координате $x$, где, собственно, и находится выход.</p>



## 입력


<p>В первой строке содержится строка $s$, описывающая перемещения существа и состоящая только из символов <code>'L'</code> и <code>'R'</code> --- перемещение влево и вправо соответственно ($1 \le |s| \le 10^5$).</p>

<p>Во второй строке содержится координата $x$, про которую хочет узнать Саламандер ($-10^5 \le x \le 10^5$).</p>



## 출력


<p>В единственной строке выведите <code>"YES"</code> (без кавычек), если после всех перемещений существо могло оказаться в координате $x$, и <code>"NO"</code> в противном случае.</p>



## 소스코드

[소스코드 보기](Поиски.cpp)