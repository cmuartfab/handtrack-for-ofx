#include "ofApp.h"

#include <opencv2/opencv.hpp>

#include "FeatureComputer.hpp"
#include "Classifier.h"
#include "LcBasic.h"
#include "HandDetector.hpp"

using namespace std;
using namespace cv;

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){
    if(TRAIN_MODEL)
    {
        cout << "Training...\n";
        HandDetector hd;
        hd.loadMaskFilenames(msk_prefix);
        hd.trainModels(basename, img_prefix, msk_prefix,model_prefix,globfeat_prefix,feature_set,num_models_to_train,target_width);
        cout << "Done Training...\n";
    }
    
    
    
    if(TEST_MODEL)
    {
        cout << "Testing...\n";
        string vid_filename		= root + "vid/"		+ basename + ".avi";
        
        HandDetector hd;
        hd.testInitialize(model_prefix,globfeat_prefix,feature_set,num_models_to_average,target_width);
        
        VideoCapture cap(0);
        Mat im;
        Mat ppr;
        
        VideoWriter avi;
        
        while(1)
        {
            cap >>(im);
            
            if(!im.data) break;
            //cap >> im; if(!im.data) break; // skip frames with these
            //cap >> im; if(!im.data) break;
            //cap >> im; if(!im.data) break;
            
            hd.test(im,num_models_to_average,step_size);
            
            
            // Different ways to visualize the results
            // hd._response_img (float probabilities in a matrix)
            // hd._blur (blurred version of _response_img)
            
            
            int SHOW_RAW_PROBABILITY = 1;
            if(SHOW_RAW_PROBABILITY)
            {
                Mat raw_prob;
                hd.colormap(hd._response_img,raw_prob,0);
                imshow("probability",raw_prob);	// color map of probability
            }
            
            int SHOW_BLUR_PROBABILITY = 1;
            if(SHOW_BLUR_PROBABILITY)
            {
                Mat pp_res;
                hd.postprocess(hd._response_img);
                imshow("blurred",hd._blu);		// colormap of blurred probability
            }
            
            int SHOW_BINARY_CONTOUR = 1;
            if(SHOW_BINARY_CONTOUR)
            {
                Mat pp_contour = hd.postprocess(hd._response_img);		// binary contour
                hd.colormap(pp_contour,pp_contour,0);					// colormap of contour
                imshow("contour",pp_contour);
            }
            
            int SHOW_RES_ALPHA_BLEND = 1;
            if(SHOW_RES_ALPHA_BLEND)
            {
                Mat pp_res = hd.postprocess(hd._response_img);
                hd.colormap(pp_res,pp_res,0);
                resize(pp_res,pp_res,im.size(),0,0,INTER_LINEAR);
                addWeighted(im,0.7,pp_res,0.3,0,pp_res);				// alpha blend of image and binary contour
                imshow("alpha_res",pp_res);
                
            }
            
            
            /*
             if(!avi.isOpened())
             {
             stringstream ss;
             ss.str("");
             ss << root + "/vis/" + basename + "_skin.avi";
             int fourcc = avi.fourcc('F','L','V','1');
             avi.open(ss.str(),fourcc,30,ppr.size(),true);
             }
             avi << ppr;
             */
            
            
            waitKey(1);
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
