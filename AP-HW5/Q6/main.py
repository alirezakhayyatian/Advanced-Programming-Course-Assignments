import subprocess
import numpy as np
from time import time as epochTime
from tabulate import tabulate
import matplotlib.pyplot as plt

#z=Popen([r"E:\film\2016\10.Cloverfield.Lane.2016.720p.ShAaNiG.mkv"],shell=True)
# z.wait()


class PGaussSolver:
    def __init__(self,func,a,b,n):
        self.func=func
        self.m_A=a
        self.m_B=b
        self.m_N=n
        self.m_Result= 0
    def legendre(self,m_N,x):
        if m_N==0:
            return 1
        elif m_N==1:
            return x
        else:
            #print('a')
            return ((2.0 * m_N - 1) / m_N) * x * self.legendre(m_N - 1, x) - ((1.0 * m_N - 1) / m_N) * self.legendre(m_N - 2, x)

    def dLegendre(self,m_N,x):
        dLegendre = (1.0 * m_N / (x * x - 1)) * ((x * self.legendre(m_N, x)) - self.legendre(m_N - 1, x))
        return dLegendre
    def legendreZeroes( self,m_N, i):
        i=i+1
        #print(f'{i}')
        pi = 3.141592655
        xold1 = np.cos(pi * (i - 1 / 4.0) / (m_N + 1 / 2.0))
        iteration =1

        while True:
            #xnew1 = 1
            if iteration !=1:
                xold1=xnew1
            xnew1 = xold1 - self.legendre(m_N, xold1) / self.dLegendre(m_N, xold1)
            iteration+=1
            if (1 + abs((xnew1 - xold1))) <= 1. :
                break
        return xnew1

    def weight(self,m_N,x):
        weightI = 2 / ((1 - x**2) * self.dLegendre(m_N, x)**2)
        return weightI
    def exec(self):
        iteration=1
        iteration+=1
        integral=0
        #print(f'{self.m_N}')
        for i in range(self.m_N):
            integral = integral + self.func(self.legendreZeroes(self.m_N, i)) * self.weight(self.m_N,self.legendreZeroes(self.m_N, i))
        self.m_Result = ((self.m_B - self.m_A) / 2.0) * integral
        return self.m_Result #I insert this line

    def getResult(self):
        return self.m_Result

def aFunction(x):
    xN=.5*x+.5
    return (xN**3 / (xN + 1)) * np.cos(xN**2)

n1=int(input('Degree?'))
a=0
b=1
cTime=[]
pTime=[]
for n in range(n1):
    start = epochTime()
    aSolver = PGaussSolver(aFunction,a,b,n)
    result =aSolver.exec() # Calculate the integral
    stop = epochTime()
    print(f'Result of Python code (n= {n}):{result}')
    pTime.append(stop-start)

    start = epochTime()
    subprocess.call(["ConsoleApplication5.exe",str(n)])
    stop = epochTime()
    cTime.append(stop-start)

table=[(n,cTime[n],pTime[n]) for n in range(n1)]
print(  tabulate(table,headers=['num','C++ timer','Python timer']) )
#subprocess.call(["ConsoleApplication5.exe",str(5)])


#print(table)
#colLabel =('num','C++ timer','Python timer')
#fig = plt.figure(1)
#ax=fig.add_axes([0, 0, 1 ,1],frame_on =False)
#x=np.linspace(0,4*np.pi,100)
#ax.xaxis.set_ticks([])
#ax[0].axis('tight')
#ax.plot(x,np.cos(x))
#tab=ax.table(np.asarray(table))
#plt.show()

fig, axs =plt.subplots(1,1)
#clust_data = np.random.random((10,3))
clust_data = np.asarray(table)
collabel=('num','C++ timer','Python timer')
axs.axis('tight')
axs.axis('off')
the_table = axs.table(cellText=clust_data,colLabels=collabel,loc='center')

#axs[1].axis('tight')
#axs[1].axis('off')
#axs[1].plot(range(n+1),cTime,range(n+1),pTime)
plt.savefig('result.pdf')
plt.show()