from __future__ import print_function
from re import S
import time

# from pipython import GCSDevice, pitools

# import nidaqmx
# from nidaqmx.constants import AcquisitionType

import matplotlib.pyplot as plt
import numpy as np
from math import e
from scipy.interpolate import make_interp_spline as spline

import threading
import numpy as np
import sys
import matplotlib
matplotlib.use('Qt5Agg')
import matplotlib.pyplot as plt
from pylab import *
import scipy
mpl.rcParams['font.sans-serif'] = ['SimHei']
mpl.rcParams['axes.unicode_minus'] = False
# 使用 matplotlib中的FigureCanvas (在使用 Qt5 Backends中 FigureCanvas继承自QtWidgets.QWidget)
from matplotlib.backends.backend_qt5agg import FigureCanvasQTAgg as FigureCanvas
from PyQt5.QtWidgets import QWidget, QPushButton, QApplication
from PyQt5.QtCore import QTimer
import sys

from PyQt5 import QtCore, QtWidgets, QtGui
from PyQt5.QtWidgets import *
from PyQt5.QtWidgets import QWidget
from PyQt5.QtGui import QIcon
from PyQt5.QtCore import Qt


__signature__ = 0x817b611ba6dac7271d73efaae3380835
# PI设备属性
CONTROLLERNAME = 'C-863.12N'
STAGES = ['M-403.8DG', ]  # connect stages to axes
REFMODES = ['FPL', ]  # reference the connected stages

# with GCSDevice() as pidevice:
class App(QWidget):
    def __init__(self, parent=None):
        # 父类初始化方法
        super(App, self).__init__(parent)
        self.initUI()

    def initUI(self):
        self.setWindowTitle('动态演示')
        self.setFixedSize(1200, 700)
        self.setMinimumSize(1200, 700)
        self.setMaximumSize(1200, 700)
        # 几个QWidgets

        self.startBtn = QPushButton('开始')
        self.endBtn = QPushButton('结束')
        self.startBtn.clicked.connect(self.startTimer)
        self.endBtn.clicked.connect(self.endTimer)
        # 时间模块
        self.timer = QTimer(self)
        self.timer.timeout.connect(self.showTime)
        #图像模块
        
        self.figure = plt.figure()
        
        self.ax = self.figure.add_axes([0.1, 0.1, 0.8, 0.8])

        
        self.ax.yaxis.set_ticks([i for i in range(2)])

        self.canvas = FigureCanvas(self.figure)
        #垂直布局

        layout=QVBoxLayout()
        layout.addWidget(self.startBtn)
        layout.addWidget(self.endBtn)
        layout.addWidget( self.canvas )
        self.setLayout(layout)



        # 数组初始化
        self.max = 10
        self.data=[0 for i in range(self.max)]
        self.data[0] = -0.001
        self.data[1] = 0.01
        self.aix = [i for i in range(self.max)]
        #时间设置
        self.time = 1    #单位为毫秒
        self.pressure = 0
        self.thread_start_stop_flag = 1

        #初始化压力传感器部分
        # pidevice.ConnectUSB(serialnum='0021550491')
        # print('connected: {}'.format(pidevice.qIDN().strip()))
        # pitools.startup(pidevice, stages=STAGES, refmodes=REFMODES)
        # print("连接成功！")
        # self.position()
        # self.task = nidaqmx.Task()
        # self.task.ai_channels.add_ai_voltage_chan("cDAQ9185-2032267Mod3/ai0", max_val=10, min_val=0)
        # self.task.timing.cfg_samp_clk_timing(rate=100, sample_mode=AcquisitionType.FINITE, samps_per_chan=10)
        self.setValue = 1

        t = threading.Thread(target=self.ni_data_target,name='n')
        t.setDaemon(True)
        t.start()

    def position(self):
        t2 = threading.Thread(target=self.position_target)
        t2.setDaemon(True)
        t2.start()

    def position_target(self):
        while True:
            time.sleep(1)
            # position = pidevice.qPOS()
            position = 1
            for p in position:
                pos = position[p]
                print("位置:{:.3f}".format(pos))
                

    def ni_data_target(self):      
        while True:
            # pressure_data = self.task.read(number_of_samples_per_channel=1)
            self.pressure = randint(1,100)

    def setup_target(self):
        while self.thread_start_stop_flag:       
            if self.pressure > self.setValue:
                print('pressure(>setValue):', self.pressure)
                for i in range(100):

                    if self.pressure > self.setValue:

                        print('压力大：{}，下移'.format(self.pressure))
                        # pidevice.VEL('1', 0.001)
                        # pidevice.MVR(1, 0.001)
                           
                    else:        
                        print('压力小:{}，上移'.format(self.pressure))
                        # self.up_low_speed()
                        # pidevice.VEL('1', 0.01)
                        # pidevice.MVR(1, -0.01)
                    time.sleep(0.1)

                # while self.pressure:
                print('低速返回')
                # self.down_low_speed()
                # time.sleep(0.5)
                # pidevice.VEL('1', 0.05)
                # pidevice.MVR(1, 0.5)
                # pitools.waitontarget(pidevice, axes='1')

                # pidevice.SVO('1', 0)
                self.thread_start_stop_flag = 0
                
                
            # 位移会累加，最终超过位置限制。平台一直移动而不是停止
            else:
                    print('pressure(<0.149):', self.pressure)   
                    # self.up_midle_speed()    
                    # pidevice.VEL('1', 0.1)
                    # pidevice.MVR(1, -0.01)



    # # 因为会出现位移限制，故采用速度多线程
    # def up_low_speed(self):
    #     t = threading.Thread(target=self.up_low_speed_target)
    #     t.setDaemon(True)
    #     t.start()
    
    # def up_low_speed_target(self):
    #     pidevice.VEL('1', 0.001)
    #     pidevice.MVR(1, -0.001)
    #     pitools.waitontarget(pidevice, axes='1')

    # def up_midle_speed(self):
    #     t = threading.Thread(target=self.up_midle_speed_target)
    #     t.setDaemon(True)
    #     t.start()
    
    # def up_midle_speed_target(self):
    #     pidevice.VEL('1', 0.5)
    #     pidevice.MVR(1, -0.5)
    #     pitools.waitontarget(pidevice, axes='1')

    # def down_low_speed(self):
    #     t = threading.Thread(target=self.down_low_speed_target)
    #     t.setDaemon(True)
    #     t.start()
    
    # def down_low_speed_target(self):
    #     pidevice.VEL('1', 0.001)
    #     pidevice.MVR(1, 0.001)
    #     pitools.waitontarget(pidevice, axes='1')

    # def down_midle_speed(self):
    #     t = threading.Thread(target=self.down_midle_speed_target)
    #     t.setDaemon(True)
    #     t.start()
    
    # def down_midle_speed_target(self):
    #     pidevice.VEL('1', 0.5)
    #     pidevice.MVR(1, 0.5)
    #     pitools.waitontarget(pidevice, axes='1')
    
    # def back(self):
    #     t = threading.Thread(target=self.back_target)
    #     t.setDaemon(True)
    #     t.start()

    # def back_target(self):
    #     pidevice.VEL('1', 1)
    #     pidevice.MVR(1, 1)
    #     pitools.waitontarget(pidevice, axes='1')






    def showTime(self):
        if self.thread_start_stop_flag:
            self.data.append(self.pressure)#数组更新
            # self.data = self.data[1:self.max]
            # self.aix.append(self.aix[-1]+1)
            # self.aix = self.aix[1:self.max]
            data_arr = np.array(self.data)
            smooth_x = np.linspace(data_arr.min(),data_arr.max(),len(self.data))
            smooth = scipy.interpolate.make_interp_spline(smooth_x,self.data)(smooth_x)
            self.ax.clear()
            self.ax.set_xlabel('time/S')
            self.ax.set_ylabel('pressure/N')
            self.ax.yaxis.set_ticks([i for i in range(self.setValue+2)])
            #plt.grid(True)
            self.ax.plot(smooth_x,smooth)
        else:
            self.startBtn.setEnabled(True)#开始按钮变为可用
            self.endBtn.setEnabled(False)#结束按钮变为可用
    

        self.canvas.draw()
    # 启动函数
    def startTimer(self):
        # pidevice.SVO('1', 1)
        self.thread_start_stop_flag  = 1 
        self.setup()
        self.timer.start(self.time)
        self.startBtn.setEnabled(False)#开始按钮变为禁用
        self.endBtn.setEnabled(True)#结束按钮变为可用
    
    def setup(self):
        t = threading.Thread(target=self.setup_target,name='t')
        t.setDaemon(True)
        t.start()

    def endTimer(self):
        self.svo_off()
        self.thread_start_stop_flag  = 0
        self.timer.stop()#计时停止
        self.startBtn.setEnabled(True)#开始按钮变为可用
        self.endBtn.setEnabled(False)#结束按钮变为可用
        #self.x=[]#清空数组
        
    def svo_off(self):
        t2 = threading.Thread(target=self.svo_off_target)
        t2.setDaemon(True)
        t2.start()

    def svo_off_target(self):
        # pidevice.SVO('1', 0)
        ...

# 运行程序
if __name__ == '__main__':
    # QApplication.setAttribute(Qt.AA_EnableHighDpiScaling)
    app = QApplication(sys.argv)
    main_window = App()
    main_window.show()
    app.exec()