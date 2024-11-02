# 17661번: Mangling Names

## 문제 설명


<p>Having figured out everyone’s first and last name, it’s time for everyone to walk across that stage, to cheers of friends and family, receive a degree, and hear one’s name pronounced/mangled. One has to have some pity, though, with the poor officials who have to pronounce hundreds or thousands of names, from dozens of countries, some of them very long. Getting the name right can take a while, and delay the whole ceremony. In this question, you will figure out just how much.</p>

<p>You will be given a table that tells you, as a function of the number of vowels (‘a’, ‘e’, ‘i’, ‘o’, ‘u’, ‘y’; we will treat ‘y’ as only a vowel, never a consonant) and consonants in the name, how long it will take to pronounce a name correctly. Then, for each graduating student, you will be given the student’s name. You are to output the total length of the ceremony.</p>



## 입력 형식


<p>The first line contains a number 1 ≤ K ≤ 100, which is the number of input data sets in the file. This is followed by K data sets of the following form:</p>

<p>The first line of each data set contains two integers 0 ≤ L ≤ 30, 0 ≤ n ≤ 100, 000. Here L is the (larger of the) maximum number of vowels/consonants in any name, and n is the number of students marching.<sup>2</sup> This is followed by L + 1 lines, each with L + 1 integers. Entry j in row i contains an integer 0 ≤ p<sub>i,j</sub> ≤ 100, which tells you how many seconds it takes to pronounce a name with i vowels and j consonants; here, 0 ≤ i, j ≤ L.</p>

<p>This is followed by n lines, each containing a string of length at most 2L, consisting only of lowercase letters. This string is the student’s name, and it will contain at most L vowels and at most L consonants.</p>

<p><sup>2</sup>If you are wondering about allowing n up to 100,000: have you seen our graduation ceremonies lately?!?</p>



## 출력 형식


<p>For each data set, first output “Data Set x:” on a line by itself, where x is its number.</p>

<p>Then, output the total duration of the ceremony in seconds.</p>

<p>Each data set should be followed by a blank line.</p>



## 예제

### 예제 입력 1

```
2
4 4
1 2 8 25 50
1 1 1 3 8
7 6 4 8 10
6 5 5 4 4
15 12 10 10 10
cthulu

amoeba
czsz
1 2
0 5
1 10
a
b

```

### 예제 출력 1

```
Data Set 1:
71

Data Set 2:
6


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
  