import numpy as np
import matplotlib.pyplot as plt


def f(x):
    return np.sin(x)*x+1          #目标函数

def bianbuchang_ti0(low, high, n):
    sum0 = (high - low)*(f(low) + f(high))/2
    for i in range(0, n):
        totals = 0
        for j in range(1, 2**i+1):
            totals += f(low+(2*j-1)*(high - low)/2**(i+1))
        sum0 = sum0/2+totals*(high-low)/2**(i+1)
    return sum0

def long_beige0( low,high, n ):    #使用龙贝格积分的结果作为数值积分的结果
    t = [0]*n
    for i in range(0, n):
        t[i] = bianbuchang_ti0(low, high, i)
    for k in range(1, n):
        tempt = [0]*(n-k)
        for j in range(0, len(tempt)):
            tempt[j] = (4**k*t[j+1]-t[j])/(4**k-1)
        t = tempt
    return tempt[0]


def bianbuchang_ti1(low, high, n, xuhao):
    sum0 = (high - low)*(f(low) + f(high))/2
    for i in range(0, n):
        totals = 0
        for j in range(1, 2**i+1):
            totals += f(low+(2*j-1)*(high - low)/2**(i+1)) * np.cos(xuhao * (low+(2*j-1)*(high - low)/2**(i+1)))
        sum0 = sum0/2+totals*(high-low)/2**(i+1)
    return sum0

def long_beige1( low,high, n ,xuhao):
    t = [0]*n
    for i in range(0, n):
        t[i] = bianbuchang_ti1(low, high, i, xuhao)
    for k in range(1, n):
        tempt = [0]*(n-k)
        for j in range(0, len(tempt)):
            tempt[j] = (4**k*t[j+1]-t[j])/(4**k-1)
        t = tempt
    return tempt[0]


def bianbuchang_ti2(low, high, n, xuhao):
    sum0 = (high - low)*(f(low) + f(high))/2
    for i in range(0, n):
        totals = 0
        for j in range(1, 2**i+1):
            totals += f(low+(2*j-1)*(high - low)/2**(i+1)) * np.sin(xuhao * (low+(2*j-1)*(high - low)/2**(i+1)))
        sum0 = sum0/2+totals*(high-low)/2**(i+1)
    return sum0

def long_beige2( low,high, n,xuhao ):
    t = [0]*n
    for i in range(0, n):
        t[i] = bianbuchang_ti2(low, high, i, xuhao)
    for k in range(1, n):
        tempt = [0]*(n-k)
        for j in range(0, len(tempt)):
            tempt[j] = (4**k*t[j+1]-t[j])/(4**k-1)
        t = tempt
    return tempt[0]


def linspaces(low ,high, nums):
    x = [0]*nums
    for i in range(0, nums):
        x[i] = low+i*(high-low)/(nums-1)
    return x


def zhankai(cishu, t, kongzhi, times, currentime):
    low = -1*np.pi             #定义下届
    high = np.pi               #定义上届
    a = [0]*cishu
    b = [0]*cishu
    a0 = long_beige0(low, high, kongzhi)/np.pi
    total = a0/2
    for i in range(1, cishu):
        a[i] = long_beige1(low, high, kongzhi, i)/np.pi
        b[i] = long_beige2(low, high, kongzhi, i)/np.pi
        total += a[i] * np.cos(i * t)
        total += b[i] * np.sin(i * t)
    print('total ', times, ' times ,has completed ', currentime, ' times iteration!-------------')
    return total


low = -1*np.pi
high = np.pi
x = linspaces(low, high, 50)    #定义采样点的个数
print('x=', x)
y = [0]*len(x)
z = [0]*len(x)
for j in range(0, len(x)):
    y[j] = zhankai(30, x[j], 12, len(x), j)  #30 表明求和级数的次数，12是龙贝格参数，都可以修改
    z[j] = f(x[j])
print('y=', y)
plt.scatter(x, z, color="red")   # 散点图
plt.plot(x, y, color="blue", linewidth=1)  # 折线图，拟合结果的曲线
plt.plot(x, z, color="red",  linewidth=1)  # 折线图，目标函数的真实曲线
plt.show()