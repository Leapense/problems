# 24928번: Magical Runes

## 문제 설명


<p>You maintain a very nice collection of magical runes. They generally come in two types, type&nbsp;<code>A</code>&nbsp;and type&nbsp;<code>B</code>.</p>

<p>You have arranged your runes on a shelf to show them off. Because they are magical runes, they change each day. That is, at the start of each day the leftmost rune will switch its type (i.e. from&nbsp;<code>A</code>&nbsp;to&nbsp;<code>B</code>&nbsp;or from&nbsp;<code>B</code>&nbsp;to&nbsp;<code>A</code>, depending on its type just before the start of the day). Every other rune will only change if the type of the rune to its left changes from&nbsp;<code>B</code>&nbsp;to&nbsp;<code>A</code>.</p>

<p>For example, if you have three runes initially arranged like&nbsp;<code>ABBAA</code>, then at the start of the next day only the leftmost rune will change and the sequence will look like&nbsp;<code>BBBAA</code>. After another day, the leftmost rune will change, but then the second rune from the left will change because the rune beside it changed from&nbsp;<code>B</code>&nbsp;to&nbsp;<code>A</code>. But then the third rune will also change for the same reason. And then the fourth rune will also change! That is, after the changes at the start of this day the runes will look like&nbsp;<code>AAABA</code>.</p>

<p>Your task is the following. Given the initial states $S$ of an initial arrangement of runes and given a number of days&nbsp;𝐷D, you should determine the states of the runes after $D$ days have elapsed.</p>



## 입력 형식


<p>Input consists of a single line that first begins with a string $S$ followed by an integer $D$. The length of $S$ will be between&nbsp;$1$&nbsp;and&nbsp;$30$&nbsp;(inclusive) and $S$ will consist only of characters&nbsp;<code>A</code>&nbsp;and&nbsp;<code>B</code>. The value&nbsp;$D$&nbsp;satisfies&nbsp;$0≤D&lt;2^{30}$.</p>

<p>Finally, you are also guaranteed that the rightmost rune does not change from&nbsp;<code>B</code>&nbsp;to&nbsp;<code>A</code>&nbsp;at the start of any of the&nbsp;$D$&nbsp;days that you are to consider.</p>



## 출력 형식


<p>Display a single string showing the states of the runes after $D$ days have elapsed, given they started in state $S$.</p>



## 예제

### 예제 입력 1

```
ABBAA 2

```

### 예제 출력 1

```
AAABA

```
          

### 예제 입력 2

```
ABAA 4

```

### 예제 출력 2

```
ABBA

```
          

### 예제 입력 3

```
ABBABBABBABBABBABBABBABBABBABA 536870912

```

### 예제 출력 3

```
ABBABBABBABBABBABBABBABBABBABB

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
  