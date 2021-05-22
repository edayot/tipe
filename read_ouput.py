
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
    
N=20
alpha=2/(N+1)
C_=[C[0]]
for i in C:
    C_.append(alpha*i+(1-alpha)*C_[-1])

C__=[]
n=10
for i in range(n,len(C)):
    M=0
    for j in range(0,n):
        M=M+C[i-j]
    C__.append(M/n)


#plt.plot(T,C)
#plt.plot(T,C_[1:])
plt.plot(T[n:],C__)
plt.show()
plt.plot(T,V)
plt.show()