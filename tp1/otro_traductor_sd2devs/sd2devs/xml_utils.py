"""
   Utilidades xml
"""

import xml.etree.ElementTree as ET


def read_xml(filename):
    '''
    Parsea el archivo xmile pasado como parametro
    '''
    return ET.parse(filename)


def elements_equal(anElementTree, otherElementTree):
    """
    Veririfica si dos objetos del tipo ElementTree son iguales
    """
    if anElementTree.tag != otherElementTree.tag:
        return False
    if anElementTree.text != otherElementTree.text:
        return False
    if not(not anElementTree.tail and
           not otherElementTree.tail) or \
       ((anElementTree.tail or
         '').strip() !=
        (otherElementTree.tail or
         '').strip()):
        return False
    if anElementTree.attrib != otherElementTree.attrib:
        return False
    if len(anElementTree) != len(otherElementTree):
        return False
    for anElementTreeChildren, \
        otherElementTreeChildren in zip(anElementTree.getchildren(),
                                        otherElementTree.getchildren()):
        if not(elements_equal(anElementTreeChildren,
                              otherElementTreeChildren)):
            return False

    return True


def show_first_elements_diff(anElementTree, otherElementTree):
    """
    Veririfica si dos objetos del tipo ElementTree son iguales
    """
    if anElementTree.tag != otherElementTree.tag:
        message = 'Elements tags not equals: \'{0}\' != \'{1}\''
        return message.format(anElementTree.tag,
                              otherElementTree.tag)
    if anElementTree.text.strip() != otherElementTree.text.strip():
        message = 'Elements texts not equals: \'{0}\' != \'{1}\''
        return message.format(anElementTree.text,
                              otherElementTree.text)
    if not(not anElementTree.tail and
           not otherElementTree.tail) or \
       ((anElementTree.tail or
         '').strip() !=
        (otherElementTree.tail or
         '').strip()):
        message = 'Element {2}  tails not equals: \'{0}\' != \'{1}\''
        return message.format(anElementTree.tail,
                              otherElementTree.tail,
                              anElementTree)
    if anElementTree.attrib != otherElementTree.attrib:
        message = 'Elements attribs not equals: {0} != {1}'
        return message.format(anElementTree.attrib, otherElementTree.attrib)
    if len(anElementTree) != len(otherElementTree):
        message = 'Elements len not equals: {0} != {1}'
        return message.format(len(anElementTree), len(otherElementTree))
    for anElementTreeChildren,\
        otherElementTreeChildren in zip(anElementTree.getchildren(),
                                        otherElementTree.getchildren()):
        if not(elements_equal(anElementTreeChildren,
                              otherElementTreeChildren)):
            return show_first_elements_diff(anElementTreeChildren,
                                            otherElementTreeChildren)

    return 'Elements are equals'
