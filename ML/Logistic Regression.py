import pandas as pd

db=pd.read_csv("titanic_train.csv")

y=db['Survived']

import seaborn as sns

survived=db["Survived"]

sns.countplot(survived, hue="Sex",data=db)
passclass= db["Pclass"]

db.isnull()
sns.heatmap(db.isnull())


x=db[["Pclass", "Sex", "Age", "SibSp", "Parch", "Embarked", "Cabin"]]

x.drop("Cabin" , axis=1, inplace= True)
def fill_Age(cols):
    pclass=cols[0]
    age=cols[1]
    
    if pd.isnull(age):
        if pclass==1:
            return 38
        elif pclass==2:
            return 30
        elif pclass==3:
            return 25
        else:
            return 30
    else:
        return age
      
      age=x[["Pclass","Age"]].apply(fill_Age,axis=1)

x["Age"]=age

sex=x["Sex"]

pclass=x["Pclass"]

pclass=pd.get_dummies(pclass, drop_first= True)

sibsp=x["SibSp"]

sibsp=pd.get_dummies(sibsp, drop_first= True)

parch=x["Parch"]

parch=pd.get_dummies(parch, drop_first= True)

embarked=x["Embarked"]

embarked=pd.get_dummies(embarked, drop_first= True)

final_ds=pd.concat([age,pclass,sex,sibsp,embarked,parch,y],axis=1)

final_ds

final_dataset=final_ds.dropna()

final_dataset

final_dataset.drop("Survived",axis=1, inplace= True)

x=final_dataset

from sklearn.model_selection  import train_test_split
x_train,x_test, y_train, y_test=train_test_split(x,y,test_size=0.20)

from sklearn.linear_model import LogisticRegression

model= LogisticRegression()

model.fit(x_train,y_train)

model.coef_
