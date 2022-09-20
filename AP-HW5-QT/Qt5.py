import sys
from PyQt5 import uic
from PyQt5 import QtWidgets 
from PyQt5.QtWidgets import QApplication ,QWidget,QLabel,QPushButton,QMainWindow
import os
import sqlite3
import requests,json
import geocoder
from PyQt5 import QtCore
from PyQt5.QtCore import QThread
from PyQt5.QtGui import QPixmap
from PyQt5 import QtGui
import io
from PIL import Image
from PIL.ImageQt import ImageQt 
myloc = geocoder.ip('me')
a=myloc.latlng

#r = requests.get("https://map.ir/static?width=700&height=400&zoom_level=12&markers=color%3Aorigin%7Clabel%3A%D9%85%D9%BE%7C51.422174%2C35.732469")

r = requests.get("https://map.ir")


Form = uic.loadUiType(os.path.join(os.getcwd(),'gui.ui'))[0]
Form_register = uic.loadUiType(os.path.join(os.getcwd(),'gui_register.ui'))[0]
Form_map = uic.loadUiType(os.path.join(os.getcwd(),'gui_map.ui'))[0]

connection = sqlite3.connect(r'C:\Users\SOS\Desktop\sixth term\AP\hws\HW5\HW5-Qt\QtDb.db')
c=connection.cursor()
#c.execute("drop table users")
c.execute('CREATE TABLE IF NOT EXISTS users(id integer AUTO_INCREMENT PRIMARY KEY,name varchar(255) ,phone varchar(255),username varchar(255) ,password varchar(255) ) ')
c.execute('CREATE TABLE IF NOT EXISTS locations(id integer AUTO_INCREMENT PRIMARY KEY,user_id integer,lat integer,lon integer)')

class Introwindow(Form,QMainWindow):
    signal = QtCore.pyqtSignal(str)
    def __init__(self):
        Form.__init__(self)
        QMainWindow.__init__(self)
        self.setupUi(self)
        self.pushButton.clicked.connect(self.login)
        self.pushButton_2.clicked.connect(self.start)
        self.register=Register()
        #self.map=Map()
    def start(self):
        self.close()
        self.register.show()
    
    def login(self):
        #select users information
        self.stmt = "select name ,phone,username,password from users where username =? and password = ?  "
        self.username =self.textEdit.toPlainText()
        self.password = self.textEdit_2.toPlainText()
        self.map=Map(self.username)
        
        
        self.args = (self.username,self.password)
        c.execute(self.stmt,self.args)
        self.rows = c.fetchall()
        #find current location
        self.info = requests.get('http://ipinfo.io/json').json()
        self.lat = self.info['loc'].split(',')[0]
        self.lon = self.info['loc'].split(',')[1]
        #print(self.lon)
        #insert location 
        self.stmt = "insert into locations(user_id,lat,lon) VALUES(?,?,?)"
        self.args =(self.username , self.lat,self.lon)
        c.execute(self.stmt,self.args)
        connection.commit()
        #select locations information 
        self.stmt = "select user_id ,lat,lon from locations where user_id =? "
        self.args = (self.username,)
        c.execute(self.stmt,self.args)
        self.rows_loc = c.fetchall()
        
        #loclon = self.rows_loc
        #print(loclon[0][1])
        #print users
        for row in self.rows:
            print(row)
        #print locations
        for row in self.rows_loc:
            print(row)
            
        self.close()
        self.map.show()

#
#class PThread(QThread):
#    update_plot = QtCore.pyqtSignal(int)
#    
#    def __init__(self):
#        QThread.__init__(self)
#    def run(self):
#        self.update_plot.emit(self.username)


        
class Register(Form_register,QMainWindow):
    def __init__(self):
        Form.__init__(self)
        QMainWindow.__init__(self)
        self.setupUi(self)
        
        self.pushButton.clicked.connect(self.start)
    
    def start(self):
        
        #self.stmt = "select name ,phone,username,password from users where username =(?) "
        #self.userId ='r'
        
        #self.args = (self.userId,)
        #c.execute(self.stmt,self.args)
        #self.rows = c.fetchall()
        
        #for row in self.rows:
        #    print(row)


        
        self.name = self.textEdit_2.toPlainText()
        self.phone = self.textEdit_3.toPlainText()
        self.username = self.textEdit_4.toPlainText()
        self.password = self.textEdit_5.toPlainText()
        
        print(f"{self.name}")
        self.stmt = "insert into users(name,phone,username,password) VALUES(?,?,?,?)"
        self.args =(self.name , self.phone,self.username,self.password)
        c.execute(self.stmt,self.args)
        connection.commit()        
        #go to login page after register
        self.close()
        #self.login.show()

class Map(Form_map,QMainWindow,QWidget):
    def __init__(self,vv):
        Form.__init__(self)
        QMainWindow.__init__(self)
        self.setupUi(self)
        
        
        print('ggg')
        print(vv)
        print('hhh')
        
        #Request to find current locations
        self.info = requests.get('http://ipinfo.io/json').json()
        self.lat = self.info['loc'].split(',')[0]
        self.lon = self.info['loc'].split(',')[1]
        #set Text of label based on current location
        self.label_5.setText( str(self.lat) )
        self.label_6.setText( str(self.lon) )
        #set text of label based on username
        self.label_8.setText(str(vv))
    
        #Request to get map from map.ir
        self.response = requests.get('https://map.ir/static',params = {'width':450, 'height':450,'zoom_level':12,'markers':'color:origin|label:Map|'+str(self.lon)+','+str(self.lat)},headers={'x-api-key':'eyJ0eXAiOiJKV1QiLCJhbGciOiJSUzI1NiIsImp0aSI6IjU4ZDZjNGQ4YTFmY2M1N2U2OWEzOTQ2MjA3Mjg2YmMzZjVkOGFkOWMwOWNiMTVlNjVhMmE2MTk3MjM0NzQyNDk3MWUwYTI5YjEyMGFmNTRmIn0.eyJhdWQiOiJteWF3ZXNvbWVhcHAiLCJqdGkiOiI1OGQ2YzRkOGExZmNjNTdlNjlhMzk0NjIwNzI4NmJjM2Y1ZDhhZDljMDljYjE1ZTY1YTJhNjE5NzIzNDc0MjQ5NzFlMGEyOWIxMjBhZjU0ZiIsImlhdCI6MTU1ODE2MTAwMSwibmJmIjoxNTU4MTYxMDAxLCJleHAiOjE1NTgxNjQ2MDEsInN1YiI6IiIsInNjb3BlcyI6WyJiYXNpYyIsImVtYWlsIl19.dEvjipQtrDBcIT9N0BJnH_ds70Z9rE3tR6Nkyt0y0_VFlXq8VD-DsCUy5IRfThaujghvcxLZE6DD_pS5PnkFzfx2tKwJpfJjHhztWxZyrnWnmHd7u6zBkXnaCE4_Sa0jqEu797xnslkOjUoim-4sDkNn6kNaVkvLHTtQj6mpkTZUujkpi6y_UZplfNGR0erWv9UfhsjUwhcrIULCqJPDKjDvIJd8817aREfueQiCu92kmE-ez-jZKPgS93PBIc3KO8KSQzSHg4gn36EOFUeCN8ra0Obfr-gfcz605Ty4DKFUz3mXZRCRViBbNFRNSiSnml3gn1l3oC9GAgYomseUUQ'})
        self.img = self.response.content
        #convert bytes array to PngImageFile
        image = Image.open(io.BytesIO(self.img))
        #convert PngImageFile to png
        qimage = ImageQt(image)
        #add image of map to label
        pixmap = QtGui.QPixmap.fromImage(qimage)         
        self.label_9.setPixmap(pixmap)
        #self.resize(pixmap.width(),pixmap.height())
    
        #self.thread = PThread()
        #self.thread.update_plot.connect(self.update)
        #def update(self,num):
        #    print(num)
        #    print('100')
        
        #select from location to add to tabel
        self.stmt = "select user_id ,lat,lon from locations where user_id =? "
        self.args = (vv,)
        c.execute(self.stmt,self.args)
        self.rows_loc = c.fetchall()
        
        print('YYY')
        print(self.rows_loc)
        for i in range(len(self.rows_loc)):
            
            self.rowPosition = self.tableWidget.rowCount()
            self.tableWidget.insertRow(self.rowPosition)
            
            self.tableWidget.setItem(self.rowPosition , 0, QtWidgets.QTableWidgetItem(str(self.rows_loc[i][1])))
            self.tableWidget.setItem(self.rowPosition , 1, QtWidgets.QTableWidgetItem(str(self.rows_loc[i][2])))
            self.tableWidget.setItem(self.rowPosition , 2, QtWidgets.QTableWidgetItem("2019-01-21"))

app = QApplication(sys.argv)
w=Introwindow()
w.show()
#w=QWidget()
#w.resize(250,100)
#w.move(100,100)
#w.setwindowTitle("alireza")
#w.show()

sys.exit(app.exec())