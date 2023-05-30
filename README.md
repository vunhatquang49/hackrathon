# hackrathon
Code hackrathon coloring
This code is written in C++ and implements the DSatur algorithm for graph coloring. The input is read from a file named "input.txt" and the output is written to a file named "output_hackrathon.txt". The input file contains the number of nodes and edges in the graph, followed by the edges themselves. The output file contains the number of colors used in the coloring, followed by the color assigned to each node.

The DSatur algorithm works by selecting the node with the highest saturation degree (i.e., the number of different colors used by its neighbors) and assigning it the lowest possible color that is not used by its neighbors. This process is repeated until all nodes are colored.

The code sorts the nodes in decreasing order of degree and assigns the first node the color 0. It then iteratively selects the node with the highest saturation degree and assigns it a color. The maximum color used is tracked and returned as the number of colors used in the coloring.

The code also includes timing information and a call to a system command to check the validity of the coloring.

To run this code, you should create an input file in the format described above and run the executable. The output will be written to the file "output_hackrathon.txt" 
