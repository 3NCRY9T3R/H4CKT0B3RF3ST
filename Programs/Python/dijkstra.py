def initiate_lists(matrix_size, open, previous, distances, origin_vertex):  # Initiate the lists
    inf = float("inf")
    for i in range(matrix_size):
        open.append(True)
        previous.append(-1)
        if i != origin_vertex:
            distances.append(inf)
        else:
            distances.append(0)

    return previous, open, distances

# Function that finds the min value of the distances that are still open
def min_value(distances, open):
    min1 = float("inf")
    min_index = 0
    for i in range(len(distances)):
        if open[i] is True:
            if min1 > distances[i]:
                min1 = distances[i]
                min_index = i
    return min_index

# Function that receives the adjacency matriz and the origin vertex and returns a list with the shortest paths between the origin vertex and the other vertexes
def dijkstra(adjacency_matrix, origin_vertex):
    origin_vertex -= 1
    open = []
    previous = []
    distances = []

    previous, open, distances = initiate_lists(len(adjacency_matrix[origin_vertex]), open, previous, distances, origin_vertex)

    while True in open:
        u = min_value(distances, open)
        open[u] = False
        for v in range(len(adjacency_matrix[u])):
            if adjacency_matrix[u][v] != 0:
                sum1 = distances[u] + adjacency_matrix[u][v]
                if sum1 < distances[v]:
                    distances[v] = sum1
                    previous[v] = u

    return distances


def show_distances(distances, origin_vertex):  # Function that shows the distances in the screen
    for i in range(len(distances)):
        print("D(" + str(origin_vertex) + "," + str(i+1) + "): " + str(distances[i]))


adjacency_matrix = [[0, 10, 0, 0, 0, 8], [0, 0, 0, 2, 0, 0], [0, 1, 0, 0, 0, 0], [0, 0, -2, 0, 0, 0], [0, -4, 0, -1, 0, 0], [0, 0, 0, 0, 1, 0]]
origin_vertex = 1
distances = dijkstra(adjacency_matrix, origin_vertex)
show_distances(distances, origin_vertex)
