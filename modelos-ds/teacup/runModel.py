import pysd

TEACUP_MODEL = pysd.read_vensim('teacup.mdl')

TEACUP_MODEL.run(params={'Room Temperature':70, 'Characteristic Time':100}, initial_condition=(0, {'Teacup Temperature':80}), return_timestamps=range(0,180), return_columns=['Characteristic Time', 'Heat Loss to Room', 'Room Temperature', 'Teacup Temperature']).to_csv('teacup_sd.csv', sep=",", encoding='utf-8')