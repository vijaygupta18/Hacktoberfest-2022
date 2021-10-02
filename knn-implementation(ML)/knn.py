from math import sqrt
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

def distance(a,b):
    dis=0.0
    for i in range(len(a)-1):
        dis+=(a[i]-b[i])**2
    return sqrt(dis)

def get_neighbors(train,test,k):
  dis=[]
  for x in train:
    dis.append((x,distance(x,test)))
  dis.sort(key=lambda tup: tup[1])
  neighbour=[]
  for i in range(k):
    neighbour.append(dis[i][0])
    
  return neighbour


def predict(train, test,k):
	neighbours = get_neighbors(train, test, k)
	output_values = [row[-1] for row in neighbours]
	prediction = max(set(output_values), key=output_values.count)
	return prediction


data=pd.read_csv('knn_data.csv',delimiter=',')
	

array=np.array(data)
prediction=predict(array,array[0],5)
print(prediction)    