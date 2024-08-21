# Calculator

**Calculator** is a simple and user-friendly cross-platform application designed for performing basic arithmetic operations. With a sleek and intuitive UI built using the Qt framework, it offers essential features to handle everyday calculations efficiently. Users can perform addition, subtraction, multiplication, and division, with support for both integer and floating-point numbers.

![calculator-capture](https://github.com/user-attachments/assets/c04879e2-42fa-4138-93fc-fd2e19da5661)

## Features of the Calculator Qt Application

### Cross-Platform Compatibility
- Works seamlessly across different operating systems, making it accessible to a wide range of users.

### Sleek and Intuitive User Interface
- Built with the Qt framework, the application offers a visually appealing and user-friendly interface, making navigation and usage simple and efficient.

### Basic Arithmetic Operations
- **Addition**: Sum two numbers with ease.
- **Subtraction**: Subtract one number from another.
- **Multiplication**: Multiply two numbers together.
- **Division**: Divide one number by another, with support for floating-point results.

### Floating-Point Support
- Handle decimal numbers in all operations, allowing for more precise calculations.

### Real-Time Results
- Instantaneously display the result of calculations as you input numbers and operators.

### Keyboard Shortcuts
- Use keyboard shortcuts to enhance productivity, making it faster and easier to perform calculations.

These features make **Calculator** a reliable tool for performing everyday mathematical tasks, tailored to the needs of students, professionals, and anyone who needs quick and accurate calculations.

## Building the Qt Application from Source

To build and run the **Calculator** application from source, the best approach is to open the project in [Qt Creator](https://www.qt.io/) and compile it. However, if you prefer to do it manually, follow these steps:

1. **Clone the Repository:**
   - Ensure you have Git installed on your system.
   - Open your terminal or command prompt and navigate to the directory where you want to clone the repository.
   - Run the following command:
     ```bash
     git clone https://github.com/ali-begic/calculator
     ```
   - Navigate into the cloned directory:
     ```bash
     cd calculator
     ```

2. **Install Qt Dependencies:**
   - Ensure you have the necessary Qt libraries, compilers, and build tools installed. Refer to the official Qt documentation for platform-specific instructions:
     - [Qt Documentation for Windows](https://doc.qt.io/qt-6/windows-deployment.html)
     - [Qt Documentation for macOS](https://doc.qt.io/qt-6/macos-deployment.html)
     - [Qt Documentation for Linux](https://doc.qt.io/qt-6/linux-deployment.html)

3. **Configure and Build:**
   - Create a build directory and navigate into it:
     ```bash
     mkdir build
     cd build
     ```
   - Run `qmake` to generate the Makefile from the `.pro` file:
     ```bash
     qmake ../src/calculator.pro
     ```
   - Compile the application:
      - On Windows with MSVC:
        ```bash
        nmake
        ```
      - On Windows with MinGW:
        ```bash
        mingw32-make
        ```
      - On macOS and Linux:
        ```bash
        make
        ```

4. **Run Your Application:**
   - After a successful build, the executable will be located in the build directory.
   - On Windows, you can find the executable in the release or debug directory depending on your build configuration.
   - Run the application:
     ```bash
     ./calculator
     ```

## Using `windeployqt` for Windows Deployment

To deploy the **Calculator** application on Windows, you can use the `windeployqt` tool. This tool automatically copies the necessary Qt runtime files (DLLs, plugins, etc.) to your application's deployment folder, making it easier to distribute the application.

### Steps to Use `windeployqt`:

1. **Build Your Application:**
   - Ensure that your application is fully built using the steps above.

2. **Open the Correct Command Prompt:**
   - Open the "Developer Command Prompt for VS 2022" or the "Qt MinGW" command prompt, depending on the compiler you used.

3. **Navigate to the Build Directory:**
   - Use the command prompt to navigate to the directory where your application’s executable is located:
     ```bash
     cd .../calculator/build/release
     ```

4. **Run `windeployqt`:**
   - Run the following command to deploy your application:
     ```bash
     windeployqt calculator.exe
     ```

5. **Test the Deployed Application:**
   - After running `windeployqt`, test the application by running the executable in its deployment directory to ensure all dependencies are correctly deployed.

6. **Distribute the Application:**
   - You can now package the deployed files (including the executable and all copied DLLs and plugins) into a ZIP file, installer, or other distribution formats for distribution.

## Contributing

Contributions are welcome! If you find a bug, have a feature request, or want to improve the code, feel free to open an issue or submit a pull request.

## License

This project is licensed under the Apache-2.0 license - see the [LICENSE](LICENSE) file for details.

## Additional Notes

- Ensure that you have the correct version of Qt and associated build tools for your platform.
- If you encounter issues, check the Qt and compiler documentation or seek assistance on community forums.
- If the application still does not work properly, try running it as an administrator.

Thank you for your interest in the **Calculator** application!
