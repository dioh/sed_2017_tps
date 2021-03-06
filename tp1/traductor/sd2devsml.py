#!/usr/bin/env python
"""
Script de punto de entrada para la traduccion xmile a devsml
"""

import argparse
import logging
try:
    from pathlib import Path
    Path().expanduser()
except (ImportError, AttributeError):
    from pathlib2 import Path
from traductor.libxmile2devsml import convert_xmile_to_devsml

logger = logging.getLogger(__name__)


def process_xmile_file(xmilefile, devsml_filename):
    """
    Procesa el archivo xmilefile y
    crea el archivo devsml equivalente de nombre devsml_filename
    """
    convert_xmile_to_devsml(devsml_filename, xmilefile)


def main():
    """
    Bloque principal
    """
    parser = argparse.ArgumentParser(description="Transforma el archivo xmilefile en su equivalente devsml de nombre devsmlout.")
    parser.add_argument("xmilefile", help="Archivo xmile a traducir")
    parser.add_argument("devsmlout", help="Nombre del archivo devsml a crear como salida")
    args = parser.parse_args()

    xmile_file = Path(args.xmilefile)
    if xmile_file.is_file():
        process_xmile_file(args.xmilefile, args.devsmlout)
    else:
        print("Error!")
        print("Archivo {0} no encontrado".format(args.xmilefile))


if __name__ == "__main__":
    main()
