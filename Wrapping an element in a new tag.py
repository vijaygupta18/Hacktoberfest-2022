# importing BeautifulSoup Module
from bs4 import BeautifulSoup

markup = '

<p>Hello World</p>

'

# parsering string to HTML
soup = BeautifulSoup(markup, 'html.parser')
print(soup)

# wraping around the string
soup.p.string.wrap(soup.new_tag("u"))
print(soup)
