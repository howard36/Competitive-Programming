n = int(input())
graph = [[]]*(n+1) # graph[i] is a list of the pages that can be directly reached from i

# get input
for i in range(1, n+1):
    graph[i] = [int(j) for j in input().split()] # get i-th line of input
    graph[i].pop(0)

level = [[], [1]] # level 0 has no pages, level 1 has only page 1. Other levels are added during the BFS
visited = [False]*(n+1) # visited[i] is true only if i has been added to the 'level' array
visited[1] = True

# start BFS
for l in range(1, n+1): # l = current level. l goes from 1 to n because the maximum possible level is n
    level.append([]) # add (l+1)-th level
    for page in level[l]:               # every page in level l+1 must be directly connected to some page in l,
        for nextPage in graph[page]:    # so we loop through all pages in level l, and all pages that are directly connected to it
            if visited[nextPage] == False: # only add nextPage to level l+1 if it doesn't appear in an earlier level (if it hasn't been visited yet)
                level[l+1].append(nextPage)
                visited[nextPage] = True # mark nextPage as visited after adding it to level l+1

# check if any page can be reached from page 1
allVisited = True
for i in range(1, n+1):
    if not visited[i]: # unable to reach page i from page 1
        allVisited = False
if allVisited:
    print("Y")
else:
    print("N")

# find the ending page closest to 1
pageFound = False
for l in range(1, n+1): # check each level for any ending pages, in increasing order of level
    for page in level[l]:
        if len(graph[page]) == 0: # if page is an ending page
            if pageFound == False: # only print the first page found
                print(l)
                pageFound = True