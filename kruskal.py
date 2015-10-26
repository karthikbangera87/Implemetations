from operator import itemgetter
result = []

#inherting dictionary class
class DisjointSet(dict):
    def add(self, item):
        self[item] = item
 
    def find(self, item):
        parent = self[item]
 
        while self[parent] != parent:
            parent = self[parent]
 
        self[item] = parent
        return parent
 
    def union(self, item1, item2):
        self[item2] = self[item1]
        
def kruskal( nodes, edges ):
    global result
    forest = DisjointSet()
    mst = []
    for n in nodes:
        forest.add( n )
    sz = len(nodes) - 1

    for e in sorted(edges, key=itemgetter( 2 ) ):
        n1, n2, w = e
        t1 = forest.find(n1)
        t2 = forest.find(n2)
        if t1 != t2:
            weight = e[2]
            result.append(weight)
            mst.append(e)
            sz -= 1
            if sz == 0:
                print 'Weight of the minimum spanning tree is',sum(result) 
                print 'The minimum spanning tree is as follows:'
                return mst
         
            forest.union(t1, t2)
 
 
#test   
 
nodes = list( "012345678" )
edges = [ ("0", "1", 4), 
          ("0", "5", 8),
          ("1", "2", 8), 
          ("1", "5", 11), 
          ("2", "6", 2),
          ("2", "3", 7),
          ("2", "8", 4), 
          ("3", "4", 9),
          ("3", "8", 14), 
          ("4", "8", 10),
          ("5", "6", 7), 
          ("5", "7", 1), 
          ("6", "7", 6), 
          ("7", "8", 2)]


print kruskal( nodes, edges )
