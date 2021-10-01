from flask import Flask , render_template, request
# from flask_sqlalchemy import SQLAlchemy
import os
import game as g

app = Flask(__name__)

@app.route('/' , methods = ["GET"])
def index():
    return render_template("index.html")

@app.route('/submit', methods=['POST'])
def submit():
    if request.method == "POST":
        value = request.form["value"]
        score = g.game(value)
        total_score += points

    return render_template('index.html', s = score , total_score = total_score)

if __name__ == '__main__':
    app.run()
