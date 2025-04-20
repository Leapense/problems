# 27612번: Determining Nucleotide Assortments - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/27612)

<p>Genes 'R Us specializes in analyzing strands of DNA to look for anomalies, matches, patterns, or whatever specific items their customers are interested in. You may recall from high school biology that the DNA molecule consists of two chains wrapped around each other to form the well-known double helix.  The chains are made up of four different types of nucleotides, each distinguished by a specific nitrogen base: adenine (<code>A</code>), thymine (<code>T</code>), guanine (<code>G</code>) and cytosine (<code>C</code>).</p>

<p>A recent customer of Genes 'R Us wants to be able to quickly determine which of the four types of nucleotides is most prevalent in a given section of DNA, as well as which are second, third and fourth most prevalent.  For a given strand of DNA (which may contain tens of thousands of nucleotides) there may be many such sections where this information is desired.  You've been asked to write an efficient program to answer such questions.</p>

## 입력

<p>Input starts with a string describing a DNA strand.  This string consists of the characters <code>A</code>, <code>T</code>, <code>G</code> and <code>C</code> and have positive length $n \leq 50\,000$.  The next line contains a positive integer $m$ ($m \leq 25\,000$) indicating the number of sections of the DNA strand to investigate.  Following this are $m$ lines each containing a pair of integers $s_i$ $e_i$, each indicating the start and ending positions of a section of the strand, where $1 \leq s_i \leq e_i \leq n$. Integer pairs are separated by a single space.</p>

## 출력

<p>For each section output a line containing a permutation of <code>ATGC</code>, where the first character indicates the most prevalent nucleotide in the section, the second character indicates the second most prevalent, and so on.  Break any ties using the ordering <code>ATGC</code> (i.e., print an <code>A</code> before an equally occurring <code>T</code>, <code>G</code> or <code>C</code>, print a <code>T</code> before an equally occurring <code>G</code> or <code>C</code>, and so on).</p>

## 소스코드

[소스코드 보기](Main.java)