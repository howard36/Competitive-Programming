import math

def normalize(v):
    r = math.sqrt(v[0]**2+v[1]**2+v[2]**2)
    if r == 0:
        return v
    else:
        return [v[0]/r, v[1]/r, v[2]/r]
    
T = int(input())
for _ in range (0,T):
    x, y, z, rx, ry, rz, theta = input().split()
    x = float(x)
    y = float(y)
    z = float(z)
    rx = float(rx)
    ry = float(ry)
    rz = float(rz)
    theta = float(theta)

    v = [rx, ry, rz]
    x1 = normalize(v) #new x-axis
    dist = x*x1[0]+y*x1[1]+z*x1[2] #distance from origin to projection of (x,y,z) onto x1
    shifted = [x-dist*x1[0], y-dist*x1[1], z-dist*x1[2]] #shifts vector
    y1 = normalize(shifted) #new y-axis
    z1 = [x1[1]*y1[2]-x1[2]*y1[1], x1[2]*y1[0]-x1[0]*y1[2], x1[0]*y1[1]-x1[1]*y1[0]] #new z-axis (cross product)
    s = math.sqrt(shifted[0]**2+shifted[1]**2+shifted[2]**2)
    rotated = [s*math.cos(theta)*y1[0]+s*math.sin(theta)*z1[0], s*math.cos(theta)*y1[1]+s*math.sin(theta)*z1[1], s*math.cos(theta)*y1[2]+s*math.sin(theta)*z1[2]] #rotate around new x axis
    shifted2 = [rotated[0]+dist*x1[0], rotated[1]+dist*x1[1], rotated[2]+dist*x1[2]] #shifts vector back

    shifted2[0] = round(shifted2[0]*1000000)/1000000
    shifted2[1] = round(shifted2[1]*1000000)/1000000
    shifted2[2] = round(shifted2[2]*1000000)/1000000
    print(shifted2[0], shifted2[1], shifted2[2])