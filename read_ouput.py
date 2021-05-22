
import matplotlib.pyplot as plt

name=input()+".txt"
lines=[]


with open(name) as f:
    lines=f.readlines()

n=lines.index("time_(μs) raw_current raw_low_voltage\n")

T=[]
C=[]
V=[]
for i in range(n+1,len(lines)-1):
    l=lines[i][:-2].split(" ")
    time=float(l[0])/1000000
    current=((float(l[1])-509.18243819266837)*10/1024)*1000
    #current=float(l[1])
    voltage=5-float(l[2])*5/1024
    T.append(time)
    C.append(current)
    V.append(voltage)

#moyenne mobile exponentielle
N=20
alpha=2/(N+1)
C1=[C[0]]
for i in C:
    C1.append(alpha*i+(1-alpha)*C1[-1])

#moyenne mobile
C2=[]
n=10
for i in range(n,len(C)):
    M=0
    for j in range(0,n):
        M=M+C[i-j]
    C2.append(M/n)




#plt.plot(T,C)
#plt.plot(T,C1[1:])
#plt.plot(T[n:],C2)
plt.plot(T,C3)
plt.show()

plt.plot(T,V)
plt.show()