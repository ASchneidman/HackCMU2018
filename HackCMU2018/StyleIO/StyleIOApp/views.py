from django.http import HttpResponseRedirect, HttpResponse
from django.shortcuts import render
from .forms import UploadFileForm
import os

def handle_uploaded_file(f):
    dir = os.path.join(os.getcwd(),os.path.join("StyleIOApp",f.name))
    print(dir)
    with open(dir, 'wb+') as destination:
        for chunk in f.chunks():
            destination.write(chunk)

def index(request):
    if request.method == 'POST':
        form = UploadFileForm(request.POST, request.FILES)
        print(request.FILES)
        if form.is_valid():
            handle_uploaded_file(request.FILES['file'])
            return HttpResponse("Got it!")
    else:
        form = UploadFileForm()
    return render(request, 'index.html', {'form': form})
