# 23369번: Fridge Distraction - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/23369)


<p>Kevin has an excellent organisation system for his refrigerator: everything is arranged on one long shelf. At the moment, every item is organised in alphabetical order from "a" at the front to "z" at the back.</p>

<p>When Kevin wants to get some item from the refrigerator, he simply pulls out everything in front of it, takes the item out, places all the other items back in their original order, and finally places the used item at the front when he is done. This takes a number of seconds equal to the total number of items taken out of the fridge.</p>

<p>You are planning a surprise birthday party for Kevin in which you and his other friends bought him a normal fridge. You will need to keep him busy for exactly the right amount of time -- and you will do this by repeatedly asking him to take items out of the fridge.</p>

<p>Given the amount of time you need to waste, in seconds, suggest an order of as little items as possible to be taken out, such that Kevin will take exactly this long.</p>



## 입력


<p>The input consists of:</p>

<ul>
<li>One line containing $n$ ($1 \leq n \leq 26$), the number of items in the refrigerator, and $t$ ($1 \leq t \leq 10000$), the number of seconds you need to waste.</li>
</ul>



## 출력


<p>Output the smallest possible number of items you should ask Kevin to take out of the fridge.</p>

<p>Next output one line containing, in order, the letters of all the items you will ask Kevin to take out of the fridge.</p>

<p>If there are multiple valid solutions, you may output any one of them.</p>



## 소스코드

[소스코드 보기](Fridge%20Distraction.cpp)