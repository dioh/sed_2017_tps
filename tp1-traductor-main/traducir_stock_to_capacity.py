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

print("Traduciendo ./tests/stock_to_capacity/stock_to_capacity.xmile a ./tests/stock_to_capacity/stock_to_capacity-devsml.xml")
subprocess_call("./sd2devsml.py ./tests/stock_to_capacity/stock_to_capacity.xmile ./tests/stock_to_capacity/stock_to_capacity-devsml.xml")

print("Traduciendo ./tests/stock_to_capacity/stock_to_capacity-devsml.xml a CD++ (ma, ev y src)")
subprocess_call("./devsml2ma.py ./tests/stock_to_capacity/stock_to_capacity-devsml.xml ./tests/stock_to_capacity/stock_to_capacity.ma ./tests/stock_to_capacity/stock_to_capacity.ev ./tests/stock_to_capacity/src/ ")
print("Fin.")

print("Archivos resultantes en ./tests/stock_to_capacity")
