# This Python file uses the following encoding: utf-8
import sys
from pathlib import Path

from PySide6.QtGui import QGuiApplication
from PySide6.QtQml import QQmlApplicationEngine
import interfaceui as ifui
from back import backmongo as mng
if __name__ == "__main__":
    app = QGuiApplication(sys.argv)
    engine = QQmlApplicationEngine()
    interface = ifui.InterFaceUi()
    mongodb = mng.BackMongo('localhost',27017)
    if (mongodb.connction()):
        interface.dataSignal.connect(mongodb.add_to_database)
    engine.rootContext().setContextProperty("_interface",interface)
    qml_file = Path(__file__).resolve().parent / "ui/main.qml"
    engine.load(qml_file)
    if not engine.rootObjects():
        sys.exit(-1)
    sys.exit(app.exec())
