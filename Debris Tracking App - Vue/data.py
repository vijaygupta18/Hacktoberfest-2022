
import urllib.request
from bs4 import BeautifulSoup
  
urllib.request.urlretrieve("https://celestrak.com/NORAD/elements/1999-025.txt",
                           "target.txt")
  
