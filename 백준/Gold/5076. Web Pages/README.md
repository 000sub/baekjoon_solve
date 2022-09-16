# [Gold IV] Web Pages - 5076 

[문제 링크](https://www.acmicpc.net/problem/5076) 

### 성능 요약

메모리: 2028 KB, 시간: 0 ms

### 분류

자료 구조(data_structures), 파싱(parsing), 스택(stack), 문자열(string)

### 문제 설명

<p>You probably know about HTML, the mark up language used to create Web pages. HTML code contains a number of tags which are expected to follow certain rules.</p>

<p>In this problem we will be concerned with two of these rules:</p>

<ol>
	<li>Every opening tag has to have a corresponding closing tag</li>
	<li>All tags must be properly nested.</li>
</ol>

<p>Tags are marked by angled brackets which contain a keyword, such as <code><body></code> or <code><strong></code>. These are opening tags, the corresponding closing tags having <code>/</code> before the keyword, ie <code></body></code> and <code></strong></code>. It is possible for a tag to be both opening and closing, such as <code><br /></code>, which complies with rule 1.</p>

<p>To be properly nested, if a tag is opened inside another tag, it must be closed before the other tag closes. For example</p>

<ul>
	<li><code><body> <strong> </strong> </body></code> is properly nested</li>
	<li><code><body> <strong> </body> </strong></code> is not, and breaks rule 2.</li>
</ul>

<p>If there are no tags present, the text complies with both rules.</p>

<p>Attributes may be present within an opening tag, such as</p>

<p><code><a href="http://www.nzprogcontest.org.nz">This is a link</a></code></p>

<p>The closing tag has only to match the keyword, not the attributes.</p>

### 입력 

 <p>Input will consist of a number of lines of HTML code, each line containing from 0 to 255 characters. The last line will contain a single # character – do not process this line. Within the text of each line will be zero or more tags. No angle bracket will be present unless it is part of a properly formed tag.</p>

<p>Determine whether or not the HTML meets the rules specified above.</p>

### 출력 

 <p>Output will consist of a single line for each line of input. The line will contain either the word legal, or the word illegal.</p>

