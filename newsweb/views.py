from django.shortcuts import render
from django.http import HttpResponse
import requests
import json
# Create your views here.
def home(request):
    news_api_request = requests.get("https://newsapi.org/v2/top-headlines?country=us&category=business&apiKey=f62e90fce1194df7b2d08a34dd2af991")
    api = json.loads(news_api_request.content)
    return render(request,'newsweb/home.html',{'api': api})
