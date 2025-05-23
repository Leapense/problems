# 30046번: HJS - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/30046)


<p>2123년에는 수를 표현하는 색다른 방식인 "홍진수"가 존재한다.</p>

<p>홍진수는 총 3가지의 문자 <span style="color:#e74c3c;"><code>H</code></span>, <span style="color:#e74c3c;"><code>J</code></span>, <span style="color:#e74c3c;"><code>S</code></span>로 이루어진 문자열로, 각 문자 <span style="color:#e74c3c;"><code>H</code></span>, <span style="color:#e74c3c;"><code>J</code></span>, <span style="color:#e74c3c;"><code>S</code></span>에 $1$부터 $9$까지의 숫자를 서로 <strong>중복되지 않게</strong> 하나씩 대입하여 수를 표현할 수 있다. 예를 들어, 홍진수 <span style="color:#e74c3c;"><code>HJSHJH</code></span>는 $358353$, $914919$는 표현할 수 있지만, $131131$, $555555$는 표현할 수 없다.</p>

<p>길이가 같은 세 개의 홍진수 $P$, $Q$, $R$이 주어졌을 때, 각 홍진수가 표현하는 수 $p$, $q$, $r$이 $p&lt;q&lt;r$을 만족하게 하는 <span style="color:#e74c3c;"><code>H</code></span>, <span style="color:#e74c3c;"><code>J</code></span>, <span style="color:#e74c3c;"><code>S</code></span>가 존재하는지 확인하자. <span style="color:#e74c3c;"><code>H</code></span>, <span style="color:#e74c3c;"><code>J</code></span>, <span style="color:#e74c3c;"><code>S</code></span>에 대입한 수는 $P$, $Q$, $R$이 모두 공유한다.</p>



## 입력


<p>첫 번째 줄에는 $P$, $Q$, $R$의 길이 $N$이 주어진다. 두 번째 줄부터 세 개의 줄에 걸쳐 문자열 $P$, $Q$, $R$이 차례대로 주어진다. $(1 \le N \le 300\,000)$</p>



## 출력


<p>첫 번째 줄에 조건에 맞는 <span style="color:#e74c3c;"><code>H</code></span>, <span style="color:#e74c3c;"><code>J</code></span>, <span style="color:#e74c3c;"><code>S</code></span>가 존재한다면 <span style="color:#e74c3c;"><code>HJS! HJS! HJS!</code></span>를 출력하고, 그렇지 않으면 <span style="color:#e74c3c;"><code>Hmm...</code></span>를 출력한다.</p>



## 소스코드

[소스코드 보기](Main.java)