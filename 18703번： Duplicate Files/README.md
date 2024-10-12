# 18703번: Duplicate Files - <img src="https://static.solved.ac/tier_small/6.svg" style="height:20px" /> Silver V

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/18703)


<p>Many of us have this problem on their computer, where we make several copies of the exact same files, which uses more memory. So you finally decided to write a program to remove all duplicate files.</p>

<p>Here’s how your computer works. Whenever you create a new file, it gets a unique ID (when you make a copy of an existing file, the new copy gets a new ID). The IDs are relative to the time, so older files get smaller IDs (but the IDs are not necessary sequential). Also each file has a name, but multiple files can have the same name, and when 2 or more files get the same name, this means they are all exactly the same and they are just identical copies of the one of them with the smallest ID.</p>

<p>You are given the list of all files with their names and IDs, your task is to delete all duplicates and just keep the oldest copy of each file.</p>



## 입력


<p>Your program will be tested on one or more test cases. The first line of the input will be a single integer T (1 ≤ T ≤ 100) representing the number of test cases. Followed by T test cases.</p>

<p>Each test case starts with a line containing an integer N (1 ≤ N ≤ 10<sup>5</sup>) representing the number of files followed by N lines, each line will contain the file name followed by a space then the file ID. The file name is a non-empty string of at most 10 lower case English letters, and the ID is a positive integer which is at most 10<sup>5</sup>.</p>

<p>All IDs will be distinct within each test case.</p>



## 출력


<p>For each test case print a single line containing the IDs of the files which won’t get deleted, the IDs should be sorted in increasing order and separated by a single space.</p>



## 소스코드

[소스코드 보기](Duplicate%20Files.cpp)