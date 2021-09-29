
"""
A trellis with vines growing up.

. = no vine
# = vine
x = vine to cut

####
.#.#
.x..
.#.. <- ground layer

.#.#
....
.@.. <- ground layer

<after doomed vine segments are removed>

....
....
....
.#.. <- ground layer
"""

# 2D trellis
# boolean

def climb(trellis,start):
  (row,col) = start
  # bounds check each
  if row < 0 or row >= len(trellis): return
  if col < 0 or col >= len(trellis[row]): return
  if trellis[row][col] == '@':
    return
  if trellis[row][col] == '.':
    return
  if trellis[row][col] == '#':
    trellis[row][col] = '@'
    climb(trellis,(row-1,col))
    climb(trellis,(row+1,col))
    climb(trellis,(row,col+1))
    climb(trellis,(row,col-1))
  return

def sweep(trellis):
  """ keep only @ """
  
  for row in range(len(trellis)):
    #"...."
    for col in range(len(row)):
      if trellis[row][col] == '#': trellis[row][col] = '.'
      if trellis[row][col] == '@': trellis[row][col] = '#'
  
def prune(trellis,cut):
  """
  policy: cleanup
  approach: mark & sweep
  trellis 2D array of character ("."=empty/novine, "#"=vine), mark&sweep ('@')
  cut (row,col)
  """
  ### nassume cut=(row,col)
  (crow,ccol) = cut
  trellis[crow][ccol] = '.'
  bottom = len(trellis)-1
  # subtle: assuming each row has same length...
  for col in range(len(trellis[bottom])):
    climb(trellis,(bottom,col))
  sweep(trellis) #cleanup reachable

trellis = [
  "....",
  "....",
  "....",
  "....", # bottom
]
prune(trellis,(2,2))

