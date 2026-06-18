from django.shortcuts import render
from django.http import HttpResponse

# Create your views here.

def index(request):
    return HttpResponse("site!")

def greet(request, name):
    return render(request, "main/greet.html", {
        "name": name.capitalize()
    })