# 23717번: Painter

## 문제 설명


<p>You have recently started to study how to paint, and in one of the first classes you learned about the three primary colors:&nbsp;<i>Red</i>,&nbsp;<i>Yellow</i>, and&nbsp;<i>Blue</i>. If you combine these colors, you can produce many more colors. For now, the combinations that you have studied are the following:</p>

<ul>
<li><i>Red</i>&nbsp;+&nbsp;<i>Yellow</i>&nbsp;=&nbsp;<i>Orange</i></li>
<li><i>Red</i>&nbsp;+&nbsp;<i>Blue</i>&nbsp;=&nbsp;<i>Purple</i></li>
<li><i>Yellow</i>&nbsp;+&nbsp;<i>Blue</i>&nbsp;=&nbsp;<i>Green</i></li>
<li><i>Red</i>&nbsp;+&nbsp;<i>Yellow</i>&nbsp;+&nbsp;<i>Blue</i>&nbsp;=&nbsp;<i>Gray</i></li>
</ul>

<p>You still do not understand shades of colors, therefore the proportion and order of each color in the combination does not matter. For example, combining&nbsp;<i>Red</i>&nbsp;and&nbsp;<i>Yellow</i>&nbsp;produces the same result as combining&nbsp;<i>Yellow</i>&nbsp;and&nbsp;<i>Red</i>, as well as the same result as combining&nbsp;<i>Red</i>,&nbsp;<i>Yellow</i>, and&nbsp;<i>Red</i>&nbsp;again.</p>

<p>To practice your skills, you want to paint a 1-dimensional painting&nbsp;$P$&nbsp;of length&nbsp;$N$. Your painting consists of&nbsp;$N$&nbsp;squares. From left to right,&nbsp;$P_i$&nbsp;represents the color of the $i-th square. Initially all squares are&nbsp;<i>Uncolored</i>, that is,&nbsp;$P_i$&nbsp;=&nbsp;<i>Uncolored</i>&nbsp;for every&nbsp;$1≤i≤N$.</p>

<p>In a single stroke, you can choose one of the three primary colors and apply it to a sequence of consecutive squares. In other words, you can choose a color&nbsp;$c$&nbsp;and two integers&nbsp;$l$&nbsp;and&nbsp;$r$, such that&nbsp;$1≤l≤r≤N$, and apply color&nbsp;$c$&nbsp;to all squares&nbsp;$P_j$&nbsp;such that&nbsp;$l≤j≤r$. If the square being painted is currently&nbsp;<i>Uncolored</i>, then its color will become&nbsp;$c$. Otherwise, the color will be a combination of all the colors applied on this square so far and the new color&nbsp;$c$, as described in the list above.</p>

<p>In order to save time, you want to use as few strokes as possible. Given the description of the painting that you want to paint, figure out what is the minimum number of strokes required to paint it.</p>



## 입력 형식


<p>The first line of the input gives the number of test cases, $T$.&nbsp;$T$&nbsp;test cases follow.</p>

<p>Each test case starts with a line containing an integer&nbsp;$N$, representing the length of the painting. Then on the next line, there will be a string&nbsp;$P$&nbsp;of length&nbsp;$N$, representing the painting. The&nbsp;$i$-th character represents the color of square $P_i$, according to the following list:</p>

<ul>
<li><code>U</code>&nbsp;=&nbsp;<i>Uncolored</i></li>
<li><code>R</code>&nbsp;=&nbsp;<i>Red</i></li>
<li><code>Y</code>&nbsp;=&nbsp;<i>Yellow</i></li>
<li><code>B</code>&nbsp;=&nbsp;<i>Blue</i></li>
<li><code>O</code>&nbsp;=&nbsp;<i>Orange</i></li>
<li><code>P</code>&nbsp;=&nbsp;<i>Purple</i></li>
<li><code>G</code>&nbsp;=&nbsp;<i>Green</i></li>
<li><code>A</code>&nbsp;=&nbsp;<i>Gray</i></li>
</ul>



## 출력 형식


<p>For each test case, output one line containing&nbsp;<code>Case #x: y</code>, where&nbsp;$x$ is the test case number (starting from 1) and&nbsp;$y$&nbsp;is the minimum number of strokes required to paint the painting.</p>



## 예제

### 예제 입력 1

```
2
9
YYYBBBYYY
6
YYGGBB

```

### 예제 출력 1

```
Case #1: 3
Case #2: 2

```
          

### 예제 입력 2

```
1
5
ROAOR

```

### 예제 출력 2

```
Case #1: 3

```
          

## 제한
제한 시간 : 
			<ul>
	<li>$1≤T≤100$.</li>
	<li>$1≤N≤10^5$.</li>
</ul>
			 초
제한 메모리 : undefined MB


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
  