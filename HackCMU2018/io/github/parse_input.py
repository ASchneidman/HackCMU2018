from glob import glob
import os

def get_files(source):
    return glob ('source/**/*.txt', True)

def parse_data (source):
    files = get_files(source)
    parsed_files = []
    for f in files:
        f_stream = open (f, "r")
        num_errors = int (readline (f_stream))
        errror_lines_str = (readline (f_stream)).split(", ")
        error_lines = [int(n) for n in error_lines_str]
        code = f_stream.readlines()
        parsed_files.append((num_errors, error_lines, code))
    return parsed_files

