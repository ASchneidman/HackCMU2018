from django.urls import path

from . import views

urlpatterns = [
    path('', views.index, name='index'),
    path('results/',views.results,name='results'),
    path('up/', views.upload, name='upload'),
    path('about/',views.about,name='about')
]
