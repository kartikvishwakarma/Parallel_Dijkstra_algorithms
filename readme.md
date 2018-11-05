Implementaiton of Serial and parallel dijkstra algorithms
using opem mp library.

In parallel dijkstra, only weight updation it done in parallel,
rest path a happening in serial order.

In dataset "data.txt" each node is of degree 100

and speed-up achive up to  28 sec while in serial it
tooks 36 second.

parallel
---------
compille:
		g++ -fopenmp dijkstra_heap_parallel -o dijkstra_heap_parallel -std=c++11

run:
		./dijkstra_heap_parallel


serial
-------
compille:
		g++ dijkstra_heap_serial -o dijkstra_heap_serial -std=c++11

run:
		./dijkstra_heap_serial
	