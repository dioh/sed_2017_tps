import pysd
import numpy as np

SIR_MODEL = pysd.read_vensim('sir.mdl')

SIR_MODEL.run(return_timestamps=np.arange(0.0,100.0,0.125), return_columns=['Contact Infectivity', 	'Duration',	'Infectious', 'Recovered', 'Recovering', 'Succumbing', 'Susceptible', 'Total Population']).to_csv('sir_sd.csv', sep=",", encoding='utf-8')