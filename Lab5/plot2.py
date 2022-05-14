from matplotlib import pyplot as plt
from numpy import arange;
import math
import os

x=[]
print(os.getcwd())
with open(os.getcwd()+"/QSP1_swaps.txt") as f:
    l=list(f.read().split("\n"))
    for i in range(len(l)):
        l[i]=float(l[i])
    x=l

y=[]
with open(os.getcwd()+"/QSPR_swaps.txt") as f:
    l=list(f.read().split("\n"))
    for i in range(len(l)):
        l[i]=float(l[i])
    y=l

z=[]
with open(os.getcwd()+"/BuSo_swaps.txt") as f:
    l=list(f.read().split("\n"))
    for i in range(len(l)):
        l[i]=float(l[i])
    z=l


plt.style.use('ggplot')
plt.figure(figsize=(15,10))
plt.plot(range(1,len(x)+1),x,linestyle='--',label="QSP1",marker='o',color='black')
plt.plot(range(1,len(y)+1),y,linestyle='-',label="QSPR",marker='o')
plt.plot(range(1,7),z[0:6],label="BuSo",marker='.')
plt.xticks(arange(1,len(x),1))
plt.yticks(arange(2,3000000,400000))
plt.xlabel("Size of the input")
plt.ylabel("Number of swaps")
# plt.xlim([0,20])
# plt.ylim([0,20])
plt.title("Swaps v/s size_of_input(multiples of 500)")
plt.legend()
plt.savefig('plot3.png')
plt.show()
