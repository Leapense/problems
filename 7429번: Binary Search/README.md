# 7429번: Binary Search - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/7429)


<p>The program fragment below performs binary search of an integer number in an array that is sorted in a nondescending order:</p>

<pre>#define MAXN 10000

int A[MAXN];
int N;

void BinarySearch(int x)
{
  int p, q, i, L;

&nbsp; p = 0; /* Left border of the search */
  q = N-1; /* Right border of the search */
  L = 0; /* Comparison counter */
  while (p &lt;= q) {
    i = (p + q) / 2;
    ++L;
    if (A[i] == x) {
      printf("Found item i = %d"
        " in L = %d comparisons\n", i, L);
      return;
    }
    if (x &lt; A[i])
      q = i - 1;
    else
      p = i + 1;
  }
}</pre>

<p>Before <code>BinarySearch</code> was called, N was set to some integer number from 1 to 10000 inclusive and array A was filled with a nondescending integer sequence.</p>

<p>It is known that the procedure has terminated with the message "<code>Found item i = XXX in L = XXX comparisons</code>" with some known values of <code>i</code> and <code>L</code>.</p>

<p>Your task is to write a program that finds all possible values of <code>N</code> that could lead to such message. However, the number of possible values of <code>N</code> can be quite big. Thus, you are asked to group all consecutive <code>N</code>s into intervals and write down only first and last value in each interval.</p>



## 입력


<p>The input file consists of a single line with two integers <code>i</code> and <code>L</code> (0 ≤ <code>i</code> &lt; 10000 and 1 ≤ <code>L</code> ≤ 14), separated by a space.</p>



## 출력


<p>On the first line of the output file write the single integer number K representing the total number of intervals for possible values of <code>N</code>. Then K lines shall follow listing those intervals in an ascending order. Each line shall contain two integers A<sub>i</sub>&nbsp;and B<sub>i</sub>&nbsp;(A<sub>i</sub> = B<sub>i</sub>) separated by a space, representing first and last value of the interval.</p>

<p>If there are no possible values of <code>N</code> exist, then the output file shall contain the single 0.</p>



## 소스코드

[소스코드 보기](Binary%20Search.cpp)