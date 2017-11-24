"""
Python model SIR.py
Translated using PySD version 0.8.2
"""
from __future__ import division
import numpy as np
from pysd import utils
import xarray as xr

from pysd.py_backend.functions import cache
from pysd.py_backend import functions

_subscript_dict = {}

_namespace = {
    'Total Population': 'total_population',
    'Recovering': 'recovering',
    'Susceptible': 'susceptible',
    'TIME STEP': 'time_step',
    'TIME': 'time',
    'SAVEPER': 'saveper',
    'Infectious': 'infectious',
    'Contact Infectivity': 'contact_infectivity',
    'FINAL TIME': 'final_time',
    'INITIAL TIME': 'initial_time',
    'Time': 'time',
    'Duration': 'duration',
    'Succumbing': 'succumbing',
    'Recovered': 'recovered'
}


@cache('run')
def total_population():
    """
    Total Population

    Persons

    constant


    """
    return 1000


@cache('run')
def final_time():
    """
    FINAL TIME

    Day

    constant

    The final time for the simulation.
    """
    return 100


@cache('step')
def recovering():
    """
    Recovering

    Persons/Day

    component


    """
    return infectious() / duration()


@cache('step')
def susceptible():
    """
    Susceptible

    Persons

    component


    """
    return integ_susceptible()


integ_susceptible = functions.Integ(lambda: -succumbing(), lambda: total_population())


@cache('run')
def contact_infectivity():
    """
    Contact Infectivity

    Persons/Persons/Day

    constant


    """
    return 0.3


@cache('step')
def infectious():
    """
    Infectious

    Persons

    component


    """
    return integ_infectious()


integ_infectious = functions.Integ(lambda: succumbing() - recovering(), lambda: 5)


@cache('step')
def saveper():
    """
    SAVEPER

    Day [0,?]

    component

    The frequency with which output is stored.
    """
    return time_step()


@cache('run')
def initial_time():
    """
    INITIAL TIME

    Day

    constant

    The initial time for the simulation.
    """
    return 0


@cache('run')
def duration():
    """
    Duration

    Days

    constant


    """
    return 5


@cache('run')
def time_step():
    """
    TIME STEP

    Day [0,?]

    constant

    The time step for the simulation.
    """
    return 0.03125


integ_recovered = functions.Integ(lambda: recovering(), lambda: 0)


@cache('step')
def succumbing():
    """
    Succumbing

    Persons/Day

    component


    """
    return susceptible() * infectious() / total_population() * contact_infectivity()


@cache('step')
def recovered():
    """
    Recovered

    Persons

    component


    """
    return integ_recovered()
