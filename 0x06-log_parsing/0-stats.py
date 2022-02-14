#!/usr/bin/python3
""" Script that reads stdin line by line and computes metrics """
import sys

cont = 0
cont_size = 0
status = {"200": 0, "301": 0, "400": 0, "401": 0, "403": 0, "404": 0,
                    "405": 0, "500": 0}


def dict_status(status_code):
    if status_code == "200":
        status["200"] += 1
    elif status_code == "301":
        status["301"] += 1
    elif status_code == "400":
        status["400"] += 1
    elif status_code == "401":
        status["401"] += 1
    elif status_code == "403":
        status["403"] += 1
    elif status_code == "404":
        status["404"] += 1
    elif status_code == "405":
        status["405"] += 1
    elif status_code == "500":
        status["500"] += 1


if __name__ == '__main__':
    try:
        for line in sys.stdin:
            cont += 1
            array_line = line.split(' ')
            status_code = array_line[7]
            dict_status(status_code)
            size = int(array_line[8][0:-1])
            cont_size += size

            if cont == 10:
                print("File size: {}".format(cont_size))

                for k, v in status.items():
                    if v != 0:
                        print("{}: {}".format(k, v))
                    status[k] = 0

                cont = 0
                cont_size = 0

    except KeyboardInterrupt:
        print("File size: {}".format(cont_size))

        for k, v in status.items():
            if v != 0:
                print("{}: {}".format(k, v))

        raise
