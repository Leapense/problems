# 25882번: Simplified Keyboard

## 문제 설명


<p>Consider a simplified keyboard consisting of the 26 lowercase letters as illustrated below:</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/0ebf61c2-5efa-4446-bd24-643c024cc529/-/preview/" style="width: 216px; height: 68px;"></p>

<p>We define the neighbors of a key (letter) as all the letters adjacent to it. For example, the neighbors of ‘a’ are {b, k, j}, neighbors of ‘b’ are {a, c, l, k, j}, neighbors of ‘n’ are {d, e, f, o, x, w, v, m}, and neighbors of ‘z’ are {p, q, r, y}.</p>

<p>Given two words consisting of lowercase letters only, you are to determine which of the following three cases applies to them:</p>

<ol>
<li>identical: this is when the two words are of the same length and they match letter-byletter. For example, “cool” and “cool” are identical, “cool” and “col” are not, and “cool” and “colo” are not</li>
<li>similar: this is when the two words are of the same length, they are not identical words, and each corresponding two letters either match or are neighbors. For example, “aaaaa” and “abkja” are similar, “moon” and “done” are similar, “knq” and “bxz” are similar, but “ab” and “cb” are not (because of ‘a’ in the first word and the corresponding ‘c’ in the second word).</li>
<li>different: this is when neither of the above two cases applies to the two words, i.e., they are not identical and they are not similar. For example, “ab” and “abc” are different, “ab” and “az” are different, and “az” and “za” are different.</li>
</ol>



## 입력 형식


<p>The first input line contains a positive integer, n, indicating the number of test cases to process. Each of the following n input lines represents a test case, consisting of two words separated by one space. Each word consists of lowercase letters only and will be between 1 and 20 letters, inclusive.</p>



## 출력 형식


<p>For each test case, output one line. That line should contain the digit (number) 1, 2, or 3, to indicate which of the above three cases applies to the two input words.</p>



## 예제

### 예제 입력 1

```
7
a k
a a
a z
cool cool
aaaaa abkja
ab abc
az za

```

### 예제 출력 1

```
2
1
3
1
2
3
3

```
          




## 추가 테스트 케이스

추가로 테스트 하고 싶은 케이스를 적고 정리해 보세요.

### 추가 입력 1

```
<입력값>
```

### 추가 출력 1

```
<출력값>
```

### 추가 입력 2

```
<입력값>
```

### 추가 출력 2

```
<출력값>
```
  