from datetime import time
from django.db import models
from django.utils import timezone

class Category(models.Model):
    name = models.CharField(max_length=100)

    class Meta:
        verbose_name = ("Category")
        verbose_name_plural = ("Categories")

    def __str__(self):
        return self.name

class ToDoList(models.Model):
    title = models.CharField(max_length=300)
    date_created = models.DateField(default=timezone.now().strftime("%Y-%m-%d"))
    content = models.TextField(blank=True)
    deadline = models.DateField(default=timezone.now().strftime("%Y-%m-%d"))
    category = models.ForeignKey(Category, default="general", on_delete=models.CASCADE)

    class Meta:
        ordering = ["-date_created"]

    def __str__(self):
        return self.title

