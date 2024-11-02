# 9953번: Paula's search - <img src="https://static.solved.ac/tier_small/6.svg" style="height:20px" /> Silver V

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/9953)


<p>Paula is searching for the perfect pink ball dress. In her High Street are 100 shops spread evenly along both sides of the street, odd numbers on one side, even numbers on the other as usual.</p>

<p>Paula always begins her search by going into the nearest shop to her home, which is shop 50, right in the middle of the even numbered side of the road. The shop owners all know where her dress of choice is, but they like to offer Paula a challenge, so they have agreed to tell her only one of 4 things:</p>

<ol>
<li>Yes, I have the perfect dress for you!</li>
<li>You are on the wrong side of the road, cross over.</li>
<li>You need to look down this side of the street (amongst the lower numbered shops).</li>
<li>You need to look up this side of the street (amongst the higher numbered shops).</li>
</ol>

<p>If Paula gets answer 1, she buys the dress and goes home. If she gets answers 2, 3 or 4, Paula always goes to the mid point of the block of shops in which she has to search (if there is an even number of shops, she goes to the lower numbered of the two middle shops). Here the shop owner gives her one of the 4 responses and Paula continues her search if necessary.</p>



## 입력


<p>Input will be a number of scenarios, each one being a single integer (between 1 and 100 inclusive) on a line on its own representing the number of the shop where Paula will find her perfect pink ball dress. Input will be terminated by a single 0, this line should not be processed.</p>



## 출력


<p>Output will be a single integer (on a line on its own) for each line of input. The integer will be the number of shops Paula had to visit in order to buy her dress.</p>



## 소스코드

[소스코드 보기](Paula's%20search.cpp)