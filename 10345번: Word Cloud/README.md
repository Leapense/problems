# 10345번: Word Cloud - <img src="https://static.solved.ac/tier_small/7.svg" style="height:20px" /> Silver IV

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/10345)


<p style="text-align:center"><img alt="sample cloud" src="https://www.acmicpc.net/upload/images2/teams.png" style="line-height:1.6em; width:675px"></p>

<p>A word cloud (or tag cloud) is a visual representation of textual data based on a weighted metric. In the above cloud (which is based on this year's list of Mid-Central teams), the font size of each word is based on its number of occurrences in the data set. Tagg Johnson is a man obsessed with counting words that appear in online documents. On his computer, he keeps a spreadsheet of all the sites he visits, along with a list of words that appear on each site and the number of times such word appears. Tagg would like to generate word clouds based on the data he has collected.</p>

<p>Before describing the algorithm Tagg uses for generating clouds, we digress for a quick lesson in typography. The basic unit of measure is known as a <em>point</em> (typically abbreviated as <em>pt</em>). A font's size is described based on the vertical number of points from one line to the next, including any interline spacing. For example, with a 12pt font, the vertical space from the top of one character to the top of a character below it is 12 points. We assume that a character's height is precisely equal to the font's point size (regardless of whether the character is upper or lower case).</p>

<p>For this problem, we focus on a fixed-width font, such as Courier, in which each character of the alphabet is also given the same amount of width. The character width for such a font depends on the font size and the aspect ratio. For Courier, a word with <em>t</em> characters rendered in a font of size <em>P</em> has a total width of \(\left\lceil \frac{9}{16} \cdot t \cdot P \right\rceil\) when measured in points. Note well the use of the ceiling operator, which converts any noninteger to the next highest integer. For example, a 5-letter word in a 20pt font would be rendered with a height of 20 points and a width equal to \(\left\lceil \frac{900}{16} \right\rceil = \left\lceil 56.25 \right\rceil = 57\) points.</p>

<p>Now we can describe Tagg's algorithm for creating a word cloud. He pre-sorts his word list into alphabetical order and removes words that do not occur at least five times. For each word&nbsp;<em>w</em>, he computes a point size based on the formula \(P = 8 + \left\lceil \frac{40(c_w - 4)}{(c_{max}-4)} \right\rceil\), where \(c_w\) is the number of occurrences of the word, and \(c_{max}\) is the number of occurrences of the most frequent word in the data set. Note that by this formula, every word will be rendered with anywhere from a 9pt font to a 48pt font. He then places the words in rows, with a 10pt horizontal space between adjacent words, placing as many words as fit in the row, subject to a maximum width&nbsp;<em>W</em> for his entire cloud. The height of a given row is equal to the <em>maximum</em> font size of any word rendered in that row.</p>

<p>As a tangible example, consider the following data set and word cloud.</p>

<table class="table table-bordered">
<tbody>
<tr>
<td><strong>word</strong></td>
<td><strong>count</strong></td>
<td>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</td>
<td rowspan="7"><img alt="fruit cloud" src="https://www.acmicpc.net/upload/images2/fruits260.png" style="width:250px"></td>
<td rowspan="7"><img alt="fruit cloud" src="https://www.acmicpc.net/upload/images2/fruits260Boxed.png" style="width:250px"></td>
</tr>
<tr>
<td>apple</td>
<td>10</td>
</tr>
<tr>
<td>banana</td>
<td>5</td>
</tr>
<tr>
<td>grape</td>
<td>20</td>
</tr>
<tr>
<td>kiwi</td>
<td>18</td>
</tr>
<tr>
<td>orange</td>
<td>12</td>
</tr>
<tr>
<td>strawberry</td>
<td>10</td>
</tr>
<!-- remaining rows are to fine tune print layout -->
<tr>
</tr>
<tr>
</tr>
<tr>
</tr>
<tr>
</tr>
<tr>
</tr>
</tbody>
</table>

<p>In this example, <code>apple</code> is rendered with 23pt font using width&nbsp;65pt, <code>banana</code> is rendered with 11pt font using width&nbsp;38pt, and <code>grape</code> is rendered with 48pt font and width&nbsp;135pt. If the overall word cloud is constrained to have width at most 260, those three words fit in a row and the overall height of that row is 48pt (due to <code>grape</code>). On the second row <code>kiwi</code> is rendered with height 43pt and width 97pt, and <code>orange</code> is rendered with height 28pt and width 95pt. A third row has <code>strawberry</code> with height 23pt and width 130pt. The overall height of this word cloud is 114pt.</p>



## 입력


<p>Each data set begins with a line containing two integers: <em>W</em> and <em>N</em>. The value <em>W</em> denotes the maximum width of the cloud; <em>W</em> ≤ 5000 will be at least as wide as any word at its desired font size. The value 1 ≤ <em>N</em> ≤ 100 denotes the number of words that appear in the cloud. Following the first line are <em>N</em> additional lines, each having a string <em>S</em> that is the word (with no whitespace), and an integer <em>C</em> that is a count of the number of occurrences of that word in the original data set, with 5 ≤ <em>C</em> ≤ 1000. Words will be given in the same order that they are to be displayed within the cloud.</p>



## 출력


<p>For each data set, output the word <kbd>CLOUD</kbd> followed by a space, a serial number indicating the data set, a colon, another space, and the integer height of the cloud, measured in font points.</p>



## 소스코드

[소스코드 보기](Word%20Cloud.cpp)