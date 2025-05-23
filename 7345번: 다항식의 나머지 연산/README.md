# 7345번: 다항식의 나머지 연산 - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/7345)


<p>계수가 0 또는 1로만 이루어지는 특수한 다항식들의 집합에&nbsp;대해 생각해보자.</p>

<p>이 집합의 두 다항식을 더하는 방법은 다음과 같다.</p>

<ul>
<li>우선, 두 다항식을 더한다.</li>
<li>결과 다항식의&nbsp;각 계수를 2로 나눈 나머지를 각각의&nbsp;계수에 대입한다.</li>
</ul>

<p>이때,&nbsp;(0 + 0) mod 2 = 0, (0 + 1) mod 2 = 1, (1 + 0) mod 2 = 1, and (1 + 1) mod 2 = 0 이므로</p>

<p>결국 결과 다항식의 각 차수의 계수는 더하고자 했던 두 다항식의 계수에 대한 XOR 연산의 결과가 된다.</p>

<p>(x <sup>6</sup> + x<sup>4</sup> + x<sup>2</sup> + x + 1) + (x<sup>7</sup> + x + 1) = x<sup>7</sup> + x<sup>6</sup> + x<sup>4</sup> + x<sup>2</sup></p>

<p>이제 뺄셈을 정의하는데, 뺄셈의 경우에도 덧셈과 같이&nbsp;(0 - 0) mod 2 = 0, (0 -&nbsp;1) mod 2 = 1, (1 - 0) mod 2 = 1, and (1 - 1) mod 2 = 0 이므로<br>
덧셈과 뺄셈은 이 다항식들의&nbsp;집합에 대해 동일한 의미를 지닌다. (계수 간의 XOR 연산이 새 다항식의 계수가 됨)</p>

<p>예시는 다음과 같다.</p>

<p>(x <sup>6</sup> + x<sup>4</sup> + x<sup>2</sup> + x + 1) - (x<sup>7</sup> + x + 1) = x<sup>7</sup> + x<sup>6</sup> + x<sup>4</sup> + x<sup>2</sup></p>

<p>다음으로 곱셈을 정의하는데, 곱셈 또한 일반적인 다항식 간의 곱셈 연산을 한 뒤 각각의 계수를 2로 나눈 나머지를 취하면 된다.</p>

<p>(x <sup>6</sup> + x<sup>4</sup> + x<sup>2</sup> + x + 1) (x<sup>7</sup>+ x + 1) = x<sup>13</sup> + x<sup>11</sup> + x<sup>9</sup> + x<sup>8</sup> + x<sup>6</sup> + x<sup>5</sup> + x<sup>4</sup> + x<sup>3</sup> + 1</p>

<p>두 다항식 f(x)와 g(x)의 곱을 h(x)로 나눈 나머지는 f(x)와 g(x)를 위와 같은 방법으로 곱한 뒤, h(x)로 나눈 나머지가 된다.</p>

<p>(x <sup>6</sup> + x<sup>4</sup> + x<sup>2</sup> + x + 1) (x<sup>7</sup> + x + 1) modulo (x<sup>8</sup> + x<sup>4</sup> + x<sup>3</sup> + x + 1) = x<sup>7</sup> + x<sup>6</sup> + 1</p>

<p>어떤 다항식의 최고차항의 차수를 degree, 줄여서 d라 하면, f(x), g(x), h(x)의 계수가 0 또는 1이므로 각 다항식은&nbsp;정수 d+1과 길이 d+1인&nbsp;비트스트링의 쌍으로 유일하게&nbsp;표기할 수 있다. 다항식의 차수는 1000보다 작다.</p>

<p>예를 들어&nbsp;x <sup>7</sup> + x<sup>6</sup> + 1은 다음과 같이 표기된다.</p>

<p>8 1 1 0 0 0 0 0 1</p>

<p>이때, 8은 총 비트의 개수이며, 최고차항의 차수(7) + 1이다.</p>

<p>이제 위에서 설명한 성질을 만족하는&nbsp;세 다항식 f(x), g(x), h(x)가 설명한 형식대로&nbsp;주어지면 f(x)g(x) modulo h(x)를 계산하면 된다.</p>



## 입력


<p>입력은 여러 테스트 케이스로 이루어져 있다.</p>

<p>입력의 첫 줄에 테스트케이스의 수 T가 주어지며, 각 테스트 케이스마다 세 줄에 걸쳐&nbsp;문제에서 설명한 형식대로 표기한 f(x), g(x), h(x)가 주어진다.</p>



## 출력


<p>각 테스트 케이스마다 한 줄에&nbsp;f(x)g(x)를 h(x)로 나눈 나머지를&nbsp;문제에서 설명한 형식대로 출력한다.</p>



## 소스코드

[소스코드 보기](다항식의%20나머지%20연산.cpp)