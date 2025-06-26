# This Python file uses the following encoding: utf-8
import sys
from pathlib import Path

from PySide6.QtGui import QGuiApplication
from PySide6.QtQml import QQmlApplicationEngine
import interfaceui as ifui
import listmodel as model
from back import backmongo as mng

if __name__ == "__main__":
    app = QGuiApplication(sys.argv)
    engine = QQmlApplicationEngine()

    interface = ifui.InterFaceUi()
    mongodb = mng.BackMongo('localhost', 27017)

    if mongodb.connction():
        mongo_data = mongodb.display_data()
        listmodel = model.ListModel(mongo_data)

        # Connect signal to refresh model after insert
        def on_data_added(new_item):
            mongodb.add_to_database(new_item)
            new_data = mongodb.display_data()
            listmodel.refreshFromMongo(new_data)
        def on_search(item):
            dic =mongodb.search(item)
            for item in dic:
                item.pop("_id", None)
              
            listmodel.refreshFromMongo([])
            listmodel.refreshFromMongo(dic)
        def clear_search():
            new_data = mongodb.display_data()
            listmodel.refreshFromMongo(new_data)

        interface.dataSignal.connect(on_data_added)
        interface.searchSignal.connect(on_search)
        interface.clearSearchSignal.connect(clear_search)
        
        engine.rootContext().setContextProperty("_interface", interface)
        engine.rootContext().setContextProperty("mymodel", listmodel)

        qml_file = Path(__file__).resolve().parent / "ui/main.qml"
        engine.load(qml_file)

        if not engine.rootObjects():
            sys.exit(-1)
        sys.exit(app.exec())
