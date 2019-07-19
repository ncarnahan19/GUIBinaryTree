# Import webbrowser attachents
import selenium, re, time, os
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.by import By

# Create regular exressions to return digits in the .txt file
addRegex = re.compile(r'[0-9]+')
delRegex = re.compile(r'[0-9]+')

# Open the browser and the BST GUI website
browser = webdriver.Firefox()
browser.get('https://www.cs.usfca.edu/~galles/visualization/BST.html')

# Find the HTML elements on which to enter the data 
buttonFrame = browser.find_element_by_id('AlgorithmSpecificControls')
insertElm = browser.find_element_by_tag_name('Input')
delElm = browser.find_element_by_xpath(r"(//input[@type='Text'])[2]")

# Open the .txt file containing the data to be entered into the website
plugBSTPath = (os.path.abspath('.') + '\\plugBST.txt')
bstFile = open(plugBSTPath)

# Loop through dictionary created by file
for data in bstFile.readlines():
    # print(data)
# Enter numbers from the add section in the c++ binary search tree into "add" section.
    numToEnter = addRegex.search(data)
    # numToDel = delRegex.search(data)
    if data[0:3] == 'Add':  
        # print(numToEnter.group())
        insertElm.send_keys(numToEnter.group()) 
        insertElm.send_keys(Keys.ENTER)
        time.sleep(2) 
# Enter numbers from the delete section in the c++ binary search tree into "delete" section.   
    elif data[0:3] == 'Del':       
        # print(numToEnter.group())
        num = numToEnter.group()
        time.sleep(2) 
        delElm.send_keys(str(num))
        delElm.send_keys(Keys.ENTER)
        time.sleep(2)
    else:
        continue
