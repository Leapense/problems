# 12186번: Sort a scrambled itinerary (Small) - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/12186)


<p>Once upon a day, Mary bought a one-way ticket from somewhere to somewhere with some flight transfers.</p>

<p>For example: SFO-&gt;DFW DFW-&gt;JFK JFK-&gt;MIA MIA-&gt;ORD.</p>

<p>Obviously, transfer flights at a city twice or more doesn't make any sense. So Mary will not do that.</p>

<p>Unfortunately, after she received the tickets, she messed up the tickets and she forgot the order of the ticket.</p>

<p>Help Mary rearrange the tickets to make the tickets in correct order.</p>



## 입력


<p>The first line contains the number of test cases&nbsp;<b>T</b>, after which&nbsp;<b>T</b>&nbsp;cases follow.</p>

<p>For each case, it starts with an integer&nbsp;<b>N</b>. There are&nbsp;<b>N</b>&nbsp;flight tickets follow.</p>

<p>Each of the next 2 lines contains the source and destination of a flight ticket.</p>



## 출력


<p>For each test case, output one line containing "Case #x: itinerary", where&nbsp;<b>x</b>&nbsp;is the test case number (starting from 1) and&nbsp;<b>itinerary</b>&nbsp;is sorted list of flight tickets which represents the actual itinerary. Each flight segment in the itinerary should be outputted as pair of source-destination airport codes.</p>



## 소스코드

[소스코드 보기](Sort%20a%20scrambled%20itinerary%20(Small).cpp)