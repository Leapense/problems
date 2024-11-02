# 32604번: Jumbled Scoreboards

## 문제 설명


<p>You were so hyped to attend the final game of the Ball And Paddle Competition, where the two best teams in the world compete to paddle as many balls into the opponent's goal as possible. But alas, you fell ill, and cannot join your friends. Luckily, your friends took lots of pictures during the match, and after the match concluded, they sent you all the pictures that they have. Because the messaging app uploads and downloads the pictures in parallel, you are wondering whether you received them in chronological order. It looks like the scoreboards in each picture are unique, and knowing that the score of a team can only increase over time, you should be able to figure this out. Feeling too sick to check the order of the pictures manually, you decide to write a program that checks temporal consistency based on the scoreboards that are in the picture.</p>

<p>Given a list of intermediate scores from the match, determine whether the scores are in chronological order.</p>



## 입력 형식


<p>The input consists of:</p>

<ul>
<li>One line with an integer $n$ ($1\leq n\leq 100$), the number of pictures you received.</li>
<li>$n$ lines, each with two integers $a$ and $b$ ($0 \leq a,b \leq 100$), the scores of the two teams in one of the pictures.</li>
</ul>

<p>Every pair of scores $(a, b)$ in the input is unique.</p>

<p>The order of the scores in the input is the order in which you received the pictures.</p>



## 출력 형식


<p>Output "<code>yes</code>" if the scores are in chronological order, or "<code>no</code>" if they are not.</p>



## 예제

### 예제 입력 1

```
4
1 0
2 0
4 0
4 1

```

### 예제 출력 1

```
yes

```
          

### 예제 입력 2

```
3
0 0
1 0
0 2

```

### 예제 출력 2

```
no

```
          

### 예제 입력 3

```
5
1 2
0 0
4 3
2 3
5 5

```

### 예제 출력 3

```
no

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
  