import sys
import heapq


class Vertex:
    def __init__(self,id):
        self.id = id
        self.adjacent = {}
        self.distance = sys.maxint
        self.previous = None
        self.weight = 0
        self.visited = False

    def add_neighbor(self, neighbor, weight):
        self.adjacent[neighbor] = weight

    def set_weight(self, weight):
        self.weight = weight

    def set_previous(self,pred):
        self.previous =  pred

    def get_weight(self,neighbor):
        return self.adjacent[neighbor]

    def get_id(self):
        return self.id

    def get_distance(self):
        return self.distance

    def set_distance(self, distance):
        self.distance = distance

    def get_adjacent(self):
        return self.adjacent.keys()

    def set_visited(self):
        self.visited = True

    def __str__(self):
        return "Vertex::{0}, adjacent vertics::{1}".format(self.id, [vertex.id for vertex in self.adjacent])


class Graph:
    def __init__(self):
        self.vertex_set = {}
        self.vertex_count = 0

    def add_vertex(self,vertex):
        self.vertex_count += 1
        new_vertex = Vertex(vertex)
        self.vertex_set[vertex] = new_vertex

    def add_edge(self, from_vertex, to_vertex, weight):
        if from_vertex not in self.vertex_set:
            new_vertex = Vertex(from_vertex)
            new_vertex.weight = weight
            self.vertex_set[from_vertex] = new_vertex
        if to_vertex not in self.vertex_set:
            new_vertex = Vertex(to_vertex)
            new_vertex.weight = weight
            self.vertex_set[to_vertex] = new_vertex

        self.vertex_set[from_vertex].add_neighbor(self.vertex_set[to_vertex], weight)
        self.vertex_set[to_vertex].add_neighbor(self.vertex_set[from_vertex], weight)

    def get_vertices(self):
        return self.vertex_set

    def get_vertex_count(self):
        return self.vertex_count

    def __iter__(self):
        return iter(self.vertex_set.values())


def dijikstra(g, start_vertex , dest_vertex):
    start_vertex.set_distance(0)
    q = [(v.get_distance(), v) for v in g]
    heapq.heapify(q)
    while q:
        uv = heapq.heappop(q)
        current = uv[1]
        current.set_visited()
        for item in current.get_adjacent():
            if item.visited:
                continue
            else:
                new_dist = current.get_distance() + current.get_weight(item)
                if new_dist < item.get_distance():
                    item.set_distance(new_dist)
                    item.set_previous(current)
                    print "Updated current node = {0}, next node = {1} , value = {2}".format(current.get_id(), item.get_id(), item.get_distance())
                else:
                    print "Not Updated current node = {0}, next node = {1} , value = {2}".format(current.get_id(), item.get_id(), item.get_distance())

        while q:
            heapq.heappop(q)

        q = [(v.get_distance(), v) for v in g if not v.visited]
        heapq.heapify(q)


def shortest(v, path):
    if v.previous:
        path.append(v.previous.get_id())
        shortest(v.previous, path)
    return

g = Graph()
g.add_vertex('a')
g.add_vertex('b')
g.add_vertex('c')
g.add_vertex('d')
g.add_vertex('e')
g.add_vertex('f')

g.add_edge('a', 'b', 7)
g.add_edge('a', 'c', 9)
g.add_edge('a', 'f', 14)
g.add_edge('b', 'c', 10)
g.add_edge('b', 'd', 15)
g.add_edge('c', 'd', 11)
g.add_edge('c', 'f', 2)
g.add_edge('d', 'e', 6)
g.add_edge('e', 'f', 9)

dijikstra(g,g.vertex_set['a'],g.vertex_set['e'])
target = g.vertex_set['f']
path = [target.get_id()]
shortest(target, path)
print 'The shortest path : %s' %(path[::-1])