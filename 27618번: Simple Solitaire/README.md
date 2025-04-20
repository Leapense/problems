# 27618번: Simple Solitaire - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/27618)

<p>There are many different varieties of solitaire (card games for one), but most require an area where you can lay out cards. Here's one you can do by simply holding the deck in your hand.</p>

<p>The game uses a standard $52$ card deck where each card has one of $4$ suits -- spades (S), hearts (H), diamonds (D) or clubs (C) -- and one of $13$ ranks -- Ace (A), $2$, $3$, $4$, $5$, $6$, $7$, $8$, $9$, $10$ (T), Jack (J), Queen (Q), King (K). To play the game you hold the deck face down in your hand and starting turning over cards from the bottom of the deck to the top, face up. Each time you turn over a card you check if it matches the rank or suit of the card three positions before it in the previously turned-over cards. If they match in rank, you remove those two cards and the two cards between them; if they match in suit you remove just those two cards. These actions might cause a cascade effect as now one or more of the remaining turned-over cards might match the ranks or suits of the cards three positions before them. (More detailed rules for processing cascades are described below.) Once all actions in a cascade have been performed (some of which may have forced the processing of even more cascades), you turn over the next card. If all the cards are removed in a single pass through the deck, you win the game!</p>

<p>The start of a sample game is shown below: suppose the first seven cards turned over are the TH, $4$C, KS, AD, $2$S and $8$H. The table below show the next few actions taken in the game -- suits and ranks are underlined when they match. Note that turning over the $8$S results in a cascade of two actions.</p>

<table class="table table-bordered table-center-50">
<tbody>
<tr>
<th>Card Dealt</th>
<th>Hand</th>
<th>Action</th>
</tr>
<tr>
<td>---</td>
<td>TH $4$C KS AD $2$S $8$H</td>
<td>none</td>
</tr>
<tr>
<td>$5$D</td>
<td>TH $4$C KS A<u>D</u> $2$S $8$H $5$<u>D</u></td>
<td>remove AD, $5$D</td>
</tr>
<tr>
<td>$6$D</td>
<td>TH $4$C KS $2$S $8$H $6$D</td>
<td>none</td>
</tr>
<tr>
<td>$8$S</td>
<td>TH $4$C KS $2$<u>S</u> $8$H $6$D $8$<u>S</u></td>
<td>remove $2$S, $8$S</td>
</tr>
<tr>
<td>---</td>
<td>T<u>H</u> $4$C KS $8$<u>H</u> $6$D</td>
<td>remove TH, $8$H</td>
</tr>
<tr>
<td>$9$H</td>
<td>$4$C KS $6$D $9$H</td>
<td>none</td>
</tr>
<tr>
<td>KC</td>
<td>$4$C <u>K</u>S $6$D $9$H <u>K</u>C</td>
<td>remove KS, $6$D, $9$H, KC</td>
</tr>
<tr>
<td>$2$C</td>
<td>$4$C $2$C</td>
<td>none</td>
</tr>
</tbody>
</table>

<p>If there is ever a choice of actions (which can happen during a cascade), you should pick an action which removes four adjacent cards over an action that removes two non-adjacent cards. If several possible actions might result in removing the same number of cards, use the one that removes the most recently turned-over card. For example, if the $6$D had been $6$C in the example above, then in the fifth row of the table the $4$C and $6$C would have been removed instead of the TH and $8$H.</p>

<p>You have one solitary task: given the order in which cards are turned over, determine the cards remaining at the end of the game.</p>

## 입력

<p>Input consists of four lines, each containing $13$ cards. Cards appear in the order in which they are turned over in the game. Each card is represented by two consecutive characters, the first indicating the rank of the card (from <code>A</code>, <code>2</code>, <code>3</code>, <code>4</code>, <code>5</code>, <code>6</code>, <code>7</code>, <code>8</code>, <code>9</code>, <code>T</code>, <code>J</code>, <code>Q</code>, <code>K</code>) and the second indicating the suit of the card (from <code>S</code>, <code>H</code>, <code>D</code>, <code>C</code>). A single space will separate adjacent cards.</p>

## 출력

<p>Output the number of cards remaining at the end of the game followed by the remaining cards, using the format described in the Input section.</p>

## 소스코드

[소스코드 보기](Simple%20Solitaire.cpp)