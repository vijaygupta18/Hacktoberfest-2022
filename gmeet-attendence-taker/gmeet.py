#written by: swapnil
#aps code competition
# position : 1

def open_gmeet(gmeet_code,email,password):

    from selenium import webdriver
    from selenium.webdriver.common.keys import Keys
    from selenium.webdriver.chrome.options import Options
    from selenium.webdriver.common.by import By
    from selenium.webdriver.support.ui import WebDriverWait
    from selenium.webdriver.support import expected_conditions as EC
    import time


    opt = Options()
    opt.add_argument("--disable-infobars")
    opt.add_argument("--window-size=1200,900")
    opt.add_argument("user-agent='User-Agent: Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/84.0.4147.125 Safari/537.36'")

        # browser will not ask for permissions

    opt.add_experimental_option("prefs", { \
    "profile.default_content_setting_values.media_stream_mic": 2,
    "profile.default_content_setting_values.media_stream_camera": 3,
    "profile.default_content_setting_values.geolocation": 2,
    "profile.default_content_setting_values.notifications": 2
    })



        #path to chrome driver


    PATH = "/home/swapnil/Desktop/sele/chromedriver"

    driver = webdriver.Chrome(PATH,chrome_options=opt)


    driver.get('https://accounts.google.com/o/oauth2/auth/identifier?client_id=717762328687-iludtf96g1hinl76e4lc1b9a82g457nn.apps.googleusercontent.com&scope=profile%20email&redirect_uri=https%3A%2F%2Fstackauth.com%2Fauth%2Foauth2%2Fgoogle&state=%7B%22sid%22%3A1%2C%22st%22%3A%2259%3A3%3Abbc%2C16%3A8761f44b2df242a2%2C10%3A1605194839%2C16%3Aa5c0f97ced3a97a0%2Cd6e1862c7d914c10f6439ba9b16cdacfc72fa9b10b30b7638c85ccda496f2a69%22%2C%22cdl%22%3Anull%2C%22cid%22%3A%22717762328687-iludtf96g1hinl76e4lc1b9a82g457nn.apps.googleusercontent.com%22%2C%22k%22%3A%22Google%22%2C%22ses%22%3A%22568af41449fc46548320092241478f27%22%7D&response_type=code&flowName=GeneralOAuthFlow')
    code = str(gmeet_code)


        #entering email
    email_login = driver.find_element_by_xpath('//*[@id="identifierId"]') 
    email_login.send_keys(email) 
    email_login.send_keys(Keys.RETURN)

        #sleeping to load the page

    time.sleep(3)

        #entering password
    pass_login = driver.find_element_by_xpath('//*[@id="password"]/div[1]/div/div[1]/input') 
    pass_login.send_keys(password) 
    pass_login.send_keys(Keys.RETURN)
    time.sleep(3)

        # getting gmeet

    driver.get("https://meet.google.com/{}".format(code))
    time.sleep(8)
    webdriver.ActionChains(driver).send_keys(Keys.ESCAPE).perform()
    time.sleep(6)
   

    #childrens\

    # driver.find_element_by_xpath('/html/body/div[1]/c-wiz/div[1]/div/div[7]/div[3]/div[6]/div[3]/div/div[2]/div[1]/span/span/div/div/span[1]/svg').click()
    
    students = []
    names = WebDriverWait(driver,50).until(EC.presence_of_all_elements_located((By.CLASS_NAME,"ZjFb7c")))

    for name in names: 
        # print(name.text)
        students.append(name.text)
    
    return students    
    
  
        




