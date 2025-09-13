from flask import Flask, render_template, request
import subprocess

app = Flask(__name__)

@app.route("/", methods = ['GET', 'POST'])
def index():
    result = None
    if request.method == 'POST':
        expression = request.form["expression"]

        process =subprocess.run(["../bin/main"],
                                input = expression,
                                stdout = subprocess.PIPE,
                                stderr = subprocess.PIPE,
                                 text = True)
        
        if process.returncode == 0:
            result = process.stdout
        else:
            result = f"Error: {process.stderr}"
    return render_template("index.html", result = result)

if __name__ == "main":
    app.run(debug=True)
