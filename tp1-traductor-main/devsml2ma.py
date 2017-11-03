"""
Script de punto de entrada para la traducción devsml a devsml
"""

import argparse
import logging
try:
    from pathlib import Path
    Path().expanduser()
except (ImportError, AttributeError):
    from pathlib2 import Path
from traductor.libdevsmlcdpp import devsml2cdpp


def process_devsml_file(devsmlfile, ma_filename, ev_filename, src_dir):
    """
    Procesa el archivo devsmlfile y
    crea el archivo devsml equivalente de nombre ma_filename
    """
    devsml2cdpp(devsmlfile, ma_filename, ev_filename, src_dir)


def main():
    """
    Bloque principal
    """
    parser = argparse.ArgumentParser(description="Transforma el archivo devsmlfile en su equivalente .ma de CD++ de nombre maout.")
    parser.add_argument("devsmlfile", help="Archivo devsml a traducir")
    parser.add_argument("maout", help="Nombre del archivo ma de CD++ a crear como salida")
    parser.add_argument("evout", help="Nombre del archivo ev de CD++ a crear como salida")
    parser.add_argument("src_dir", help="Ruta donde crear los archivos fuentes C++ (.h y .cpp) de CD++ que contienen los modelos")
    args = parser.parse_args()

    devsml_file = Path(args.devsmlfile)
    if devsml_file.is_file():
        process_devsml_file(args.devsmlfile, args.maout,
                            args.evout, args.src_dir)
    else:
        print("Error!")
        print("Archivo {0} no encontrado".format(args.devsmlfile))


if __name__ == "__main__":
    main()