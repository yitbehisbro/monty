Brainf*ck code script to add two numbers from user input

,               Reads first number and store at c0
>,              Reads second number and store at c1

[               While loop for case c1
< +             Adds 1 to the c0
> -             Substracts 1 from c1
]               While continues till c1 equals 0

Converts and displays the value in ASCII code

++++ ++++       While loop in case c1 = 8 and c0 = 6
[
< --- ---       Substract 6 from from the given code
> -
]
<.
