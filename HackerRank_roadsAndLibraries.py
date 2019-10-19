##https://www.hackerrank.com/challenges/torque-and-development/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=graphs
import math
import os
import random
import re
import sys

def roadsAndLibraries(n, c_lib, c_road, cities):
    if c_lib <= c_road:
        return n * c_lib

    g = [[] for _ in range(n)]

    for _ in range(len(cities)):
        u, v = cities[_]
        g[u-1].append(v-1)
        g[v-1].append(u-1)
    
    check = [False] * n
    q = []
    citiesNumber = 0
    roadNumbers = 0

    for _ in range(len(g)):
        if check[_] == False:
            node = _
            citiesNumber += 1

        q.append(node)
        check[node] = citiesNumber

        while not(len(q) == 0):
            nextN = q.pop()
            for _ in range(len(g[nextN])):
                tempInt = g[nextN][_]
                if check[tempInt] == False:
                    q.append(tempInt)
                    check[tempInt] = citiesNumber
                    roadNumbers += 1

    return ((citiesNumber * c_lib) + (roadNumbers * c_road))

q = int(input())

for q_itr in range(q):
    nmC_libC_road = input().split()

    n = int(nmC_libC_road[0])

    m = int(nmC_libC_road[1])

    c_lib = int(nmC_libC_road[2])

    c_road = int(nmC_libC_road[3])

    cities = []

    for _ in range(m):
        cities.append(list(map(int, input().rstrip().split())))

    print(roadsAndLibraries(n, c_lib, c_road, cities))
