#Python Computer Vision

##Basic Image Handling and Processing
Computer Vision is the automated extraction of information from images.

Mimic human Vision

Use data and statistical approach

Install OpenCV

```
$ sudo apt-get install python-numpy
$ sudo apt-get install python-scipy
$ sudo apt-get install libopencv-*
$ sudo apt-get install python-opencv
```

Reading Writing Image file

convert an image from PNG to JPEG:
```python
import cv2
image = cv2.imread('MyPic.png')
cv2.imwrite('MyPic.jpg', image)
```

let's load a PNG as a grayscale image (losing any color information in the process) and, then,
save it as a grayscale PNG image:
```python
import cv2
grayImage = cv2.imread('MyPic.png', cv2.CV_LOAD_IMAGE_GRAYSCALE)
cv2.imwrite('MyPicGray.png', grayImage)
```
