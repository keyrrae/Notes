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

Provided that an image has 8 bits per channel, we can cast it to a standard Python
bytearray , which is one-dimensional:
byteArray = bytearray(image)
Conversely, provided that bytearray contains bytes in an appropriate order, we can
cast and then reshape it to get a numpy.array type that is an image:
grayImage = numpy.array(grayByteArray).reshape(height, width)
bgrImage = numpy.array(bgrByteArray).reshape(height, width, 3)
As a more complete example, let's convert bytearray containing random bytes to a
grayscale image and a BGR image:
import cv2
import numpy
import os
# Make an array of 120,000 random bytes.
randomByteArray = bytearray(os.urandom(120000))flatNumpyArray = numpy.array(randomByteArray)
# Convert the array to make a 400x300 grayscale image.
grayImage = flatNumpyArray.reshape(300, 400)
cv2.imwrite('RandomGray.png', grayImage)
# Convert the array to make a 400x100 color image.
bgrImage = flatNumpyArray.reshape(100, 400, 3)
cv2.imwrite('RandomColor.png', bgrImage)
After running this script, we should have a pair of randomly generated images,
RandomGray.png and RandomColor.png , in the script's directory
