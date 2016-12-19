#include <iostream>
#include <cmath>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <cv.h>

using namespace cv;
using namespace std;

int main() {
    Mat img = cvLoadImage("/home/azamat/a/len.png");
    cvtColor(img, img, CV_RGB2GRAY);
    Mat res = img.clone();
    double normal[256], q[256], user[256], pix[256], s[256], s_[256], q_[256], temp[256];
    int raz = 256, pos1 = 0, pos2 = 0, b = 0, l = 0, con = 0;;

    for (int x = 0; x < 256; x++) normal[x] = 0;
    for (int x = 0; x < img.rows; x++) for (int y = 0; y < img.cols; y++) normal[(img.at<uchar>(x, y))] += 1;

    for (int x = 0; x < 256; x++) {
        normal[x] /= (img.cols * img.rows);
        q[x] = round((255 * normal[x]));
//        cout<<x<<"-->"<<normal [x]<<"  s --> "<<q[x]<<endl;
    }

    for (int x = 0; x < 256; x++) {
        if (x <= 28) {
            user[x] = 0.6;
            pix[x] = 28;
        } else if (x > 56 && x <= 84) {
            user[x] = 1.0;
            pix[x] = 56;
        } else if (x > 86 && x <= 112) {
            user[x] = 0.8;
            pix[x] = 112;
        } else if (x > 86 && x <= 112) {
            user[x] = 0.8;
            pix[x] = 112;
        } else if (x > 112 && x <= 140) {
            user[x] = 0.75;
            pix[x] = 140;
        } else if (x > 140 && x <= 168) {
            user[x] = 0.0;
            pix[x] = 168;
        } else if (x > 168 && x <= 196) {
            user[x] = 0.0;
            pix[x] = 196;
        } else if (x > 196 && x <= 224) {
            user[x] = 0.05;
            pix[x] = 224;
        } else if (x > 224 && x <= 255) {
            user[x] = 0.05;
            pix[x] = 255;
        }
    }

    for (int x = 0; x < 256; x++) s[x] = round((255 * user[x]));
    for (int x = 0; x < 256; x++) temp[x] = q[x];

    for (int x = 0; x < 256; x++) {
        for (int y = 0; y < 256; y++) {
            if (temp[y] != -1 && temp[y] == s[x]) {
                for (int z = 0; z <= l; z++) {
                    if (q_[z] == s[x]) {
//                        cout<<"BLa"<<endl;
                    }
                }
                if (con == 0) {
                    s_[l] = temp[y];
                    q_[l] = s[x];
                    l++;
                    for (int x = 0; x < res.rows; x++)
                        for (int z = 0; z < res.cols; z++)
                            for (int y = 0; y < l; y++)
                                if (q[res.at<uchar>(x, z)] == s_[y]) res.at<uchar>(x, z) = (uchar) pix[y];

                    namedWindow("Original", CV_WINDOW_AUTOSIZE);
                    namedWindow("Result", CV_WINDOW_AUTOSIZE);
                    imshow("Original", img);
                    imshow("Result", res);
                    waitKey(0);
                    return 0;
                }
            }
        }
    }
}