from django.http import HttpResponseRedirect, HttpResponse
from django.shortcuts import render, redirect
from .forms import UploadFileForm
import os

def handle_uploaded_file(f):
    dir = os.path.join(os.getcwd(),os.path.join("StyleIOApp",f.name))
    print(dir)
    with open(dir, 'wb+') as destination:
        for chunk in f.chunks():
            destination.write(chunk)
        return 10


def index(request):
    if request.method == 'POST':
        form = UploadFileForm(request.POST, request.FILES)
        print(request.FILES)
        if form.is_valid():
            num_errors = handle_uploaded_file(request.FILES['file'])
            return redirect('results',num_errors)
    else:
        form = UploadFileForm()
    return render(request, 'index.html', {'form': form})

def results(request,num_errors):
    context = {
        'num_errors': num_errors
    }
    return render(request,'results.html',context)
