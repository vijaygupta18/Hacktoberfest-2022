"""
A Python project to Scrap data from ICC Rankings page and get the ranking table for Mens ODI Teams using Selenium webdriver and create a DataFrame using pandas to store the information.
From DataFrame to, We are saving this data into SQL Database file. 

Link of page- "https://www.icc-cricket.com/rankings/mens/team-rankings/odi"

"""

#Import Libraries
import pandas as pd
from selenium import webdriver

#URL
url = "https://www.icc-cricket.com/rankings/mens/team-rankings/odi"

#Load Webdriver from path
driver = webdriver.Firefox(executable_path="E:\geckodriver\geckodriver.exe")

# Opening the submission url
driver.get(url)

#Finding all tables
all_tables   =  driver.find_element_by_tag_name('tbody')

#Generate lists
A, B, C, D, E = [], [], [], [], []

for row in all_tables.find_elements_by_tag_name('tr'):
    
    cells = row.find_elements_by_tag_name('td')
    
    if len(cells) == 5:
        A.append(cells[0].text.strip())
        B.append(cells[1].text.strip())
        C.append(cells[2].text.strip())
        D.append(cells[3].text.strip())
        E.append(cells[4].text.strip())


from collections import OrderedDict

col_name = ["Pos","Team","Matches","Points","Rating"]
col_data = OrderedDict(zip(col_name,[A,B,C,D,E]))

#MAKING DATAFRAME
df = pd.DataFrame(col_data)

print(df)


#Saving file into sql database file

import sqlite3

# File based database ( connects if exists or creates a new one if it does not exists ) 
conn = sqlite3.connect ( 'ranking.db' )

#CREATING CURSOR
c = conn.cursor()

#SAVING DB TABLE
df.to_sql("rankingselenium", con=conn, if_exists = 'replace', index=False)

#PRINT FILE DATA
c.execute("SELECT * FROM rankingselenium")
print ([print(i) for i in c.fetchall()] )


#EXIT DRIVER
driver.quit()