

get_ipython().run_line_magic('matplotlib', 'inline')
import matplotlib.pyplot as plt

from sklearn.datasets import load_digits



digits=load_digits()

dir(digits)

digits.data[0]



plt.gray()
for i in range(5):
    plt.matshow(digits.images[i])



digits.target[0:5]

from sklearn.model_selection import train_test_split
xtrain,xtest,ytrain,ytest=train_test_split(digits.data,digits.target,test_size=0.4)



len(xtrain)

len(xtest)

from sklearn.linear_model import LogisticRegression

model=LogisticRegression()
model.fit(xtrain,ytrain)

model.score(xtest,ytest)

plt.matshow(digits.images[67])

digits.target[67]

model.predict([digits.data[67]])



model.predict(digits.data[0:5])

ypred=model.predict(xtest)
from sklearn.metrics import confusion_matrix

cm=confusion_matrix(ytest,ypred)
cm


import seaborn as sn   #used for visulaization
plt.figure(figsize=(10,7))
sn.heatmap(cm,annot=True)
plt.xlabel('Predicted')
plt.ylabel('Truth')
