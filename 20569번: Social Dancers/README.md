# 20569번: Social Dancers

## 문제 설명


<p>Community social dance classes are a great way to meet new people. A typical introductory social dance class covers a variety of dance styles, but they all have some basic structural elements in common. Most social dances are set up for two people: one lead and one follow.</p>

<p>The local social dance club teaches three types of dances to its students: swing, country, and bachata. At the final dance of the semester, each student knows some subset of these three dances. To keep the students on their toes, the instructors play songs from all three styles. The students are well trained, so they know immediately what kind of dance they should do depending on the song played.</p>

<p>When a lead asks a follow to dance, they compare which dances they know. There are three possibilities for what a lead-follow pair does when a song comes on:</p>

<ol>
<li>Both people know how to dance to this song. They dance.</li>
<li>Neither person knows how to dance to this song. They sit out and have a nice conversation.</li>
<li>Exactly one person knows how to dance to this song. The person who does not turns bright red, gets embarrassed and flustered, and runs out of the dance hall, tripping over a cable on their way out, knocking over a candle, which sets the dance hall on fire.</li>
</ol>

<p>The third case may be a bit of an exaggeration, but the students refuse to pair up if it's a possibility that exactly one of them knows how to dance to a song.</p>

<p>After the students pair up, the school plays $M$ songs. Not all students are required to pair up. Some may sit out and be fire monitors. Each song is chosen uniformly and independently at random to be swing, country or bachata.</p>

<p>The students collectively want to do as many dances as possible. The total number of dances is the sum of the number of lead-follow pairs who dance to each song. Assuming the students pair up optimally and the dance styles of the songs are chosen independently at random, what is the expected number of dances that occur over the course of the night?</p>



## 입력 형식


<p>The first line of input contains three integers $L$, $F$ and $M$, the number of leads, the number of follows, and the number of songs the dance hall plays. $L + F \leq 10^5$, $1 \leq M \leq 10^{12}$. Following are $L$ lines, one for each lead. Each line starts with an integer $k (1 \leq k \leq 3)$, the number of dances that lead knows, followed by the names of those dances. Each dance name is one of "swing", "country" or "bachata". Each dance style appears at most once for a given dancer. Then $F$ lines follow, describing the follows in the same format.</p>



## 출력 형식


<p>Output a single real number, the expected number of dances that happen. Your answer is considered correct if its absolute or relative error is at most $10^{-5}$.</p>



## 예제

### 예제 입력 1

```
1 1 1
1 swing
1 swing

```

### 예제 출력 1

```
0.333333333333333

```
          

### 예제 입력 2

```
2 2 2
2 swing bachata
1 country
1 country
2 bachata swing

```

### 예제 출력 2

```
2.000000000000000

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
  