# Hand Tracker
This repository contains code for performing foreground/background segmentation of the human hand in videos from an egocentric perspective, using pixel-level classification.  This project is based on [work by Cheng Li and Kris Kitani](http://www.cs.cmu.edu/~kkitani/datasets/), and described in the publication below: 

Li, Cheng, and Kris M. Kitani. "Pixel-level hand detection in ego-centric videos." Proceedings of the IEEE Conference on Computer Vision and Pattern Recognition. 2013. [(pdf)](http://www.cs.cmu.edu/~kkitani/pdf/LK-CVPR13.pdf)

## Training Data
Using this app requires training data.  This project comes with sample training data, but you can create your own by labeling images using [Kitani's 'Labeling Tool'](http://www.cs.cmu.edu/~kkitani/perpix/code_grabcut/), which we have also ported to work with the latest Xcode IDE. You can find it [here](https://github.com/cmuartfab/grabcut).

## Dependencies

### ofx addons
This project requires:
* ofxCV
* ofxOpenCV
* ofxGUI

### IDE
This project is ported to work in Apple's [Xcode]
Hand Tracker uses Xcode which can be installed from the Mac App Store [here](https://developer.apple.com/xcode/downloads/).

This project has been tested with openframeworks 0.9.4


## Running the Project
* With Xcode open, on the top toolbar go to `Xcode->preferences->Text Editing`. Check `Show Line Numbers`.
* In `main.cpp`, change 
	
```c++
bool TRAIN_MODEL = 1;
bool TEST_MODEL  = 0;
```

* In `main.cpp`, change line 36 with the absolute file path to the Hand Tracker project folder.
	
```c++
string root = "ABSOLUTE PATH TO PROJECT FOLDER"; 
```

* Click Run to run the training model. When completed you should see .xml files in `models/` and `globfeat/`
* In `main.cpp`, change lines 13 and 14 to the following to run testing:
	
```c++
bool TRAIN_MODEL = 0;
bool TEST_MODEL  = 1;
```

* Click Run to run the testing model. This should open your laptop's webcam and shade your hands with a deep purple color in real time. 
