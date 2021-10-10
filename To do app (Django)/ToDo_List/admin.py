from django.contrib import admin
from . import models

class ToDoListAdmin(admin.ModelAdmin):
    list_display = ["title", "date_created", "deadline"]

class CategoryAdmin(admin.ModelAdmin):
    list_display = ["name"]

admin.site.register(models.ToDoList, ToDoListAdmin)
admin.site.register(models.Category, CategoryAdmin)

