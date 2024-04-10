from PyQt5 import QtWidgets, uic
from PyQt5.QtCore import pyqtSlot
from motionViewController import Ui_MainWindow
import sys

motorNamesArray = ["headPitchBox", "headYawBox",
"elbowPitchRightBox", "shoulderRollRightBox", "shoulderPitchRightBox",
"elbowPitchLeftBox", "shoulderRollLeftBox", "shoulderPitchLeftBox", 
"hipPitchRightBox", "hipRollRightBox", "hipYawRightBox", "hipPitchLeftBox", 
"hipRollLeftBox", "hipYawLeftBox", 
"kneePitchRightBox", 
"kneePitchLeftBox", 
"ankleRollLeftBox", "anklePitchLeftBox", 
"ankleRollRightBox", "anklePitchRightBox"]


oldMotorValues = []


class motionToolWindow(QtWidgets.QMainWindow):
    def __init__(self):
        super(motionToolWindow, self).__init__()
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)

        # Buttons 
        self.clearButton = self.findChild(QtWidgets.QPushButton, 'clearButton')
        self.clearButton.clicked.connect(self.clearButtonClicked) 

        self.setButton = self.findChild(QtWidgets.QPushButton, 'setButton')
        self.setButton.clicked.connect(self.setButtonClicked) 
        
        self.pos0Button = self.findChild(QtWidgets.QPushButton, 'pos0Button')
        self.pos0Button.clicked.connect(self.pos0ButtonClicked) 

        self.show()


    def clearButtonClicked(self):
        global motorNamesArray
        print('clear Button Clicked')
        for x in motorNamesArray:
            # print(motorNamesArray)
            self.nameOfMotors = self.findChild(QtWidgets.QDoubleSpinBox, x)
            self.nameOfMotors.setValue(0.0)
            print(self.nameOfMotors.value())


    def setButtonClicked(self):
        for nameOfObject in motorNamesArray:
            self.nameOfMotors = self.findChild(QtWidgets.QDoubleSpinBox, nameOfObject)
            currentValue = self.nameOfMotors.value()
            self.nameOfMotors.setValue(currentValue)
            print("set " + str(currentValue) + " for " + str(nameOfObject))
            print('set Button Clicked')
        
        _set()
        

    def pos0ButtonClicked(self):
        print('pos0 Button Clicked')


def get():
    print("get func called")

def _set():
    print("_set func called")

if __name__ == '__main__':
    app = QtWidgets.QApplication([])
    application = motionToolWindow()
    application.show()
    sys.exit(app.exec())