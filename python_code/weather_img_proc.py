#! /usr/bin/python3

from PIL import Image
import numpy as np
import scipy
from scipy import ndimage
import matplotlib
import matplotlib.pyplot as plt
import imageio
from scipy import misc
from skimage import data, color
from skimage.transform import rescale, resize, downscale_local_mean
import h5py
from numpy import genfromtxt

im = imageio.imread("/home/morgan/ussat_1280x720.jpg?v=ap")

imageio.imwrite('/home/morgan/ussat_1280x720.png', im) 

im = misc.imread("/home/morgan/ussat_1280x720.png")

image = scipy.misc.imresize(im, size=(180,320))

img = Image.fromarray(image)

img_vec = np.reshape(img, (180*320*3, 1)) 

print(img_vec.shape)
