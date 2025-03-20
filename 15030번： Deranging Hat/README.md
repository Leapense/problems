# 15030번: Deranging Hat - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/15030)


<p>In the wizarding world of security, there are two kinds of researcher: the idealist arranging hat and the mercenary deranging hat.</p>

<p>As we learned last year, an arranging hat carefully sorts out any list of letters given to it into ascending order. However, a deranging hat performs the exact opposite function: putting a sorted string of letters back into its original order.</p>

<p>The tool of choice for today’s discerning headwear is a sorting network: a sequence of instructions represented by a list of pairs of numbers A<sub>i</sub> and B<sub>i</sub>, meaning that if at step i the A-th item in the string is not already smaller than the B-th item, they should be swapped immediately.</p>

<p>Given a specific word W, output a sorting network that the deranging hat can use to form the word from its original sorted letters.</p>



## 입력


<p>One line containing one string of lowercase Latin letters (‘a’-‘z’), S, containing at most 1000 characters.</p>



## 출력


<p>Output at most 10000 lines, each containing two integers A<sub>i</sub> and B<sub>i</sub> (1 ≤ A<sub>i</sub>, B<sub>i</sub> ≤ |S|) giving the i-th operation to perform.</p>



## 소스코드

[소스코드 보기](Deranging%20Hat.cpp)