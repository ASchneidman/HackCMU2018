from sys import argv
from functools import reduce
from ml import agent

def runML(agent_src, data = '../../res/data'):
    agent = agent.Agent (agent_src, init_data)
    data = parse_data (data)
    fitness = []
    for i in range(100):
        agent.load_model()
        agent.mutate_model([(i % 10)])
        fitness.append((agent.get_model(), agent.run_model(data, 100)))
    (model, score) = reduce (lambda t1, t2: t1[0] if t1[1] >= t2[1] else t2[1], fitness)
    agent.set_model(model)
    agent.save_model



if __name__ == "__main__":
    if len(argv) == 1: raise ValueError ('usage: train_model.py path/to/agent path/to/data (optional)')
    elif len(argv) == 2: runML(argv[1])
    else: runML(argv[1], argv[2])
