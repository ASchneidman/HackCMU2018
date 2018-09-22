from glob import glob
import code
import re
import pickle

def parse_tokens (input_str):
    regex = re.compile(r"[\w\.]+|.")
    tokens = re.findall(regex, input_str)
    if len(tokens) > 80:
        tokens = tokens[:79]

    tokens.extend(['' for i in range(80 - len(tokens))])
    word_adjusted = [re.sub(r"[\w\.]+", r"\0", s) for s in tokens]
    return word_adjusted

def get_token_values(str_list,dict_src='../../res/dictionaries/dictionary.bin'):
    dict = {}
    with open (dict_src, 'rb') as handle:
        dict = pickle.load(handle)

    try:
        return [dict[token] for token in str_list]
    except:
        raise ValueError("a character was found that was not in the dictionary")

class ParseInput:

    def __init__(self, lines_max):
        self.surprise = ""
        self.lines_max = lines_max

    def get_files(self, source):
        #print (source)
        if not (source is None):
            return glob(source + "/*.txt", recursive=True)
        else:
            return glob ('../../linter/outputfiles/*.txt', recursive=True)

    def parse_data (self, source):
        files = self.get_files(source)
        parsed_files = []
        for f in files:
            print ("Parsing " + str(f))
            f_stream = open (f, "r", encoding="ISO-8859-1")
            num_errors = int (f_stream.readline())
            if (num_errors == 0):
                continue
            line = f_stream.readline()
            error_lines_str = (line.split(", "))
            error_lines = [int(n) for n in error_lines_str]
            code = f_stream.readlines()
            if len(code) > 1000:
                code = code[:999]
            code.extend(['' for i in range(self.lines_max - len(code))])
            token_code = [get_token_values (parse_tokens (line_str)) 
                          for line_str in code]
            parsed_files.append((num_errors, error_lines, token_code))
        return parsed_files
