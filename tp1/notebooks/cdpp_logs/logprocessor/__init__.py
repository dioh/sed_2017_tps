"""
Utilidades para procesar archivos de output y log de CD++
"""

from functools import partial
import re


def extract_model_name(model_str_from_log):
    return model_str_from_log.split('(')[0]


def time_str_to_seconds(time_str):
    """
    Transforma un string de tiempo del tipo HH:MM:SS:ms en segundos
    """
    if time_str == '...':
        return float('Inf')

    vals = [float(x) for x in time_str.strip().split(':')]
    return vals[0]*3600 + vals[1] * 60 + vals[2] + vals[3]/1000


def remove_square_brackets(value):
    return re.sub('[]', '', value)



class DevsLogs(object):

    message_transform_map = {'X': log_line_to_x_y_message,
                             'Y': log_line_to_x_y_message,
                             '*': log_line_to_at_asterisk_message,
                             '@': log_line_to_at_asterisk_message,
                             'D': log_line_to_d_message}

    @classmethod
    def add_to_message_to_list(cls, a_list, a_message):
        a_list.append(a_message)

    def __init__(self):
        self.y_messages = []
        self.x_messages = []
        self.at_messages = []
        self.asterisk_messages = []
        self.d_messages = []
        self.add_message_map = {'X': partial(self.add_to_message_to_list,
                                             self.x_messages),
                                'Y': partial(self.add_to_message_to_list,
                                             self.y_messages),
                                '*': partial(self.add_to_message_to_list,
                                             self.asterisk_messages),
                                '@': partial(self.add_to_message_to_list,
                                             self.at_messages),
                                'D': partial(self.add_to_message_to_list,
                                             self.d_messages)}

    def add_message(self, raw_message):
        message_parts = [part.strip() for part in raw_message.split('/')]
        message_type = message_parts[2]
        message = self.message_transform_map[message_type](message_parts)
        self.add_message_map[message_type](message)

    @classmethod
    def log_line_to_x_y_message(cls, log_line):
        """
        Transforma mensajes del tipo
        0 / L / (X|Y) / time_mark / model_from(int) / port / [value] / model_to(int)
        
        en:
        { 'seconds': time_mark_in_seconds, 'model_from': model_from,
          'model_to': model_to, 'port_to': port, 'value':value }
        """
        return {'message_type': log_line[2],
                'time_mark': log_line[3],
                'time_in_seconds': time_str_to_seconds(log_line[3]),
                'model_from': extract_model_name(log_line[4]),
                'model_to': extract_model_name(log_line[-1]),
                'port_to': log_line[5],
                'value': remove_square_brackets(log_line[6])}

    @classmethod
    def log_line_to_at_asterisk_message(cls, log_line):
        """
        Transforma mensajes del tipo
        0 / L / (X|Y) / time_mark / model_from(int) / model_to(int)
        
        en:
        { 'seconds': time_mark_in_seconds, 'model_from': model_from,
          'model_to': model_to, 'port_to': port, 'value':value }
        """
        return {'message_type': log_line[2],
                'time_mark': log_line[3],
                'time_in_seconds': time_str_to_seconds(log_line[3]),
                'model_from': extract_model_name(log_line[4]),
                'model_to': extract_model_name(log_line[-1])}

    @classmethod
    def log_line_to_d_message(cls, log_line):
        """
        Transforma mensajes del tipo
        0 / L / (X|Y) / time_mark / model_from(int) / time / model_to(int)

        en:
        { 'seconds': time_mark_in_seconds, 'model_from': model_from,
          'model_to': model_to, 'port_to': port, 'value':value }
        """
        return {'message_type': log_line[2],
                'time_mark': log_line[3],
                'time_in_seconds': time_str_to_seconds(log_line[3]),
                'model_from': extract_model_name(log_line[4]),
                'model_to': extract_model_name(log_line[-1]),
                'next_time_mark': if_three_dot_transform_to_inf(log_line[5]),
                'next_time_mark_in_seconds': time_str_to_seconds(log_line[5])}


def if_three_dot_transform_to_inf(time_str):
    if time_str == '...':
        return 'Inf'

    return time_str
    


def devs_outputline_to_dict(line):
    splitted_line = line.split(' ')
    return {'time_mark': splitted_line[0],
            'time_in_seconds': time_str_to_seconds(splitted_line[0]),
            'port': splitted_line[1],
            'value': remove_square_brackets(splitted_line[2])}


def devs_output_to_list_of_dict(filename):
    ret_val = []
    with open(filename, 'r') as file:
        ret_val = [devs_outputline_to_dict(line) for line in file.readlines()]

    return ret_val


def get_devs_logs(filename):
    devs_logs = DevsLogs()
    with open(filename, 'r') as file:
        for line in file:
            devs_logs.add_message(line)

    return devs_logs
