#include "mainwindow.h"
#include "resizedialog.h"
#include "cropdialog.h"
#include "mergeoptionsdialog.h"
#include "./ui_mainwindow.h"
#include "Lib/Image_Class.h"

#include <bits/stdc++.h>
#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QInputDialog>
#include <QLabel>
#include <QPushButton>
#include <QFileDialog>
#include <QColorDialog>
#include <QColor>
#include <QPixmap>
#include <bits/stdc++.h>
using namespace std;

#define PI 3.14159265358979323846

QString loadedImagePath;
QString originalPath = "";
QString pathTmp;
QString preserveImgPath;
// Grayscale function
void gray_scale(string name)
{
    Image image(name);
    for (int i = 0; i < image.width; ++i)
    {
        for (int j = 0; j < image.height; ++j)
        {
            // Initialize average
            unsigned short int avg = 0;
            // get pixel values
            for (int k = 0; k < 3; ++k)
            {
                avg += image(i, j, k);
            }
            // Calculate average
            avg /= 3;
            // Set all channels (RGB) to the average value
            for (int k = 0; k < 3; ++k)
            {
                image(i, j, k) = avg;
            }
        }
    }
    // Get the Extenion of the image
    string tmp = "tmp" + name.substr(name[name.length()-4] == '.' ? name.length()-4 : name.length()-5);
    pathTmp = QString::fromStdString(tmp);
    image.saveImage(tmp);
}
// Appling Oil Painting Effect
void oilPaintingEffect(string name)
{
    // I set it as a constant for the purpose of testing the code
    // Number of intensity levels for binning pixel intensities
    const int INTENSITY_LEVELS = 20;
    // control the level of detail in the oil painting effect
    const int radius = 5;

    Image img(name);
    Image outputImg(img.width, img.height);
    for (int x = 0; x < img.width; x++)
    {
        for (int y = 0; y < img.height; y++)
        {
            // arrays to store counts and averages of RGB values for each intensity level
            int intensityCount[INTENSITY_LEVELS] = {0};
            int averageR[INTENSITY_LEVELS] = {0};
            int averageG[INTENSITY_LEVELS] = {0};
            int averageB[INTENSITY_LEVELS] = {0};
            int curMax = 0;
            int maxIndex = 0;
            // Iterate over neighboring pixels within the radius
            // To Ensure to be in the Boundry
            for (int i = max(0, x - radius); i <= min(img.width - 1, x + radius); i++)
            {
                for (int j = max(0, y - radius); j <= min(img.height - 1, y + radius); j++)
                {
                    // Calculate intensity and update counters and averages
                    int r = img(i, j, 0);
                    int g = img(i, j, 1);
                    int b = img(i, j, 2);
                    int curIntensity = int((r + g + b) / 3.0 * INTENSITY_LEVELS / 255.0);
                    intensityCount[curIntensity]++;
                    averageR[curIntensity] += r;
                    averageG[curIntensity] += g;
                    averageB[curIntensity] += b;
                }
            }
            // Find the most frequent intensity level
            for (int i = 0; i < INTENSITY_LEVELS; ++i)
            {
                if (intensityCount[i] > curMax)
                {
                    curMax = intensityCount[i];
                    maxIndex = i;
                }
            }
            // Calculate final RGB values based on the most frequent intensity level
            int finalR = averageR[maxIndex] / curMax;
            int finalG = averageG[maxIndex] / curMax;
            int finalB = averageB[maxIndex] / curMax;
            outputImg.setPixel(x, y, 0, finalR);
            outputImg.setPixel(x, y, 1, finalG);
            outputImg.setPixel(x, y, 2, finalB);
        }
    }
    string tmp = "tmp" + name.substr(name[name.length()-4] == '.' ? name.length()-4 : name.length()-5);
    pathTmp = QString::fromStdString(tmp);
    outputImg.saveImage(tmp);
}
// InfraRed Effect
void infraRed(string name)
{
    Image image(name);
    Image outputImage(image.width, image.height);
    for (int i = 0; i < image.width; ++i)
    {
        for (int j = 0; j < image.height; ++j)
        {
            outputImage.setPixel(i, j, 0, 230);
            for (int k = 1; k < 3; ++k)
            {
                outputImage.setPixel(i, j, k, 255 - image(i, j, k));
            }
        }
    }
    string tmp = "tmp" + name.substr(name[name.length()-4] == '.' ? name.length()-4 : name.length()-5);
    pathTmp = QString::fromStdString(tmp);
    outputImage.saveImage(tmp);
}
// Black And White Function
Image blackWhite(string name)
{
    Image img(name);
    // Loop on every Pixel and change their color
    for (int i = 0; i < img.width; i++)
    {
        for (int j = 0; j < img.height; j++)
        {
            unsigned int avg = 0;
            for (int k = 0; k < img.channels; k++)
            {
                avg += img(i, j, k);
            }
            // Calculate the average of All RGB Channels
            avg /= 3;
            // if the Average value brighter
            if (avg >= 128)
            {
                // Set all RGB Channels to the white
                img.setPixel(i, j, 0, 255);
                img.setPixel(i, j, 1, 255);
                img.setPixel(i, j, 2, 255);
            }
            else
            {
                // Set all RGB Channels to the Black
                img.setPixel(i, j, 0, 0);
                img.setPixel(i, j, 1, 0);
                img.setPixel(i, j, 2, 0);
            }
        }
    }
    string tmp = "tmp" + name.substr(name[name.length()-4] == '.' ? name.length()-4 : name.length()-5);
    pathTmp = QString::fromStdString(tmp);
    img.saveImage(tmp);
    return img;
}
// Invert Image color
void invert_image_color(string name)
{
    Image image(name);
    // Loop for pixel place
    for (int i = 0; i < image.width; ++i)
    {
        for (int j = 0; j < image.height; ++j)
        {
            // Loop for channel
            for (int k = 0; k < 3; ++k)
            {
                image.setPixel(i, j, k, 255 - image(i, j, k));
            }
        }
    }
    string tmp = "tmp" + name.substr(name[name.length()-4] == '.' ? name.length()-4 : name.length()-5);
    pathTmp = QString::fromStdString(tmp);
    image.saveImage(tmp);
}

void tv_effect(string name) {
    Image image(name);
    // Function to simulate bright and dark lines in tv (CRT)
    // it's recommended to see this function on a graphing program
    auto function = [](double x, const double c = 0.9, const int maximum = 1){ while (x > maximum) {x--;} return exp( 0.5 * (0.5 - x) * (x - 0.5) / (c * c));};
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            // Take a random integer
            int x = rand() % 31;
            for (int k = 0; k < 3; ++k) {
                // if row index is even, subtracts the random variable
                // and if it is odd, adds the random number
                if (j % 2) {
                    if (image.getPixel(i, j, k) + x > 255) {
                        image(i, j, k) = 255;
                    } else {
                        image(i, j, k) += x;
                    }
                } else {
                    if (image.getPixel(i, j, k) - x < 0) {
                        image(i, j, k) = 0;
                    } else {
                        image(i, j, k) -= x;
                    }
                }
                // apply Function
                image(i, j, k) = int(image(i, j, k) * function(0.2 * j));
            }
        }
    }
    string tmp = "tmp" + name.substr(name[name.length()-4] == '.' ? name.length()-4 : name.length()-5);
    pathTmp = QString::fromStdString(tmp);
    image.saveImage(tmp);
}
// Extra 1
void hue(string name, float hue_shift) {
    Image image(name);
    // limit shift from 0 to 360
    while (hue_shift > 360) {
        hue_shift -= 361;
    }
    while (hue_shift < 0) {
        hue_shift += 361;
    }
    if (hue_shift == 0){
        string tmp = "tmp" + name.substr(name[name.length()-4] == '.' ? name.length()-4 : name.length()-5);
        pathTmp = QString::fromStdString(tmp);
        image.saveImage(tmp);
    } else {
        Image shifted_image(image.width, image.height);
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                // RGB to HSV
                float r_ratio = (float) image(i, j, 0) / 255.0f, g_ratio = (float) image(i, j, 1) / 255.0f, b_ratio = (float) image(i, j, 2) / 255.0f;
                // Calculate (V)alue
                float V = max(max(r_ratio, g_ratio), b_ratio);
                float difference = V - min(min(r_ratio, g_ratio), b_ratio), H = 60, S = 0;
                // Calculate (H)ue
                if (difference == 0) {
                    H = 0;
                } else if (V == r_ratio) {
                    H *= fmod((g_ratio - b_ratio) / difference, 6.0f);
                } else if (V == g_ratio) {
                    H *= (b_ratio - r_ratio) / difference + 2;
                } else {
                    H *= (r_ratio - g_ratio) / difference + 4;
                }
                // Calculate (S)aturation
                if (V != 0) {
                    S = difference / V;
                }

                // Hue after shift
                if (H + hue_shift > 360) {
                    H = H + hue_shift - 361;
                } else {
                    H += hue_shift;
                }

                // HSV to RGB
                float C = V * S, M = V - C, X = (float) (C * (1 - abs(fmod(H / 60, 2) - 1)));
                if (H < 60) {
                    r_ratio = C;
                    g_ratio = X;
                    b_ratio = 0;
                } else if (H < 120) {
                    r_ratio = X;
                    g_ratio = C;
                    b_ratio = 0;
                } else if (H < 180) {
                    r_ratio = 0;
                    g_ratio = C;
                    b_ratio = X;
                } else if (H < 240) {
                    r_ratio = 0;
                    g_ratio = X;
                    b_ratio = C;
                } else if (H < 300) {
                    r_ratio = X;
                    g_ratio = 0;
                    b_ratio = C;
                } else {
                    r_ratio = C;
                    g_ratio = 0;
                    b_ratio = X;
                }
                int new_R = int ((r_ratio + M) * 255), new_G = int ((g_ratio + M) * 255), new_B = int ((b_ratio + M) * 255);
                // Set new RGB
                shifted_image.setPixel(i, j, 0, new_R);
                shifted_image.setPixel(i, j, 1, new_G);
                shifted_image.setPixel(i, j, 2, new_B);
            }
        }
        string tmp = "tmp" + name.substr(name[name.length()-4] == '.' ? name.length()-4 : name.length()-5);
        pathTmp = QString::fromStdString(tmp);
        shifted_image.saveImage(tmp);
    }
}

// Extra 2
void pixelate(string name, int intensity = 17) {
    Image image(name);
    if (intensity < 1) {
        intensity = 1;
    }
    if (intensity == 1) {
        string tmp = "tmp" + name.substr(name[name.length()-4] == '.' ? name.length()-4 : name.length()-5);
        pathTmp = QString::fromStdString(tmp);
        image.saveImage(tmp);
    }
    int new_row = image.width / intensity, new_column = image.height / intensity;
    Image pixelated(new_row, new_column);
    for (int k = 0; k < 3; ++k) {
        // Create 2d Pointer instead of an array because of large size
        // The (+1) is for the line of Zeros
        unsigned long long** prefix_sum = new unsigned long long *[image.width + 1];
        for (int i = 0; i < image.width + 1; ++i) {
            prefix_sum[i] = new unsigned long long [image.height + 1];
        }
        // Fill upper and left edges with 0
        for (int i = 0; i < image.width + 1; ++i) {
            prefix_sum[i][0] = 0;
        }
        for (int j = 0; j < image.height + 1; ++j) {
            prefix_sum[0][j] = 0;
        }
        // Fill inside
        for (int i = 1; i < image.width + 1; ++i) {
            for (int j = 1; j < image.height + 1; ++j) {
                prefix_sum[i][j] = prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1] + prefix_sum[i - 1][j] +
                                   image(i - 1, j - 1, k);
            }
        }
        // Assign pixelated
        for (int i = 0; i < new_row; ++i) {
            for (int j = 0; j < new_column; ++j) {
                pixelated(i, j, k) = (prefix_sum[(i+1) * intensity][(j+1) * intensity]
                                      + prefix_sum[i * intensity][j * intensity]
                                      - prefix_sum[i * intensity][(j+1) * intensity]
                                      - prefix_sum[(i+1) * intensity][j * intensity]) / (intensity * intensity);
            }
        }
        // Delete Pointer
        for (int i = 0; i < new_row; ++i) {
            delete[] prefix_sum[i];
        }
        delete[] prefix_sum;
    }
    string tmp = "tmp" + name.substr(name[name.length()-4] == '.' ? name.length()-4 : name.length()-5);
    pathTmp = QString::fromStdString(tmp);
    pixelated.saveImage(tmp);
}

void Edge_detction(string name) {
    Image image;
    image = blackWhite(name);
    Image Final(image.width, image.height);

    //sobel matrix for X_axis and Y_axis
    int matX[3][3] = { {-1 , 0 , 1} , {2 , 0 , -2} , {-1 , 0 , 1} };
    int matY[3][3] = { {1 , 2 , 1} , {0 , 0 , 0} , {-1 , -2 , -1} };

    for (int i = 1; i < image.height - 1; i++)
    {
        for (int j = 1; j < image.width - 1; j++)
        {
            long long sumX = 0;
            long long sumY = 0;
            for (int k = -1; k <= 1; k++)
            {
                for (int l = -1; l <= 1; l++)
                {
                    //sobel gradient X and Y
                    sumX += image(j + l, i + k, 0) * matX[k + 1][l + 1];
                    sumY += image(j + l, i + k, 0) * matY[k + 1][l + 1];
                }
            }
            //gradient magnitude
            long mag = sqrt(sumX * sumX + sumY * sumY);
            Final(j, i, 0) = (mag > 128) ? 0 : 255;
            Final(j, i, 1) = Final(j, i, 0);
            Final(j, i, 2) = Final(j, i, 0);
        }
    }
    string tmp = "tmp" + name.substr(name[name.length()-4] == '.' ? name.length()-4 : name.length()-5);
    pathTmp = QString::fromStdString(tmp);
    Final.saveImage(tmp);
}

void Purble(string name) {
    Image image(name);
    Image purble_image(image.width, image.height);
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            int red = image(i, j, 0) * 1.2;
            int blue = image(i, j, 2) * 1.2;
            int green = image(i, j, 1) * 0.8;
            if (red > 255)
            {
                red = 255;
            }
            if (blue > 255)
            {
                blue = 255;
            }
            purble_image(i, j, 0) = red;
            purble_image(i, j, 2) = blue;
            purble_image(i, j, 1) = green;
        }
    }
    string tmp = "tmp" + name.substr(name[name.length()-4] == '.' ? name.length()-4 : name.length()-5);
    pathTmp = QString::fromStdString(tmp);
    purble_image.saveImage(tmp);
}

void Sunlight(string name) {
    Image image(name);
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                int brightness = image(i, j, k) * 0.8;
                image(i, j, k) = brightness;
            }
        }
    }

    for (int i = 0; i < image.width; i++)
    {
        for (int j = 0; j < image.height; j++)
        {
            int red = image(i, j, 0) * 1.5;
            int green = image(i, j, 1) * 1.4;
            int blue = image(i, j, 2) * 1;
            if (blue > 255)
            {
                blue = 255;
            }
            if (green > 255)
            {
                green = 255;
            }
            if (red > 255)
            {
                red = 255;
            }
            image(i, j, 0) = red;
            image(i, j, 1) = green;
            image(i, j, 2) = blue;
        }
    }
    string tmp = "tmp" + name.substr(name[name.length()-4] == '.' ? name.length()-4 : name.length()-5);
    pathTmp = QString::fromStdString(tmp);
    image.saveImage(tmp);
}

void blur_image(string name, int blur_intensity) {
    Image image(name);
    Image blurred(image.width, image.height);
    // int blur_intensity = 21;
    // Make sure intensity is odd
    if (blur_intensity % 2 == 0) {
        blur_intensity -= 1;
    }
    if (blur_intensity == 1) {
        string tmp = "tmp" + name.substr(name[name.length()-4] == '.' ? name.length()-4 : name.length()-5);
        pathTmp = QString::fromStdString(tmp);
        image.saveImage(tmp);
    }
    // Add extra edges, so it works on all (will be removed later)
    int border_length = blur_intensity / 2;
    int new_row = image.width + blur_intensity, new_column = image.height + blur_intensity;
    for (int k = 0; k < 3; ++k) {
        // Create 2d Pointer instead of an array because of large size
        unsigned long long** prefix_sum = new unsigned long long *[new_row];
        for (int i = 0; i < new_row; ++i) {
            prefix_sum[i] = new unsigned long long [new_column];
        }
        // Fill the upper and left edges
        for (int i = 0; i < new_row; ++i) {
            prefix_sum[i][0] = 0;
        }
        for (int j = 0; j < new_column; ++j) {
            prefix_sum[0][j] = 0;
        }
        // Fill the upper left block
        for (int i = 1; i <= border_length; ++i) {
            for (int j = 1; j <= border_length; ++j) {
                prefix_sum[i][j] = prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1] + image(0, 0 , k) + prefix_sum[i - 1][j];
            }
        }
        // Fill the upper and left edges
        for (int i = 1; i <= border_length; ++i) {
            for (int j = border_length + 1; j < new_column - border_length; ++j) {
                prefix_sum[i][j] = prefix_sum[i - 1][j] - prefix_sum[i - 1][j - 1] + prefix_sum[i][j - 1] +
                                   image(0, j - border_length - 1, k);
            }
        }
        for (int i = border_length + 1; i < new_row - border_length; ++i) {
            for (int j = 1; j <= border_length; ++j) {
                prefix_sum[i][j] = prefix_sum[i - 1][j] - prefix_sum[i - 1][j - 1] + prefix_sum[i][j - 1] +
                                   image(i - border_length - 1, 0, k);
            }
        }
        // Fill the upper right block
        for (int i = 1; i <= border_length; ++i) {
            for (int j = new_column - border_length; j < new_column; ++j) {
                prefix_sum[i][j] =
                    prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1] + prefix_sum[i - 1][j] + image(0, image.height - 1, k);
            }
        }
        // Fill the down left block
        for (int i = new_row - border_length; i < new_row; ++i) {
            for (int j = 1; j <= border_length; ++j) {
                prefix_sum[i][j] =
                    prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1] + prefix_sum[i - 1][j] + image(image.width - 1, 0, k);
            }
        }
        // Fill inside
        for (int i = border_length + 1; i < new_row - border_length; ++i) {
            for (int j = border_length + 1; j < new_column - border_length; ++j) {
                prefix_sum[i][j] = prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1] + prefix_sum[i - 1][j] +
                                   image(i - border_length - 1, j - border_length - 1, k);
            }
        }
        // Fill the right edge
        for (int i = border_length + 1; i < new_row - border_length; ++i) {
            for (int j = new_column - border_length; j < new_column; ++j) {
                prefix_sum[i][j] = prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1] + prefix_sum[i - 1][j] +
                                   image(i - border_length - 1, 0, k);
            }
        }
        // Fill the downside
        for (int i = new_row - border_length; i < new_row; ++i) {
            for (int j = border_length + 1; j < new_column - border_length; ++j) {
                prefix_sum[i][j] = prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1] + prefix_sum[i - 1][j] +
                                   image(image.width - 1, j - border_length - 1, k);
            }
        }
        // Fill the down right block
        for (int i = new_row - border_length; i < new_row; ++i) {
            for (int j = new_column - border_length; j < new_column; ++j) {
                prefix_sum[i][j] = prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1] + prefix_sum[i - 1][j] +
                                   image(image.width - 1, image.height - 1, k);
            }
        }
        // Assign blurred
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                blurred(i, j, k) = int(
                    (prefix_sum[blur_intensity + i][j + blur_intensity] - prefix_sum[blur_intensity + i][j] -
                     prefix_sum[i][blur_intensity + j] + prefix_sum[i][j]) / (blur_intensity * blur_intensity));
            }
        }
        // Delete Pointer
        for (int i = 0; i < new_row; ++i) {
            delete[] prefix_sum[i];
        }
        delete[] prefix_sum;
    }
    string tmp = "tmp" + name.substr(name[name.length()-4] == '.' ? name.length()-4 : name.length()-5);
    pathTmp = QString::fromStdString(tmp);
    blurred.saveImage(tmp);
}

void rotate_image(string name)
{
    Image old_image(name);
    Image new_image(old_image.width, old_image.height);

    // Fix dimensions when rotated
    new_image.height = old_image.width;
    new_image.width = old_image.height;
    for (int i = 0; i < old_image.width; ++i)
    {
        for (int j = 0; j < old_image.height; ++j)
        {
            new_image(old_image.height - 1 - j, i, 0) = old_image(i, j, 0);
            new_image(old_image.height - 1 - j, i, 1) = old_image(i, j, 1);
            new_image(old_image.height - 1 - j, i, 2) = old_image(i, j, 2);
        }
    }
    string tmp = "tmp" + name.substr(name[name.length()-4] == '.' ? name.length()-4 : name.length()-5);
    pathTmp = QString::fromStdString(tmp);
    new_image.saveImage(tmp);
}

void flipImage(string name, int opt)
{
    Image img(name);
    Image flippedImage(img.width, img.height);
    for (int i = 0; i < img.width; i++)
    {
        for (int j = 0; j < img.height; j++)
        {
            for (int k = 0; k < img.channels; k++)
            {
                if (opt == 1) // Flip the image Horizontally
                    flippedImage(i, j, k) = img(img.width - i - 1, j, k);
                else if (opt == 2) // Flip the image Vertically
                    flippedImage(i, j, k) = img(i, img.height - j - 1, k);
            }
        }
    }
    string tmp = "tmp" + name.substr(name[name.length()-4] == '.' ? name.length()-4 : name.length()-5);
    pathTmp = QString::fromStdString(tmp);
    flippedImage.saveImage(tmp);
}

// skew the image by the given angle
// angle > -90 and angle < 90
void skew(string name , int skew_degree) {
    Image image(name);
    // Take angle from user
    if (skew_degree < 0) {
        int start[image.height];
        for (int i = 0; i < image.height; ++i) {
            start[i] = int (i / tan((90 + skew_degree) * PI / 180));
        }
        Image skewed(image.width + start[image.height - 1], image.height);
        for (int i = 0; i < skewed.width; ++i) {
            for (int j = 0; j < skewed.height; ++j) {
                if (start[j] > i) {
                    for (int k = 0; k < 3; ++k) {
                        skewed(i, j, k) = 255;
                    }
                } else if (i > image.width + start[j]) {
                    for (int k = 0; k < 3; ++k) {
                        skewed(i, j, k) = 255;
                    }
                } else {
                    for (int k = 0; k < 3; ++k) {
                        skewed(i, j, k) = image(i - start[j], j, k);
                    }
                }
            }
        }
        string tmp = "tmp" + name.substr(name[name.length()-4] == '.' ? name.length()-4 : name.length()-5);
        pathTmp = QString::fromStdString(tmp);
        skewed.saveImage(tmp);
    } else if (skew_degree > 0) {
        int start[image.height];
        for (int i = 0; i < image.height; ++i) {
            start[i] = int (i / tan((90 - skew_degree) * PI / 180));
        } Image skewed(image.width + start[image.height - 1], image.height);
        for (int i = 0; i < skewed.width; ++i) {
            for (int j = 0; j < skewed.height; ++j) {
                if (start[image.height - j - 1] > i) {
                    for (int k = 0; k < 3; ++k) {
                        skewed(i, j, k) = 255;
                    }
                } else if (i > image.width + start[image.height - j - 1]) {
                    for (int k = 0; k < 3; ++k) {
                        skewed(i, j, k) = 255;
                    }
                } else {
                    for (int k = 0; k < 3; ++k) {
                        skewed(i, j, k) = image(i - start[image.height - j - 1], j, k);
                    }
                }
            }
        }
        string tmp = "tmp" + name.substr(name[name.length()-4] == '.' ? name.length()-4 : name.length()-5);
        pathTmp = QString::fromStdString(tmp);
        skewed.saveImage(tmp);
    } else {
        string tmp = "tmp" + name.substr(name[name.length()-4] == '.' ? name.length()-4 : name.length()-5);
        pathTmp = QString::fromStdString(tmp);
        image.saveImage(tmp);
    }
}

// Resize the Image
Image resize_image(string name, int newWidth, int newHeight)
{
    Image img(name);
    // Make Image according to New Width and height
    Image resizedImage(newWidth, newHeight);
    for (int i = 0; i < newWidth; i++)
    {
        for (int j = 0; j < newHeight; j++)
        {
            // Copy pixel from original image to resized image
            for (int k = 0; k < img.channels; k++)
            {
                // Apply Nearest Neighbor Method
                int oldX = round(i * img.width / newWidth);
                int oldY = round(j * img.height / newHeight);
                resizedImage(i, j, k) = img(oldX, oldY, k);
            }
        }
    }
    string tmp = "tmp" + name.substr(name[name.length()-4] == '.' ? name.length()-4 : name.length()-5);
    pathTmp = QString::fromStdString(tmp);
    resizedImage.saveImage(tmp);
    return resizedImage;
}

// Crop Images //
Image cropImage(string name,int X, int Y,int W, int H)
{
    Image img(name);
    // To Store the Cropped Image in it
    Image croppedImage(W, H);
    for (int i = 0; i < W; i++)
    {
        for (int j = 0; j < H; j++)
        {
            for (int k = 0; k < img.channels; k++)
            {
                croppedImage(i, j, k) = img(i + Y, j + X, k);
            }
        }
    }
    string tmp = "tmp" + name.substr(name[name.length()-4] == '.' ? name.length()-4 : name.length()-5);
    pathTmp = QString::fromStdString(tmp);
    croppedImage.saveImage(tmp);
    return croppedImage;
}

// Merge //
void merge(string filename1,string filename2, string answer = "1")
{
    Image image1(filename1),image2(filename2);
    if (answer == "1")
    {
        int newW = max(image1.width, image2.width);
        int newH = max(image1.height, image2.height);
        // use the function of resize on both image1 and image2
        image1 = resize_image(filename1, newW, newH);
        image2 = resize_image(filename2, newW, newH);
    }
    else if(answer == "2")
    {
        int newW = min(image1.width, image2.width);
        int newH = min(image1.height, image2.height);
        // use the function of resize on both image1 and image2
        image1 = resize_image(filename1, newW, newH);
        image2 = resize_image(filename2, newW, newH);
    }
    else
    {
        int newW = min(image1.width, image2.width);
        int newH = min(image1.height, image2.height);
        image1 = cropImage(filename1, 0, 0, newW, newH);
        image2 = cropImage(filename2, 0, 0, newW, newH);
    }

    for (int i = 0; i < image2.width; i++)
    {
        for (int j = 0; j < image2.height; j++)
        {
            image2(i, j, 0) = (image1(i, j, 0) + image2(i, j, 0)) / 2;
            image2(i, j, 1) = (image1(i, j, 1) + image2(i, j, 1)) / 2;
            image2(i, j, 2) = (image1(i, j, 2) + image2(i, j, 2)) / 2;
        }
    }
    string tmp = "tmp" + filename1.substr(filename1[filename1.length()-4] == '.' ? filename1.length()-4 : filename1.length()-5);
    pathTmp = QString::fromStdString(tmp);
    image2.saveImage(tmp);
}

// Frame //
// Add frame around the image
void add_frame(string name, int border_size, const int color[3]){
    const Image& old_image(name);
    // Automatic border size
    if (border_size == 0) {
        if (old_image.height > old_image.width) {
            border_size = int (0.1618 * old_image.width * 0.25);
        } else {
            border_size = int (0.1618 * old_image.height * 0.25);
        }
    }
    // Border size (frame size)
    // Normal Frame
    Image image(old_image.width + border_size * 2, old_image.height + border_size * 2);
    // For the top side
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < border_size; ++j) {
            for (int k = 0; k < 3; ++k) {
                image.setPixel(i, j, k, color[k]);
            }
        }
    }
    // For the left side
    for (int i = 0; i < border_size; ++i) {
        for (int j = border_size; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                image.setPixel(i, j, k, color[k]);
            }
        }
    }
    // For the right side
    for (int i = image.width - border_size; i < image.width; ++i) {
        for (int j = border_size; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                image.setPixel(i, j, k, color[k]);
            }
        }
    }
    // For the bottom side
    for (int i = border_size; i < image.width - border_size; ++i) {
        for (int j = image.height - border_size; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                image.setPixel(i, j, k, color[k]);
            }
        }
    }

    // Fill photo inside frame
    for (int i = border_size; i < image.width - border_size; ++i) {
        for (int j = border_size; j < image.height - border_size; ++j) {
            for (int k = 0; k < 3; ++k) {
                image.setPixel(i, j, k, old_image(i - border_size, j - border_size, k));
            }
        }
    }
    string tmp = "tmp" + name.substr(name[name.length()-4] == '.' ? name.length()-4 : name.length()-5);
    pathTmp = QString::fromStdString(tmp);
    image.saveImage(tmp);
}
// Fancy Frame
void add_frame_fancy(string name, int border_size, const int color[3], const int color2[3]) {
    const Image& old_image(name);
    // Automatic border size
    if (border_size == 0) {
        if (old_image.height > old_image.width) {
            border_size = int (0.1618 * old_image.width * 0.25);
        } else {
            border_size = int (0.1618 * old_image.height * 0.25);
        }
    }
    // Border size (frame size)
    // Normal Frame
    Image image(old_image.width + border_size * 2, old_image.height + border_size * 2);
    // For the top side
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < border_size; ++j) {
            for (int k = 0; k < 3; ++k) {
                image.setPixel(i, j, k, color[k]);
            }
        }
    }
    // For the left side
    for (int i = 0; i < border_size; ++i) {
        for (int j = border_size; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                image.setPixel(i, j, k, color[k]);
            }
        }
    }
    // For the right side
    for (int i = image.width - border_size; i < image.width; ++i) {
        for (int j = border_size; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                image.setPixel(i, j, k, color[k]);
            }
        }
    }
    // For the bottom side
    for (int i = border_size; i < image.width - border_size; ++i) {
        for (int j = image.height - border_size; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                image.setPixel(i, j, k, color[k]);
            }
        }
    }

    // Fill photo inside frame
    for (int i = border_size; i < image.width - border_size; ++i) {
        for (int j = border_size; j < image.height - border_size; ++j) {
            for (int k = 0; k < 3; ++k) {
                image.setPixel(i, j, k, old_image(i - border_size, j - border_size, k));
            }
        }
    }

    // For fancy frame
    int space = border_size / 7, square_end = int (border_size / 2.4167), thickness = border_size / 29;
    // small square up left
    for (int i = space; i <= square_end; ++i) {
        for (int j = space; j <= square_end; ++j) {
            for (int k = 0; k < 3; ++k) {
                image.setPixel(i, j, k, color2[k]);
            }
        }
    }
    // small square down left
    for (int i = space; i <= square_end; ++i) {
        for (int j = image.height - square_end - 1; j < image.height - space; ++j) {
            for (int k = 0; k < 3; ++k) {
                image.setPixel(i, j, k, color2[k]);
            }
        }
    }
    // small square up right
    for (int i = image.width - square_end - 1; i < image.width - space; ++i) {
        for (int j = space; j <= square_end; ++j) {
            for (int k = 0; k < 3; ++k) {
                image.setPixel(i, j, k, color2[k]);
            }
        }
    }
    // small square down right
    for (int i = image.width - square_end - 1; i < image.width - space; ++i) {
        for (int j = image.height - square_end - 1; j < image.height - space; ++j) {
            for (int k = 0; k < 3; ++k) {
                image.setPixel(i, j, k, color2[k]);
            }
        }
    }

    // From square to square

    // thin line up
    for (int i = square_end + 1; i < image.width - (square_end + 1); ++i) {
        for (int j = square_end + 1; j <= square_end + thickness ; ++j) {
            for (int k = 0; k < 3; ++k) {
                image.setPixel(i, j, k, color2[k]);
            }
        }
    }
    // thin line down
    for (int i = square_end + 1; i < image.width - (square_end + thickness); ++i) {
        for (int j = image.height - square_end - thickness - 1; j < image.height - square_end - 1; ++j) {
            for (int k = 0; k < 3; ++k) {
                image.setPixel(i, j, k, color2[k]);
            }
        }
    }
    // thin line left
    for (int i = square_end + 1; i <= square_end + thickness; ++i) {
        for (int j = square_end + 1; j < image.height - square_end - 1; ++j) {
            for (int k = 0; k < 3; ++k) {
                image.setPixel(i, j, k, color2[k]);
            }
        }
    }
    // thin line right
    for (int i = image.width - square_end - thickness - 1; i < image.width - square_end - 1; ++i) {
        for (int j = square_end + 1; j < image.height - square_end - 1; ++j) {
            for (int k = 0; k < 3; ++k) {
                image.setPixel(i, j, k, color2[k]);
            }
        }
    }

    // thin out-line

    // Upper
    for (int i = border_size * 6 / 7; i < image.width - border_size * 6 / 7; ++i) {
        for (int j = border_size * 6 / 7; j < border_size * 6 / 7 + thickness; ++j) {
            for (int k = 0; k < 3; ++k) {
                image.setPixel(i, j, k, color2[k]);
            }
        }
    }
    // Lower
    for (int i = border_size * 6 / 7; i < image.width - border_size * 6 / 7; ++i) {
        for (int j = image.height - border_size * 6 / 7 - thickness; j < image.height - border_size * 6 / 7; ++j) {
            for (int k = 0; k < 3; ++k) {
                image.setPixel(i, j, k, color2[k]);
            }
        }
    }
    // Left
    for (int i = border_size * 6 / 7; i < border_size * 6 / 7 + thickness; ++i) {
        for (int j = border_size * 6 / 7; j < image.height - border_size * 6 / 7; ++j) {
            for (int k = 0; k < 3; ++k) {
                image.setPixel(i, j, k, color2[k]);
            }
        }
    }
    // Right
    for (int i = image.width - (border_size * 6 / 7 + thickness); i < image.width - border_size * 6 / 7; ++i) {
        for (int j = border_size * 6 / 7; j < image.height - border_size * 6 / 7; ++j) {
            for (int k = 0; k < 3; ++k) {
                image.setPixel(i, j, k, color2[k]);
            }
        }
    }

    // Thick frame

    int line_limit = 2 * square_end - space + 2;

    // Middle up
    for (int i = line_limit; i < image.width - line_limit; ++i) {
        for (int j = space; j < space + 2 * thickness; ++j) {
            for (int k = 0; k < 3; ++k) {
                image.setPixel(i, j, k, color2[k]);
            }
        }
    }
    // Corner up left
    // Horizontal
    for (int i = space; i < line_limit + 2 * thickness; ++i) {
        for (int j = line_limit; j < line_limit + 2 * thickness; ++j) {
            for (int k = 0; k < 3; ++k) {
                image.setPixel(i, j, k, color2[k]);
            }
        }
    }
    // Vertical
    for (int i = line_limit; i < line_limit + thickness * 2; ++i) {
        for (int j = space; j < line_limit + 2 * thickness; ++j) {
            for (int k = 0; k < 3; ++k) {
                image.setPixel(i, j, k, color2[k]);
            }
        }
    }
    // Corner up right
    // Horizontal
    for (int i = image.width - line_limit - 2 * thickness; i < image.width - space; ++i) {
        for (int j = line_limit; j < line_limit + 2 * thickness; ++j) {
            for (int k = 0; k < 3; ++k) {
                image.setPixel(i, j, k, color2[k]);
            }
        }
    }
    // Vertical
    for (int i = image.width - line_limit - thickness * 2; i < image.width - line_limit; ++i) {
        for (int j = space; j < line_limit + 2 * thickness; ++j) {
            for (int k = 0; k < 3; ++k) {
                image.setPixel(i, j, k, color2[k]);
            }
        }
    }

    // Left
    for (int i = space; i < space + thickness * 2; ++i) {
        for (int j = line_limit; j < image.height - line_limit; ++j) {
            for (int k = 0; k < 3; ++k) {
                image.setPixel(i, j, k, color2[k]);
            }
        }
    }
    // Right
    for (int i = image.width - space - 2 * thickness; i < image.width - space; ++i) {
        for (int j = line_limit; j < image.height - line_limit; ++j) {
            for (int k = 0; k < 3; ++k) {
                image.setPixel(i, j, k, color2[k]);
            }
        }
    }

    // Corner down left
    // Horizontal
    for (int i = space; i < line_limit + 2 * thickness; ++i) {
        for (int j = image.height - line_limit - 2 * thickness; j < image.height - line_limit; ++j) {
            for (int k = 0; k < 3; ++k) {
                image.setPixel(i, j, k, color2[k]);
            }
        }
    }
    // Vertical
    for (int i = line_limit; i < line_limit + thickness * 2; ++i) {
        for (int j = image.height - line_limit - 2 * thickness; j < image.height - space; ++j) {
            for (int k = 0; k < 3; ++k) {
                image.setPixel(i, j, k, color2[k]);
            }
        }
    }
    // Corner down right()
    // Horizontal
    for (int i = image.width - line_limit - 2 * thickness; i < image.width - space; ++i) {
        for (int j = image.height - line_limit - 2 * thickness; j < image.height - line_limit; ++j) {
            for (int k = 0; k < 3; ++k) {
                image.setPixel(i, j, k, color2[k]);
            }
        }
    }
    // Vertical
    for (int i = image.width - line_limit - 2 * thickness; i < image.width - line_limit; ++i) {
        for (int j = image.height - line_limit - 2 * thickness; j < image.height - space; ++j) {
            for (int k = 0; k < 3; ++k) {
                image.setPixel(i, j, k, color2[k]);
            }
        }
    }

    // Down
    for (int i = line_limit; i < image.width - line_limit; ++i) {
        for (int j = image.height - space - 2 * thickness; j < image.height - space; ++j) {
            for (int k = 0; k < 3; ++k) {
                image.setPixel(i, j, k, color2[k]);
            }
        }
    }
    string tmp = "tmp" + name.substr(name[name.length()-4] == '.' ? name.length()-4 : name.length()-5);
    pathTmp = QString::fromStdString(tmp);
    image.saveImage(tmp);
}

void Brightness(string name,double num) {
    Image image(name);
    Image new_image(image.width, image.height);
    double bright_factor;
    bright_factor = num;

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                int brightness = image(i, j, k) * bright_factor;
                if (brightness > 255)
                {
                    brightness = 255;
                }
                new_image(i, j, k) = brightness;
            }
        }
    }
    string tmp = "tmp" + name.substr(name[name.length()-4] == '.' ? name.length()-4 : name.length()-5);
    pathTmp = QString::fromStdString(tmp);
    new_image.saveImage(tmp);
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //
    // Set cool theme stylesheet
    QString draculaTheme = R"(
    QMainWindow {
        background-color: #282a36; /* Dark background */
        color: #f8f8f2; /* Light text */
    }

    QPushButton {
        background-color: #6272a4; /* Purple button background */
        color: #f8f8f2; /* Light button text */
        border: 2px solid #6272a4; /* Purple border */
        border-radius: 5px; /* Rounded corners */
        padding: 5px 10px; /* Padding */
    }

    QPushButton:hover {
        background-color: #6272a4; /* Purple on hover */
        border-color: #bd93f9; /* Lighter purple border on hover */
    }

    QLabel {
        color: #f8f8f2; /* Light label text */
    }

    QSlider::groove:horizontal {
        border: 1px solid #6272a4; /* Purple groove border */
        height: 10px; /* Groove height */
        background: #44475a; /* Dark purple background */
        margin: 2px 0;
    }

    QSlider::handle:horizontal {
        background: #bd93f9; /* Light purple handle */
        border: 2px solid #bd93f9; /* Light purple border */
        width: 18px; /* Handle width */
        margin: -2px 0; /* Handle margin */
        border-radius: 9px; /* Handle border radius */
    }

    QSlider::handle:horizontal:hover {
        background: #bd93f9; /* Lighter purple handle on hover */
        border-color: #f1fa8c; /* Lighter purple border on hover */
    }
     QDialog {
        background-color: #282a36; /* Dark background */
        color: #f8f8f2; /* Light text */
    }
    /* Style for the QSpinBox */
    QSpinBox {
        background-color: #44475a; /* Dark background */
        color: #f8f8f2; /* Light text */
        border: 2px solid #6272a4; /* Purple border */
        border-radius: 5px; /* Rounded corners */
        padding: 3px; /* Adjust padding as needed */
        min-width: 40px; /* Set a minimum width */
    }




)";

    // Apply the stylesheet to the entire application
    this->setStyleSheet(draculaTheme);
    //
    // Connect signal-slot for the load image button
    connect(ui->btnLoadImg, &QPushButton::clicked, this, &MainWindow::on_btnLoadImg_clicked);
    // Connect signal-slot for the load image button
    connect(ui->btnSaveImg, &QPushButton::clicked, this, &MainWindow::on_btnSaveImg_clicked);
    // Add this line to the constructor to connect the signal-slot for the clear button
    connect(ui->btnClearRslt, &QPushButton::clicked, this, &MainWindow::on_btnClearRslt_clicked);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked);
    // Connect signal-slot for the gray filter button
    connect(ui->btnGray, &QPushButton::clicked, this, &MainWindow::on_btnGray_clicked);
    // Connect signal-slot for the Black and White filter button
    connect(ui->btnBlackWhite, &QPushButton::clicked, this, &MainWindow::on_btnBlackWhite_clicked);
    // Connect signal-slot for the gray filter button
    connect(ui->btnInfraRed, &QPushButton::clicked, this, &MainWindow::on_btnInfraRed_clicked);
    // Connect signal-slot for the oil Paint Effect filter button
    connect(ui->btnOilPnt, &QPushButton::clicked, this, &MainWindow::on_btnOilPnt_clicked);
    // Connect signal-slot for the Invert filter button
    connect(ui->btnInvertClr, &QPushButton::clicked, this, &MainWindow::on_btnInvertClr_clicked);
    // Connect signal-slot for the TV Effect filter button
    connect(ui->btnTV, &QPushButton::clicked, this, &MainWindow::on_btnTV_clicked);
    // Connect signal-slot for the Edge Detection Effect filter button
    connect(ui->btnEdgeDetection, &QPushButton::clicked, this, &MainWindow::on_btnEdgeDetection_clicked);
    // Connect signal-slot for the Hue Effect filter button
    // Hide the Hue intensity slider initially
    ui->hueSlider->hide();
    // Connect the valueChanged signal of the slider to the onHueIntensityChanged slot
    connect(ui->hueSlider, &QSlider::valueChanged, this, &MainWindow::on_hueSlider_actionTriggered);
    // Connect signal-slot for the Hue Effect filter button
    connect(ui->btnHue, &QPushButton::clicked, this, &MainWindow::on_btnHue_clicked);
    // Connect signal-slot for the Purble Effect filter button
    connect(ui->btnPurble, &QPushButton::clicked, this, &MainWindow::on_btnPurble_clicked);
    // Connect signal-slot for the Sunlight Effect filter button
    connect(ui->btnSunlight, &QPushButton::clicked, this, &MainWindow::on_btnSunlight_clicked);
    // Connect signal-slot for the Pixelate Effect filter button
    connect(ui->btnPixelate, &QPushButton::clicked, this, &MainWindow::on_btnPixelate_clicked);
    // BLUR //
    // Hide the blur intensity slider initially
    ui->blurSlider->hide();
    // Connect the valueChanged signal of the slider to the onBlurIntensityChanged slot
    connect(ui->blurSlider, &QSlider::valueChanged, this, &MainWindow::on_blurSlider_actionTriggered);
    // Connect signal-slot for the Blur Effect filter button
    connect(ui->btnBlur, &QPushButton::clicked, this, &MainWindow::on_btnBlur_clicked);
    // Rotate //
    connect(ui->btnRotat, &QPushButton::clicked, this, &MainWindow::on_btnRotat_clicked);
    // Flip Hor//
    connect(ui->btnFlipH, &QPushButton::clicked, this, &MainWindow::on_btnFlipH_clicked);
    // Flip Ver//
    connect(ui->btnFlipV, &QPushButton::clicked, this, &MainWindow::on_btnFlipV_clicked);
    // Connect signal-slot for the resize button
    connect(ui->btnResize, &QPushButton::clicked, this, &MainWindow::on_btnResize_clicked);
    // Skew//
    // Hide the Skew  slider initially
    ui->skewSlider->hide();
    // Connect the valueChanged signal of the slider to the onBlurIntensityChanged slot
    connect(ui->skewSlider, &QSlider::valueChanged, this, &MainWindow::on_skewSlider_actionTriggered);
    // Connect signal-slot for the Skew button
    connect(ui->btnSkew, &QPushButton::clicked, this, &MainWindow::on_btnSkew_clicked);
    // MERGE //
    connect(ui->btnMerge, &QPushButton::clicked, this, &MainWindow::on_btnMerge_clicked);

    // Connect signal-slot for the normal frame button
    connect(ui->btnNormalFrame, &QPushButton::clicked, this, &MainWindow::on_btnNormalFrame_clicked);
    connect(ui->btnFancyFrame, &QPushButton::clicked, this, &MainWindow::on_btnFancyFrame_clicked);    // Connect signal-slot for the fancy frame button

    // BLUR //
    // Hide the blur intensity slider initially
    ui->brightnessSlider->hide();
    // In the constructor of MainWindow
    ui->brightnessSlider->setRange(0, 100); // Set the range to accommodate decimals
    ui->brightnessSlider->setSingleStep(1); // Set the step size
    ui->brightnessSlider->setPageStep(10); // Set the page step size
    // Connect the valueChanged signal of the slider to the onBlurIntensityChanged slot
    // Connect the valueChanged signal of the slider to the on_brightnessSlider_actionTriggered slot
    connect(ui->brightnessSlider, QOverload<int>::of(&QSlider::valueChanged), [=](int value) {
        on_brightnessSlider_actionTriggered(static_cast<double>(value));
    });
    // Connect signal-slot for the Blur Effect filter button
    connect(ui->btnBrightness, &QPushButton::clicked, this, &MainWindow::on_btnBrightness_clicked);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnLoadImg_clicked()
{
    // Disconnect the signal-slot connection to prevent multiple dialog openings
    disconnect(ui->btnLoadImg, &QPushButton::clicked, this, &MainWindow::on_btnLoadImg_clicked);

    QString filename = QFileDialog::getOpenFileName(this, tr("Open Image"), "", tr("Image Files (*.png *.jpg *.bmp)"));
    if (!filename.isEmpty()) {
        // Store the path of the loaded image
        loadedImagePath = filename;
        originalPath = filename;
        QPixmap pixmap(filename);
        if (!pixmap.isNull()) {
            // Scale the pixmap to exactly fit the size of the insertImg box without maintaining aspect ratio and center it
            ui->insertImg->setPixmap(pixmap.scaled(ui->insertImg->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
            ui->insertImg->setAlignment(Qt::AlignCenter); // Center the pixmap within the label
            // ui->insertImg->setPixmap(pixmap.scaled(ui->insertImg->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        } else {
            qDebug() << "Error: Unable to load image";
        }
    }
    else {
        qDebug() << "Error: No image selected";
    }
}

void MainWindow::on_btnSaveImg_clicked()
{
    // Disconnect the signal-slot connection to prevent multiple dialog openings
    disconnect(ui->btnSaveImg, &QPushButton::clicked, this, &MainWindow::on_btnSaveImg_clicked);
    if (!ui->resultImg->pixmap().isNull()) {
        QString saveFileName = QFileDialog::getSaveFileName(this, tr("Save Image"), "", tr("Image Files (*.png *.jpg *.bmp)"));
        if (!saveFileName.isEmpty()) {
            QPixmap pixmap = ui->resultImg->pixmap();

            // Resize the pixmap with the selected dimensions
            if (resizedWidth > 0 && resizedHeight > 0) {
                pixmap = pixmap.scaled(resizedWidth, resizedHeight, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
            }
            else
            {
                Image img(pathTmp.toStdString());
                int w = img.width;
                int h = img.height;
                pixmap = pixmap.scaled(w, h);
            }

            if (!pixmap.save(saveFileName)) {
                qDebug() << "Error: Unable to save image";
            }
        } else {
            qDebug() << "Error: No filename provided";
        }
    } else {
        qDebug() << "Error: No image to save";
    }
}

void MainWindow::on_btnClearRslt_clicked()
{
    ui->skewSlider->hide();
    ui->brightnessSlider->hide();
    ui->hueSlider->hide();
    ui->blurSlider->hide();
    // Clear the pixmap from the resultImg label
    ui->resultImg->clear();
    loadedImagePath = originalPath;
}

void MainWindow::on_pushButton_clicked()
{
    pathTmp = originalPath;
    loadedImagePath = originalPath;
    if (!originalPath.isEmpty()) {
        // Store the path of the loaded image
        loadedImagePath = originalPath;
        originalPath = originalPath;
        QPixmap pixmap(originalPath);
        if (!pixmap.isNull()) {
            // Scale the pixmap to exactly fit the size of the insertImg box without maintaining aspect ratio and center it
            ui->resultImg->setPixmap(pixmap.scaled(ui->resultImg->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
            ui->resultImg->setAlignment(Qt::AlignCenter); // Center the pixmap within the label
            // ui->insertImg->setPixmap(pixmap.scaled(ui->insertImg->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        } else {
            qDebug() << "Error: Unable to load image";
        }
    }
    else {
        qDebug() << "Error: No image selected";
    }
}

void MainWindow::on_btnGray_clicked()
{
    ui->skewSlider->hide();
    ui->brightnessSlider->hide();
    ui->hueSlider->hide();
    ui->blurSlider->hide();
    // Disconnect the signal-slot connection to prevent multiple dialog openings
    disconnect(ui->btnGray, &QPushButton::clicked, this, &MainWindow::on_btnGray_clicked);

    if (!loadedImagePath.isEmpty()) {
        // Convert QString to std::string
        std::string stdFilename = loadedImagePath.toStdString();
        // Call your gray_scale function with the std::string filename
        gray_scale(stdFilename);
        // Display the updated image
        QPixmap pixmap(pathTmp);
        if (!pixmap.isNull()) {
            qInfo() << "SUCCESS";
            ui->resultImg->setPixmap(pixmap.scaled(ui->resultImg->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
            ui->resultImg->setAlignment(Qt::AlignCenter);
            // ui->resultImg->setPixmap(pixmap.scaled(ui->resultImg->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        } else {
            qDebug() << "Error: Unable to load image";
        }
    } else {
        qDebug() << "Error: No image loaded";
    }
}

void MainWindow::on_btnOilPnt_clicked()
{
    ui->skewSlider->hide();
    ui->brightnessSlider->hide();
    ui->hueSlider->hide();
    ui->blurSlider->hide();
    // Disconnect the signal-slot connection to prevent multiple dialog openings
    disconnect(ui->btnOilPnt, &QPushButton::clicked, this, &MainWindow::on_btnOilPnt_clicked);

    if (!loadedImagePath.isEmpty()) {
        // Convert QString to std::string
        std::string stdFilename = loadedImagePath.toStdString();
        // Call your gray_scale function with the std::string filename
        oilPaintingEffect(stdFilename);
        // Display the updated image
        QPixmap pixmap(pathTmp);
        if (!pixmap.isNull()) {
            qInfo() << "SUCCESS";
            ui->resultImg->setPixmap(pixmap.scaled(ui->resultImg->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
            ui->resultImg->setAlignment(Qt::AlignCenter);
            // ui->resultImg->setPixmap(pixmap.scaled(ui->resultImg->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        } else {
            qDebug() << "Error: Unable to load image";
        }
    } else {
        qDebug() << "Error: No image loaded";
    }
}

void MainWindow::on_btnBlackWhite_clicked()
{    ui->skewSlider->hide();
    ui->brightnessSlider->hide();
    ui->hueSlider->hide();
    ui->blurSlider->hide();
    // Disconnect the signal-slot connection to prevent multiple dialog openings
    disconnect(ui->btnBlackWhite, &QPushButton::clicked, this, &MainWindow::on_btnBlackWhite_clicked);

    if (!loadedImagePath.isEmpty()) {
        // Convert QString to std::string
        std::string stdFilename = loadedImagePath.toStdString();
        // Call your gray_scale function with the std::string filename
        blackWhite(stdFilename);
        // Display the updated image
        QPixmap pixmap(pathTmp);
        if (!pixmap.isNull()) {
            qInfo() << "SUCCESS";
            ui->resultImg->setPixmap(pixmap.scaled(ui->resultImg->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
            ui->resultImg->setAlignment(Qt::AlignCenter);
            // ui->resultImg->setPixmap(pixmap.scaled(ui->resultImg->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        } else {
            qDebug() << "Error: Unable to load image";
        }
    } else {
        qDebug() << "Error: No image loaded";
    }
}

void MainWindow::on_btnInvertClr_clicked()
{
    ui->skewSlider->hide();
    ui->brightnessSlider->hide();
    ui->hueSlider->hide();
    ui->blurSlider->hide();
    // Disconnect the signal-slot connection to prevent multiple dialog openings
    disconnect(ui->btnInvertClr, &QPushButton::clicked, this, &MainWindow::on_btnInvertClr_clicked);

    if (!loadedImagePath.isEmpty()) {
        // Convert QString to std::string
        std::string stdFilename = loadedImagePath.toStdString();
        // Call your gray_scale function with the std::string filename
        invert_image_color(stdFilename);
        // Display the updated image
        QPixmap pixmap(pathTmp);
        if (!pixmap.isNull()) {
            qInfo() << "SUCCESS";
            ui->resultImg->setPixmap(pixmap.scaled(ui->resultImg->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
            ui->resultImg->setAlignment(Qt::AlignCenter);
            // ui->resultImg->setPixmap(pixmap.scaled(ui->resultImg->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        } else {
            qDebug() << "Error: Unable to load image";
        }
    } else {
        qDebug() << "Error: No image loaded";
    }
}

void MainWindow::on_btnInfraRed_clicked()
{
    ui->skewSlider->hide();
    ui->brightnessSlider->hide();
    ui->hueSlider->hide();
    ui->blurSlider->hide();
    // Disconnect the signal-slot connection to prevent multiple dialog openings
    disconnect(ui->btnInfraRed, &QPushButton::clicked, this, &MainWindow::on_btnInfraRed_clicked);

    if (!loadedImagePath.isEmpty()) {
        // Convert QString to std::string
        std::string stdFilename = loadedImagePath.toStdString();
        // Call your gray_scale function with the std::string filename
        infraRed(stdFilename);
        // Display the updated image
        QPixmap pixmap(pathTmp);
        if (!pixmap.isNull()) {
            qInfo() << "SUCCESS";
            ui->resultImg->setPixmap(pixmap.scaled(ui->resultImg->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
            ui->resultImg->setAlignment(Qt::AlignCenter);
            // ui->resultImg->setPixmap(pixmap.scaled(ui->resultImg->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        } else {
            qDebug() << "Error: Unable to load image";
        }
    } else {
        qDebug() << "Error: No image loaded";
    }
}

void MainWindow::on_btnSunlight_clicked()
{

    ui->skewSlider->hide();
    ui->brightnessSlider->hide();
    ui->hueSlider->hide();
    ui->blurSlider->hide();
    // Disconnect the signal-slot connection to prevent multiple dialog openings
    disconnect(ui->btnSunlight, &QPushButton::clicked, this, &MainWindow::on_btnSunlight_clicked);

    if (!loadedImagePath.isEmpty()) {
        // Convert QString to std::string
        std::string stdFilename = loadedImagePath.toStdString();
        // Call your gray_scale function with the std::string filename
        Sunlight(stdFilename);
        // Display the updated image
        QPixmap pixmap(pathTmp);
        if (!pixmap.isNull()) {
            qInfo() << "SUCCESS";
            ui->resultImg->setPixmap(pixmap.scaled(ui->resultImg->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
            ui->resultImg->setAlignment(Qt::AlignCenter);
            // ui->resultImg->setPixmap(pixmap.scaled(ui->resultImg->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        } else {
            qDebug() << "Error: Unable to load image";
        }
    } else {
        qDebug() << "Error: No image loaded";
    }
}

void MainWindow::on_btnPurble_clicked()
{
    ui->skewSlider->hide();
    ui->brightnessSlider->hide();
    ui->hueSlider->hide();
    ui->blurSlider->hide();
    // Disconnect the signal-slot connection to prevent multiple dialog openings
    disconnect(ui->btnPurble, &QPushButton::clicked, this, &MainWindow::on_btnPurble_clicked);

    if (!loadedImagePath.isEmpty()) {
        // Convert QString to std::string
        std::string stdFilename = loadedImagePath.toStdString();
        // Call your gray_scale function with the std::string filename
        Purble(stdFilename);
        // Display the updated image
        QPixmap pixmap(pathTmp);
        if (!pixmap.isNull()) {
            qInfo() << "SUCCESS";
            ui->resultImg->setPixmap(pixmap.scaled(ui->resultImg->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
            ui->resultImg->setAlignment(Qt::AlignCenter);
            // ui->resultImg->setPixmap(pixmap.scaled(ui->resultImg->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        } else {
            qDebug() << "Error: Unable to load image";
        }
    } else {
        qDebug() << "Error: No image loaded";
    }
}

void MainWindow::on_btnPixelate_clicked()
{
    ui->skewSlider->hide();
    ui->brightnessSlider->hide();
    ui->hueSlider->hide();
    ui->blurSlider->hide();
    // Disconnect the signal-slot connection to prevent multiple dialog openings
    disconnect(ui->btnPixelate, &QPushButton::clicked, this, &MainWindow::on_btnPixelate_clicked);

    if (!loadedImagePath.isEmpty()) {
        // Convert QString to std::string
        std::string stdFilename = loadedImagePath.toStdString();
        // Call your gray_scale function with the std::string filename
        pixelate(stdFilename);
        // Display the updated image
        QPixmap pixmap(pathTmp);
        if (!pixmap.isNull()) {
            qInfo() << "SUCCESS";
            ui->resultImg->setPixmap(pixmap.scaled(ui->resultImg->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
            ui->resultImg->setAlignment(Qt::AlignCenter);
            // ui->resultImg->setPixmap(pixmap.scaled(ui->resultImg->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        } else {
            qDebug() << "Error: Unable to load image";
        }
    } else {
        qDebug() << "Error: No image loaded";
    }
}

void MainWindow::on_btnEdgeDetection_clicked()
{
    ui->skewSlider->hide();
    ui->brightnessSlider->hide();
    ui->hueSlider->hide();
    ui->blurSlider->hide();
    // Disconnect the signal-slot connection to prevent multiple dialog openings
    disconnect(ui->btnEdgeDetection, &QPushButton::clicked, this, &MainWindow::on_btnEdgeDetection_clicked);

    if (!loadedImagePath.isEmpty()) {
        // Convert QString to std::string
        std::string stdFilename = loadedImagePath.toStdString();
        // Call your gray_scale function with the std::string filename
        Edge_detction(stdFilename);
        // Display the updated image
        QPixmap pixmap(pathTmp);
        if (!pixmap.isNull()) {
            qInfo() << "SUCCESS";
            ui->resultImg->setPixmap(pixmap.scaled(ui->resultImg->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
            ui->resultImg->setAlignment(Qt::AlignCenter);
            // ui->resultImg->setPixmap(pixmap.scaled(ui->resultImg->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        } else {
            qDebug() << "Error: Unable to load image";
        }
    } else {
        qDebug() << "Error: No image loaded";
    }
}

void MainWindow::on_btnTV_clicked()
{
    ui->skewSlider->hide();
    ui->brightnessSlider->hide();
    ui->hueSlider->hide();
    ui->blurSlider->hide();
    // Disconnect the signal-slot connection to prevent multiple dialog openings
    disconnect(ui->btnTV, &QPushButton::clicked, this, &MainWindow::on_btnTV_clicked);

    if (!loadedImagePath.isEmpty()) {
        // Convert QString to std::string
        std::string stdFilename = loadedImagePath.toStdString();
        // Call your gray_scale function with the std::string filename
        tv_effect(stdFilename);
        // Display the updated image
        QPixmap pixmap(pathTmp);
        if (!pixmap.isNull()) {
            qInfo() << "SUCCESS";
            ui->resultImg->setPixmap(pixmap.scaled(ui->resultImg->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
            ui->resultImg->setAlignment(Qt::AlignCenter);
            // ui->resultImg->setPixmap(pixmap.scaled(ui->resultImg->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        } else {
            qDebug() << "Error: Unable to load image";
        }
    } else {
        qDebug() << "Error: No image loaded";
    }
}

//  Blur //
void MainWindow::on_blurSlider_actionTriggered(int action)
{
    // Update blur intensity
    blur_intensity = action;
    // Apply blur effect with the updated intensity
    applyBlurEffect();
}
void MainWindow::on_btnBlur_clicked()
{
    ui->skewSlider->hide();
    ui->brightnessSlider->hide();
    ui->hueSlider->hide();
    // Disconnect the signal-slot connection to prevent multiple dialog openings
    disconnect(ui->btnBlur, &QPushButton::clicked, this, &MainWindow::on_btnBlur_clicked);
    // Show the blur intensity slider
    ui->blurSlider->show();
    // Call the applyBlurEffect function to apply the blur with the initial intensity
    applyBlurEffect();
}
void MainWindow::applyBlurEffect()
{
    // Apply blur effect with the current blur intensity
    if (!loadedImagePath.isEmpty()) {
        // Convert QString to std::string
        std::string stdFilename = loadedImagePath.toStdString();
        // Call your blur_image function with the std::string filename and blur intensity
        qInfo() << blur_intensity;
        blur_image(stdFilename, blur_intensity);
        // Display the updated image
        QPixmap pixmap(pathTmp);
        if (!pixmap.isNull()) {
            qInfo() << "SUCCESS";
            ui->resultImg->setPixmap(pixmap.scaled(ui->resultImg->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
            ui->resultImg->setAlignment(Qt::AlignCenter);
        } else {
            qDebug() << "Error: Unable to load image";
        }
    } else {
        qDebug() << "Error: No image loaded";
    }
}

// Rotat
void MainWindow::on_btnRotat_clicked()
{
    ui->skewSlider->hide();
    ui->brightnessSlider->hide();
    ui->hueSlider->hide();
    ui->blurSlider->hide();
    // Disconnect the signal-slot connection to prevent multiple dialog openings
    disconnect(ui->btnRotat, &QPushButton::clicked, this, &MainWindow::on_btnRotat_clicked);

    if (!loadedImagePath.isEmpty()) {
        // Convert QString to std::string
        std::string stdFilename = loadedImagePath.toStdString();
        // Call your blur_image function with the std::string filename and blur intensity
        rotate_image(stdFilename);
        // Display the updated image
        QPixmap pixmap(pathTmp);
        loadedImagePath = pathTmp;
        if (!pixmap.isNull()) {
            qInfo() << "SUCCESS";
            ui->resultImg->setPixmap(pixmap.scaled(ui->resultImg->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
            ui->resultImg->setAlignment(Qt::AlignCenter);
        } else {
            qDebug() << "Error: Unable to load image";
        }
    } else {
        qDebug() << "Error: No image loaded";
    }
}

// Flip
void MainWindow::on_btnFlipH_clicked()
{
    ui->skewSlider->hide();
    ui->brightnessSlider->hide();
    ui->hueSlider->hide();
    ui->blurSlider->hide();
    // Disconnect the signal-slot connection to prevent multiple dialog openings
    disconnect(ui->btnFlipH, &QPushButton::clicked, this, &MainWindow::on_btnFlipH_clicked);

    if (!loadedImagePath.isEmpty()) {
        // Convert QString to std::string
        std::string stdFilename = loadedImagePath.toStdString();
        flipImage(stdFilename, 1);
        // Display the updated image
        QPixmap pixmap(pathTmp);
        loadedImagePath = pathTmp;
        if (!pixmap.isNull()) {
            qInfo() << "SUCCESS";
            ui->resultImg->setPixmap(pixmap.scaled(ui->resultImg->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
            ui->resultImg->setAlignment(Qt::AlignCenter);
        } else {
            qDebug() << "Error: Unable to load image";
        }
    } else {
        qDebug() << "Error: No image loaded";
    }
}
void MainWindow::on_btnFlipV_clicked()
{
    ui->skewSlider->hide();
    ui->brightnessSlider->hide();
    ui->hueSlider->hide();
    ui->blurSlider->hide();
    // Disconnect the signal-slot connection to prevent multiple dialog openings
    disconnect(ui->btnFlipV, &QPushButton::clicked, this, &MainWindow::on_btnFlipV_clicked);

    if (!loadedImagePath.isEmpty()) {
        // Convert QString to std::string
        std::string stdFilename = loadedImagePath.toStdString();
        flipImage(stdFilename, 2);
        // Display the updated image
        QPixmap pixmap(pathTmp);
        loadedImagePath = pathTmp;
        if (!pixmap.isNull()) {
            qInfo() << "SUCCESS";
            ui->resultImg->setPixmap(pixmap.scaled(ui->resultImg->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
            ui->resultImg->setAlignment(Qt::AlignCenter);
        } else {
            qDebug() << "Error: Unable to load image";
        }
    } else {
        qDebug() << "Error: No image loaded";
    }
}

// Resize
// Define the slot for the resize button click
void MainWindow::on_btnResize_clicked()
{
    ui->brightnessSlider->hide();
    ui->skewSlider->hide();
    // Create and display the ResizeDialog
    ResizeDialog* dialog = new ResizeDialog(this);
    connect(dialog, &ResizeDialog::accepted, this, &MainWindow::onResizeDialogAccepted);
    connect(dialog, &ResizeDialog::rejected, this, &MainWindow::onResizeDialogRejected);
    // Use a lambda to automatically disconnect the signal-slot connections when the dialog is closed
    QObject::connect(dialog, &QDialog::finished, dialog, [dialog, this]() {
        disconnect(dialog, &ResizeDialog::accepted, this, &MainWindow::onResizeDialogAccepted);
        disconnect(dialog, &ResizeDialog::rejected, this, &MainWindow::onResizeDialogRejected);
        dialog->deleteLater(); // Clean up the dialog after it's closed
    });

    dialog->exec();
}
// Define the slot for handling the accepted signal from the resize dialog
void MainWindow::onResizeDialogAccepted()
{
    // Retrieve the dimensions from the resize dialog
    ResizeDialog* dialog = qobject_cast<ResizeDialog*>(sender()); // Get the sender of the signal
    if (dialog) {
        int width = dialog->selectedWidth(); // Retrieve the selected width from the dialog
        int height = dialog->selectedHeight(); // Retrieve the selected height from the dialog

        // Update the member variables with the selected dimensions
        resizedWidth = dialog->selectedWidth(); // Retrieve the selected width from the dialog
        resizedHeight = dialog->selectedHeight(); // Retrieve the selected height from the dialog
        // Disconnect the signal-slot connection to prevent multiple dialog openings
        disconnect(ui->btnResize, &QPushButton::clicked, this, &MainWindow::on_btnResize_clicked);
        // Check if an image is loaded
        if (!loadedImagePath.isEmpty()) {
            // Resize the loaded image with the entered dimensions
            resize_image(loadedImagePath.toStdString(), width, height);

            // Display the resized image in the result box
            QPixmap pixmap(pathTmp);
            loadedImagePath = pathTmp;
            if (!pixmap.isNull()) {
                // Scale the pixmap to fit within the resultImg but maintaining aspect ratio
                QPixmap scaledPixmap = pixmap.scaled(ui->resultImg->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
                ui->resultImg->setPixmap(scaledPixmap);
                ui->resultImg->setAlignment(Qt::AlignCenter);
            } else {
                qDebug() << "Error: Unable to load resized image";
            }
        } else {
            qDebug() << "Error: No image loaded";
        }
    }
}
void MainWindow::onResizeDialogRejected()
{
    // Retrieve the dimensions from the resize dialog
    ResizeDialog* dialog = qobject_cast<ResizeDialog*>(sender()); // Get the sender of the signal
    if (dialog) {
        // Disconnect the signal-slot connection to prevent multiple dialog openings
        disconnect(ui->btnResize, &QPushButton::clicked, this, &MainWindow::on_btnResize_clicked);
    }
}

// Crop
void MainWindow::on_btnCrop_clicked() {
    ui->skewSlider->hide();
    ui->brightnessSlider->hide();
    ui->hueSlider->hide();
    ui->blurSlider->hide();
    // Get the current pixmap dimensions
    int imgWidth = ui->insertImg->pixmap().width();
    int imgHeight = ui->insertImg->pixmap().height();

    // Create an instance of the CropDialog
    CropDialog cropDialog(imgWidth, imgHeight, this);

    // Show the dialog modally
    if (cropDialog.exec() == QDialog::Accepted) {
        // Retrieve crop parameters from the dialog
        int startX = cropDialog.getX();
        int startY = cropDialog.getY();
        int width = cropDialog.getWidth();
        int height = cropDialog.getHeight();
        // Update the member variables with the selected dimensions
        resizedWidth = cropDialog.getWidth(); // Retrieve the selected width from the dialog
        resizedHeight = cropDialog.getHeight(); // Retrieve the selected height from the dialog
        // Perform cropping operation using these parameters
        // Call the appropriate function to update the resultImg QLabel with the cropped image
        ui->blurSlider->hide();
        // Disconnect the signal-slot connection to prevent multiple dialog openings
        disconnect(ui->btnCrop, &QPushButton::clicked, this, &MainWindow::on_btnCrop_clicked);

        // Check if an image is loaded
        if (!loadedImagePath.isEmpty()) {
            // Resize the loaded image with the entered dimensions
            cropImage(loadedImagePath.toStdString(),startX,startY, width, height);

            // Display the resized image in the result box
            QPixmap pixmap(pathTmp);
            loadedImagePath = pathTmp;
            if (!pixmap.isNull()) {
                // Scale the pixmap to fit within the resultImg but maintaining aspect ratio
                QPixmap scaledPixmap = pixmap.scaled(ui->resultImg->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
                ui->resultImg->setPixmap(scaledPixmap);
                ui->resultImg->setAlignment(Qt::AlignCenter);
            } else {
                qDebug() << "Error: Unable to load resized image";
            }
        } else {
            qDebug() << "Error: No image loaded";
        }
    }
}

//  Skew //
void MainWindow::on_skewSlider_actionTriggered(int action)
{
    // Update skew_degree
    skew_degree = action;
    // Apply blur effect with the updated intensity
    applySkew();
}
void MainWindow::on_btnSkew_clicked()
{
    ui->brightnessSlider->hide();
    ui->hueSlider->hide();
    ui->blurSlider->hide();
    // Disconnect the signal-slot connection to prevent multiple dialog openings
    disconnect(ui->btnSkew, &QPushButton::clicked, this, &MainWindow::on_btnSkew_clicked);
    // Show the apply Skew degree slider
    ui->skewSlider->show();
    // Call the applySkew function to apply the blur with the initial intensity
    applySkew();
}
void MainWindow::applySkew()
{
    // Apply blur effect with the current blur intensity
    if (!loadedImagePath.isEmpty()) {
        // Convert QString to std::string
        std::string stdFilename = loadedImagePath.toStdString();
        // Call your blur_image function with the std::string filename and blur intensity
        qInfo() << skew_degree;
        skew(stdFilename, skew_degree);
        // Display the updated image
        QPixmap pixmap(pathTmp);
        loadedImagePath = pathTmp;
        if (!pixmap.isNull()) {
            qInfo() << "SUCCESS";
            ui->resultImg->setPixmap(pixmap.scaled(ui->resultImg->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
            ui->resultImg->setAlignment(Qt::AlignCenter);
        } else {
            qDebug() << "Error: Unable to load image";
        }
    } else {
        qDebug() << "Error: No image loaded";
    }
}

// Merge //
// Implement the merge button slot
void MainWindow::on_btnMerge_clicked() {
    ui->skewSlider->hide();
    ui->brightnessSlider->hide();
    ui->hueSlider->hide();
    ui->blurSlider->hide();
    // Create an instance of the merge options dialog
    MergeOptionsDialog mergeDialog(this);

    // Connect the mergeDialog's signal to a slot in MainWindow
    connect(&mergeDialog, &MergeOptionsDialog::mergeOptionSelected, this, &MainWindow::handleMergeOptionSelected);
    disconnect(ui->btnMerge, &QPushButton::clicked, this, &MainWindow::on_btnMerge_clicked);
    // Open the dialog as modal
    if (mergeDialog.exec() == QDialog::Accepted) {
        // Dialog accepted, do nothing (slot will handle the selected merge option)
    }
}
// Slot to handle the selected merge option
void MainWindow::handleMergeOptionSelected(QString mergeOption) {
    // Get the paths of the two images to merge
    QString filename1 = loadedImagePath;
    QString filename2 = QFileDialog::getOpenFileName(this, tr("Open Second Image"), "", tr("Image Files (*.png *.jpg *.bmp)"));
    disconnect(ui->btnMerge, &QPushButton::clicked, this, &MainWindow::on_btnMerge_clicked);
    if (!filename2.isEmpty()) {
        // Perform the merge operation
        merge(filename1.toStdString(), filename2.toStdString(), mergeOption.toStdString());

        // Display the result image
        QPixmap pixmap(QString::fromStdString(pathTmp.toStdString()));
        loadedImagePath = pathTmp;
        if (!pixmap.isNull()) {
            ui->resultImg->setPixmap(pixmap.scaled(ui->resultImg->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
            ui->resultImg->setAlignment(Qt::AlignCenter);
        } else {
            qDebug() << "Error: Unable to load result image";
        }
    } else {
        qDebug() << "Error: No second image selected";
    }
}

// Implement the slots for the frame buttons
void MainWindow::on_btnNormalFrame_clicked() {
    ui->skewSlider->hide();
    ui->brightnessSlider->hide();
    ui->hueSlider->hide();
    ui->blurSlider->hide();
    if (!loadedImagePath.isEmpty()) {
        // Convert QString to std::string
        std::string stdFilename = loadedImagePath.toStdString();

        // Open the border size input dialog
        disconnect(ui->btnNormalFrame, &QPushButton::clicked, this, &MainWindow::on_btnNormalFrame_clicked);
        bool ok;
        int borderSize = QInputDialog::getInt(this, "Enter Border Size", "Border Size:", 10, 0, 100, 1, &ok);
        if (!ok) return; // User canceled

        // Open the color selection dialog
        QColor color = QColorDialog::getColor(Qt::white, this, "Choose Frame Color");
        if (!color.isValid()) return; // User canceled

        // Convert QColor to RGB array
        int frameColor[3] = {color.red(), color.green(), color.blue()};

        // Call add_frame function with chosen border size and color
        add_frame(loadedImagePath.toStdString(), borderSize, frameColor);
        loadedImagePath = pathTmp;
        // Display the updated image
        updateResultImage();
    } else {
        qDebug() << "Error: No image loaded";
    }
}
void MainWindow::on_btnFancyFrame_clicked() {
    ui->skewSlider->hide();
    ui->brightnessSlider->hide();
    ui->hueSlider->hide();
    ui->blurSlider->hide();
    if (!loadedImagePath.isEmpty()) {
        // Convert QString to std::string
        std::string stdFilename = loadedImagePath.toStdString();

        // Open the border size input dialog
        disconnect(ui->btnFancyFrame, &QPushButton::clicked, this, &MainWindow::on_btnFancyFrame_clicked);
        bool ok;
        int borderSize = QInputDialog::getInt(this, "Enter Border Size", "Border Size:", 0, 0, 100, 1, &ok);
        if (!ok) return; // User canceled

        // Open the color selection dialog for the frame color
        QColor frameColor = QColorDialog::getColor(Qt::white, this, "Choose Frame Color");
        if (!frameColor.isValid()) return; // User canceled

        // Convert QColor to RGB array
        int frameRGB[3] = {frameColor.red(), frameColor.green(), frameColor.blue()};

        // Open the color selection dialog for the fancy frame color
        QColor fancyColor = QColorDialog::getColor(Qt::white, this, "Choose Fancy Frame Color");
        if (!fancyColor.isValid()) return; // User canceled

        // Convert QColor to RGB array
        int fancyRGB[3] = {fancyColor.red(), fancyColor.green(), fancyColor.blue()};

        // Call add_frame_fancy function with chosen colors
        add_frame_fancy(loadedImagePath.toStdString(), borderSize, frameRGB, fancyRGB);
        loadedImagePath = pathTmp;
        // Display the updated image
        updateResultImage();
    } else {
        qDebug() << "Error: No image loaded";
    }
}
void MainWindow::updateResultImage() {
    // Display the updated image
    QPixmap pixmap(pathTmp);
    if (!pixmap.isNull()) {
        qInfo() << "SUCCESS";
        ui->resultImg->setPixmap(pixmap.scaled(ui->resultImg->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
        ui->resultImg->setAlignment(Qt::AlignCenter);
    } else {
        qDebug() << "Error: Unable to load image";
    }
}

//  Brithness //
void MainWindow::on_brightnessSlider_actionTriggered(double action)
{
    // Update brightness factor
    num = action / 10.0; // Adjust the scale as needed
    // Apply blur effect with the updated intensity
    applyBrightness();
}
void MainWindow::on_btnBrightness_clicked()
{
    ui->skewSlider->hide();
    ui->hueSlider->hide();
    ui->blurSlider->hide();
    // Disconnect the signal-slot connection to prevent multiple dialog openings
    disconnect(ui->btnBrightness, &QPushButton::clicked, this, &MainWindow::on_btnBrightness_clicked);
    // Show the blur intensity slider
    ui->brightnessSlider->show();
    // Call the applyBlurEffect function to apply the blur with the initial intensity
    applyBrightness();
}
void MainWindow::applyBrightness()
{
    // Apply blur effect with the current blur intensity
    if (!loadedImagePath.isEmpty()) {
        // Convert QString to std::string
        std::string stdFilename = loadedImagePath.toStdString();
         qInfo() << num;
        // Call your blur_image function with the std::string filename and blur intensity
        Brightness(stdFilename, num);
        // Display the updated image
        QPixmap pixmap(pathTmp);
        if (!pixmap.isNull()) {
            qInfo() << "SUCCESS";
            ui->resultImg->setPixmap(pixmap.scaled(ui->resultImg->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
            ui->resultImg->setAlignment(Qt::AlignCenter);
        } else {
            qDebug() << "Error: Unable to load image";
        }
    } else {
        qDebug() << "Error: No image loaded";
    }
}

// Hue //
void MainWindow::on_hueSlider_actionTriggered(int action)
{
    // Update brightness factor
    hue_shift = action;
    // Apply blur effect with the updated intensity
    applyHue();
}
void MainWindow::on_btnHue_clicked()
{
    ui->brightnessSlider->hide();
    ui->skewSlider->hide();
    ui->blurSlider->hide();
    // Disconnect the signal-slot connection to prevent multiple dialog openings
    disconnect(ui->btnHue, &QPushButton::clicked, this, &MainWindow::on_btnHue_clicked);
    // Show the blur intensity slider
    ui->hueSlider->show();
    // Call the applyBlurEffect function to apply the blur with the initial intensity
    applyHue();
}
void MainWindow::applyHue()
{
    // Apply blur effect with the current blur intensity
    if (!loadedImagePath.isEmpty()) {
        // Convert QString to std::string
        std::string stdFilename = loadedImagePath.toStdString();
        // Call your blur_image function with the std::string filename and blur intensity
        hue(stdFilename, hue_shift);
        // Display the updated image
        QPixmap pixmap(pathTmp);
        if (!pixmap.isNull()) {
            qInfo() << "SUCCESS";
            ui->resultImg->setPixmap(pixmap.scaled(ui->resultImg->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
            ui->resultImg->setAlignment(Qt::AlignCenter);
        } else {
            qDebug() << "Error: Unable to load image";
        }
    } else {
        qDebug() << "Error: No image loaded";
    }
}






