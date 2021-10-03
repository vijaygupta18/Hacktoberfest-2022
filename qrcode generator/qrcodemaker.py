import pyqrcode
import png
from pyqrcode import QRCode


def textToQR(text):
    qrcode = pyqrcode.create(text)
    qrcode.png("qrcode.png", 10)


text = input("Enter the text:")

textToQR(text)