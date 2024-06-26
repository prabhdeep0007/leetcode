<h2><a href="https://leetcode.com/problems/calculator-with-method-chaining/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag">No companies found for this problem</div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px;"><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>2726. Calculator with Method Chaining</a></h2><h3>Easy</h3><hr><div><p>Design a <code>Calculator</code> class. The class should provide the&nbsp;mathematical operations of&nbsp;addition, subtraction, multiplication, division, and exponentiation. It should also allow consecutive operations to be performed using method chaining.&nbsp;The <code>Calculator</code> class constructor should accept a number&nbsp;which serves as the&nbsp;initial value of <code>result</code>.</p>

<p>Your <font face="monospace"><code>Calculator</code>&nbsp;</font>class should have the following methods:</p>

<ul>
	<li><code>add</code> - This method adds the given number <code>value</code> to the&nbsp;<code>result</code> and returns the updated <code>Calculator</code>.</li>
	<li><code>subtract</code> -&nbsp;This method subtracts the given number <code>value</code>&nbsp;from the&nbsp;<code>result</code> and returns the updated <code>Calculator</code>.</li>
	<li><code>multiply</code> -&nbsp;This method multiplies the <code>result</code>&nbsp; by the given number <code>value</code> and returns the updated <code>Calculator</code>.</li>
	<li><code>divide</code> -&nbsp;This method divides the <code>result</code> by the given number <code>value</code> and returns the updated <code>Calculator</code>. If the passed value is <code>0</code>, an error <code>"Division by zero is not allowed"</code> should be thrown.</li>
	<li><code>power</code> -&nbsp;This method raises the&nbsp;<code>result</code> to the power of the given number <code>value</code> and returns the updated <code>Calculator</code>.</li>
	<li><code>getResult</code> -&nbsp;This method returns the <code>result</code>.</li>
</ul>

<p>Solutions within&nbsp;<code>10<sup>-5</sup></code>&nbsp;of the actual result are considered correct.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> 
actions = ["Calculator", "add", "subtract", "getResult"], 
values = [10, 5, 7]
<strong>Output:</strong> 8
<strong>Explanation:</strong> 
new Calculator(10).add(5).subtract(7).getResult() // 10 + 5 - 7 = 8
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> 
actions = ["Calculator", "multiply", "power", "getResult"], 
values = [2, 5, 2]
<strong>Output:</strong> 100
<strong>Explanation:</strong> 
new Calculator(2).multiply(5).power(2).getResult() // (2 * 5) ^ 2 = 100
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> 
actions = ["Calculator", "divide", "getResult"], 
values = [20, 0]
<strong>Output:</strong> "Division by zero is not allowed"
<strong>Explanation:</strong> 
new Calculator(20).divide(0).getResult() // 20 / 0 

The error should be thrown because we cannot divide by zero.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>actions</code> is a valid JSON array of strings</li>
	<li><code>values</code>&nbsp;is a valid JSON array of numbers</li>
	<li><code>2 &lt;= actions.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= values.length &lt;= 2 * 10<sup>4</sup>&nbsp;- 1</code></li>
	<li><code>actions[i]</code> is one of "Calculator", "add", "subtract", "multiply", "divide", "power", and&nbsp;"getResult"</li>
	<li>First action is always "Calculator"</li>
	<li>Last action is always "getResult"</li>
</ul>
</div>