# 31825번: 알파벳과 쿼리 (Easy) - <img src="https://static.solved.ac/tier_small/6.svg" style="height:20px" /> Silver V

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/31825)


<p><strong>Hard 버전과 $N$, $Q$의 제한을 제외한 문제 차이는 없다.</strong></p>

<p>다음 조건들을 만족하는 부분 문자열을 <strong>알파벳 묶음</strong>이라고 하자.</p>

<ul>
<li>하나의 동일한 알파벳으로만 문자열이 이루어져 있어야 한다.</li>
<li>전체 문자열에서 해당 부분 문자열을 포함한 길이가 더 긴 부분 문자열로 알파벳 묶음을 만들 수 있으면 그 부분 문자열은 알파벳 묶음이 아니다.</li>
</ul>

<p>예를 들어 "<code>AAABBAAC</code>"와 같은 문자열이 있을 때, <strong>알파벳 묶음</strong>은 "<code>AAA</code>", "<code>BB</code>", "<code>AA</code>", "<code>C</code>"로 4개다. 위의 문자열에서 "<code>B</code>", "<code>AC</code>"는 조건을 만족하지 않으므로 <strong>알파벳 묶음</strong>이 아니다.</p>

<p>영어 알파벳 대문자로만 이루어진 길이가 $N$인 문자열 $S = S_1 S_2 \dots S_N$가 주어질 때, 다음 쿼리를 수행하는 프로그램을 작성하자.</p>

<ul>
<li>$1 \ l \ r$ : 부분 문자열 $S_l S_{l+1} \dots S_r$에서 <strong>알파벳 묶음</strong>의 개수를 출력한다.</li>
<li>$2 \ l \ r$ : 부분 문자열 $S_l S_{l+1} \dots S_r$의 모든 알파벳을 각각 알파벳 순서로 다음인 알파벳으로 변경한다. 단, <code><span color="#e74c3c">Z</span></code>인 경우 <code><span style="color:#e74c3c">A</span></code>로 변경한다.</li>
</ul>

<p>$S_l S_{l+1} \dots S_r$는 $S$의 $l$번째 알파벳부터 $r$번째 알파벳까지를 모두 순서대로 포함하는 부분 문자열이다.</p>



## 입력


<p>첫 번째 줄에 문자열의 길이 $N$과 쿼리의 개수 $Q$가 공백으로 구분되어 주어진다. $(3 \leq N, Q \leq 200)$</p>

<p>두 번째 줄에 영어 알파벳 대문자로만 이루어진 길이가 $N$인 문자열 $S$가 주어진다.</p>

<p>세 번째 줄부터 $Q$개의 줄에 걸쳐 쿼리가 한 줄에 하나씩 주어진다. $(1 \leq l \leq r \leq N)$</p>

<p>$1$번 쿼리는 한 번 이상 주어진다.</p>



## 출력


<p>$1$번 쿼리에 대한 결괏값을 한 줄에 하나씩 입력으로 주어진 순서대로 출력한다.</p>



## 소스코드

[소스코드 보기](알파벳과%20쿼리%20(Easy).cpp)