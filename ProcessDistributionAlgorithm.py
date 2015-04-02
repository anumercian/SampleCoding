#/usr/bin/python

# Author - Anu Mercian
# Problem Statement: You are provided with two files: One, which has a number of processes and the amount of memory required to run them. Two, which has a number of nodes and the amount of freely available memory. Design an algorithm to assign the different processes almost evenly among the different nodes and write them on an output file. 
# Assumptions: 
# 1. A file can be computed only in one node, split computing is avoided
# 2. If file size is larger than all nodes, then return NULL
# 3. All files have same priority

# Design:
# 1. Sort all files in descending order of file sizes
# 2. Sort all nodes in descending order of node sizes
# 3. Largest file size will get largest size node. This is for reasonable balance
# 4. Arrange files in round-robin fashion to balance the load on machines.

import sys, getopt
import operator

def main(argv):
    inputfile = ''
    inputnode = ''
    outputfile = ''

    try:
	opts, args = getopt.getopt(argv,"hf:n:o:",["ifile=","nfile=","ofile="])
    except getopt.GetoptError:
	print 'Incorrect Input Options.'
	print 'solution.py -f <filename> -n <nodename> -o <result>'
	sys.exit(2)
    for opt, arg in opts:
	if opt == '-h':
	    print 'solution.py -f <filename> -n <nodename> -o <result>'
	    sys.exit()
	elif opt in ("-f", "--ifile"):
	    inputfile = arg
	elif opt in ("-n", "--nfile"):
	    inputnode = arg
	elif opt in ("-o", "--ofile"):
	    outputfile = arg
    #File array will ignore empty lines and lines starting with '#'
    filearr = [line.rstrip('\n').split(' ') for line in open(inputfile) if not line.startswith(('#')) and not len(line.strip()) == 0]
    nodearr = [line.rstrip('\n').split(' ') for line in open(inputnode) if not line.startswith(('#')) and not len(line.strip()) == 0]

    #Sorting files in descending order (using quicksort)
    filearr_des = sorted(filearr, key=operator.itemgetter(1), reverse=True)  
 
    #Sorting nodes in descending order 
    nodearr_des = sorted(nodearr, key=operator.itemgetter(1), reverse=True)  

    #Creating new Output if necessary
    if (outputfile == ''):
	outputfile = open("results.txt", 'a')
    #Distribution Plan
    distribution(filearr_des, nodearr_des, outputfile)



def distribution(fileList, nodeList, outputfile):
    #Creating Results array
    result = [[x for x in range(2)] for y in range(len(fileList))]

    #case 1: Number of files are less than or equal to number of nodes
    if (len(fileList) <= len(nodeList)):
	node_index=0
	for index in range(len(fileList)):
	    #check to see if size does not match with the largest value
	    if ((int(nodeList[node_index][1]) - int(fileList[index][1])) < 0):
		result[index][0] = fileList[index][0]
		result[index][1] = 'NULL'
		#If a file has been assigned to NULL, try next file on same node
		#do not increment node_index
	    elif ((int(nodeList[node_index][1]) - int(fileList[index][1])) >= 0):
 	        result[index][0] = fileList[index][0]
	        result[index][1] = nodeList[node_index][0]
	        #update node size
	        nodeList[node_index][1] = int(nodeList[node_index][1]) - int(fileList[index][1])
		node_index=node_index+1

    #case 2: Number of files more than number of nodes (round-robin)
    elif (len(fileList) > len(nodeList)):
	index = 0
	while (index < (len(fileList))):
	    for node_index in range(0, len(nodeList)):
#	    while (node_index < (len(nodeList))):
	        #check to see if size does not match with the largest value
		if (index < (len(fileList))):
	         if ((int(nodeList[node_index][1]) - int(fileList[index][1])) < 0):
		    result[index][0] = fileList[index][0]
		    result[index][1] = 'NULL'
		    #If node not used, do not decrement node_index
		    index = index + 1
		    break
	         elif (int(nodeList[node_index][1]) - int(fileList[index][1]) >= 0 and index < (len(fileList))):

		    result[index][0] = fileList[index][0]
		    result[index][1] = nodeList[node_index][0]
		    #update node list sizes
		    nodeList[node_index][1] = int(nodeList[node_index][1]) -  int(fileList[index][1])
		    index = index + 1
	    nodeList = sorted(nodeList, key=operator.itemgetter(1), reverse=True)
    #Output in Distribution Files
    for i in range(len(result)):
	result_str = ' '.join(result[i])
	outputfile.write("%s\n" % result_str)
			
if __name__ == "__main__":
    main(sys.argv[1:])


