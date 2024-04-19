# Photo Editor Project README

## Introduction
Welcome to the README file for our Qt C++ photo editor project! This document provides detailed instructions on setting up and running the code, including the tools and their versions used. Additionally, it lists all the implemented filters, with explanations for any new filters developed.

## Setup and Usage
### Prerequisites
- Qt (Version Qt6 6.7.0)
- C++ Compiler (Version 6_7_0_MinGW_64_bit)
- [Any other dependencies]

### Installation
1. **Open the Project in Qt Creator:** Launch Qt Creator and open your project by selecting the project file (usually a `.pro` file) from the file browser.
2. **Configure Build Settings:** Once the project is open, configure the build settings according to your requirements. This includes selecting the build kit (compiler and Qt version) and configuring any additional build steps.
3. **Build the Project:** Click on the build button (usually a green play button) or select Build > Build Project from the menu to compile the project. This step generates the executable file.
4. **Run the Project:** After a successful build, click on the run button (usually a green arrow) or select Build > Run from the menu to execute the compiled program. This launches the application in the Qt Creator's integrated environment.
5. **Test the Application:** Once the application is running, test its functionality to ensure that it behaves as expected.
6. **Deploy or Distribute (Optional):** If you intend to distribute the application, you may need to package it for deployment. Qt provides tools for deploying applications on various platforms, including compiling the project statically or dynamically linking required libraries.
7. **External Execution:** If you prefer to run the application outside of Qt Creator, navigate to the directory where the executable is located and run it directly by double-clicking on it or executing it from the command line.

## Implemented Filters
1. **Filter 1: Gray**
2. **Filter 2: Black and white**
3. **Filter 3: Infrared**
4. **Filter 4: Skew**
5. **Filter 5: Brightness**
6. **Filter 6: Resize Image**
7. **Filter 7: Crop**
8. **Filter 8: Merge**
9. **Filter 9: TV Effect**
10. **Filter 10: Invert Image**
11. **Filter 11: Flip Image (horizontally or vertically)**
12. **Filter 12: Rotate**
13. **Filter 13: Darken and Lighten Image**
14. **Filter 14: Adding a Frame to the Picture**
15. **Filter 15: Detect Image Edges**
16. **Filter 16: Blur Images**
17. **Filter 17: Sunlight**
18. **Filter 18: Oil painting Effect**
19. **Filter 19: Purple**

## Explanation of New Filters
1. **Filter 1: Hue shift**
   - Take Image and Hue shift
   - Take Image Pixels' RGB and convert it to HSV
   - Add Hue shift to HSV
   - Turn new HSV to RGB
   - Set color to the new RGB

2. **Filter 2: Pixelate**
   - Take old Image and Pixelate intensity
   - Make new image of size (Image / Pixelate intensity)
   - Set every pixel of new image with the average of every pixel's RGB with area of (Pixelate intensity)^2

## Video Demonstration
For a visual demonstration of the photo editor in action, please watch our video tutorial [here](https://youtu.be/OTbHigu-GZQ).
