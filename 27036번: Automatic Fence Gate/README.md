# 27036번: Automatic Fence Gate

## 문제 설명


<p>Farmer John recently installed an electronic gate between his two fields.  He can control the gate from his home computer by sending it commands such as "raise 10 inches" and "lower 5 inches".</p>

<p>The gate is considered to be open when it is raised up as high as possible and it is closed when it is lowered to the ground level. FJ had carefully planned the sequence of gate raising and lowering instructions to be sent over the course of the day, but unfortunately a lightning storm scrambled the contents of FJ's computer.  His list of N (1 ≤ N ≤ 1000) instructions now appear out of order, for example like the following:</p>

<ul>
<li>11:30pm raise the gate 5 inches</li>
<li>10:05am lower the gate 3 inches</li>
<li>12:03pm raise the gate 6 inches</li>
<li>04:01am lower the gate 2 inches</li>
<li>... and so on.</li>
</ul>

<p>FJ had planned to execute these instructions in chronological order starting at midnight (12:00am) and ending at 11:59pm the same day. He remembers that his instructions would have caused the gate to completely close at least once.  Help him determine the total number of minutes the gate would have been closed if he were to execute his instructions in the order he originally planned.</p>



## 입력 형식


<ul>
<li>Line 1: The single integer N</li>
<li>Lines 2..1+N: Each line corresponds to an instruction and contains two space-separated fields.  The first is a 7-digit timestamp of the form HH:MMxx where HH denotes hours, MM denotes minutes, and xx is either am or pm. The second entry in each line is an integer indicating the number of inches to raise the gate (negative numbers mean lowering the gate).</li>
</ul>



## 출력 형식


<ul>
<li>* Line 1: A single integer, giving the number of minutes during the day that the  gate is completely closed.</li>
</ul>



## 예제

### 예제 입력 1

```
3
1:30pm 1
1:30am -10
1:00am 5

```

### 예제 출력 1

```
720

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
  