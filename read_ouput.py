
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
    current=float(l[1])*5/1024*1000
    voltage=5-float(l[2])*5/1024
    T.append(time)
    C.append(current)
    V.append(voltage)
    
plt.plot(T,C)
plt.show()
plt.plot(T,V)
plt.show()