import random ,turtle
from copy import deepcopy

def Sort(sub_li):
	sub_li.sort(key = lambda x: x[1],reverse=True)    
	return sub_li   
  
def getChromosomeValue(chromosome):
    return int(''.join(str(bit) for bit in chromosome),2)

def draw_graph(y_cord):
    sc = turtle.Screen()   
    pen = turtle.Turtle()
    pen.shape("turtle")
    sc.setup(600, 600)    
    pen.speed(0)
    x=-100
    pen.penup()
    pen.width(5)
    pen.setpos(-100,0)
    pen.pendown()
    pen.fd(1000)
    pen.rt(180)
    pen.fd(1000)
    pen.rt(90)
    pen.fd(1000)
    pen.rt(180)
    pen.fd(1000)
    pen1 = turtle.Turtle()
    
    pen1.penup()
    pen1.setpos(-100,0)
    pen1.pendown()
    pen1.width(3)
    max_y = max(y_cord)
    space = 800/len(y_cord)
    for y in y_cord:
        x= x+ space
        pen1.setpos(x,y*2)
        pen1.color('blue')
        pen1.dot(size = 7)
        pen1.color('black')
    pen1.penup()
    pen1.fd(1000)
    pen2 = turtle.Turtle()
    pen2.penup()
    pen2.setpos(-100,max_y*2)
    pen2.pendown()    
    pen2.fd(1000)
    


        
    turtle.done()

def getFitnessValue(population):
    fitnessValues = list()    
    for chromosome in population:
        x = getChromosomeValue(chromosome)
        fitnessValues.append([chromosome ,(2*(x**2)+1)])
    
    fitnessValues = Sort(fitnessValues)
    
    return fitnessValues

def get_best_fitness_value_chromosome(population):
    fitnessValues = list()    
    for chromosome in population:
        x = getChromosomeValue(chromosome)
        fitnessValues.append([chromosome ,(2*(x**2)+1)])
    
    fitnessValues = Sort(fitnessValues)
    
    return fitnessValues[0][0]

def tournament_Selection(population):        
    parents =list()
    for i in range(2):
        randomly_selected_population = list()
        k = random.randrange(1,len(population)+1)

        while len(randomly_selected_population) != k:
            temp = random.randrange(0,len(population))
            randomly_selected_population.append(population[temp])

        parents.append(get_best_fitness_value_chromosome(randomly_selected_population))

    return parents

def single_point_crossover(parents,crossover_probability):
    offsprings_list = list()

    randomC = random.uniform(0, 1)     # Probability Check    
    if randomC < crossover_probability:
        print("crossover ++")
        while len(offsprings_list) == 0 :
            crossover_point = random.randint(0,2)
            offspring1 = parents[0][0:crossover_point+1] + parents[1][crossover_point+1:]
            offspring2 = parents[1][0:crossover_point+1] + parents[0][crossover_point+1:]
            a = getChromosomeValue(offspring1)
            b = getChromosomeValue(offspring2)
            if a > 0 and a < 7 and b > 0  and b < 7 :
                offsprings_list.append(offspring1)
                offsprings_list.append(offspring2)
                print("point : ",crossover_point)
                print("off 1",offspring1)
                print("off 2",offspring2)
        
        return offsprings_list
    
    return parents  #if crossover doesn't happen then offsprings are identical to parents

def uniform_crossover(parents,crossover_probability):
    offsprings_list = list()

    randomC = random.uniform(0, 1)     # Probability Check    
    if randomC < crossover_probability:
        print("Crossover Happened")
        while len(offsprings_list) == 0 :
            
            offspring1 = list()
            offspring2 = list()
            
            for i in range(len(parents[0])):
                coin1 = random.randint(0,1)
                offspring1.append(parents[coin1][i])

                coin2 = random.randint(0,1)
                offspring2.append(parents[coin2][i])


            a = getChromosomeValue(offspring1)
            b = getChromosomeValue(offspring2)
            if a > 0 and a < 7 and b > 0  and b < 7 :
                offsprings_list.append(offspring1)
                offsprings_list.append(offspring2)
                print("OffSprings",offspring1,offspring1)
                
        
        return offsprings_list

    print("Crossover didn't Happen")
    print("OffSprings (Same as Parents) :",parents)
    return parents  #if crossover doesn't happen then offsprings are identical to parents
    
def bit_flip_mutation(chromosome,mutation_probability):
    flag=0

    randomM = random.uniform(0, 1)     # Probability Check
    if randomM < mutation_probability :
        print("Mutation Happened")
        while flag == 0:
            temporary_chromosome = deepcopy(chromosome)
            flip_index = random.randint(0,2)
            temporary_chromosome[flip_index] = 1 - temporary_chromosome[flip_index]
            chromosome_value = getChromosomeValue(temporary_chromosome)
            if chromosome_value > 0 and chromosome_value < 7:
                flag=1
                print("Mutation before and after : ",chromosome,temporary_chromosome)
                chromosome = deepcopy(temporary_chromosome)
    else:
        print("Mutation didn't Happen:")
        print("Before and After (Will be Same) : ",chromosome,chromosome)

    
    return chromosome






############################### Main/Driver ##################################



bestFitnessValue = -1
n=4
crossover_probability = random.uniform(0, 1)
mutation_probability = random.uniform(0, 1)
# n = random.randrange(1,4)*2
# crossover_probability = (input("Enter the CrossOver Probability : "))
# mutation_probability = (input("Enter the CrossOver Probability : "))

#Encoding - Binary


#Randomly generating a population
population = list()
temp = list()
while len(population)!=n :
    temp = [random.randint(0,1) for z in range(3)]
    if getChromosomeValue(temp) > 0  and getChromosomeValue(temp) < 7:
        population.append(temp)

print("Initial Population : ")
print(population)
all_values = list()

same_bestValueCount = 0
i=1
while 1==1 :
    print("\n\n\nGeneration",i,":")
    

    # Getting Fitness values of the Population
    fitnessValues = list()
    fitnessValues = getFitnessValue(population)
    print("\nCurrent Population and its best Fitness value : ", population ,fitnessValues[0][1],"\n")
    all_values.append(fitnessValues[0][1])
    if bestFitnessValue < fitnessValues[0][1]:
        bestFitnessValue = fitnessValues[0][1]

    if bestFitnessValue == fitnessValues[0][1]:
        same_bestValueCount = same_bestValueCount +1

    if same_bestValueCount == 50:
        print("\n\n\n\n\nNo. of Nodes Generated : ",n*(i-1))
        print("No. of Nodes Expanded : ",n*(i-1))
        print("\n\nMaximum Value of the Function:",bestFitnessValue)
        print("\nFinal Population : ",getFitnessValue(population))
        print("\nNo. of Generation :",i-1,"\n\n")
        
        draw_graph(all_values)
        break

    
    new_generated_population = list()
    for generation_count in range(int(len(population)/2)):

        # Parent Selection using Tournament Selection
        parents = list()
        parents = tournament_Selection(population)
        
        print("Parents Selection",generation_count,":",parents)

        
        offsprings = list()  
            
        #offsprings = deepcopy(single_point_crossover(parents,crossover_probability))  # Single Point Crossover


        # Uniform Crossover
        offsprings = deepcopy(uniform_crossover(parents,crossover_probability))
        new_generated_population = new_generated_population + offsprings
    print("\nPopulation after Crossover and Before Mutation : ",new_generated_population,"\n")
    

    population_after_mutation = list()
    # Mutation (Bit Flip)
    for chromosome in new_generated_population:
        population_after_mutation.append(bit_flip_mutation(chromosome,mutation_probability))
        

    print("\nPopulation After  Mutation : ",population_after_mutation,"\n\n\n")
    population = deepcopy(population_after_mutation)
    i+=1
    




    
