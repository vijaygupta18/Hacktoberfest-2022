
import urllib.request

  
# here we have to pass url and path
# (where you want to save ur text file)
urllib.request.urlretrieve("https://celestrak.com/NORAD/elements/1999-025.txt",
                           "target.txt")
  
# file = open("text_file.txt", "r")
# contents = file.read()
# soup = BeautifulSoup(contents, 'html.parser')
  
# f = open("test1.txt", "w")
  
# # traverse paragraphs from soup
# for data in soup.find_all("p"):
#     sum = data.get_text()
#     f.writelines(sum)
  
# f.close()