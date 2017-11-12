#!/usr/bin/env python

import subprocess

def print_results(out):
    if out is None:
        return False

    result = out.decode('utf8').split('\n')
    for lin in result:
        if not lin.startswith('#') or len(lin.strip()) > 0:
            print(lin)


def subprocess_call(cmd):
    p = subprocess.Popen(cmd, stdout=subprocess.PIPE, shell=True)
    out, err = p.communicate()
    print_results(out)
    print_results(err)

print("Traduciendo ./tests/sir/sir.xmile a ./tests/sir/sir-devsml.xml")
subprocess_call("sd2devsml.py ./tests/sir/sir.xmile ./tests/sir/sir-devsml.xml")

print("Traduciendo ./tests/sir/sir-devsml.xml a CD++ (ma, ev y src)")
subprocess_call("devsml2ma.py ./tests/sir/sir-devsml.xml ./tests/sir/sir.ma ./tests/sir/sir.ev ./tests/sir/src/ ")
print("Fin.")

print("Archivos resultantes en ./tests/sir")
