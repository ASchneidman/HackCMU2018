from glob import glob

class ParseInput:

    def __init__(self, lines_max):
        self.surprise = ""
        self.lines_max = lines_max

    def get_files(self, source):
        return glob ('source/**/*.txt', True)

    def parse_data (self, source):
        files = self.get_files(source)
        parsed_files = []
        for f in files:
            f_stream = open (f, "r")
            num_errors = int (f_stream.readline())
            error_lines_str = (f_stream.readline().split(", "))
            error_lines = [int(n) for n in error_lines_str]
            code = f_stream.readlines()
            code = code.append(['' for i in range(self.lines_max - len(code))])
            parsed_files.append((num_errors, error_lines, code))
        return parsed_files

