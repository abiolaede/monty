[
	This program prints "School" and a new line
	S - 83, c - 99, h - 104, o - 111, o - 111, l - 108 
]
++++++++						Add 8 to cell #0
[
	>++++						Add 4 to cell #1
	[
		>+++					Add 3 to cell #2
		>+++					ADD 3 to cell #3
		>+++					Add 4 to cell #4
		>+++					Add 4 to cell #5
		>+++					Add 4 to cell #6
		>+++ 					Add 4 to cell #7
		<<<<<<-					Go to cell 1
	]
	>--					Subtract 2 fron cell 2
	>>+					Add 1 to cell 4
	>++					Add 2 to cell 5
	>++					Add 2 to cell 6
	>+					Add 1 to cell 7
	>+					Add 1 to cell 8
	[<]
	<-
]
The result of this is
cell:  0  1   2   3   4     5    6    7  8
cont:  0  0  80  96  104  112  112  104  8 
>>+++.
>+++.
>.
>-.
>-.
>++++.
>++.
