# 10859번: 뒤집어진 소수 - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/10859)


<p>어제 자다가 알람 시계를 떨어뜨렸는지, 08:15분이 51:80분이 되어 있었다. 그때 나는 디지털로 표시된 어떤 숫자는 180도 뒤집혔을 때도 숫자가 될 수 있다는 걸 깨달았다.</p>

<p style="text-align:center"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/10859/f1.png" style="height:80px; width:302px"></p>

<p style="text-align:center">소수 18115211이 디지털로 표시된 그림</p>

<p style="text-align:center"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/10859/f2.png" style="height:75px; width:300px"></p>

<p style="text-align:center">18115211이 180도 뒤집혀서 11251181이 되었다. (소수가 아님)</p>

<ul>
<li><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/10859/0.png" style="height:34px; width:21px">, <img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/10859/2.png" style="height:34px; line-height:20.7999992370605px; width:21px">, <img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/10859/5.png" style="height:34px; line-height:20.7999992370605px; width:21px">,&nbsp;<img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/10859/8.png" style="height:34px; line-height:20.7999992370605px; width:21px">&nbsp;은 뒤집혀서도&nbsp;<img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/10859/0.png" style="height:34px; line-height:20.7999992370605px; width:21px">, <img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/10859/2.png" style="height:34px; line-height:20.7999992370605px; width:21px">, <img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/10859/5.png" style="height:34px; line-height:20.7999992370605px; width:21px">, <img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/10859/8.png" style="height:34px; line-height:20.7999992370605px; width:21px">&nbsp;그대로이다.</li>
<li><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/10859/1.png" style="height:34px; line-height:20.7999992370605px; width:21px"> 은 그냥 왼쪽으로 옮겨진다.&nbsp;<img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/10859/11.png" style="height:34px; line-height:20.7999992370605px; width:21px"></li>
<li><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/10859/6.png" style="height:34px; line-height:20.7999992370605px; width:21px"> 은 <img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/10859/9.png" style="height:34px; line-height:20.7999992370605px; width:21px">가 되고,&nbsp;<img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/10859/9.png" style="height:34px; line-height:20.7999992370605px; width:21px"> 는 <img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/10859/6.png" style="height:34px; line-height:20.7999992370605px; width:21px">이 된다.</li>
<li><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/10859/3.png" style="height:34px; line-height:20.7999992370605px; width:21px">, <img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/10859/4.png" style="height:34px; line-height:20.7999992370605px; width:21px">,&nbsp;<img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/10859/7.png" style="height:34px; line-height:20.7999992370605px; width:21px">&nbsp;은 더 이상 숫자가 아니다. (<img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/10859/E.png" style="height:34px; line-height:20.7999992370605px; width:21px">, <img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/10859/h.png" style="height:34px; line-height:20.7999992370605px; width:21px">,&nbsp;<img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/10859/L.png" style="height:34px; line-height:20.7999992370605px; width:21px">)</li>
</ul>

<p>내가 좋아하는 숫자는 소수이다. 당신이 할 일은 주어진 숫자가 소수인지, 뒤집혀서도 소수인지 확인하는 것이다.</p>



## 입력


<p>첫 번째 줄에 N이 주어진다 (1 ≤ N ≤ 10<sup>16</sup>).</p>

<p>N의 첫 숫자는 0이 아니다.</p>



## 출력


<p>첫 번째 줄에 N이 소수이고 뒤집혀서도 소수이면 "yes"를 출력하고, 아니면 "no"를 출력한다.</p>



## 소스코드

[소스코드 보기](뒤집어진%20소수.cpp)