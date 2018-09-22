from sys import argv
from functools import reduce
from ml import agent
from ml import parse_input

MAX = 2500

def runML(agent_src, data = '../../res/data'):
    init_data = [MAX, []]
    for i in range(4):
        init_data[1][i] = 50
    init_data[1][4] = MAX
    agent = agent.Agent (agent_src, init_data)
    parser = parse_input(MAX)
    data = parser.parse_data (data)
    fitness = []
    for i in range(100):
        agent.load_model()
        agent.mutate_model((i % 10) / 100.0)
        fitness.append((agent.get_model(), agent.run_model(data, 100)))
    (model, score) = reduce (lambda t1, t2: t1[0] if t1[1] >= t2[1] else t2[1], fitness)
    agent.set_model(model)
    agent.save_model



if __name__ == "__main__":
    if len(argv) == 1: raise ValueError ('usage: train_model.py path/to/agent path/to/data (optional)')
    elif len(argv) == 2: runML(argv[1])
    else: runML(argv[1], argv[2])
