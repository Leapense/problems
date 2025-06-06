# 31747번: 점호 - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/31747)


<p>당신은 서울과학고등학교 1학년으로, 기상곡이 울리자마자 기숙사 2층으로 달려나가 아침 점호 줄을 섰습니다. 하지만 당신은 늦어버렸고, 당신 앞에 이미 $N$명의 1학년과 2학년 학생이 서 있음을 알게 되었습니다. 당신은 이 $N$명이 모두 점호를 끝내기까지의 시간을 알고 싶습니다.현재 $p$명이 점호 줄에 서 있을 때, 점호의 규칙은 다음과 같습니다.</p>

<ul>
<li>줄의 가장 앞에 있는 $\min(K,p)$명 중 1학년이 있으면 가장 앞에 있는 1학년이 점호를 하고 줄에서 빠지고, 2학년이 있으면 가장 앞에 있는 2학년이 점호를 하고 줄에서 빠집니다. <strong>1학년과 2학년이 둘 다 있다면, 가장 앞에 있는 1학년 학생과 가장 앞에 있는 2학년 학생이 동시에 줄에서 빠집니다.</strong></li>
<li>위 과정은 1학년과 2학년에 대해 동시에 일어나며, 시간 $1$이 걸립니다.</li>
</ul>

<p>$N$명이 모두 점호를 끝내기까지 걸리는 시간을 구하는 프로그램을 작성하세요.</p>



## 입력


<p>첫째 줄에 $N$, $K$가 띄어쓰기를 사이에 두고 주어집니다.둘째 줄에 $A_1$, $A_2$, $\cdots$, $A_N$이 띄어쓰기를 사이에 두고 주어집니다. $A$는 줄의 상태를 나타내는 수열이며, 앞에서부터 $i$번째 학생이 1학년이면 $A_i=1$, 2학년이면 $A_i=2$의 값을 가집니다.</p>



## 출력


<p>첫째 줄에 $N$명의 학생이 모두 점호를 끝내기까지 걸리는 시간을 출력합니다.</p>



## 소스코드

[소스코드 보기](점호.cpp)