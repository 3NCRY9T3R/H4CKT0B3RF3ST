
#Function that creates a matrix  with a single value (i utilize 0 for prim).
def matrix (nRow,nColumns, value):
    matrix = []
    for i in range(nRow):
        row = []
        for j in range(nColumns):
            row.append(value)
        matrix.append(row)
    return matrix

#Function that prints the adjacency matrix in a file.
def printMatrix (nRows,nColumnas, matrix):
    for i in range(nRows):
        rowPrint = ""
        for j in range(nColumnas):
            rowPrint += str(matrix[i][j])
            if(j<nColumnas-1):
                rowPrint += ","
        print(rowPrint)


#Function that utilizes Prim's Algorithm to find the adjacency matrix of the minimum spanning tree of a graph.
def prim (nRows,nColumns,adjMatrix):
    visitedVertexes=[]
    newAdj = matrix(nRows,nColumns,0)
    path=[]
    path.append(0)
    path.append(0)
    visitedVertexes.append(0)
    for i in range(nRows-1):
        shortestPath=0
        for j in visitedVertexes:
            for k in range(nColumns):
                if(shortestPath==0 and adjMatrix[j][k]!=0 and  (k not in visitedVertexes)):
                    shortestPath=adjMatrix[j][k]
                    path.insert(0, j)
                    path.insert(1, k)
                elif(adjMatrix[j][k]!=0 and adjMatrix[j][k]<shortestPath and (k not in visitedVertexes)):
                    shortestPath = adjMatrix[j][k]
                    path.insert(0,j)
                    path.insert(1,k)
        visitedVertexes.append(path[1])
        newAdj[path[0]][path[1]] = shortestPath
        newAdj[path[1]][path[0]] = shortestPath
    return newAdj


#We start with  the adjacency matrix of a weighted undirected graph.
adjacencyMatrix = [[0, 10, 5, 0, 0, 0], [0, 0, 0, 1, 0, 0], [0, 3, 0, 8, 2, 0], [0, 0, 0, 0, 4, 4], [0, 0, 0, 0, 0, 6], [0, 0, 0, 0, 0, 0]]
nRows=len(adjacencyMatrix[0])
nColumns=len(adjacencyMatrix)
#Here we utilize a function to get the minimum spanning tree's adjacency matrix for the original graph's adjacency matrix.
finalMatrix=prim(nRows,nColumns,adjacencyMatrix)
#Now we just print the new adjacency matrix.
printMatrix(nRows,nColumns,finalMatrix)
