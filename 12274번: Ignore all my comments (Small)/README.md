# 12274번: Ignore all my comments (Small) - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/12274)


<p>Good programmers write fabulous comments. Igor is a programmer and he likes the old C-style comments in&nbsp;<b><code>/* ... */</code></b>&nbsp;blocks. For him, it would be ideal if he could use this style as a uniform comment format for all programming languages or even documents, for example Python, Haskell or HTML/XML documents.</p>

<p>Making this happen doesn't seem too difficult to Igor. What he will need is a comment pre-processor that removes all the comment blocks in&nbsp;<b><code>/*</code></b>, followed by comment text, and by another&nbsp;<b><code>*/</code></b>. Then the processed text can be handed over to the compiler/document renderer to which it belongs—whatever it is.</p>

<p>Igor's pre-processor isn't quite that simple, though. Here are some cool things it does:</p>

<ul>
<li>The comments the pre-processor reads can be nested the same way brackets are nested in most programming languages. It's possible to have comments inside comments. For example, the following code block has an outer level of comments that should be removed by the comment pre-processor. The block contains two inner comments.
<pre>printf("Hello /* a comment /* a comment inside comment */ 
        inside /* another comment inside comment */ 
        string */ world");
</pre>
After the pre-process step, it becomes:

<pre>printf("Hello  world");
</pre>
</li>
<li>Igor recognizes comments can appear anywhere in the text, including inside a string&nbsp;<code>"/*...*/"</code>, a constant number&nbsp;<code>12/*...*/34</code>&nbsp;or even in a character escape&nbsp;<code>\/*...*/n</code>
<p>Or more formally:</p>

<pre>text:
  text-piece
  text-piece remaining-text
text-piece:
  char-sequence-without-/*
  empty-string
remaining-text:
  comment-block text

comment-block:
  /* comment-content */
comment-content:
  comment-piece
  comment-piece remaining-comment
comment-piece:
  char-sequence-without-/*-or-*/
  empty-string
remaining-comment:
  comment-block comment-content

char:
  letters
  digits
  punctuations
  whitespaces
</pre>
</li>
</ul>

<p>Our pre-processor, given a&nbsp;<code><b>text</b></code>, removes all&nbsp;<code><b>comment-block</b></code>&nbsp;instances as specified.</p>



## 입력


<p>A text document with comment blocks in&nbsp;<b><code>/*</code></b>&nbsp;and&nbsp;<b><code>*/</code></b>. The input file is valid. It follows the specification of&nbsp;<b><code>text</code></b>&nbsp;in the problem statement. The input file always terminates with a newline symbol.</p>



## 출력


<p>We only have one test case for this problem. First we need to output the following line.</p>

<pre>Case #1:
</pre>

<p>Then, print the document with all comments removed, in the way specified in the problem statements. Don't remove any spaces or empty lines outside comments.</p>



## 소스코드

[소스코드 보기](Ignore%20all%20my%20comments%20(Small).cpp)