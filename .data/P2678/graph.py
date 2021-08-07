import numpy as np
import matplotlib.pyplot as plt 

#data = np.loadtxt("f:/HUST/myCS/2020-fall/algorithm/ALGORITHM/luogu/1/P2678/tmp.txt")   #将文件中数据加载到data数组里
data = np.loadtxt("f:/HUST/myCS/2020-fall/algorithm/ALGORITHM/luogu/1/tmp2.txt")   #将文件中数据加载到data数组里
plt.figure(figsize=(8,4))           #设置图像大小
plt.plot(data)  #作图，设置标签、线条颜色、线大小
# plt.axhline(y=0, color='r', linestyle='-')
plt.show()                          #显示作图结果
