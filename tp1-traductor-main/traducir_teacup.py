#!/usr/bin/env python
import os

print("Traduciendo .//tests//teacup//teacup.xmile a .//tests//teacup//teacup-devsml.xml")
os.system("./sd2devsml.py .//tests//teacup//teacup.xmile .//tests//teacup//teacup-devsml.xml")

print("Traduciendo .//tests//teacup//teacup-devsml.xml a CD++ (ma, ev y src)")
os.system("./devsml2ma.py .//tests//teacup//teacup-devsml.xml .//tests//teacup//teacup.ma .//tests//teacup//teacup.ev .//tests//teacup//src// ")
print("Fin.")

print("Archivos resultantes en .//tests//teacup")
