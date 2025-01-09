# 17175번: 피보나치는 지겨웡~ - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/17175)


<p>혁진이는 알고리즘 문제를 만들라는 독촉을 받아 스트레스다. 하지만 피보나치 문제는 너무 많이 봐서 지겹기 그지없다. 그러나 문제를 만들 시간이 없는 혁진이는 피보나치 문제를 응용해서 문제를 만들려 한다.</p>


<pre>int fibonacci(int n) { // 호출
  if (n &lt; 2) {
    return n;
  }  
  return fibonacci(n-2) + fibonacci(n-1);
}</pre>


<p>위와 같이 코딩하였을 때&nbsp;<em><code>fibonacci(n)</code></em>를 입력했을 때에&nbsp;<em><code>fibonacci</code>&nbsp;</em>함수가 호출되는 횟수를 계산해보자.</p>



## 입력


<p><em>fibonacci&nbsp;</em>함수에 인자로 입력할 <em>n</em>이 주어진다. (0 ≤ <em>n</em>&nbsp;≤ 50)</p>



## 출력


<p><em>fibonacci&nbsp;</em>함수가 호출된 횟수를 출력한다.</p>

<p>출력값이 매우 커질 수 있으므로 정답을&nbsp;1,000,000,007 로 나눈 나머지를 출력한다.</p>



## 소스코드

[소스코드 보기](피보나치는%20지겨웡~.cpp)