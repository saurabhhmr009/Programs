# Print a list of all possible coordinates given by  on a 3D grid where 
# the sum of i+j+k is not equal to n.


x,y,z,n  = map(int,input().split())
print([[i,j,k] for i in range(x+1) for j in range(y+1) for k in range(z+1) if(i+j+k) !=n])

