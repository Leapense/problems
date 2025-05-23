# 17890번: Mathemagicians - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/17890)


<p>There are n mathemagicians standing in a circle. Each mathemagician wears either a blue hat or a red hat. A mathemagician can cast a color change charm which changes the color of their hat to the same color as the hat of the mathemagician directly to the left or to the right of them (the caster of the spell may choose which one of them). Note that mathemagicians are polite people and do not like interrupting each other, so only one mathemagician at a time may perform mathemagic.</p>

<p>The mathemagicians are not happy with their current hat configuration, so they would like to use the color change charm repeatedly to enter another hat configuration. Time isn’t an issue because they can conjure cookies to eat.</p>



## 입력


<p>The first line contains an integer n (3 ≤ n ≤ 105 ), the number of mathemagicians. The next contains a string of length n. If the ith mathemagician wears a blue hat in the beginning, the ith character of the string is ‘B’, otherwise the ith character is ‘R’. Finally, the third line contains a string of length n. If the ith mathemagician would like to wear a blue hat in the end, the ith character of the string is ‘B’, otherwise the ith character is ‘R’.</p>

<p>It is guaranteed that not every mathemagician is happy with their hat color in the beginning.</p>



## 출력


<p>Output “yes” if it is possible for the mathemagicians to achieve the desired hat configuration after a finite number of color change charms, otherwise output “no”.</p>



## 소스코드

[소스코드 보기](Mathemagicians.cpp)