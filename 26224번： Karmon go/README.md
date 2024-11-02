# 26224번: Karmon go - <img src="https://static.solved.ac/tier_small/4.svg" style="height:20px" /> Bronze II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/26224)


<p>As part of the import phaseout government plan in you-know-what country, a game called "Karmon go" was released; the game mechanics is based around karaoke monsters, the Karmons. Among other things, each karmon in the game has a battle power parameter  --- the BP. BP can be increased by two means: by <em>powering up</em> the karmon and by <em>evolving</em> it into another karmon species. When a karmon is powered up, a certain constant is added to its BP, which depends only on the species of the karmon. When a karmon evolves, BP is multiplied by a certain factor, depending only on the species of the karmon into which it evolves. A karmon can be evolved only once, and can be powered up only a limited number of times. The player must use both methods of increasing his karmon's BP, but he's free to choose the order: to power up and then to evolve, or vice versa. The resulting BP depends on the chosen order.</p>

<p>Consider the following example: let a player have a Bichu karmon with a BP of $7$. Powering up Bichu raises its BP by $5$. Bichu can be evolved into Bikachu, multiplying its BP by $1.6$. Powering up Bikachu raises its BP by $7$. Let a player, for example, power his karmon up $3$ times. First powering Bichu up and then evolving it results in a BP of $(7 + 3 \cdot 5) \cdot 1.6 = 35.2$. On the other hand, first evolving Bichu into Bikachu and subsequently powering it up brings its BP to $7 \cdot 1.6 + 3 \cdot 7 = 32.2$. It turns out that in the current example powering up followed by evolving is more advantageous.</p>

<p>Help our rookie players figure out the best strategy to develop their karmons: powering up then evolving or vice versa.</p>



## 입력


<p>The input file consists of a single line describing a karmon's features and its evolution in the following format: $name_0$ $inc_0$ $name_1$ $mul_1$ $inc_1$, </p>

<ul>
<li>$name_0$  --- karmon name.</li>
<li>$inc_0$  --- integer constant added to the karmon's BP when powered up prior to evolution ($1 \leq inc_0 \leq 10^6$).</li>
<li>$name_1$  --- karmon name after evolution.</li>
<li>$mul_1$  --- real number factor, by which the karmon's BP is multiplied after evolution ($1 \leq mul_1 \leq 100$). The number contains no more than five decimal digits after decimal point.</li>
<li>$inc_1$  --- integer constant added to the karmon's BP when powered up after evolution ($1 \leq inc_1 \leq 10^6$).</li>
</ul>

<p>The name of any karmon can contain only Latin characters in upper and lower case. The length of the name should be no less than one and no longer than a hundred characters.</p>



## 출력


<p>The output file must contain the line "Power up, Evolve" or the line "Evolve, Power up" depending on which way of developing the karmon is more advantageous to achieve the highest BP: first power up and then evolve, or the opposite, respectively. If the order of powering up and evolution makes no difference, print the word "Whatever".</p>



## 소스코드

[소스코드 보기](Karmon%20go.py)