import sys
input = sys.stdin.readline

def line(p1, p2): #returns (a, b, c), where ax+by=c is the line between the two points
    a = p1[1]-p2[1]
    b = p2[0]-p1[0]
    c = p2[0]*p1[1]-p1[0]*p2[1]
    return (a, b, c)

def intersect(a1, a2, b1, b2):
    l1 = line(a1, a2)
    l2 = line(b1, b2)
    det = l1[0]*l2[1]-l1[1]*l2[0]
    if det == 0: #parallel lines
        if (a1[1]-b1[1])*(a2[0]-b1[0]) == (a2[1]-b1[1])*(a1[0]-b1[0]): #a1, a2, b1 collinear
            if min(a1[0], a2[0]) <= max(b1[0], b2[0]) and min(b1[0], b2[0]) <= max(a1[0], a2[0]):
                if min(a1[1], a2[1]) <= max(b1[1], b2[1]) and min(b1[1], b2[1]) <= max(a1[1], a2[1]):
                    return True
        return False
    detX = l1[2]*l2[1]-l1[1]*l2[2]
    detY = l1[0]*l2[2]-l1[2]*l2[0]
    x = detX/det
    y = detY/det
    if min(a1[0], a2[0]) <= x <= max(a1[0], a2[0]) and min(a1[1], a2[1]) <= y <= max(a1[1], a2[1]):
        if min(b1[0], b2[0]) <= x <= max(b1[0], b2[0]) and min(b1[1], b2[1]) <= y <= max(b1[1], b2[1]):
            return True
    else:
        return False

a = input().split()
p1 = (int(a[0]), int(a[1]))
p2 = (int(a[2]), int(a[3]))
n = int(input())
count = 0
for _ in range(n):
    a = input().split()
    m = int(a[0])
    intersect_bool = False
    points = []
    for i in range(m):
        points.append((int(a[2*i+1]), int(a[2*i+2])))
    for i in range(m-1):
        if intersect(p1, p2, points[i], points[i+1]):
            intersect_bool = True
            break
    if intersect(p1, p2, points[0], points[-1]):
        intersect_bool = True
    if intersect_bool:
        count += 1
print(count)