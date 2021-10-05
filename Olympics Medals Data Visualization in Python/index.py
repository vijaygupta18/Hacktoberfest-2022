"""
 This is a beginner level project which includes:
 - Basic File Handling
 - Use of Python Modules
 - Using Matplotlib.pyplot to visualize data and create different types of graphs for efficient data analysis
"""

import matplotlib.pyplot as plt
from tabulate import tabulate
import csv

print('--:Program to Fetch & Visualize Olympics Medals Data of Various Countries:--')

csvdata = []
countries = []
y2021, y2016, y2012, y2008 = [], [], [], []
# Fetching the data
with open('medals.csv', 'r') as csv_file:
    readCSV = csv.reader(csv_file, delimiter=',')
    for row in readCSV:
        csvdata.append(row)
    print('Considered Dataset: Medals earned by Countries')
    print(tabulate(csvdata))
    # Storing data in appropriate format
    for row in csvdata[1:]:
        countries.append(row[0])
        y2021.append([int(row[1]), int(row[2]), int(row[3]), int(row[1]) + int(row[2]) + int(row[3])])
        y2016.append([int(row[4]), int(row[5]), int(row[6]), int(row[4]) + int(row[5]) + int(row[6])])
        y2012.append([int(row[7]), int(row[8]), int(row[9]), int(row[7]) + int(row[8]) + int(row[9])])
        y2008.append([int(row[10]), int(row[11]), int(row[12]), int(row[10]) + int(row[11]) + int(row[12])])

# Plotting Multiple bar graph
years = ['2008', '2012', '2016', '2021']
x = countries
tot2021 = [i[3] for i in y2021]
tot2016 = [i[3] for i in y2016]
tot2012 = [i[3] for i in y2012]
tot2008 = [i[3] for i in y2008]
xpos1 = [i for i in range(len(countries))]
xpos2 = [i + 0.2 for i in range(len(countries))]
xpos3 = [i + 0.4 for i in range(len(countries))]
xpos4 = [i + 0.6 for i in range(len(countries))]
plot1 = plt.figure(1)
plt.bar(xpos1, tot2008, color='blue', width=0.2, label='2008')
plt.bar(xpos2, tot2012, color='green', width=0.2, label='2012')
plt.bar(xpos3, tot2016, color='yellow', width=0.2, label='2016')
plt.bar(xpos4, tot2021, color='red', width=0.2, label='2021')
plt.title('Olympics Total Medals Summary')
plt.ylabel('Total no. of medals')
plt.xticks([i-0.1 for i in xpos3], countries)
plt.xlabel('Countries')
plt.legend()
# plt.show()
plt.savefig('fig1_OlympicsTotalMedalSummary.png')

# Creating dictionary for further plots
medal_type_data = {}
for i in range(len(countries)):
    gold = [y2008[i][0], y2012[i][0], y2016[i][0], y2021[i][0], y2008[i][0] + y2012[i][0] + y2016[i][0] + y2021[i][0]]
    silver = [y2008[i][1], y2012[i][1], y2016[i][1], y2021[i][1], y2008[i][1] + y2012[i][1] + y2016[i][1] + y2021[i][1]]
    bronze = [y2008[i][2], y2012[i][2], y2016[i][2], y2021[i][2], y2008[i][2] + y2012[i][2] + y2016[i][2] + y2021[i][2]]
    total = [y2008[i][3], y2012[i][3], y2016[i][3], y2021[i][3], y2008[i][3] + y2012[i][3] + y2016[i][3] + y2021[i][3]]
    medal_type_data[countries[i]] = [gold, silver, bronze, total]
# print(medal_type_data)

# Plotting Line graph subplots
i = 1
plot2 = plt.figure(2)
plt.suptitle('Country-wise medals earned throughout the years'.title())

for country in countries:
    x = years
    gold = medal_type_data[country][0][0:4]
    silver = medal_type_data[country][1][0:4]
    bronze = medal_type_data[country][2][0:4]
    total = medal_type_data[country][3][0:4]
    plt.subplot(230 + i)
    plt.plot(x, gold, color='gold', label='Gold', linewidth=1, marker='o', markersize=3, markerfacecolor='white')
    plt.plot(x, silver, color='silver', label='Silver', linewidth=1, marker='o', markersize=3, markerfacecolor='white')
    plt.plot(x, bronze, color='brown', label='Bronze', linewidth=1, marker='o', markersize=3, markerfacecolor='white')
    plt.plot(x, total, color='blue', label='Total', linewidth=1, marker='o', markersize=3, markerfacecolor='white')
    plt.title(country)
    plt.xlabel('Years')
    plt.ylabel('No. of medals')
    i += 1
plt.legend(loc=0)
# plt.show()

# Plotting Pie chart subplots
labels = ['gold', 'silver', 'bronze']
colors = ('gold', 'silver', 'brown')
fig, axs = plt.subplots(2, 3)
plot3 = plt.figure(3)
plt.suptitle('Country-wise Pie chart for no. of medals earned of each type/total medals'.title())
i = 0
for j in range(2):
    for k in range(3):
        axs[j, k].pie([med[3] for med in medal_type_data[countries[i]][0:3]], labels=labels, colors=colors)
        axs[j, k].set_title(countries[i])
        i += 1

# Plotting Scatter plot
x = countries
y = [ctmed[3][4] for ctmed in medal_type_data.values()]
plot4 = plt.figure(4)
plt.scatter(x, y, label='Total Medals', color='purple', marker='*', s=40)
plt.xlabel('Countries')
plt.ylabel('Total no. of Medals')
plt.title('Total no. of medals earned by Countries in 4 Olympics'.title())
for i, txt in enumerate(y):
    plt.annotate(txt, (x[i], y[i]))
plt.savefig('fig4_TotalMedalsIn4Olympics.png')

plt.show()


"""
Console Output:
--:Program to Fetch & Visualize Olympics Medals Data of Various Countries:--
Considered Dataset: Medals earned by Countries
---------  ---------  -----------  -----------  ---------  -----------  -----------  ---------  -----------  -----------  ---------  -----------  -----------
Country    2021 gold  2021 silver  2021 bronze  2016 gold  2016 silver  2016 bronze  2012 gold  2012 silver  2012 bronze  2008 gold  2008 silver  2008 bronze
India      1          2            4            0          1            1            0          2            4            1          0            2
Italy      10         10           20           8          12           8            8          9            11           8          10           10
USA        39         41           33           46         37           38           47         27           30           36         38           36
Australia  17         7            22           8          11           10           8          15           12           14         15           17
China      38         32           18           25         19           26           38         31           22           51         21           28
Jamaica    4          1            4            6          3            2            4          5            3            6          3            2
---------  ---------  -----------  -----------  ---------  -----------  -----------  ---------  -----------  -----------  ---------  -----------  -----------
"""
