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

print("Traduciendo ./tests/teacup/teacup.xmile a ./tests/teacup/teacup-devsml.xml")
subprocess_call("sd2devsml.py ./tests/teacup/teacup.xmile ./tests/teacup/teacup-devsml.xml")
print("Traduciendo ./tests/teacup/teacup-devsml.xml a CD++ (ma, ev y src)")
subprocess_call("devsml2ma.py ./tests/teacup/teacup-devsml.xml ./tests/teacup/teacup.ma ./tests/teacup/teacup.ev ./tests/teacup/src/ ")
print("Fin.")
print("Archivos resultantes en ./tests/teacup")
