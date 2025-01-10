# 17390번: 이건 꼭 풀어야 해! - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/17390)


<p>숭실골 높은 언덕 깊은 골짜기에&nbsp;출제로 고통 받는 욱제가 살고 있다!</p>

<p>욱제는 또 출제를 해야 해서 단단히 화가 났다. 그래서 욱제는 길이 <em>N</em>짜리 수열 <em>A</em>를 만들고,&nbsp;<em>A</em>를 비내림차순으로 정렬해서 수열&nbsp;<em>B</em>를 만들어 버렸다!! 여기서 <em>B</em>를 출력하기만 하면 문제가 너무 쉬우니까 하나만 더 하자. 아래와 같은 질문이 무려 <em>Q</em>개나 주어진다!! (ㅎㅎ;; ㅈㅅ.. ㅋㅋ!!)</p>

<ul>
<li><strong>L&nbsp;R:</strong>&nbsp;<em>B<sub>L</sub> + B<sub>L+1</sub> + ... + B<sub>R-1</sub> + B<sub>R</sub></em> 을 출력한다.</li>
</ul>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/c849170d-749c-4743-9829-2136c89e2212/-/preview/"></p>

<p style="text-align: center;"><strong>Figure 1.</strong>&nbsp;모든 참가자가&nbsp;문제를 풀 수 있을 것이라고&nbsp;기대하는 욱제의 표정</p>

<p>욱제의 질문에 답하고 함께 엠티를 떠나자!!</p>



## 입력


<p>첫 번째 줄에 수열 <em>A</em>의 길이<em> N</em>과 질문의 개수<em> Q</em>가 공백으로 구분되어 주어진다. (1 ≤ <em>N</em>, <em>Q</em>&nbsp;≤ 300,000)</p>

<p>두 번째 줄에 <em>N</em>개의 정수 <em>A<sub>1</sub></em>, <em>A<sub>2</sub></em>, ..., <em>A<sub>N</sub></em> 이 공백으로 구분되어 주어진다. <em>A<sub>i</sub></em> 는 수열 <em>A</em>의 <em>i</em> 번째 수이다. (1&nbsp;≤ <em>A<sub>i</sub></em>&nbsp;≤ 1,000)</p>

<p>세 번째 줄부터 <em>Q</em>개의 줄에 걸쳐 욱제의 질문을 의미하는 두 수 <em>L</em>, <em>R</em>이 공백으로 구분되어 주어진다. (1&nbsp;≤ <em>L</em>&nbsp;≤ <em>R</em>&nbsp;≤ <em>N</em>)</p>

<p>주어지는 모든 입력은 자연수이다.</p>



## 출력


<p><em>Q</em>개의 줄에 걸쳐, 질문의 답을 순서대로 각각 출력한다.</p>



## 소스코드

[소스코드 보기](이건%20꼭%20풀어야%20해!.cpp)