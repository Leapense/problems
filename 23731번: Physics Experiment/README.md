# 23731번: Physics Experiment

## 문제 설명


<p>Yunee is taking a physics lab class. One day, after an experiment, Yunee noticed that some figures in the experiment result came out lower than expected. So Yunee decided to manipulate the result by rounding the values several times.</p>

<p>When rounding a number to the $i$-th place, it is rounded down if the digit one place right to the $i$-th place is less than $5$. Otherwise, it is rounded up. For example, rounding $454$ to the nearest tens gives $450$. On the other hand, rounding $454$ to the nearest hundreds gives $500$.</p>

<p>By rounding $454$ to the nearest hundreds and then thousands, we get $454 \rightarrow 500 \rightarrow 1000$. This is the maximum value we can get by rounding $454$ zero or more times.</p>

<p>Help Yunee maximize the value in the experiment result by rounding it zero or more times.</p>



## 입력 형식


<p>The first line contains an integer $N$ representing the value in the experiment result $(1\le N \le 10^{15})$. <strong>Note that $N$ may exceed the 32-bit integer limit.</strong></p>



## 출력 형식


<p>Output the maximized value by rounding $N$ zero or more times. The output should not have leading zeros.</p>



## 예제

### 예제 입력 1

```
454

```

### 예제 출력 1

```
1000

```
          

### 예제 입력 2

```
4445

```

### 예제 출력 2

```
10000

```
          

### 예제 입력 3

```
1234321

```

### 예제 출력 3

```
1234321

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
  