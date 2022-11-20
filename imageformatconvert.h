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

typedef enum ImageTypeEn
{
    NV12 = 0,
    NV21,
    I444,
    YV24,
    JPG
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
    void NV12ToJpg(QStringList paths,int Height=0,int Width=0,int Stride=0);
    void NV21ToJpg(QStringList paths,int Height=0,int Width=0,int Stride=0);
    void I444ToJpg(QStringList paths,int Height=0,int Width=0,int Stride=0);
    void YV24ToJpg(QStringList paths,int Height=0,int Width=0,int Stride=0);
    void I420ToJpg(QStringList paths,int Height=0,int Width=0,int Stride=0);
    void YV12ToJpg(QStringList paths,int Height=0,int Width=0,int Stride=0);
    void JpgToJpg(QStringList paths,int Height=0,int Width=0,int Stride=0);

    void YUVToRGB(int Y,int U,int V);
};

#endif // IMAGEFORMATCONVERT_H
