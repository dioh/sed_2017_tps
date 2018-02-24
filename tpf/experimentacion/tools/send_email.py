#!/usr/bin/env python
"""
Script para correos a gmail
"""

import argparse
import logging
import smtplib
import os.path as op
from email.mime.multipart import MIMEMultipart
from email.mime.base import MIMEBase
from email.mime.text import MIMEText
from email.utils import COMMASPACE, formatdate
from email import encoders
import sys
import traceback

logger = logging.getLogger(__name__)


def config_logging():
    handler = logging.StreamHandler()
    formatter = logging.Formatter(
            '%(asctime)s %(name)-12s %(levelname)-8s %(message)s')
    handler.setFormatter(formatter)
    logger.addHandler(handler)
    logger.setLevel(logging.DEBUG)


# Code from: https://stackoverflow.com/a/16509278/5948384
def send_email(send_from, send_to, subject, message, files=[],
               username='', password='', server="smtp.gmail.com", port=587,
               use_tls=True):
    """Compose and send email with provided info and attachments.

    Args:
        send_from (str): from name
        send_to (str): to name
        subject (str): message title
        message (str): message body
        files (list[str]): list of file paths to be attached to email
        server (str): mail server host name
        port (int): port number
        username (str): server auth username
        password (str): server auth password
        use_tls (bool): use TLS mode
    """
    try:
        msg = MIMEMultipart()
        msg['From'] = send_from
        msg['To'] = COMMASPACE.join(send_to)
        msg['Date'] = formatdate(localtime=True)
        msg['Subject'] = subject

        msg.attach(MIMEText(message))

        for path in files:
            part = MIMEBase('application', "octet-stream")
            with open(path, 'rb') as file:
                part.set_payload(file.read())
            encoders.encode_base64(part)
            part.add_header('Content-Disposition',
                            'attachment; filename="{}"'.format(
                                op.basename(path)))
            msg.attach(part)

        smtp = smtplib.SMTP(server, port)
        if use_tls:
            smtp.starttls()
        smtp.login(username, password)
        smtp.sendmail(send_from, send_to, msg.as_string())
        smtp.quit()
        print('successfully sent the mail')
    except:
        print("failed to send mail")
        print("Unexpected error:", sys.exc_info()[0])
        print("Detail (?):", sys.exc_info()[1])
        print("Stack trace:", traceback.print_tb(sys.exc_info()[2]))


def main():
    """
    Bloque principal
    """
    config_logging()
    parser = argparse.ArgumentParser(
        description="Auto envia un email con la info de la ejecucion.")
    parser.add_argument("email",
                        help="e-mail a utilizar.")
    parser.add_argument("password",
                        help="Password del email.")
    parser.add_argument("subject",
                        help="Asunto del correo.")
    parser.add_argument("file",
                        help="Archivo a adjuntar.")
    args = parser.parse_args()

    send_email(args.email, args.email,
               args.subject, "Ver archivo adjunto.", [args.file],
               args.email, args.password)


if __name__ == "__main__":
    main()
