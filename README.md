<h1 class="gap">0x19. C - Stacks, Queues - LIFO, FIFO</h1>
<h3>Compilation &amp; Output</h3>

<ul>
<li>The code will be compiled this way:</li>
</ul>

<pre><code>$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
</code></pre>

<ul>
<li>Any output must be printed on <code>stdout</code></li>
<li>Any error message must be printed on <code>stderr</code>

<ul>
<li><a href="/rltoken/Cv-FVD5dZn3814FM4WkBPQ" title="Here is a link to a GitHub repository" target="_blank">Here is a link to a GitHub repository</a> that could help you making sure your errors are printed on <code>stderr</code></li>
</ul></li>
</ul>

<h3>Tests</h3>

<h3>The Monty language</h3>

<p>Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.</p>

<p><strong>Monty byte code files</strong></p>

<p>Files containing Monty byte codes usually have the <code>.m</code> extension. Most of the industry uses this standard but it is not required by the specification of the language.
There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:</p>

<pre><code>julien@ubuntu:~/monty$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
julien@ubuntu:~/monty$
</code></pre>

<p>Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:</p>

<pre><code>julien@ubuntu:~/monty$ cat -e bytecodes/001.m
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
julien@ubuntu:~/monty$
</code></pre>

<p><strong>The monty program</strong></p>

<ul>
<li>Usage: <code>monty file</code>

<ul>
<li>where <code>file</code> is the path to the file containing Monty byte code</li>
</ul></li>
<li>If the user does not give any file or more than one argument to your program, print the error message <code>USAGE: monty file</code>, followed by a new line, and exit with the status <code>EXIT_FAILURE</code></li>
<li>If, for any reason, it’s not possible to open the file, print the error message <code>Error: Can't open file &lt;file&gt;</code>, followed by a new line, and exit with the status <code>EXIT_FAILURE</code>

<ul>
<li>where <code>&lt;file&gt;</code> is the name of the file</li>
</ul></li>
<li>If the file contains an invalid instruction, print the error message <code>L&lt;line_number&gt;: unknown instruction &lt;opcode&gt;</code>, followed by a new line, and exit with the status <code>EXIT_FAILURE</code>

<ul>
<li>where <line_number> is the line number where the instruction appears.</line_number></li>
<li>Line numbers always start at 1</li>
</ul></li>
<li>The monty program runs the bytecodes line by line and stop if either:

<ul>
<li>it executed properly every line of the file</li>
<li>it finds an error in the file</li>
<li>an error occured</li>
</ul></li>
<li>If you can’t malloc anymore, print the error message <code>Error: malloc failed</code>, followed by a new line, and exit with status <code>EXIT_FAILURE</code>.</li>
<li>You have to use <code>malloc</code> and <code>free</code> and are not allowed to use any other function from <code>man malloc</code> (realloc, calloc, …)</li>
</ul>
<p><strong>The push opcode</strong></p>

<p>The opcode <code>push</code> pushes an element to the stack.</p>

<ul>
<li>Usage: <code>push &lt;int&gt;</code>

<ul>
<li>where <code>&lt;int&gt;</code> is an integer</li>
</ul></li>
<li>if <code>&lt;int&gt;</code> is not an integer or if there is no argument given to <code>push</code>, print the error message <code>L&lt;line_number&gt;: usage: push integer</code>, followed by a new line, and exit with the status <code>EXIT_FAILURE</code>

<ul>
<li>where <line_number> is the line number in the file</line_number></li>
</ul></li>
<li>You won’t have to deal with overflows. Use the <code>atoi</code> function</li>
</ul>

<p><strong>The pall opcode</strong></p>

<p>The opcode <code>pall</code> prints all the values on the stack, starting from the top of the stack.</p>

<ul>
<li>Usage <code>pall</code></li>
<li>Format: see example</li>
<li>If the stack is empty, don’t print anything</li>
</ul>

<pre><code>julien@ubuntu:~/monty$ cat -e bytecodes/00.m
push 1$
push 2$
push 3$
pall$
julien@ubuntu:~/monty$ ./monty bytecodes/00.m
3
2
1
julien@ubuntu:~/monty$
</code></pre>
<p><strong>The pint opcode</strong></p>

<p>The opcode <code>pint</code> prints the value at the top of the stack, followed by a new line.</p>

<ul>
<li>Usage: <code>pint</code></li>
<li>If the stack is empty, print the error message <code>L&lt;line_number&gt;: can't pint, stack empty</code>, followed by a new line, and exit with the status <code>EXIT_FAILURE</code></li>
</ul>

<pre><code>julien@ubuntu:~/monty$ cat bytecodes/06.m 
push 1
pint
push 2
pint
push 3
pint
julien@ubuntu:~/monty$ ./monty bytecodes/06.m 
1
2
3
julien@ubuntu:~/monty$ 
</code></pre>
<p><strong>The pop opcode</strong></p>

<p>The opcode <code>pop</code> removes the top element of the stack.</p>

<ul>
<li>Usage: <code>pop</code></li>
<li>If the stack is empty, print the error message <code>L&lt;line_number&gt;: can't pop an empty stack</code>, followed by a new line, and exit with the status <code>EXIT_FAILURE</code></li>
</ul>

<pre><code>julien@ubuntu:~/monty$ cat bytecodes/07.m 
push 1
push 2
push 3
pall
pop
pall
pop
pall
pop
pall
julien@ubuntu:~/monty$ ./monty bytecodes/07.m 
3
2
1
2
1
1
julien@ubuntu:~/monty$ 
</code></pre>
<p><strong>The swap opcode</strong></p>

<p>The opcode <code>swap</code> swaps the top two elements of the stack.</p>

<ul>
<li>Usage: <code>swap</code></li>
<li>If the stack contains less than two elements, print the error message <code>L&lt;line_number&gt;: can't swap, stack too short</code>, followed by a new line, and exit with the status <code>EXIT_FAILURE</code></li>
</ul>

<pre><code>julien@ubuntu:~/monty$ cat bytecodes/09.m 
push 1
push 2
push 3
pall
swap
pall
julien@ubuntu:~/monty$ ./monty bytecodes/09.m 
3
2
1
2
3
1
julien@ubuntu:~/monty$ 
</code></pre>
<p><strong>The add opcode</strong></p>

<p>The opcode <code>add</code> adds the top two elements of the stack.</p>

<ul>
<li>Usage: <code>add</code></li>
<li>If the stack contains less than two elements, print the error message <code>L&lt;line_number&gt;: can't add, stack too short</code>, followed by a new line, and exit with the status <code>EXIT_FAILURE</code></li>
<li>The result is stored in the second top element of the stack, and the top element is removed, so that at the end:

<ul>
<li>The top element of the stack contains the result</li>
<li>The stack is one element shorter</li>
</ul></li>
</ul>

<pre><code>julien@ubuntu:~/monty$ cat bytecodes/12.m 
push 1
push 2
push 3
pall
add
pall

julien@ubuntu:~/monty$ ./monty bytecodes/12.m 
3
2
1
5
1
julien@ubuntu:~/monty$
</code></pre>
<p><strong>The sub opcode</strong></p>

<p>The opcode <code>sub</code> subtracts the top element of the stack from the second top element of the stack.</p>

<ul>
<li>Usage: <code>sub</code></li>
<li>If the stack contains less than two elements, print the error message <code>L&lt;line_number&gt;: can't sub, stack too short</code>, followed by a new line, and exit with the status <code>EXIT_FAILURE</code></li>
<li>The result is stored in the second top element of the stack, and the top element is removed, so that at the end:

<ul>
<li>The top element of the stack contains the result</li>
<li>The stack is one element shorter</li>
</ul></li>
</ul>

<pre><code>julien@ubuntu:~/monty$ cat bytecodes/19.m 
push 1
push 2
push 10
push 3
sub
pall
julien@ubuntu:~/monty$ ./monty bytecodes/19.m 
7
2
1
julien@ubuntu:~/monty$
</code></pre>
