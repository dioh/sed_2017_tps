#C:\Documents and Settings\usuario\Escritorio>c:\Python24\python.exe params.py
#C:\eclipse\CD++Builder Example Workspace\CellDEVS Examples\Tp Final

#"C:\eclipse\CD++Builder Example Workspace\CellDEVS Examples\Tp 02 - Opinion"
#C:/eclipse/plugins/cdBuilder.simulator_1.0.0.201010092241/internal/simuOrig.exe  -m"Influmodel.ma" -o"InflumodelOUT_5.out" -l"InflumodelLOG_5.log" -t"00:00:20:000"  
#C:/eclipse/plugins/cdBuilder.simulator_1.0.0.201010092241/internal/drawlog.exe  -m'Influmodel.ma' -c'opinion' -l'InflumodelLOG_5.log' -w'6' -p'2'  1>InflumodelDRW_4.drw 

import subprocess as sp
import os
import glob
import sys

#os.chdir('C:\eclipse\CD++Builder Example Workspace\CellDEVS Examples\Tp Final')

cmd1 = 'C:/eclipse/plugins/cdBuilder.simulator_1.0.0.201010092241/internal/simuOrig.exe  -m"%s" -o"InflumodelOUT_%s.out" -l"InflumodelLOG_%s.log" -t"00:%s:00:000" 1>x'
cmd2 = 'C:/eclipse/plugins/cdBuilder.simulator_1.0.0.201010092241/internal/drawlog.exe  -m"%s" -c"opinion" -l"InflumodelLOG_%s.log" -w"6" -p"2"  1>InflumodelDRW_%s.drw' 


def reemplazar(org,dest,reemplazos):
        template = open(org) 
        macro = open(dest,'w') 
        templ = template.read()

        for r in reemplazos:
            templ = templ.replace(r[0],r[1])
        macro.write(templ)

        template.close()
        macro.close()


def simular(ini):
    params_ini = ini.split(".val")[0].split("_")[1:] # 10.60_03
    po = params_ini[0].split(".")[0]
    influ = params_ini[0].split(".")[1]
    replica = params_ini[1]
    
    nombre = str(po) + "_" + str(influ) + "_" + replica	
    
    modelo = 'Influmodel.ma' # <----------------<< 
    
    reemplazar(modelo  + '.template',modelo ,[("zzzzzz",'CC/' + ini)])    

    cmd = cmd1 % (modelo , nombre,nombre,"4") # <----------------<< TIEMPO EN MINUTOS
    sp.call(cmd,shell=True)
    
    cmd = cmd2 % (modelo , nombre,nombre)        
    sp.call(cmd,shell=True)

    os.remove("InflumodelLOG_%s.log" % nombre)
    os.remove("InflumodelOUT_%s.out" % nombre)

    drawlog = 'InflumodelDRW_%s.drw' % nombre
    dl = open(drawlog)
    r,a,i = parse(dl.read(),10)  # <----------------<< R
    dl.close()
    os.remove(drawlog)
    
    
    pepe = open('hola.txt','a')
    linea = " ".join(  map(str,[po,influ,replica,r,a,i]) )
    print linea
    pepe.write(linea + "\n")
    pepe.close()

def parse(raw,n):
    mat = raw.split("Line :")[1:][-1].split("\n")[3:][0:n]
    mat2 = [ [ float(x) for  x in fila.split("|")[1].strip().split(" ") if x] for fila in mat  ]
    vec = []
    for m in mat2:
        vec = vec + m
    r,a,i = (0,0,0)
    for e in vec:
        if e > 1:
            a +=1
        elif e < -1:
            r += 1
        else:
            i += 1

    return (r,a,i)

for ini in os.listdir('./CC'):
    simular(ini)
                        
	

            
