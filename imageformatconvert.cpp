#include "imageformatconvert.h"
#include <string>
using namespace cv;
void ImageFormatConvert::NV12ToJpg(std::string path, int Height, int Width, int Stride)
{

    FILE* fp = fopen(path.c_str(),"rb");

    int rows = Height;
    int cols = Width;
    unsigned char* yuvbuff = new unsigned char[int(1.5 * rows * cols)];
    memset(yuvbuff,0,int(1.5 * rows * cols));
    fread(yuvbuff,sizeof (unsigned char),int(1.5 * rows * cols),fp);
//    R= Y + ((360 * (V - 128))>>8) ;
//    G= Y - (( ( 88 * (U - 128)  + 184 * (V - 128)) )>>8) ;
//    B= Y +((455 * (U - 128))>>8) ;

    int file_size = 0;
    fseek(fp,0,SEEK_END);
    file_size=ftell(fp);
    qDebug()<<"file_size: "<<file_size;

    Height = file_size/Stride;
    qDebug()<<"Height: "<<Height;

    int yHeight = int(Height/3*2);
    qDebug()<<"yHeight: "<<yHeight;
    qDebug()<<"Width: "<<Width;
    qDebug()<<"Stride: "<<Stride;
    unsigned char U;
    unsigned char V;
    unsigned char Y;

    std::string filename = path.substr(0,path.find_last_of('.')+1)+"jpg";
    qDebug()<<"filename: "<<QString::fromStdString(filename);

    for (int i = 0; i < yHeight; i++) {
        for (int j = 0;j<Width;j++) {
            Y = int(yuvbuff[j + i * Stride]);
          // std::cout << "Y index: " << j + i * Stride << "Y value: "<< int(yuvbuff[j + i * Stride]) << std::endl;
           //std::cout << "U index: " << yHeight * Stride + (j / 2) * 2 + i / 2 * Stride << "U value: " << int(yuvbuff[yHeight * Stride + (j / 2) * 2 + i / 2 * Stride])<<std::endl;

           U = int(yuvbuff[yHeight * Stride + (j / 2) * 2 + i / 2 * Stride - 1]);
           V = int(yuvbuff[yHeight * Stride + (j / 2) * 2 + i / 2 * Stride]);


           /*int R = Y + ((360 * (V - 128)) >> 8);
           int G = Y - (((88 * (U - 128) + 184 * (V - 128))) >> 8);
           int B = Y + ((455 * (U - 128)) >> 8);*/


           int R = Y + 1.4075 * (V - 128);
           int G = Y - 0.3455 * (U -128) - 0.7169 * (V -128);
           int B = Y + 1.779 * (U - 128);

           R = (R < 0) ? 0 : ((R > 255) ? 255 : R);
           G = (G < 0) ? 0 : ((G > 255) ? 255 : G);
           B = (B < 0) ? 0 : ((B > 255) ? 255 : B);
           jpgImg.at<cv::Vec3b>(i, j)[0] = char(B);
           jpgImg.at<cv::Vec3b>(i, j)[1] = char(G);
           jpgImg.at<cv::Vec3b>(i, j)[2] = char(R);
        }
    }
}

void ImageFormatConvert::NV21ToJpg(std::string path, int Height, int Width, int Stride)
{
    FILE* fp = fopen(path.c_str(),"rb");

    int rows = Height;
    int cols = Width;
    unsigned char* yuvbuff = new unsigned char[int(1.5 * rows * cols)];
    memset(yuvbuff,0,int(1.5 * rows * cols));
    fread(yuvbuff,sizeof (unsigned char),int(1.5 * rows * cols),fp);
//    R= Y + ((360 * (V - 128))>>8) ;
//    G= Y - (( ( 88 * (U - 128)  + 184 * (V - 128)) )>>8) ;
//    B= Y +((455 * (U - 128))>>8) ;

    int file_size = 0;
    fseek(fp,0,SEEK_END);
    file_size=ftell(fp);
    qDebug()<<"file_size: "<<file_size;

    Height = file_size/Stride;
    qDebug()<<"Height: "<<Height;

    int yHeight = int(Height/3*2);
    qDebug()<<"yHeight: "<<yHeight;
    qDebug()<<"Width: "<<Width;
    unsigned char U;
    unsigned char V;
    unsigned char Y;

    std::string filename = path.substr(0,path.find_last_of('.')+1)+"jpg";
    qDebug()<<"filename: "<<QString::fromStdString(filename);

    for (int i = 0; i < yHeight; i++) {
        for (int j = 0;j<Width;j++) {
            Y = int(yuvbuff[j + i * Stride]);
          // std::cout << "Y index: " << j + i * Stride << "Y value: "<< int(yuvbuff[j + i * Stride]) << std::endl;
           //std::cout << "U index: " << yHeight * Stride + (j / 2) * 2 + i / 2 * Stride << "U value: " << int(yuvbuff[yHeight * Stride + (j / 2) * 2 + i / 2 * Stride])<<std::endl;

           V = int(yuvbuff[yHeight * Stride + (j / 2) * 2 + i / 2 * Stride - 1]);
           U = int(yuvbuff[yHeight * Stride + (j / 2) * 2 + i / 2 * Stride]);


           /*int R = Y + ((360 * (V - 128)) >> 8);
           int G = Y - (((88 * (U - 128) + 184 * (V - 128))) >> 8);
           int B = Y + ((455 * (U - 128)) >> 8);*/


           int R = Y + 1.4075 * (V - 128);
           int G = Y - 0.3455 * (U -128) - 0.7169 * (V -128);
           int B = Y + 1.779 * (U - 128);

           R = (R < 0) ? 0 : ((R > 255) ? 255 : R);
           G = (G < 0) ? 0 : ((G > 255) ? 255 : G);
           B = (B < 0) ? 0 : ((B > 255) ? 255 : B);
           jpgImg.at<cv::Vec3b>(i, j)[0] = char(B);
           jpgImg.at<cv::Vec3b>(i, j)[1] = char(G);
           jpgImg.at<cv::Vec3b>(i, j)[2] = char(R);
        }
    }
}


void ImageFormatConvert::I444ToJpg(std::string path, int Height, int Width, int Stride)
{

    FILE* fp = fopen(path.c_str(),"rb");

    int rows = Height;
    int cols = Width;
    unsigned char* yuvbuff = new unsigned char[int(3 * rows * cols)];
    memset(yuvbuff,0,int(3 * rows * cols));
    fread(yuvbuff,sizeof (unsigned char),int(3 * rows * cols),fp);
//    R= Y + ((360 * (V - 128))>>8) ;
//    G= Y - (( ( 88 * (U - 128)  + 184 * (V - 128)) )>>8) ;
//    B= Y +((455 * (U - 128))>>8) ;

    int file_size = 0;
    fseek(fp,0,SEEK_END);
    file_size=ftell(fp);
    qDebug()<<"file_size: "<<file_size;

    Height = file_size/Stride;
    qDebug()<<"Height: "<<Height;

    int yHeight = int(Height/3);
    qDebug()<<"yHeight: "<<yHeight;
    qDebug()<<"Width: "<<Width;
    unsigned char U;
    unsigned char V;
    unsigned char Y;

    std::string filename = path.substr(0,path.find_last_of('.')+1)+"jpg";
    qDebug()<<"filename: "<<QString::fromStdString(filename);

    for (int i = 0; i < yHeight; i++) {
        for (int j = 0;j<Width;j++) {
            Y = int(yuvbuff[j + i * Stride]);
          // std::cout << "Y index: " << j + i * Stride << "Y value: "<< int(yuvbuff[j + i * Stride]) << std::endl;
           //std::cout << "U index: " << yHeight * Stride + (j / 2) * 2 + i / 2 * Stride << "U value: " << int(yuvbuff[yHeight * Stride + (j / 2) * 2 + i / 2 * Stride])<<std::endl;

           U = int(yuvbuff[yHeight * Stride + j + i * Stride]);
           V = int(yuvbuff[yHeight * Stride*2 + j + i * Stride]);


           /*int R = Y + ((360 * (V - 128)) >> 8);
           int G = Y - (((88 * (U - 128) + 184 * (V - 128))) >> 8);
           int B = Y + ((455 * (U - 128)) >> 8);*/


           int R = Y + 1.4075 * (V - 128);
           int G = Y - 0.3455 * (U -128) - 0.7169 * (V -128);
           int B = Y + 1.779 * (U - 128);

           R = (R < 0) ? 0 : ((R > 255) ? 255 : R);
           G = (G < 0) ? 0 : ((G > 255) ? 255 : G);
           B = (B < 0) ? 0 : ((B > 255) ? 255 : B);
           jpgImg.at<cv::Vec3b>(i, j)[0] = char(B);
           jpgImg.at<cv::Vec3b>(i, j)[1] = char(G);
           jpgImg.at<cv::Vec3b>(i, j)[2] = char(R);
        }
    }
}

void ImageFormatConvert::YV24ToJpg(std::string path,int Height, int Width, int Stride)
{
    FILE* fp = fopen(path.c_str(),"rb");

    int rows = Height;
    int cols = Width;
    unsigned char* yuvbuff = new unsigned char[int(3 * rows * cols)];
    memset(yuvbuff,0,int(3 * rows * cols));
    fread(yuvbuff,sizeof (unsigned char),int(3 * rows * cols),fp);
//    R= Y + ((360 * (V - 128))>>8) ;
//    G= Y - (( ( 88 * (U - 128)  + 184 * (V - 128)) )>>8) ;
//    B= Y +((455 * (U - 128))>>8) ;

    int file_size = 0;
    fseek(fp,0,SEEK_END);
    file_size=ftell(fp);
    qDebug()<<"file_size: "<<file_size;

    Height = file_size/Stride;
    qDebug()<<"Height: "<<Height;

    int yHeight = int(Height/3);
    qDebug()<<"yHeight: "<<yHeight;
    qDebug()<<"Width: "<<Width;
    unsigned char U;
    unsigned char V;
    unsigned char Y;

    std::string filename = path.substr(0,path.find_last_of('.')+1)+"jpg";
    qDebug()<<"filename: "<<QString::fromStdString(filename);

    for (int i = 0; i < yHeight; i++) {
        for (int j = 0;j<Width;j++) {
           Y = int(yuvbuff[j + i * Stride]);
          // std::cout << "Y index: " << j + i * Stride << "Y value: "<< int(yuvbuff[j + i * Stride]) << std::endl;
           //std::cout << "U index: " << yHeight * Stride + (j / 2) * 2 + i / 2 * Stride << "U value: " << int(yuvbuff[yHeight * Stride + (j / 2) * 2 + i / 2 * Stride])<<std::endl;

           V = int(yuvbuff[yHeight * Stride + j + i * Stride]);
           U = int(yuvbuff[yHeight * Stride*2 + j + i * Stride]);


           /*int R = Y + ((360 * (V - 128)) >> 8);
           int G = Y - (((88 * (U - 128) + 184 * (V - 128))) >> 8);
           int B = Y + ((455 * (U - 128)) >> 8);*/


           int R = Y + 1.4075 * (V - 128);
           int G = Y - 0.3455 * (U -128) - 0.7169 * (V -128);
           int B = Y + 1.779 * (U - 128);

           R = (R < 0) ? 0 : ((R > 255) ? 255 : R);
           G = (G < 0) ? 0 : ((G > 255) ? 255 : G);
           B = (B < 0) ? 0 : ((B > 255) ? 255 : B);
           jpgImg.at<cv::Vec3b>(i, j)[0] = char(B);
           jpgImg.at<cv::Vec3b>(i, j)[1] = char(G);
           jpgImg.at<cv::Vec3b>(i, j)[2] = char(R);
        }
    }
}
//tobe modify
void ImageFormatConvert::I420ToJpg(std::string path, int Height, int Width, int Stride)
{
    FILE* fp = fopen(path.c_str(),"rb");

    int rows = Height;
    int cols = Width;
    unsigned char* yuvbuff = new unsigned char[int(1.5 * rows * cols)];
    memset(yuvbuff,0,int(1.5 * rows * cols));
    fread(yuvbuff,sizeof (unsigned char),int(1.5 * rows * cols),fp);
//    R= Y + ((360 * (V - 128))>>8) ;
//    G= Y - (( ( 88 * (U - 128)  + 184 * (V - 128)) )>>8) ;
//    B= Y +((455 * (U - 128))>>8) ;

    int file_size = 0;
    fseek(fp,0,SEEK_END);
    file_size=ftell(fp);
    qDebug()<<"file_size: "<<file_size;

    Height = file_size/Stride;
    qDebug()<<"Height: "<<Height;

    int yHeight = int(Height/3*2);
    qDebug()<<"yHeight: "<<yHeight;
    qDebug()<<"Width: "<<Width;
    unsigned char U;
    unsigned char V;
    unsigned char Y;

    std::string filename = path.substr(0,path.find_last_of('.')+1)+"jpg";
    qDebug()<<"filename: "<<QString::fromStdString(filename);

    for (int i = 0; i < yHeight; i++) {
        for (int j = 0;j<Width;j++) {
            Y = int(yuvbuff[j + i * Stride]);
          // std::cout << "Y index: " << j + i * Stride << "Y value: "<< int(yuvbuff[j + i * Stride]) << std::endl;
           //std::cout << "U index: " << yHeight * Stride + (j / 2) * 2 + i / 2 * Stride << "U value: " << int(yuvbuff[yHeight * Stride + (j / 2) * 2 + i / 2 * Stride])<<std::endl;

           U = int(yuvbuff[(yHeight+i/2) * Stride + (j / 2)]);
           qDebug()<<"UHeight: "<<(yHeight+i/2) * Stride + (j / 2);
           qDebug()<<"VHeight: "<<int(yHeight* 1.25+i/2) * Stride + (j / 2);
           V = int(yuvbuff[int(yHeight* 1.25+i/2) * Stride + (j / 2)]);


           /*int R = Y + ((360 * (V - 128)) >> 8);
           int G = Y - (((88 * (U - 128) + 184 * (V - 128))) >> 8);
           int B = Y + ((455 * (U - 128)) >> 8);*/


           int R = Y + 1.4075 * (V - 128);
           int G = Y - 0.3455 * (U -128) - 0.7169 * (V -128);
           int B = Y + 1.779 * (U - 128);

           R = (R < 0) ? 0 : ((R > 255) ? 255 : R);
           G = (G < 0) ? 0 : ((G > 255) ? 255 : G);
           B = (B < 0) ? 0 : ((B > 255) ? 255 : B);
           jpgImg.at<cv::Vec3b>(i, j)[0] = char(B);
           jpgImg.at<cv::Vec3b>(i, j)[1] = char(G);
           jpgImg.at<cv::Vec3b>(i, j)[2] = char(R);
        }
    }
}
void ImageFormatConvert::JpgToJpg(std::string path, int Height, int Width, int Stride)
{
     QString Qpath = QString::fromStdString(path);
     myQImage.load(Qpath);
}



ImageFormatConvert::ImageFormatConvert()
{

}
