# 7802번: No Pause Telegraph - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/7802)


<p>Several hundreds years ago in a country, there was a war between the colonialist and the military of the country. In the war, telegraph machine was used to communicate between the country and its allied cities around the country. The Morse code was used to send messages through telegraph machine. In Morse, letters are represented only by "." (dot) and "-" (dash). Between letters there is a pause to avoid mistranslation of letters.</p>

<p>In that era with the popularity of telegraph machine, there was wariness that the enemy could read the messages, if the messages were accidentally sent to them. Being aware of the threat, a machine was created to encode the messages. It was called No Pause Telegraph. This new telegraph machine was similar to the regular machine, only that the machine encoded the messages with no pause between letters.</p>

<p>After doing some researches on old relics, our archeologist has analyzed the code being used successfully. The archeologist so far has found 7 letters that been used on the found relics, those are:</p>

<pre>A.--dot dash dash
B-.dash dot
C---dash dash dash
D..dot dot
E--..dash dash dot dot
F--.-dash dash dot dash
G.-.dot dash dot</pre>

<p>Your task is to translate several messages encoded by the machine on the remaining relics. You should be careful that any ambiguousity may arise when translating those messages. For example: If the code for X were "." and the code for Y were "..", then two dots in a row could be either XX or Y. For this particular reason, you should output only the least alphabetical solution.</p>



## 입력


<p>Each line of input is a code encoded by No Pause Telegraph. The line will consists of only characters of . (dot(s)) and - (dash(es)).</p>

<p>&nbsp;</p>



## 출력


<p>For each line of input, print the least alphabetical possible message in one line. If there is no possible message, print "could not be translated" (without quotes).</p>

<p>&nbsp;</p>



## 소스코드

[소스코드 보기](No%20Pause%20Telegraph.py)