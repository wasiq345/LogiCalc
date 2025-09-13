from flask import Flask, render_template, request
import subprocess, json

app = Flask(__name__)

@app.route("/", methods = ['GET', 'POST'])
def index():
    result = None
    if request.method == 'POST':
        expression = request.form["expression"]

        process =subprocess.run(["../bin/main", expression],
                                capture_output=True,
                                text = True)
        
        if process.returncode == 0:
            result = json.loads(process.stdout)
        else:
            result = f"Error: {process.stderr}"
    return render_template("index.html", variables = result["variables"], rows = result["rows"])

if __name__ == "main":
    app.run(debug=True)