# 26934번: The Bus Card

## 문제 설명


<p>You are going to purchase a bus card. It's a refillable card that cash can be deposited into, and then used to ride the bus until you are out of money. You know that you're planning to travel for $K$ Swedish crowns (SEK). Charging the card takes some time since you can only charge it with $100$, $200$ or $500$ SEK at a time.</p>

<p>At the moment you are in a hurry, so you want to make as few transactions as possible, but never insert more money than necessary. If you are to travel for $800$ SEK, this means you should load it with $500$, then $200$, and then $100$ SEK. On the other hand, if you are traveling for $850$ SEK you should load it first with $500$, and then $200$ SEK twice. $50$ SEK will be wasted, but it's still the best alternative.</p>

<p>Compute the minimum number of transactions necessary.</p>



## 입력 형식


<p>The input consists of the integer $K$ ($1 \le K \le 10\,000$), the amount you will travel for.</p>



## 출력 형식


<p>Output a single integer -- the number of transactions necessary.</p>



## 예제

### 예제 입력 1

```
850

```

### 예제 출력 1

```
3

```
          

### 예제 입력 2

```
1800

```

### 예제 출력 2

```
5

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
  