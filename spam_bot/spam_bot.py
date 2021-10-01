import pyautogui, time
time.sleep(5)
# write the name of the text file from where you want to bombard messages f = open("<name-of-file>","r")
for word in f:
	pyautogui.typewrite(word)
	pyautogui.press("enter")