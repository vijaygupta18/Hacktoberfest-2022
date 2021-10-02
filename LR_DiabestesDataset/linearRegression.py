import numpy as np
import matplotlib.pyplot as plt
from sklearn import datasets, linear_model
from sklearn.metrics import mean_squared_error, r2_score

diabetes_X, diabetes_y = datasets.load_diabetes(return_X_y=True)
from sklearn.model_selection import train_test_split
x_train,x_test,y_train,y_test=train_test_split(diabetes_X,diabetes_y)

print(x_train.shape)
print(x_test.shape)

print(y_train.shape)
print(y_test.shape)

model_lr=linear_model.LinearRegression()
model_lr.fit(x_train,y_train)

model_lr.intercept_
model_lr.coef_
y_pred=model_lr.predict(x_test)

print(y_pred.shape)
print(y_test.shape)

r2_score(y_test,y_pred)
mean_squared_error(y_test,y_pred)


#plotting of the regression and finding linear relation between BMI and Diabtes

x_train_plt=x_train[:,2]
x_test_plt=x_test[:,2]
print(x_test)
print(x_test_plt)
x_test_plt=x_test_plt.reshape(-1,1)
x_train_plt=x_train_plt.reshape(-1,1)
print(x_train_plt.shape,x_test_plt.shape)


model_plt=linear_model.LinearRegression()
model_plt.fit(x_train_plt,y_train)

y_pred_plt=model_plt.predict(x_test_plt)

plt.scatter(x_test_plt,y_test,color='red')

plt.plot(x_test_plt,y_pred_plt,color='pink')