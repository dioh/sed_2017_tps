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

print("Traduciendo ./examples/stock_to_capacity/stock_to_capacity.xmile a ./examples/stock_to_capacity/stock_to_capacity-devsml.xml")
subprocess_call("./sd2devsml.py ./examples/stock_to_capacity/stock_to_capacity.xmile ./examples/stock_to_capacity/stock_to_capacity-devsml.xml")

print("Traduciendo ./examples/stock_to_capacity/stock_to_capacity-devsml.xml a CD++ (ma, ev y src)")
subprocess_call("./devsml2ma.py ./examples/stock_to_capacity/stock_to_capacity-devsml.xml ./examples/stock_to_capacity/stock_to_capacity.ma ./examples/stock_to_capacity/stock_to_capacity.ev ./examples/stock_to_capacity/src/ ")
print("Fin.")

print("Archivos resultantes en ./examples/stock_to_capacity")
