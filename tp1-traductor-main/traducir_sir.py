#!/usr/bin/env python
import os

print("Traduciendo .//tests//sir//sir.xmile a .//tests//sir//sir-devsml.xml")
os.system(".//sd2devsml.py .//tests//sir//sir.xmile .//tests//sir//sir-devsml.xml")

print("Traduciendo .//tests//sir//sir-devsml.xml a CD++ (ma, ev y src)")
os.system(".//devsml2ma.py .//tests//sir//sir-devsml.xml .//tests//sir//sir.ma .//tests//sir//sir.ev .//tests//sir//src// ")
print("Fin.")

print("Archivos resultantes en .//tests//sir")
