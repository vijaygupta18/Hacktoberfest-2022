import random

def stochastic_hillclimbing(state):
    expand=0
    generate=0
    while 1:
          steep = []
          neighbors = []
          next_state = state.copy()
          current=attacking_queens(next_state)

          if current==0:
              print("No of nodes generated:")
              print(generate)
              print("No of nodes expanded:")
              print(expand)

              return state

          for i in range(0,8):

              next_state[random.randint(0,7)]=random.randint(0,7)
              next=attacking_queens(next_state)
              if current==next:
                  next_state = state.copy()
                  continue

              else:

                 if(next<current):
                    steep.append(current-next)
                    neighbors.append(next_state)
                    next_state = state.copy()

          if len(neighbors)==0:
              continue
          generate+=len(neighbors)
          #if len(neighbors)==1:
           #   state = neighbors[0].copy()
            #  expand += 1
             # continue

          j=random.randrange(0,len(neighbors))
          state=neighbors[j].copy()
          expand+=1
          print ("Next state:")
          print(state)


def attacking_queens(state):
    attack = 0
    for i in range(0,len(state)):
        for j in range(0, len(state)):
            if i!=j:
              if state[i] == state[j]:
                 attack += 1
              offset = j - i
              if abs(state[i] - state[j]) == offset:
                 attack += 1

    return attack

def initial_state():
    state=[]
    for i in range(0,8):
        state.append(random.randint(0,7))

    return state

def main():
    s=initial_state()
    print("Initial state:")
    print(s)
    sol=stochastic_hillclimbing(s)
    print("\n\nSolution:")
    print(sol)
    for i in range(8):
        for i2 in range(8):
            if sol[i2] == i:
                print('Q', end=' ')
            else:
                print('*', end=' ')
        print()

if __name__ == "__main__":
    main()
