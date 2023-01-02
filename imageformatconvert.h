#ifndef IMAGEFORMATCONVERT_H
#define IMAGEFORMATCONVERT_H
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/core.hpp"
#include <QString>
#include <QStringList>
#include <QDebug>
#include <QImage>
#include "Demosaicing.h"

typedef enum ImageTypeEn
{
    NV12 = 0,
    NV21,
    I444,
    YV24,
    JPG,
    RAW
}ImageType_E;


class ImageFormatConvert
{
public:
    cv::Mat jpgImg;
    QImage myQImage;
    unsigned int ImgW;
    unsigned int ImgH;
    unsigned int ImgStride;
    ImageFormatConvert();
    void NV12ToJpg(std::string path,int Height=0,int Width=0,int Stride=0);
    void NV21ToJpg(std::string path,int Height=0,int Width=0,int Stride=0);
    void I444ToJpg(std::string path,int Height=0,int Width=0,int Stride=0);
    void YV24ToJpg(std::string path,int Height=0,int Width=0,int Stride=0);
    void I420ToJpg(std::string path,int Height=0,int Width=0,int Stride=0);
    void YV12ToJpg(std::string path,int Height=0,int Width=0,int Stride=0);
    void JpgToJpg(std::string path,int Height=0,int Width=0,int Stride=0);
    void RawTojpg(std::string path,int Height=0,int Width=0,int Stride=0);

    void YUVToRGB(int Y,int U,int V);
};

#endif // IMAGEFORMATCONVERT_H
