# 15183번: Musical Chairs

## 문제 설명


<p>Musical chairs is a game frequently played at children's parties. Players are seated in a circle facing outwards. When the music starts, the players have to stand up and move clockwise round the chairs. One chair is removed, and when the music stops the players all have to try to sit down on one of the chairs. The player who does not manage to sit down is out, and the game continues until there is just one player left, who is the winner.</p>



## 입력 형식


<p>The first line contains a single integer, N which is the number of players (1 &lt; N &lt;= 15). The next N lines have the names of the players. The length of player's name does not exceed 10.</p>

<p>The next line contains R, an integer which tells how many rounds are to be processed (0 &lt; R &lt; N). The next R lines each contain a pair of integers S and M, separated by a space. S is the number of the seat to be removed. Seats are numbered from 1 to the number of seats remaining in a clockwise direction.</p>

<p>M is the number of moves made before the music stops (0 &lt; M &lt;= 30). A move takes a player from one seat to the next in a clockwise direction. A move from the highest seat number takes a player to seat 1.</p>



## 출력 형식


<p>After each round has taken place, output a line</p>

<pre>&lt;name&gt; has been eliminated.</pre>

<p>where &lt;name&gt; is the name of the person who does not find a seat. This will be the person who would have ended up at the seat which was removed.</p>

<p>At the end of the specified number of moves, output a line which either says&nbsp;</p>

<pre>&lt;name&gt; has won.</pre>

<p>where a single player remains, or&nbsp;</p>

<pre>Players left are &lt;name list&gt;.</pre>

<p>where the game is not yet finished.&nbsp;</p>

<p>&lt;name list&gt; contains the name of each player not yet eliminated in the same order as in the input. The names are separated by spaces.</p>



## 예제

### 예제 입력 1

```
5
Anne
Bill
Chen
Di
Everet
4
3 6
2 8
1 5
2 6

```

### 예제 출력 1

```
Bill has been eliminated.
Anne has been eliminated.
Chen has been eliminated.
Everet has been eliminated.
Di has won.

```
          

### 예제 입력 2

```
6
Ferdinand
Garcia
Henrietta
Isabel
Jacob
Kirstin
3
6 10
5 1
2 30

```

### 예제 출력 2

```
Garcia has been eliminated.
Kirstin has been eliminated.
Jacob has been eliminated.
Players left are Ferdinand Henrietta Isabel.

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
  