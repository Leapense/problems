# 10342번: Fun House - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/10342)


<p>American Carnival Makers Inc. (ACM) has a long history of designing rides and attractions. One of their more popular attractions is a fun house that includes a room of mirrors. Their trademark is to set up the room so that when looking forward from the entry door, the exit door appears to be directly ahead. However, the room has double-sided mirrors placed throughout at 45 degree angles. So, the exit door can be on any of the walls of the room. The set designer always places the entry and mirrors, but can never seem to be bothered to place the exit door. One of your jobs as part of the construction crew is to determine the placement of the exit door for the room given an original design.</p>

<p>The final diagram for a sample room is given below. The asterisk (<kbd>*</kbd>) marks the entry way, lower case x's mark the walls, the mirrors are given by the forward and backward slash characters (<kbd>/</kbd> and <kbd>\</kbd>), open spaces with no visual obstructions are marked by periods (<kbd>.</kbd>), and the desired placement of the exit is marked with an ampersand (<kbd>&amp;</kbd>). In the input diagram, there is an 'x' in place of the '&amp;', since the exit has not yet been located. You need to alter the input diagram by replacing the proper 'x' with an '&amp;' to identify the exit. Note that entrances and exits can appear on any of the walls (although never a corner), and that it is physically impossible for the exit to be the same as the entrance. (You don't need to understand why this is so, although it may be fun to think about.)</p>

<pre>xxxxxxxxxxx
x../..\...x
x..../....x
*../......x
x.........x
xxxxxx&amp;xxxx
</pre>



## 입력


<p>Each room will be preceded by two integers, W and L, where 5 ≤ W ≤ 20 is the width of the room including the border walls and 5 ≤ L ≤ 20 is the length of the room including the border walls. Following the specification of W and L are L additional lines containing the room diagram, with each line having W characters from the alphabet: { <kbd>*</kbd> , <kbd>x</kbd> , <kbd>.</kbd> , <kbd>/</kbd> , <kbd>\</kbd> }. The perimeter will always be comprised of walls, except for one asterisk (<kbd>*</kbd>) which marks the entrance; the exit is not (yet) marked. A line with two zeros indicates the end of input data.</p>



## 출력


<p>For each test case, the first line will contain the word, HOUSE, followed by a space and then an integer that identifies the given fun house sequentially. Following that should be a room diagram which includes the proper placement of the exit door, as marked by an ampersand (<kbd>&amp;</kbd>).</p>

<p><strong>Note:</strong>&nbsp; In both Java and C++ the backslash character (<kbd>\</kbd>) has special meaning as an escape character within character and string literals. You must use the combination&nbsp;<kbd>\\</kbd> to express a single backslash within a character or string literal within source code.</p>



## 소스코드

[소스코드 보기](Fun%20House.cpp)