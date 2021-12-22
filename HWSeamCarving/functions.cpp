#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include "functions.h"

#define INFO(X) cout << "[INFO] ("<<__FUNCTION__<<":"<<__LINE__<<") " << #X << " = " << X << endl;

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ofstream;
using std::ifstream;

Pixel** createImage(int width, int height) {
  cout << "Start createImage... " << endl;

  // Create a one dimensional array on the heap of pointers to Pixels
  //    that has width elements (i.e. the number of columns)
  Pixel** image = new Pixel*[width];

  bool fail = false;

  for (int i=0; i < width; ++i) { // loop through each column
    // assign that column to a one dimensional array on the heap of Pixels
    //  that has height elements (i.e. the number of rows)
    image[i] = new Pixel[height];

    if (image[i] == nullptr) { // failed to allocate
      fail = true;
    }
  }

  if (fail) { // if any allocation fails, clean up and avoid memory leak
    // deallocate any arrays created in for loop
    for (int i=0; i < width; ++i) {
      delete [] image[i]; // deleting nullptr is not a problem
    }
    delete [] image; // dlete array of pointers
    return nullptr;
  }

  // initialize cells
  //cout << "Initializing cells..." << endl;
  for (int row=0; row<height; ++row) {
    for (int col=0; col<width; ++col) {
      //cout << "(" << col << ", " << row << ")" << endl;
      image[col][row] = { 0, 0, 0 };
    }
  }
  cout << "End createImage... " << endl;
  return image;
}

void deleteImage(Pixel** image, int width) {
  cout << "Start deleteImage..." << endl;
  // avoid memory leak by deleting the array
  for (int i=0; i<width; ++i) {
    delete [] image[i]; // delete each individual array placed on the heap
  }
  delete [] image;
  image = nullptr;
}

int* createSeam(int length) {
    // TODO(student): create a seam
    INFO(length);
    int* array = new int[length];
    for(int i=0; i<length; i++){
      array[i] = 0;
    }
  return array;
}

void deleteSeam(int* seam) {
    // TODO(student): delete a seam
    INFO(seam);
    delete [] seam;
}

bool loadImage(string filename, Pixel** image, int width, int height) {
    // TODO(student): load an image
    INFO(filename);
    INFO(image);
    INFO(width);
    INFO(height);
    // declare/define and open input file stream
  ifstream ifs (filename);

  // check if input stream opened successfully
  if (!ifs.is_open()) {
    cout << "Error: failed to open input file - " << filename << endl;
    return false;
  }

  // get type from preamble
  char type[3];
  ifs >> type; // should be P3
  if ((toupper(type[0]) != 'P') || (type[1] != '3')) { // check that type is correct
    cout << "Error: type is " << type << " instead of P3" << endl;
    return false;
  }

  // get width (w) and height (h) from preamble
  int w = 0, h = 0;
  ifs >> w >> h;
  if(ifs.fail()){
    cout<<"Error: read non-integer value";
    return false;
  }
  if (w != width) { // check that width matches what was passed into the function
    cout << "Error: input width ("<<width<<") does not match value in file ("<<w<<")" << endl;
    return false;
  }
  if (h != height) { // check that height matches what was passed into the function
    cout << "Error: input height ("<<height<<") does not match value in file ("<<h<<")" << endl;
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
      ifs >> r >> g >> b; //get RGB values
      if(ifs.fail()){
        if(ifs.eof()){
          cout<<"Error: not enough color values"<<endl;
          return false;
        }
        cout<<"Error: read non-integer value";
        return false;
      }
      if(r<0 || r>255){
        cout<<"Error: invalid color value "<<r<<endl;
        return false;
      }
      if(g<0 || g>255){
        cout<<"Error: invalid color value "<<g<<endl;
        return false;
      }
      if(b<0 || b>255){
        cout<<"Error: invalid color value "<<b<<endl;
        return false;
      }
      image[j][i] = {r,g,b};
    }
  }
  if(ifs>>r){
    cout<<"Error: too many color values"<<endl;
    return false;
  }

  return true;
}

bool outputImage(string filename, Pixel** image, int width, int height) {
    // TODO(student): output an image
    INFO(filename);
    INFO(image);
    INFO(width);
    INFO(height);
    ofstream ofs (filename);
  // TODO(student): check if output stream opened successfully
  if (!ofs.is_open()) {
    cout << "Error: failed to open output file - " << filename << endl;
    return false;
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
  return true;
}

int energy(Pixel** image, int column, int row, int width, int height) {
    // TODO(student): compute the energy of a pixel
    /*
    INFO(image);
    INFO(column);
    INFO(row);
    INFO(width);
    INFO(height);
    */
    int energy = 0;
    int energyX = 0;
    int energyY = 0;
    if(width==1){
      energyX = 0;
    }else if(column==0){
      energyX = pow((image[1][row].r-image[width-1][row].r),2)+
                pow((image[1][row].g-image[width-1][row].g),2)+
                pow((image[1][row].b-image[width-1][row].b),2);
    }else if(column==width-1){
      energyX = pow((image[0][row].r-image[column-1][row].r),2)+
                pow((image[0][row].g-image[column-1][row].g),2)+
                pow((image[0][row].b-image[column-1][row].b),2);
    }else{
      energyX = pow((image[column+1][row].r-image[column-1][row].r),2)+
                pow((image[column+1][row].g-image[column-1][row].g),2)+
                pow((image[column+1][row].b-image[column-1][row].b),2);
    }
    if(height==1){
      energyY = 0;
    }else if(row==0){
      energyY = pow((image[column][1].r-image[column][height-1].r),2)+
                pow((image[column][1].g-image[column][height-1].g),2)+
                pow((image[column][1].b-image[column][height-1].b),2);
    }else if(row==height-1){
      energyY = pow((image[column][0].r-image[column][row-1].r),2)+
                pow((image[column][0].g-image[column][row-1].g),2)+
                pow((image[column][0].b-image[column][row-1].b),2);
    }else{
      energyY = pow((image[column][row+1].r-image[column][row-1].r),2)+
                pow((image[column][row+1].g-image[column][row-1].g),2)+
                pow((image[column][row+1].b-image[column][row-1].b),2);
    }
    energy = energyX + energyY;
    //INFO(energy)
    return energy;
}

int loadVerticalSeam(Pixel** image, int start_col, int width, int height, int* seam) {
    // TODO(student): load a vertical seam
    INFO(image);
    INFO(start_col);
    INFO(width);
    INFO(height);
    INFO(seam);
    int min;
    //start_col
    int total = energy(image,start_col,0,width,height);
    seam[0] = start_col;

    for(int i=1; i<height; i++){
      min = energy(image,seam[i-1],i,width,height); //middle
      seam[i] = seam[i-1];
      if(width==1){
        min = energy(image,seam[i-1],i,width,height);
        seam[i] = seam[i-1];
      }else if(seam[i]==0){
        if(energy(image,seam[i-1]+1,i,width,height)<min){
          min = energy(image,seam[i-1]+1,i,width,height);
          seam[i] = seam[i-1]+1;
        }
      }else if(seam[i]==width-1){
        if(energy(image,seam[i-1]-1,i,width,height)<min){
          min = energy(image,seam[i-1]-1,i,width,height);
          seam[i] = seam[i-1]-1;
        }
      }else{
        if(energy(image,seam[i-1]+1,i,width,height)<min){
          min = energy(image,seam[i-1]+1,i,width,height);
          seam[i] = seam[i-1]+1;
        }
        if(energy(image,seam[i-1]-1,i,width,height)<min){
          min = energy(image,seam[i-1]-1,i,width,height);
          seam[i] = seam[i-1]-1;
        }
      }
      total+=min;
    }

  return total;
}

int loadHorizontalSeam(Pixel** image, int start_row, int width, int height, int* seam) {
    // TODO(student): load a horizontal seam
    INFO(image);
    INFO(start_row);
    INFO(width);
    INFO(height);
    INFO(seam);

    return 0;
}

int* findMinVerticalSeam(Pixel** image, int width, int height) {
    // TODO(student): find min vertical seam
    INFO(image);
    INFO(width);
    INFO(height);
    int * seam1 = new int[height];
    int * seam2 = new int[height];
    int min = loadVerticalSeam(image, 0, width, height, seam1);

    for(int i=1; i<width; i++){
      if(loadVerticalSeam(image, i, width, height, seam2) < min){
        min = loadVerticalSeam(image, i, width, height, seam1);
        /*
        for(int j=0; j<height; j++){
          seam1[j] = seam2[j];
        }
        */
      }
    }
    delete [] seam2;
  return seam1;
}

int* findMinHorizontalSeam(Pixel** image, int width, int height) {
    // TODO(student): find min horizontal seam
    INFO(image);
    INFO(width);
    INFO(height);
  return nullptr;
}

void removeVerticalSeam(Pixel** image, int width, int height, int* verticalSeam) {
    // TODO(student): remove a vertical seam
    INFO(image);
    INFO(width);
    INFO(height);
    INFO(verticalSeam);
    for(int i=0; i<height; i++){
      for(int j=verticalSeam[i]; j<width-1; j++){
        image[j][i]= image[j+1][i];
      }
    }

}

void removeHorizontalSeam(Pixel** image, int width, int height, int* horizontalSeam) {
    // TODO(student): remove a horizontal seam
    INFO(image);
    INFO(width);
    INFO(height);
    INFO(horizontalSeam);
}
