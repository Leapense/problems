# 31291번: Barabashka - <img src="https://static.solved.ac/tier_small/5.svg" style="height:20px" /> Bronze I

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/31291)


<p><em>The tests for this problem are open. In this problem, you have to choose one of the five items according to a textual description of an image.</em></p>

<p>"Barabashka" (originally named "Geistesblitz") is a board game that favors fast reaction. Below are the rules of the game for this problem. Please read them carefully, as they are slightly different from the original game rules.</p>

<p>The game set includes five items of different colors: a white ghost named Barabashka, a green bottle, a gray mouse, a blue book and a red chair, and also special cards. Each card contains an image with exactly two of these five items. Each of the items also has one of the aforementioned five colors, but the color of each item may be wrong. The colors of these two items are different. The image can contain other objects, but their colors are guaranteed to be different from the five colors above.</p>

<p>A single move in the game proceeds as follows. All items are put on the table, and after that, a card is drawn from the deck and shown to the players. If the card contains an item of the right color (the color on the picture matches the color of the real item on the table), the players have to grab that item. Otherwise, the players have to grab the item which is not present on the picture, and the true color of which also does not appear on the picture. The winner is the player who grabs the right item earlier than the others. The winner gets the card as a reward. It is guaranteed that all cards contain images for which there exists a unique right answer.</p>

<p>In this problem, each test consists of exactly five sentences. A sentence is a textual description of one card in English. The right answer for a sentence is the description of the item to grab when the players see such card.</p>

<p>Each sentence is written in English and can contain English letters, spaces and characters "<code>'</code>", "<code>,</code>", "<code>-</code>" and "<code>.</code>" (ASCII codes 39, 44, 45 and 46). The names and the right colors of the items are the following: "<code>white Barabashka</code>", "<code>blue book</code>", "<code>red chair</code>", "<code>gray mouse</code>" and "<code>green bottle</code>".</p>

<p>Let a word be a sequence of English letters surrounded from both ends by line ends or non-letter characters. Then we can formulate the following restrictions on the sentences:</p>

<ul>
<li>A sentence contains exactly two positions of the form "<code>color name</code>" where the word "<code>color</code>" is one of the five colors mentioned above, and the word "<code>name</code>" is one of the five item names.</li>
<li>No other word in the sentence is equal to the name or the color of some of the items on the table.</li>
</ul>

<p>The tests in this problem are open for contestants and can be downloaded at the following addresses:</p>

<ul>
<li><a href="https://upload.acmicpc.net/a8853ad9-923b-4311-a272-8bf861652499/">tests.zip</a> (Windows line breaks),</li>
<li><a href="https://upload.acmicpc.net/a7dd5f43-5e6c-49bf-9284-7d629d5fea38/">tests.tar.gz</a> (Linux line breaks).</li>
</ul>

<p>The problem contains $24$ tests, that is, $24 \cdot 5 = 120$ card descriptions: one description for each possible combination of items and their colors on a card.</p>



## 입력


<p>The input consists of five lines. Each line contains one sentence of length from $1$ to $80$ characters. The exact format of each sentence is given in the problem description. Uppercase and lowercase letters are considered different.</p>



## 출력


<p>For each sentence, print a line containing two words separated by a space: the right color and name of the item to grab when the players see the card described by that sentence. Uppercase and lowercase letters are considered different.</p>



## 소스코드

[소스코드 보기](Barabashka.cpp)