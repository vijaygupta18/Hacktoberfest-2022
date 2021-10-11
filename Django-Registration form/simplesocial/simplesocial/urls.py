"""simplesocial URL Configuration

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/2.0/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.urls import include, path
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""
from django.contrib import admin
from django.conf.urls import url, include
from . import views

urlpatterns = [
    url(r'^$', views.HomePage.as_view(), name="home"),
    url('admin/', admin.site.urls),
    url('test/', views.TestPage.as_view(), name="test"),
    url('thanks/', views.ThanksPage.as_view(), name="thanks"),
    url('accounts/', include("accounts.urls", namespace="accounts")),
    url('accounts/', include("django.contrib.auth.urls")),
]
