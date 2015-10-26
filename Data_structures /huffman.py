# Reference material utilized : http://rosettacode.org/wiki/Huffman_coding#Python

from heapq import heappush, heappop, heapify

def encode(chartofreq):
    """encode converts the given dict mapping of characters and frequencies into an encoded format """
    heap = [[freq, [char, ""]] for char, freq in chartofreq.items()]
    heapify(heap)
    while len(heap) > 1:
        low = heappop(heap)
        high = heappop(heap)
        for hpair in low[1:]:
            hpair[1] = '0' + hpair[1]
        for hpair in high[1:]:
            hpair[1] = '1' + hpair[1]
        heappush(heap, [low[0] + high[0]] + low[1:] + high[1:])
    return sorted(heappop(heap)[1:])
 
# Dictionary of alphabets and their frequencies
alphatofreq = {'a': 45,'b': 13,'c':12,'d':16,'e':9,'f':5}

huffman = encode(alphatofreq)
print "Symbol\tFreq\tHuffman Code"
for p in huffman:
    print "{0}\t{1}\t{2}" .format(p[0], alphatofreq[p[0]], p[1])