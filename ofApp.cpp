#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(39);
	ofSetCircleResolution(60);
	ofSetLineWidth(2);

	this->font.loadFont("fonts/msgothic.ttc", 40, true, true, true);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);

	int radius = 250;
	for (int deg = 0; deg < 360; deg += 8) {

		auto point = glm::vec2(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));
		
		ofPushMatrix();
		ofTranslate(point);
		ofRotate(deg - 270);

		string word = string{ (char)ofMap(ofNoise(point.x * 0.001, point.y * 0.001, ofGetFrameNum() * 0.005), 0, 1, 65, 91) };
		this->font.drawString(word, 0, 0);

		ofPopMatrix();
	}

	ofFill();
	ofBeginShape();
	for (int deg = 0; deg < 360; deg += 1) {

		auto point = glm::vec2(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));
		auto radius = ofMap(ofNoise(point.x * 0.001, point.y * 0.001, ofGetFrameNum() * 0.005), 0, 1, 50, 150);

		ofVertex(glm::vec2(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD)));
	}
	ofEndShape(true);

	ofNoFill();
	ofDrawCircle(glm::vec2(), radius - 10);
	ofDrawCircle(glm::vec2(), radius + 50);
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}