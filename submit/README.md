Dijkstra's Benchmark Test

|	N			| Elasped Time  | Memory Usage  |
|---------------|---------------|---------------|
|	10			|	5.8 ms		|	.214 kB		|
|	20			|	7.2 ms		|	.717 kB		|
|	50			|	8.2 ms		|	40.9 kB		|
|	100			|	17.6 ms		|	1.09 MB		|
|	200			|	46.6 ms		|	4.35 MB		|
|	500			|	253.2 ms	|	26.1 MB		|
|	1000		|	986.8 ms	|	104.4 MB	|
|---------------|---------------|---------------|

  Summary:	I am Graham Brown, and this is my summary of my individual contributions
			to this project. I implemented the intial reading of values into the
			dijkstras program and designed the general structure of our code before
			we discussed how to approach the algorithm. I aslo finalized the code by 
			cleaning and commenting before I started timing the program's running
			times and finding the total memory usage.

		1.	We represented the map as a graph by having a map with every visited node
			that is keyed to the index and has the distance to the source as its value.
			We then use the backend node pointer to go back through the map and find
			the cheapest distance between each node in the graph.

		2.	The overall time complexity of our implementation of Dijkstra's Algorithm 
			is O(n^2). You can see on our table of average running times that the time
			for larger inputs get exponentially larger. Additionally, our memory usage
			also has a space complexity of O(n^2), which is also reflected through the
			table above. Our implementation is O(n^2) because we had to run through the
			size of the input map for each node to find weights.

		3.	Our implementation scales poorly, since it is O(n^2) time and space complexity.
			The size of the map exponentially degraded the performance of our program
			in both time and space complexities. 
