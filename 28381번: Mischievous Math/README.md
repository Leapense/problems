# 28381번: Mischievous Math

## 문제 설명


<p>Max enjoys playing number games, whether it involves finding a combination that leads to a given result or discovering all possible results for some given integers. The problem is that Max is only 10 and has limited mathematical knowledge, which restricts the possibilities for these games. Luckily, in today's maths class, Max learned the concept of parentheses and their effects on calculations. He realises that incorporating parentheses into his number games could make them much more interesting. After getting home from school, he asked his sister Nina to play a variant of his favourite number game with him, using parentheses.</p>

<p>In this new game, Max first tells her a number $d$. Nina then tells him three numbers $a$, $b$ and $c$. Now, Max needs to find an arithmetic expression using addition, subtraction, multiplication and division, using each of these three numbers ($a$, $b$ and $c$) at most once, such that the result is equal to $d$. The numbers $a, b, c$ and $d$ all have to be distinct, and Max is allowed to use parentheses as well.</p>

<p>For instance, for $a = 5$, $b = 8$, $c = 17$ and $d = 96$ a possible solution would be $(17 - 5) \times 8 = 96$, and for $a = 3$, $b = 7$, $c = 84$ and $d = 12$ a possible solution would be $84 \div 7 = 12$, without using the $3$.</p>

<p>Nina is quickly annoyed by this game. She would rather spend the afternoon with her friends instead of playing games with her little brother. Therefore, she wants to give him a task that occupies him for as long as possible. Help her to find three numbers $a$, $b$ and $c$ such that it is impossible for Max to come up with a solution.</p>



## 입력 형식


<p>The input consists of:</p>

<ul>
<li>One line with an integer $d$ ($1 \le d \le 100$), Max's chosen number.</li>
</ul>



## 출력 형식


<p>Output three numbers $a$, $b$ and $c$ ($1 \le a,b,c \le 100$) such that the numbers $a$, $b$, $c$ and $d$ are pairwise distinct and there is no solution to the number game.</p>



## 예제

### 예제 입력 1

```
5

```

### 예제 출력 1

```
1 20 30

```
          

### 예제 입력 2

```
100

```

### 예제 출력 2

```
33 55 77

```
          

### 예제 입력 3

```
3

```

### 예제 출력 3

```
11 9 4

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
  