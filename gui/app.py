from flask import Flask, render_template, request
import subprocess, json

app = Flask(__name__)
@app.route("/", methods=['GET', 'POST'])
def index():
    expression = ""
    vars_ = []
    rows_ = []
    classification_ = ""
    
    if request.method == 'POST':
        expression = request.form["expression"]
        process = subprocess.run(["./bin/main", expression],
                                 capture_output=True,
                                 text=True)
        if process.returncode == 0:
            try:
                result = json.loads(process.stdout)
                vars_ = result.get("variables", [])
                rows_ = result.get("rows", [])
                classification_ = result.get("classification", "")
            except json.JSONDecodeError:
                vars_ = []
                rows_ = []
                classification_ = f"Error decoding JSON: {process.stdout}"
        else:
            classification_ = f"Error: {process.stderr}"

    return render_template("index.html", variables=vars_, rows=rows_,
                           classification=classification_, expression=expression)


if __name__ == "__main__":
    import os
    port = int(os.environ.get("PORT", 5000))
    app.run(host="0.0.0.0", port=port)
