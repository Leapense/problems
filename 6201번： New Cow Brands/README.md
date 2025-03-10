# 6201번: New Cow Brands - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/6201)


<p>The cows are beside themselves: Farmer John has decided to use RFID tags instead of branding the cows with red-hot irons that cause intense pain.</p>

<p>The RFID tags contain a code that is N (3 &lt;= N &lt;= 15) characters (each in the range 'A'..'Z') in length. No character appears twice in the code. The character chosen for any given position in the code is chosen from a supplied set for that position. The set is always given in alphabetical order.</p>

<p>A machine generates the codes in alphabetical order. Each new batch &nbsp; &nbsp;of cows uses the next unused set of codes. FJ keeps track of the number of codes he has already used.<br>
&nbsp;<br>
Help FJ confirm the RFID brands to be used for the next set of cows. &nbsp; Given the count of the starting and finishing brands (1 &lt;= start &lt; finish &lt;= 22,000,000 and finish-start &lt; 2000), print (in alphabetical order) the brands that will be used. See the I/O specifications for an example.</p>



## 입력


<ul>
<li>Line 1: Three space-separated integers, respectively: N, start, and finish.</li>
<li>Lines 2..N+1: Line i+1 contains a number (1..26) of characters that are the valid characters for position i in the RFID code</li>
</ul>

<p>&nbsp;</p>



## 출력


<p>Lines 1..finish-start+1: Line i contains RFID code # start+i-1</p>



## 소스코드

[소스코드 보기](New%20Cow%20Brands.cpp)