import functools
import operator

tweets = ["The best Pizza in the city. Do try it out. #food",
          "Who knew solo #travel could be this fun.",
          "People who love to eat are always the best people #food",
         "India would have never eliminated polio, if people had to BUY polio vaccines. Same logic applies for #COVID19",
         "It was so fun spending the day with @sumitra trying all the fun #food in the area.",
         "One who doesn't travel, dies a lonely life. #travel",
         "Khalsa Aid India arranges Oxygen concentrators for COVID-19 patients, will deliver them in Delhi. #COVID19"]

food = ["#food"] * len(tweets)
travel = ["#travel"] * len(tweets)

def segregate_tweets(lst, topic):
    if topic in lst.lower():
        return lst

resultfood = list(map(segregate_tweets, tweets, food))
resulttravel = list(map(segregate_tweets, tweets, travel))

def filter_list(lst):
    if lst != "":
        return lst

result_food = list(filter(filter_list, resultfood))
result_travel = list(filter(filter_list, resulttravel))

print("Food tweets: {}".format(len(result_food)))
print("Travel tweets: {}".format(len(result_travel)))
