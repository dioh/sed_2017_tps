import pysd

#No hay modelo de prueba en formato vensim :_(
LV_MODEL = pysd.read_vensim('hares-lynxes.mdl')

LV_MODEL.run(return_timestamps=range(0,180), return_columns=['area','size of one time lynx harvest','hares.hares','hares.births','hares.deaths','hares.birth fraction','hares.hares killed per lynx','hares.hare density','lynxes.lynxes','lynxes.births','lynxes.deaths','lynxes.harvest','lynxes.birth fraction','lynxes.death fraction']).to_csv('lv_sd.csv', sep=",", encoding='utf-8')