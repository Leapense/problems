# 18018번: Alphabet Animals

## 문제 설명


<p>You are playing a game in which a group of players take turns saying animal names. The animal name you say when it is your turn must start with the same letter as the previously said animal ends with and it must not have been said previously in this round of the game. If there is no valid name or you cannot come up with one you are eliminated.</p>

<p>Given the last animal name said before your turn and a list of all names not yet used, can you make it through this turn? If so, can you make sure to eliminate the next player?</p>



## 입력 형식


<p>The first line of input contains a single word, the animal that the previous player just said. The next line contains a single integer n (0 ≤ n ≤ 10<sup>5</sup>), the number of valid unused animal names. Each of the following n lines contains one valid unused animal name.</p>

<p>All animal names (including the one the previous player said) are unique and consist of at least 1 and at most 20 lower case letters ‘a’-‘z’.</p>



## 출력 형식


<p>If there is any animal name you can play that eliminates the next player, output the first such name from the input list, followed by an exclamation mark. Otherwise, if there is any animal name that you can play, output the first such name. Otherwise, output a question mark (in this case you will just have to make up a fake name in the hope that the others will trust you that this is a real animal).</p>



## 예제

### 예제 입력 1

```
pig
2
goat
toad

```

### 예제 출력 1

```
goat

```
          

### 예제 입력 2

```
dog
2
snake
emu

```

### 예제 출력 2

```
?

```
          

### 예제 입력 3

```
hare
3
bee
cat
eagle

```

### 예제 출력 3

```
eagle!

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
  