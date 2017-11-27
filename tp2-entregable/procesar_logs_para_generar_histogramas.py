#!/usr/bin/env python2


from os.path import walk, join
import re

def procesar_uno(file_name): 
    N = 10
    M = 10
    found = [[0] * M for i in range(0,N)]
    cntFound = 0
    A, B, C = [], [], []
    for ln in reversed(open(file_name,"r").readlines()):
        if cntFound == N * M:
            break
        if ln.startswith("0 / L / Y /"): 
            cell = ln.split('/')[4]
            p = re.compile("opinion(.*)\([0-9]+\)")
            s = p.findall(cell)[0]
            x, y, z = int(s[1]), int(s[3]), int(s[5])
            if(z == 0 and found[x][y] == 0):
                cntFound += 1
                found[x][y] = 1

                val  = ln.split('/')[6]
                #print([x,y])
                val = float(val.strip())

                if(val < -1):
                    A.append(val)
                elif(val >= -1 and val <= 1):
                    B.append(val)
                elif(val > 1):
                    C.append(val)

    return len(A), len(B), len(C)


def procesar(arg, dirname, fnames):
    if fnames[0] in ['exp_55555', 'exp_56667', 'exp_55667', 'exp_55777', 'exp_57777', 'exp_55677']:
        return
    for filename in fnames:
        ffile = join(dirname, filename)
        print(ffile)
        with open(dirname + '.out', 'a') as f:
            procesado = procesar_uno(ffile)
            print(procesado)
            f.write("%s,%s,%d,%d,%d\n" % (dirname,filename, procesado[0],
                procesado[1], procesado[2]))


walk('result_logs', procesar, None)


