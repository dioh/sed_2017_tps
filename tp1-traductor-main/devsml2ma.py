"""
Script de punto de entrada para la traducción devsml a devsml
"""

import argparse
from pathlib import Path


def process_devsml_file(devsmlfile, ma_filename):
    """
    Procesa el archivo devsmlfile y
    crea el archivo devsml equivalente de nombre ma_filename
    """
    print("Procesando {0}".format(devsmlfile))
    print("Creando ma {1}".format(ma_filename))


def main():
    """
    Bloque principal
    """
    parser = argparse.ArgumentParser(description="Transforma el archivo devsmlfile en su equivalente .ma de CD++ de nombre maout.")
    parser.add_argument("devsmlfile", help="Archivo devsml a traducir")
    parser.add_argument("maout", help="Nombre del archivo ma de CD++ a crear como salida")
    args = parser.parse_args()

    devsml_file = Path(args.devsmlfile)
    if devsml_file.is_file():
        process_devsml_file(args.devsmlfile, args.maout)
    else:
        print("Error!")
        print("Archivo {0} no encontrado".format(args.devsmlfile))


if __name__ == "__main__":
    main()