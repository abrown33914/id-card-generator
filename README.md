
# 🎫 ID Card Generator with Qt

The **ID Card Generator** is a comprehensive application developed for a **Programming II Final Project**. Built with **Qt** and **C++**, this project allows users to generate professional ID cards for **Florida Gulf Coast University** students and faculty with a simple, user-friendly interface. Featuring **PDF export capabilities**, the application makes it easy to save and manage ID cards directly on your computer.

## 🌟 Key Features

- **🎓 Student & Faculty ID Creation**: Separate forms for entering relevant details for students and faculty.
- **👀 Preview Styled Cards**: Preview custom FGCU-styled generated ID cards.
- **💾 Save as PDF**: Export ID cards directly to PDF format for easy access and printing.
- **📂 View Previous Cards**: Easily navigate and view previously created ID cards.
- **⚠️ Error & Exception Handling**: Smooth and reliable experience, even when things don't go as planned.
- **💻 Demonstrates Core C++ and OOP Concepts**:
  - Polymorphism, Inheritance, Encapsulation
  - Control Structures and Abstract Classes
  - Effective Dynamic Memory Management

## 🚀 Getting Started

### 🛠️ Prerequisites

To run the ID Card Generator, make sure you have:

- **Qt Creator**: Download from [Qt's official website](https://www.qt.io/download).
- **C++ Development Environment**: Ensure it's configured for Qt.

### ⚙️ Installation

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/yourusername/id-card-generator.git
   cd id-card-generator-qt
   ```

2. **Open in Qt Creator**:
   - Open the project by navigating to `File > Open File or Project` and selecting the `id-card-generator.pro` file.
   - Click "Run" to compile and execute the application.

### ⚠️ Important Note:

To display the FGCU logo on the ID cards, **update the image path** in the following files:

- **mainwindow.cpp**
- **facultyform.cpp**
- **studentform.cpp**
- **studentcarddisplay.cpp**
- **facultycarddisplay.cpp**

Find the following lines:

```cpp
// ####### REPLACE WITH YOUR FGCU LOGO IMAGE PATH #############################
QString globalLogoPath = "C:/Users/abrow/OneDrive/Documents/QT/fgcu_logo.png";
// ############################################################################
```

**Replace** the `globalLogoPath` value with the full path to your local `fgcu_logo.png`.

## 💡 How It Works

1. **🏠 Main Menu**: Choose to create a new ID card or view a previously made one.
2. **📝 Fill out Forms**: Input information for either a Student or Faculty ID.
3. **💾 Save as PDF (Optional)**: Save the final version as a PDF.
4. **🔄 View Previous Cards**: Navigate through previously created cards to review them.

## 💥 Why This Project Stands Out

This project is a strong showcase of core C++ programming concepts learned throughout the Fall 2024 semester, highlighting object-oriented principles such as polymorphism, inheritance, and encapsulation, alongside solid memory management and efficient control structure utilization. Additionally, robust error and exception handling and template usage ensures a smooth user experience.
