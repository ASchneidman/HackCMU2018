from django.urls import path

from . import views

urlpatterns = [
    path('', views.index, name='index'),
    path('results/<int:num_errors>',views.results,name='results')
]
