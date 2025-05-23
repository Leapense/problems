# 4509번: Coffin Tiles - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/4509)


<p>The Pumpkin King has a great idea for this Christmas: Personalized coffins for all the good little boys and girls! To make them extra special, Jack has ordered that the coffins have various designs based upon the interests of the children (This was of course determined by what Google searches the children do most often. The Clown with the Tear-Away face has mad hacking skills).</p>

<p>Most little girls, and some of the boys (Bronies) happen to be really into My Little Pony: Friendship is Magic, and so a large number of Twilight Sparkle themed coffins have been ordered (Twilight is of course, the most awesome pony on the show). These coffins are decorated by affixing alternating tiles in a rectangle up the middle of the coffin lid (They're flat). Now, all the children are different sizes and shapes. Some lids will need a rectangle 3 tiles wide, some less, and some more. In order to keep from ordering too many tiles from the.. ummm... coffin tile factory (Just go with it). The Mayor wants to know how many tiles he needs to order, based upon how many dimensionally unique rectangles can be made using tiles of a certain number.</p>

<p>So, the mayor has asked you to write a program that will, for each given integer, "n", output the minimal number of tiles (The tiles are square) that can be arranged into exactly <code>n</code> unique rectangles. For example, if the number two was given, the minimal number of tiles required to make 2 unique rectangles is 4. With 4 you can make a <code>1x4</code> and a <code>2x2</code> rectangle.</p>



## 입력


<p>Input consists of a single integer indicating the number of integers to read and a sequence of positive integers separated by whitespace. For each input integer <code>n</code>.</p>



## 출력


<p>Your program should output either a single line containing the minimal number of unit squares that can be arranged into exactly <code>n</code> rectangles, or "<code>Too big</code>" if the number of needed unit squares is bigger than 1000000.</p>

<p>&nbsp;</p>



## 소스코드

[소스코드 보기](Coffin%20Tiles.cpp)