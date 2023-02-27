import sys
import ctypes
from PyQt5.QtCore import *
from PyQt5.QtGui import *
from PyQt5.QtWidgets import *
from PyQt5.QtCore import QTimer
from PyQt5.QtWidgets import *

class Menu(QWidget):
    def __init__(self):
        super().__init__()
        # self.color = "FF0000"
        self.initUI()
    
    def initUI(self):
        self.resize(400,200)

        self.button = QPushButton(self)
        self.button.move(160,80)
        self.button.resize(50,50)
        self.button.setStyleSheet('''QPushButton{background:#FF0000;border-radius:25px;}''')#注意这里的圆角要设置为大小的一般

        self.switch_btn = QPushButton("转换",self)
        self.switch_btn.clicked.connect(self.switch_color)
    def switch_color(self):
        self.button.setStyleSheet('''QPushButton{background:#FF00FF;border-radius:25px;}''')

if __name__ == "__main__":
    app = QApplication(sys.argv)
    win = Menu()
    win.show()
    sys.exit(app.exec_())
        