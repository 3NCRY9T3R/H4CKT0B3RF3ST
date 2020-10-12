import requests
from bs4 import BeautifulSoup

class Product:
    def __init__(self,title,price,img):
        self.title=title
        self.price=price
        self.img=img
def scrap(query):
    url='https://www.snapdeal.com/search'
    params={
        'keyword':query,
        'sort':'plth'
    }
    r=requests.get(url,params=params)
    soup= BeautifulSoup(r.content)
    products=soup.findAll('div',attrs={'class':'product-tuple-listing'})
    results=[]
    for product in products:
        title=product.find('p',attrs={'class':'product-title'})
        price=product.find('span',attrs={'class':'product-price'})
        img=product.find('img',attrs={'class':'product-image'})
        if "src" in img.attrs:
            results.append(
                Product(title.text,price.text,img.attrs["src"])
            )
            
        elif "data-src" in img.attrs:
            results.append(
                Product(title.text,price.text,img.attrs["data-src"])
            )
    return results
