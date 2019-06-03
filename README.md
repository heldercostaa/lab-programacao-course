# Programming Laboratory
> Helder Costa (github/linkedin: heldercostaa)  
> Programming Laboratory  
> Federal University of Ceará  
> Professor: [Pablo Mayckon](http://dc.ufc.br/~pablo/index_en.html)  

## About
The intention of this course is to practice implementations (in C/C++) of some algorithms that we've seen a lot of the theory through computer science graduation. The complete program and some extra information about the course can be seen in [this page](http://dc.ufc.br/~pablo/2019-1/lp/) (in Portuguese).  

This repository is divided into folders related to every class and its corresponding implementation and, **for each main assignment, a separated folder**. It's possible that some folders may not contain any implementation because this class was probably just about the theory and explanation.  

Thus, each class has pictures of the board (in Portuguese) with the Professor's annotations.  

## Implementations
The following implementations were built through the course:  

### Quicksort and variations [[_link_](https://github.com/heldercostaa/lab-programacao-course/tree/master/quicksort)]
The focus of these implementations is to check the impact of the different ways to implement **Quicksort** algorithm, the **pivot selection**, and the **partition**.  

> - For the **quicksort**, variations are built: a full recursive implementation with indexes, a full recursive implementation with pointers and an optimized implementation with a recursion on the smaller side of the array and a loop on the biggest side.  
> - For the **pivot selection**, are implemented four strategies: one based on fixed (the first) index of the array, one based on a random element on the array, one with Hoare algorithm and the last with BFPRT algorithm.  
> - And about the **partitions**, the one pivot (2 partitions) and dual pivot (3 partitions) were implemented.  

After passing some input about the array to sort, for each combination of these above implementations, a quicksort is built to sort the array and, at the end, the time of **all combinations** is compared in a table.  

### Pattern Search [[_link_](https://github.com/heldercostaa/lab-programacao-course/tree/master/pattern-search)]
The intention of this assignment is to implement an **Intuitive Search** algorithm and the **Knuth-Morris-Pratt** algorithm to compare the time cost over some instances.

> - The **Intuitive Search**, in short, checks every letter on the text to see if it's equal on the pattern, if it's equal check the next one and, if it's not, reset the pattern and move to the next letter on the text.  
> - The **Knuth-Morris-Pratt** creates a new array called **pi** to avoid going though all the letters of the text.  
> - There are 4 types of **instances**: The **random one** that generates a random text and random pattern. The **worst case 1** that generates the text as 'aaa..aa' and the pattern as 'aaa..ab'. The **worst case 2** generates the text as 'aaa..aa' and the pattern as 'aaa.aa'. And, finally, the **real instance** looks for a word, as pattern, into a real book, as text.

After passing the input about the size of the text, size of the pattern, what size the alphabet has (in case of random instances) and which word (in case of the real instances), there is shown a table with the comparison between the **two search algorithms** over **one instance**.

### Huffman Coding [[_link_](https://github.com/heldercostaa/lab-programacao-course/tree/master/huffman-coding)]
Implementing....
