



Graph={
  'a':['b','c'],
  'b':['d','e'],
  'c':['b','d','e','h'],
  'd':['f'],
  'e':['f'],
  'h':['e'],
  'f':[]
}

Graph={
  'a':['b','c','e'],
  'b':['c','d'],
  'c':['d','e'],
  'd':['e'],
  'e':[]
}

parent=set()
path=range(1000)

visited=dict()

for k,v in Graph.items():
  visited[k]=0


def dfs(G,start,index):
  if start == 'e':
    for e in path:
      parent.add(e)
    print path[:index]
    return  
  for e in G[start]:
    if e in parent or visited[e] == 0:
      path[index]=e
      dfs(G,e,index+1)

path[0]='a'
dfs(Graph,'a',1)