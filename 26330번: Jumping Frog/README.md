# 26330번: Jumping Frog

## 문제 설명


<p>A frog is located at the coordinate (x<sub>1</sub>,y<sub>1</sub>). He wants to go to the coordinate (x<sub>2</sub>,y<sub>2</sub>). He will perform one or more jumps to reach his destination. The rule of the jumping is as follows: Suppose the frog is located at the coordinate (x,y); then he can jump to the following four squares:</p>

<ol>
<li>(x+y,y)</li>
<li>(x-y,y)</li>
<li>(x,y+x)</li>
<li>(x,y-x)</li>
</ol>

<p>Given the coordinates (x<sub>1</sub>,y<sub>1</sub>) and (x<sub>2</sub>,y<sub>2</sub>), you need to determine if it is possible for the frog to travel from (x<sub>1</sub>,y<sub>1</sub>) to (x<sub>2</sub>,y<sub>2</sub>) through a series of jumps as described.</p>



## 입력 형식


<p>The first input line contains an integer, n (1 ≤ n ≤ 100), indicating the number of test cases. Each test case consists of four integers (between -1,000,000,000 to +1,000,000,000 inclusive) separated by a single space denoting x<sub>1</sub>, y<sub>1</sub>, x<sub>2</sub> and y<sub>2</sub>, respectively.</p>



## 출력 형식


<p>For each test case, output 1 if the frog can travel from (x<sub>1</sub>,y<sub>1</sub>) to (x<sub>2</sub>,y<sub>2</sub>) through a series of jumps as described or 0 otherwise.</p>



## 예제

### 예제 입력 1

```
3
-6 8 17 25
13 17 -16 11
0 0 5 6

```

### 예제 출력 1

```
0
1
0

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
  