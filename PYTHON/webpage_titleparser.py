'''
Program to parse the title of web page
'''

import re
from urllib.request import urlopen


#url of web page
url = "https://en.wikipedia.org/wiki/Comparison_of_HTML_parsers"

#open the web page from where data needs to be extracted
page = urlopen(url)

#extracts html from the web page
html = page.read().decode("utf-8")


pattern = "<title.*?>.*?</title.*?>"

#extract text using regular expressions
match_results = re.search(pattern, html, re.IGNORECASE)
title = match_results.group()

# Remove HTML tags
title = re.sub("<.*?>", "", title) 

print(title)
