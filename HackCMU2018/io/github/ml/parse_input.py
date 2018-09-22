from glob import glob
import code

class ParseInput:

    def __init__(self, lines_max):
        self.surprise = ""
        self.lines_max = lines_max

    def get_files(self, source):
        #print (source)
        return glob ('../../linter/outputfiles/*.txt', recursive=True)
    

    def parse_data (self, source):
        files = self.get_files(source)
        parsed_files = []
        for f in files:
            print(f)
            f_stream = open (f, "r", encoding="ISO-8859-1")
            num_errors = int (f_stream.readline())
            if (num_errors == 0):
                continue
            line = f_stream.readline()
            error_lines_str = (line.split(", "))
            error_lines = [int(n) for n in error_lines_str]
            code = f_stream.readlines()
            code.extend(['' for i in range(self.lines_max - len(code))])
            parsed_files.append((num_errors, error_lines, code))
        return parsed_files

