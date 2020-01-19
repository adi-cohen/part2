# Searching Algorithms Server
In this program we created a generic server, which can be used for several projects.

the server solve problem that accepted from client, and return the solution to the client.

the program is generically written so it can accept and solve varios problem.

## our problem - finding shortes path in matrix

in our code the problem is finding shortest path in matrix, and return the path with the cost of the nodes in the shortest path.

to solve this problem, we used 4 algorethms.


### ALGORITHMS

* **Best first search** - a search algorithm which explores a graph by expanding the most promising node chosen according to a specified rule. 
[read more](https://en.wikipedia.org/wiki/Best-first_search) 

* **Breadth-first search** - an algorithm for traversing or searching tree or graph data structures. It starts at the tree root , and explores all of the neighbor nodes at the present depth prior to moving on to the nodes at the next depth level. [read more](https://en.wikipedia.org/wiki/Breadth-first_search)

* **Depth-first search** -  an algorithm for traversing or searching tree or graph data structures. The algorithm starts at the root node  and explores as far as possible along each branch before backtracking. [read more](https://en.wikipedia.org/wiki/Depth-first_search)

* **A-sart** - an informed search algorithm, starting from a specific starting node of a graph, it aims to find a path to the given goal node having the smallest cost . It does this by maintaining a tree of paths originating at the start node and extending those paths one edge at a time until its termination criterion is satisfied. [read more](https://en.wikipedia.org/wiki/A*_search_algorithm)

we preformes an experiment and choose the most effective algorithem.
below the result of the experiment:
![the table](https://github.com/adi-cohen/part2/blob/master/table.png)

### Design Patterns in C++

in this program we used some design patters, for exemple:

* Single responsibility principle - A class should only have one responsibility.

* Open/closed principle -The systems we build should be open for extension, but closed for modification. 

* bridge -  A mechanism that decouples an interface (interface hierarchy) from an implementation (implementation hierarchy).

* etc.

### Test the program

you can test the program by runnig the following command,


```
python3 auto_client.py -vv
```
