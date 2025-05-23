# 11335번: Solitaire - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/11335)


<p>You have a deck of N cards valued from 1 to N. The game starts with cards facing down in the "initial" location. There are also three other locations where you can play your cards face up (once they are face up at the top of any of the other piles): "goal", "helper" and "pile". You win the game once all the cards are placed on the goal in ascending order (N on the top). Rules:</p>

<ol>
<li>you can play cards onto "goal" only if the top "goal" card's value is one less than the value of the card you are trying to place (if "goal" is empty, you can only play the card with value 1(one) there). E.g. if the top card in "goal" is 3, you can only play 4 to "goal".</li>
<li>you can play cards onto "helper" only if the top "helper" card's value is one more than the value of the card you are trying to place (if "helper" is empty, you can only play the card with value N there). E.g. if the top card in "helper" is 8, you can only play 7 to "helper".</li>
<li>you can only move a card onto the "pile" from the top of the "initial" deck by turning that card over(remember? cards in the initial deck are facing down).</li>
<li>once all cards are facing up ("initial" deck is empty) and if the game is not finished yet, take the cards from the "pile" and turn all of them over onto the "initial" position. This will be your new "initial deck". To clarify - the top card in "pile" (facing up) will become the bottom card in "initial" (facing down)</li>
</ol>

<p>What is the minimum number of type 4 moves you need to finish the game?</p>



## 입력


<p>First line of the input contains an integer T (1 &lt;= T &lt;= 100) - the number of test cases. Each test case consists of two lines:</p>

<p>First line contains an integer N ( 1 &lt;= N &lt;= 1000)</p>

<p>Second line contains description of the "initial" deck. The first number is the value of the card at the bottom of the initial deck facing down (so the last card will be played first onto "pile"). This will be a permutation of the list of integers from 1 to N.</p>



## 출력


<p>For each test case print the minimum number of type 4 moves you neeed to "win" the game on a separate line.</p>



## 소스코드

[소스코드 보기](Main.java)