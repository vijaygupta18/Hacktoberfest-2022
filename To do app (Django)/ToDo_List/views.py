from django.shortcuts import render, redirect
from .models import ToDoList, Category

def index(request):
    todos = ToDoList.objects.all()
    categories = Category.objects.all()

    if request.method == "POST":
        if "taskAdd" in request.POST:
            title = request.POST["description"]
            date = str(request.POST["date"])
            category = request.POST["category_select"]
            content = title + " -- " + date + " " + category

            ToDo = ToDoList(title=title, content=content,deadline=date,category=Category.objects.get(name=category))
            ToDo.save()
            return redirect("/")

        if "taskDelete" in request.POST:
            checklist = request.POST["checkedbox"]

            for todo_id in checklist:
                todo = ToDoList.objects.get(id=int(todo_id))

                todo.delete()
    return render(request, "index.html",{"todos": todos,"categories":categories}) 
