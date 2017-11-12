#!/usr/bin/env python
import sys
import subprocess


def remove_prefix(prefix, value):
    if value.startswith(prefix):
        return value[len(prefix):]
    return value


def print_results(out):
    if out is None:
        return False

    result = out.decode('utf8').split('\n')
    for lin in result:
        if not lin.startswith('#') or len(lin.strip()) > 0:
            print(lin)


def subprocess_call(cmd):
    cmd_to_call = cmd
    if sys.platform == 'win32':
        cmd_to_call = remove_prefix('./', cmd)

    p = subprocess.Popen(cmd_to_call, stdout=subprocess.PIPE, shell=True)
    out, err = p.communicate()
    print_results(out)
    print_results(err)

print("Traduciendo ./tests/samuelson/samuelson.xmile a ./tests/samuelson/samuelson-devsml.xml")
subprocess_call("./sd2devsml.py ./tests/samuelson/samuelson.xmile ./tests/samuelson/samuelson-devsml.xml")

print("Traduciendo ./tests/samuelson/samuelson-devsml.xml a CD++ (ma, ev y src)")
subprocess_call("./devsml2ma.py ./tests/samuelson/samuelson-devsml.xml ./tests/samuelson/samuelson.ma ./tests/samuelson/samuelson.ev ./tests/samuelson/src/ ")
print("Fin.")

print("Archivos resultantes en ./tests/samuelson")
