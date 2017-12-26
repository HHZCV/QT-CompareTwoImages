#include "mainwindow.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>
#include <QFileDialog>
#include <QDebug>
#include <QTextEdit>
#include "cvimagewidget.h"
#include <QMainWindow>
#include <QDialog>
#include <QMessageBox>
using namespace cv;
using namespace std;

class QFileDialogTester : public QWidget
{
public:
  std::string openFile(const QString windowText)
  {
    QString filename =  QFileDialog::getOpenFileName(
          this,
          windowText,
          QDir::currentPath(),
          "All files (*.*) ;; Document files (*.doc *.rtf);; PNG files (*.png)");

    return filename.toStdString();
  }
};



void CompareTwoImages(){

    /// Read image ( same size, same type )
    ///
    QFileDialogTester test;

    string img1Name,img2Name;
    Mat src1, src2, diff;
    Mat src2Copy;

    img1Name=test.openFile("Select First Image");   
    img2Name=test.openFile("Select Second Image");

    if (img1Name==img2Name){
        QMessageBox *msgBox=new QMessageBox();
        msgBox->setText("The same file is selected twice!");
        msgBox->show();
    }
     src1 = imread(img1Name);
     src2 = imread(img2Name);
     src2.copyTo(src2Copy);

     namedWindow(img1Name,1);
     imshow(img1Name,src1);
     namedWindow(img2Name,1);
     imshow(img2Name,src2);
/*
     QMainWindow img1WD,img2WD;
     CVImageWidget* img1Widget = new CVImageWidget();
     CVImageWidget* img2Widget = new CVImageWidget();
     img1WD.setWindowTitle(QString::fromStdString(img1Name));
     img2WD.setWindowTitle(QString::fromStdString(img2Name));
     img1WD.setCentralWidget(img1Widget);
     img1Widget->showImage(src1);
     img1WD.show();
     img2WD.setCentralWidget(img2Widget);
     img2Widget->showImage(src2);
     img2WD.show();
*/
     absdiff(src1,src2,diff);
     Mat bgr[3],binarydiff;   //destination array
     split(diff,bgr);//split source
     binarydiff=bgr[0]+bgr[1]+bgr[2];
     Mat diffLocation;
     findNonZero(binarydiff,diffLocation);

     Mat diffMask;
     threshold(binarydiff,diffMask,0,255,0);
     namedWindow("Locations of Different Pixels",1);
     imshow("Locations of Different Pixels",diffMask);
     /*
     QMainWindow diffMaskWD;
     CVImageWidget* diffWidget = new CVImageWidget();
     diffMaskWD.setWindowTitle("Locations of Different Pixels");
     diffMaskWD.setCentralWidget(diffWidget);
     diffWidget->showImage(diffMask);
     diffMaskWD.show();
*/
     for(int i=0;int(i<diffLocation.total());i++){
         circle(src2Copy,diffLocation.at<Point>(i),1,Scalar(255,255,255),1,8,0);
     }
     namedWindow("Different Pixels on Image2",1);
     imshow("Different Pixels on Image2",src2Copy);
     /*
     QMainWindow diffImg2WD;
     CVImageWidget* diffImg2Widget = new CVImageWidget();
     diffImg2WD.setWindowTitle("Locations of Different Pixels on Image2");
     diffImg2WD.setCentralWidget(diffImg2Widget);
     diffImg2Widget->showImage(src2Copy);
     diffImg2WD.show();
*/
     QTextEdit *txt = new QTextEdit();
      txt->setText("Activate any image window and press any key to close all windows.");
      txt->append("Different Pixels Values:");
      if(int(diffLocation.total()==0)){
          txt->append("None. Two images are identical.");
      }else{

     for(int i=0;i<int(diffLocation.total());i++){
         Vec3b intensitySrc1, intensitySrc2;
         std::string strIntensitySrc1,strIntensitySrc2,pixelList;
         intensitySrc1=src1.at<Vec3b>(diffLocation.at<Point>(i));
         intensitySrc2=src2.at<Vec3b>(diffLocation.at<Point>(i));
         strIntensitySrc1="[ "+std::to_string(intensitySrc1[0])+", "+
                 std::to_string(intensitySrc1[1])+", "+std::to_string((intensitySrc1[2]))+" ]";
         strIntensitySrc2="[ "+std::to_string(intensitySrc2[0])+", "+
                 std::to_string(intensitySrc2[1])+", "+std::to_string((intensitySrc2[2]))+" ]";
         pixelList=std::to_string(i+1)+". Image1 pixel value:"+strIntensitySrc1+
                 ", Image2 pixel value:"+strIntensitySrc2;
         txt->append(QString::fromStdString(pixelList));
        // cout<<(i+1)<<". Image1 pixel value:"<<intensitySrc1<<", Image2 pixel value:"<<intensitySrc2<<endl;

      }
      }
     txt->show();
    // cout<<"Press any key to exit."<<endl;

     waitKey(0);
     destroyAllWindows();

}



