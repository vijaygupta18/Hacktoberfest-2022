# Build n-gram with NLTK
# n-gram: https://en.wikipedia.org/wiki/N-gram
# pip install nltk
from nltk import ngrams

n = 1 # 1 = unigram, 2 = bigram and 3 = trigram

sent = "I love cat." # your sentence
ngrams = ngrams(sent.split(), n)
print(list(ngrams)) # [('I',), ('love',), ('cat.',)]
