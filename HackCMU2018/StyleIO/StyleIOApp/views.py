from django.http import HttpResponseRedirect, HttpResponse
from django.shortcuts import render, redirect
from .forms import UploadFileForm
import os
#from StyleIOApp.io.github.predict_model import runPredictML

def handle_uploaded_file(f):
    dir = os.path.join(os.getcwd(),os.path.join("StyleIOApp",f.name))
    print(dir)
    with open(dir, 'wb+') as destination:
        for chunk in f.chunks():
            destination.write(chunk)

        #return runPredictML(modelpath,destination)
        return [1,2,3,4]

def results(request):
    error_lines = request.session['list']
    context = {
        'errors': error_lines
    }
    return render(request,'results.html',context)

def index(request):
    return render(request, 'index.html')


def upload(request):
    if request.method == 'POST':
        form = UploadFileForm(request.POST, request.FILES)
        print(request.FILES)
        if form.is_valid():
            error_lines = handle_uploaded_file(request.FILES['file'])
            request.session['list'] = error_lines
            return render(request,'results.html',{'errors': error_lines})
    else:
        form = UploadFileForm()
    return render(request, 'upload.html', {'form': form})
