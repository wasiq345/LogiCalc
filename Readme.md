
# LogiCalc
*Interactive Truth table & logic Expression Evaluator*

**LogiCalc** is a hybrid C++ + Python project that brings together speed, logic, and beauty.
It evaluates **logical expressions** (using a C++ backend for performance) and displays **interactive truth tables** in a **Flask-powered web interface** styled with **HTML + CSS**.


## ✨ Features
✅ **Logic Engine in C++** – fast postfix expression evaluation, full truth table generation.

✅ **Web GUI with Flask** – clean, interactive frontend for input & results.

✅ **Beautiful Styling** – responsive design with HTML & CSS.

✅ **Expression Classification** – detect whether an expression is a Tautology, Contradiction, or Contingency.

✅ **Separation of Concerns** – all logic in C++, all presentation in Python



## 🖥️ Tech Stack

- **C++17** – core logic evaluation (postfix parser, truth table generator)

- **nlohmann/json** – JSON export of truth tables from C++

- **Python 3 + Flask** – lightweight server & GUI frontend

- **HTML5 / CSS3** – styling and responsive design







## 📸 Demo Preview
![Preview](<Screenshot from 2025-09-14 14-22-55.png>)




## 🚀 Getting Started

### 1\. Clone the project

```bash
git clone https://github.com/wasiq345/LogiCalc.git
```

### 2\. Go to the project directory

```bash
cd LogiCalc
```

### 3\. Build the Engine

- **Linux/MacOs**
```bash
g++ -g -std=c++17 -Wall -Wextra -Iinclude src/*.cpp -o bin/main

```
- **On Windows**
```bash
g++ -g -std=c++17 -Wall -Wextra -Iinclude src/*.cpp -o bin/main.exe

```
This will generate an executable inside **bin/** that Flask will call.


### 4\. Setup Python Environment

```bash
cd gui
python3 -m venv venv      # create virtual environment
source venv/bin/activate  # activate (Linux/macOS)
venv\Scripts\activate     # activate (Windows)

pip install flask
```

### 5\. Run the Flask App

```bash
cd gui
python app.py
```

Visit 👉 http://127.0.0.1:5000 in your browser.



## 📂 Project Structure

```text
LogiCalc/
│
├── src/                 
│   ├── main.cpp        
│   ├── tokenizer.cpp    
│   ├── parser.cpp      
│   ├── evaluator.cpp    
│
├── include/            
│   ├── tokenizer.h
│   ├── parser.h
│   ├── evaluator.h
│
├── gui/               
│   ├── static/
|   |   ├── style.css
|   ├── templates/
|   |    ├── index.html
|   ├── app.py
│
├── README.md           
├── .gitignore  
```


## ⚙️ How It Works

**1.** User enters an expression in the Flask web interface (e.g. (A ∧ B) → C).

**2.** Flask sends the expression to the C++ engine.

**3.** C++ generates the truth table + classification in JSON format.

**4.** Flask parses the JSON and renders it beautifully in the browser.



## 🌟 Future Improvements

- Add support for custom operators
- Export tables to CSV / PDF
- Add interactive step-by-step evaluation
- Add evaluation for arguments using rules of inference



## 👨‍💻 Author

 - Github Profile [@wasiq345](https://github.com/wasiq345)
 -  Connect with me on [LinkedIn](https://www.linkedin.com/in/wasiq-azeem-730215367/)


