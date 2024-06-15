# Page_Rank
In this project, I implemented a C program that can analyze directed graphs and compute the page rank of
its vertices. The directed graphs that we are interested in can be considered as consisting of websites and the
hyperlinks connecting two websites.<br /><br />

In the early days of search engines, PageRank was the distinguishing algorithm that effectively was key in making
Google the giant it nowadays is, by giving it a perceivable advantage over other search engines. It was developed
by the co-founders of Google, Sergey Brin and Larry Page. PageRank assigns to every website a score, the page
rank, that ranks its relevance among all search results. In the case of Google, the pages with the highest page
rank would be the search results displayed to you.<br />
In this project, we will first use the random surfer model to simulate and approximate the page ranks of the
websites of a given network. Then, we will look at the mathematical foundations needed to compute the page
rank<br /><br />

The program understand and correctly interprete the following command line options:
$ ./ pagerank -h
Usage : ./ pagerank [ OPTIONS ] ... [ FILENAME ]
Perform pagerank computations for a given file in the DOT format<br />

-h Print a brief overview of the available command line parameters
-r N Simulate N steps of the random surfer and output the result
-m N Simulate N steps of the Markov chain and output the result
-s Compute and print the statistics of the graph as defined
 -p P Set the parameter p to P%. ( Default : P = 10)