#ifndef IMAGEFORMATCONVERT_H
#define IMAGEFORMATCONVERT_H
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <QString>
#include <QStringList>
#include <QDebug>

class ImageFormatConvert
{
public:
    ImageFormatConvert();
    void NV12ToJpg(QStringList paths,int Height=0,int Width=0,int Stride=0);
    void NV21ToJpg(QStringList paths,int Height=0,int Width=0,int Stride=0);
    void I444ToJpg(QStringList paths,int Height=0,int Width=0,int Stride=0);
    void YV24ToJpg(QStringList paths,int Height=0,int Width=0,int Stride=0);
    void I420ToJpg(QStringList paths,int Height=0,int Width=0,int Stride=0);
    void YV12ToJpg(QStringList paths,int Height=0,int Width=0,int Stride=0);

    void YUVToRGB(int Y,int U,int V);
};

#endif // IMAGEFORMATCONVERT_H
