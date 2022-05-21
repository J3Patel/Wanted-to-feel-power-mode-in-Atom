from pynput.mouse import Button, Listener
import serial
from pynput import keyboard
from threading import Thread
import signal

arduino = serial.Serial('COM12', 9600)
listener_thread = None
interrupted = False

def on_click(x, y, button, pressed):
    if button == Button.left:
        if pressed == True:
            arduino.write(bytes("2", 'utf-8'))
        else:
            arduino.write(bytes("1", 'utf-8'))
    elif button == Button.middle:
        return False

with Listener(on_click=on_click) as listener:
    listener.join()

#listener_thread = keyboard.Listener(on_press=on_press, on_release=on_release)
#listener_thread.start()
