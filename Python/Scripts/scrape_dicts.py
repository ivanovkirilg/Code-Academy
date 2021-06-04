import requests
import lxml
import re
from bs4 import BeautifulSoup

def scrape_bg_dict(word):
    bg_src = requests.get("http://rechnik.info/" + word).text
    bg_soup = BeautifulSoup(bg_src, "lxml")

    definitions = bg_soup.find('div', class_='defbox').text
    print(definitions)


def scrape_thesaurus(word):
    thes_src = requests.get("https://www.thesaurus.com/browse/" + word).text
    thes_soup = BeautifulSoup(thes_src, "lxml")
    
    thes_words = thes_soup.find('div', {"data-testid": "word-grid-container"}).find_all('li')
    for word in thes_words:
        print(word.text, end='\t')
    print()


def scrape_en_dict(word):
    en_src = requests.get("https://www.dictionary.com/browse/" + word).text
    en_soup = BeautifulSoup(en_src, "lxml")

    en_words = en_soup.find_all('section', class_="css-pnw38j e1hk9ate4")
    for word in en_words:
        for div in word:
            print(div.text)



word = input()
while (word):
    try:
        scrape_bg_dict(word)
        print()
    except:
        print("bulgarian definitions not found" + '\n')

    try:
        scrape_en_dict(word)
        print()
    except:
        print("english definitions not found" + '\n')

    try:
        scrape_thesaurus(word)
        print()
    except:
        print("thesaurus entry not found" + '\n')

    print()

    word = input()
