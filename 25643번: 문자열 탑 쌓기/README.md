# 25643번: 문자열 탑 쌓기 - <img src="https://static.solved.ac/tier_small/5.svg" style="height:20px" /> Bronze I

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/25643)


<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/1c9437d8-61d6-4151-83ed-c5d7088a4195/-/crop/4000x1545/0,455/-/preview/" style="height: 232px; width: 600px;"></p>

<p>인경이는 $N$개의 문자열을 쌓아서 문자열 탑을 완성하려고 한다. 탑을 완성하기 위해서는 모든 문자열을 한 층에 하나씩 아래에서부터 순서대로 쌓아 올려야 한다.</p>

<p>인경이는 문자열 탑의 꼭대기에 다음 순서의 문자열을 쌓을 수 있다. 단, 탑을 튼튼하게 만들기 위해서 탑의 꼭대기에 위치한 문자열과 새로 쌓으려는 문자열이 <strong>둘이 겹치는 부분이 완전히 동일</strong>하게 쌓아야 한다. 가장 첫 문자열인 경우는 바닥에 아무렇게나 쌓을 수 있다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/d9094d8d-b9d1-4e61-9ef3-ad05aba6d9ca/-/preview/" style="width: 450px;"> <img alt="" src="https://upload.acmicpc.net/0c0cd21c-3a51-4b06-9d19-34da9456572b/-/preview/" style="width: 450px"></p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/cbb48a1d-2665-48f2-bcb8-2f7f3055c105/-/preview/" style="width: 450px;"> <img alt="" src="https://upload.acmicpc.net/fd6d3fba-c892-4afa-8b54-864b30e72a79/-/preview/" style="width: 450px;"></p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/f2cbaeb9-2712-46bf-a847-d111f7e5531f/-/preview/" style="height: 154px;"></p>

<p>예를 들어, <code>abc</code> 위에 <code>cab</code> 를 쌓는다고 할 때, 일부가 겹치게 쌓는 경우의 수는 위와 같이 $5$개가 있다. 그 중에서 <code>abc</code>와 <code>cab</code>가 겹치는 부분이 완전히 동일한 경우만 쌓을 수 있다.</p>

<p>인경이가 문자열을 잘 쌓는다면 $N$개의 문자열을 순서대로 쌓아서 문자열 탑을 완성하는 것이 가능할까?</p>



## 입력


<p>첫째 줄에 주어지는 문자열의 개수 $N(1\le N \le 100)$과 문자열의 길이 $M(1\le M \le 100)$이 주어진다.</p>

<p>둘째 줄부터 $N$개의 줄에 $s_1, s_2, ... ,s_N$이 주어진다. $s_i$는 $i$번째로 쌓는 문자열을 의미한다. 주어지는 모든 문자열은 길이가 $M$이며 알파벳 소문자로만 이루어져 있다.</p>



## 출력


<p>모든 문자열을 순서대로 쌓아서 탑을 완성할 수 있다면 <code>1</code> 을 그렇지 않다면 <code>0</code> 을 출력한다.</p>



## 소스코드

[소스코드 보기](문자열%20탑%20쌓기.cpp)