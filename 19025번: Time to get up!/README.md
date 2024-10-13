# 19025번: Time to get up!

## 문제 설명


<p>Little Q's alarm is ringing! It's time to get up now! However, after reading the time on the clock, Little Q lies down and starts sleeping again. Well, he has five alarms, and it's just the first one, he can continue sleeping for a while.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/d9b66f26-5dc6-44dc-8fc0-f50d34972c0c/-/preview/" style="width: 320px; height: 48px;"></p>

<p>Little Q's clock uses a standard 7-segment LCD display for all digits, plus two small segments for the "<code>:</code>", and shows all times in 24-hour format. The "<code>:</code>" segments are on at all times.</p>

<p>Your job is to help Little Q read the time shown on his clock.</p>



## 입력 형식


<p>The first line of the input contains an integer $T$: the number of test cases ($1 \leq T \leq 1440$).</p>

<p>Each test case is given on seven lines as a $7 \times 21$ ASCII image of the clock screen.</p>

<p>Each digit segment is represented by two characters, and each colon segment is represented by one character. Character "<code>X</code>"&nbsp;indicates a lit segment, character "<code>.</code>" indicates a dark segment or empty space. See the sample input for details.</p>



## 출력 형식


<p>For each test case, print a single line containing a string $t$ formatted as "<code>HH:MM</code>": the time shown on the clock ($\texttt{00:00} \leq t \leq \texttt{23:59}$).</p>



## 예제

### 예제 입력 1

```
1
.XX...XX.....XX...XX.
X..X....X......X.X..X
X..X....X.X....X.X..X
......XX.....XX...XX.
X..X.X....X....X.X..X
X..X.X.........X.X..X
.XX...XX.....XX...XX.

```

### 예제 출력 1

```
02:38

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
  