#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <limits>
#include "functions.h"

using std::cin, std::cout, std::endl;
using std::numeric_limits, std::streamsize;
using std::ofstream, std::ifstream;

/***************************************************************************
 *
 * This provided code uses C-style strings.
 * Later this semester the students will be learning and using C++ Strings
 * instead.
 * It is important to know about C-style strings because they are used
 * in a lot of code. Unless you have a specific, compelling reason to use C-style
 * strings, once you learn C++ Strings, use std::string (defined in the <string> header) instead.
 * std::string is easier, safer, and more flexible.
 *
 ***************************************************************************/

/*  Function processImage
 *  choice: char representing which type of image processing to perform
 *  image: 2d-array of Pixels (structs)
 *  Return value: none
 */
 // You should not modify this function unless you add another processing option. //
void processImage(char choice, Pixel image[MAX_WIDTH][MAX_HEIGHT]) {
  const int maxFilenameSize = 100;
  char originalImageFilename[maxFilenameSize];

  int width = 0, height = 0;

  // get filename, width and height from user
  cout << "Image filename: ";
  cin >> originalImageFilename;
  width = getInteger("width", 1, MAX_WIDTH); // ensure user does not input value greater than the MAX_WIDTH for our array
  height = getInteger("height", 1, MAX_HEIGHT); // ensure user does not input value greater than the MAX_HEIGHT for our array

  // load image
  if (loadImage(originalImageFilename, image, width, height)) {
    // only get in here if image loaded successfully

    char outputImageFilename[maxFilenameSize+7]; // maxFilenameSize plus 6 for adding on "sepia." ".copy" is smaller so works as well

    // modify image
    switch (toupper(choice)) {
      case 'G':
        grayscaleImage(image, width, height);
        strncpy(outputImageFilename, "grey.", 6);
        strncat(outputImageFilename, originalImageFilename, maxFilenameSize);
        break;
      case 'S':
        sepiaImage(image, width, height);
        strncpy(outputImageFilename,"sepia.", 7);
        strncat(outputImageFilename, originalImageFilename, maxFilenameSize);
        break;
    }

    // output image
    outputImage(outputImageFilename, image, width, height);
  }
}



/*  Function loadImage
 *  filename: c-string which is the ppm file to read
 *  image: 2d-array of Pixels (structs)
 *  width: int for the width of the image array
 *  height: int for height of the image array
 *  Return value: bool true if the image loads, bool false if the image fails to load
 */
 // You should complete this function. //
bool loadImage(const char filename[], Pixel image[MAX_WIDTH][MAX_HEIGHT], int width, int height) {
  cout << "Loading image..." << endl;
  // declare/define and open input file stream
  ifstream ifs (filename);

  // check if input stream opened successfully
  if (!ifs.is_open()) {
    cout << "Error: failed to open input file " << filename << endl;
    return false;
  }

  // get type from preamble
  char type[3];
  ifs >> type; // should be P3
  if ((toupper(type[0]) != 'P') || (type[1] != '3')) { // check that type is correct
    cout << "Error: type is " << type << "instead of P3" << endl;
    return false;
  }

  // get width (w) and height (h) from preamble
  int w = 0, h = 0;
  ifs >> w >> h;
  if (w != width) { // check that width matches what was passed into the function
    cout << "Error: file width does not match input" << endl;
    cout << " - input width: " << width << endl;
    cout << " -  file width: " << w << endl;
    return false;
  }
  if (h != height) { // check that height matches what was passed into the function
    cout << "Error: file height does not match input" << endl;
    cout << " - input height: " << height << endl;
    cout << " -  file height: " << h << endl;
    return false;
  }

  // get maximum value from preamble
  int colorMax = 0;
  ifs >> colorMax;
  if (colorMax != 255) {
    cout << "Error: file is not using RGB color values." << endl;
    return false;
  }

  // TODO(student): get RGB pixel values
  int r,g,b;
  for(int i=0; i<height; i++){
    for(int j=0; j<width; j++){
      ifs >> r >> g >> b;
      image[j][i].r = r;
      image[j][i].g = g;
      image[j][i].b = b;
    }
  }

  return true;
}



/*  Function grayscale
 *  image: 2d-array of Pixels (structs)
 *  width: int for the width of the image array
 *  height: int for height of the image array
 *  Return value: none, but image should be modified to be grayscale colors
 */
 // You should write this function. //
void grayscaleImage(Pixel image[MAX_WIDTH][MAX_HEIGHT], int width, int height) {
  cout << "Making grayscale image... " << endl;
  // TODO(student): iterate through 2d image of Pixels and convert them to grayscale
  int average;
  for(int i=0; i<height; i++){
    for(int j=0; j<width; j++){
      average = round((image[j][i].r + image[j][i].g + image[j][i].b)/3.0);
      image[j][i].r = average;
      image[j][i].g = average;
      image[j][i].b = average;
    }
  }
}



/*  Function sepiaImage
 *  image: 2d-array of Pixels (structs)
 *  width: int for the width of the image array
 *  height: int for height of the image array
 *  Return value: none, but image should be modified to be sepia colors
 */
 // You should write this function. //
void sepiaImage(Pixel image[MAX_WIDTH][MAX_HEIGHT], int width, int height) {
  cout << "Making sepia image... " << endl;
  // TODO(student): iterate through 2d image of Pixels and convert them to sepia
  int rT,gT,bT; //temporary values for RGB
  for(int i=0; i<height; i++){
    for(int j=0; j<width; j++){
      rT = image[j][i].r;
      gT = image[j][i].g;
      bT = image[j][i].b;
      if(round(0.393*rT + 0.769*gT + 0.189*bT)>255){
        image[j][i].r = 255;
      }else{
        image[j][i].r = round(0.393*rT + 0.769*gT + 0.189*bT);
      };
      if(round(0.349*rT + 0.686*gT + 0.168*bT)>255){
        image[j][i].g = 255;
      }else{
        image[j][i].g = round(0.349*rT + 0.686*gT + 0.168*bT);
      };
      if(round(0.272*rT + 0.534*gT + 0.131*bT)>255){
        image[j][i].b = 255;
      }else{
        image[j][i].b = round(0.272*rT + 0.534*gT + 0.131*bT);
      };
    }
  }
}



/*  Function outputImage
 *  filename: c-string which is the ppm file to write
 *  image: 2d-array of Pixels (structs)
 *  width: int for the width of the image array
 *  height: int for height of the image array
 *  Return value: none, but ppm file should be created
 */
 // You should write this function. //
void outputImage(const char filename[], const Pixel image[MAX_WIDTH][MAX_HEIGHT], int width, int height) {
  cout << "Outputting image..." << endl;
  // TODO(student): declare/define and open output file stream
  ofstream ofs (filename);
  // TODO(student): check if output stream opened successfully
  if (!ofs.is_open()) {
    cout << "Error: failed to open input file " << filename << endl;
  }
  // TODO(student): output preamble
  ofs << 'P' << 3 << endl;
  ofs << width << " " << height << endl;
  ofs << 255 << endl;
  // TODO(student): output pixels
  for(int i=0; i<height; i++){
    for(int j=0; j<width; j++){
      ofs << image[j][i].r << endl;
      ofs << image[j][i].g << endl;
      ofs << image[j][i].b << endl;
    }
  }

}



/*  Function printMenu
 *  Return value: none
 */
 // You should not modify this function. //
void printMenu() {
  cout << "--------------------------" << endl;
  cout << " 'G': Make grayscale image" << endl;
  cout << " 'S': Make sepia image" << endl;
  cout << " 'Q': Quit" << endl;
  cout << "--------------------------" << endl;
  cout << endl << "Please enter your choice: ";
}



/*  Function getInteger
 *  label: label for outputing what the user is inputting, it should work when used as "Please enter <label>"
 *  min: int value indicating the smallest value the user should provide
 *  max: int value indicating the largest value the user should provide
 *  Return value: int value within the range min <= value <= max
 */
 // You should not modify this function. //
int getInteger(const char label[], int min, int max) {
  // get value from user repeatedly until input matches requirements
  int num = 0;
  do {
    cin.clear(); // reset stream states
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear buffer

    cout << "Please enter " << label << " (" << min << " - " << max << "): ";
    cin >> num;
  } while (!cin.good() || num < min || num > max); // while input does not match requirements
  return num;
}
